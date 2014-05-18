var JsfsConnection = function() {

	/**
	 * JSFS Dispatcher URL
	 */
	var jsfsDispatcherUrl = "/jsfs-dispatcher/jsfs";
	
	/**
	 * URL to the token service of your web application.
	 */
	var tokenServiceUrl = "/yourapp/auth?jsfstoken=true";
	
	/**
	 * BYPS client object.
	 * Provides access to the service interface of the JSFS dispatcher.
	 */
	this.bclient = null;
	
	/**
	 * JSFS Agent service interface. 
	 */
	this.agent = null;
	
	/**
	 * Authentication class.
	 * This class is used by the BYPS framework to perform authentication.
	 * For the use of JSFS, it connects to "Your Web Application" and requests a token.
	 * When the token is received, the FileSystemNotifyImpl object is registered
	 * with the JSFS dispatcher.
	 */
	var JsfsAuthentication = function() {
		
		/**
		 * Token received from "Your Web Application"
		 */
		this._token = "";
		
		this.getToken = function() {
			return this._token;
		};
		
		/**
		 * Authentication function.
		 * This function is called by the BYPS framework if authentication is required.
		 * It is invoked after the protocol is negotiated or if a HTTP status 401 is received 
		 * from a previsious request.
		 * Sends a GET request to the token service at tokenServiceUrl.
		 * Expects a token in the response text.
		 * This private function is called from this.authenticate().
		 */
		this.authenticate = function(bclient, asyncResult) {

			if (asyncResult) throw byps.BException(byps.BExceptionC.INTERNAL, "Authentication does not provide an asynchronous implementation.");
			 
			var me = this;
			var xhr = new XMLHttpRequest();
			xhr.open('GET', tokenServiceUrl, false);
			
			xhr.send();
			
			if (xhr.status == 200) {
				me._token = xhr.responseText;
			}
			else {
				var ex = new byps.BException(byps.BExceptionC.IOERROR, "HTTP status " + xhr.status, xhr.responseText);
				throw ex;
			}
		};
		
		
		/**
		 * Check, if given exception should trigger an authenication process.
		 * This function is called from the BYPS framework.
		 */
		this.isReloginException = function(bclient, ex, typeId) { 
			return bclient.transport.isReloginException(ex, typeId); 
		};
		
		/**
		 * Return the session object.
		 * BYPS allows to send an implicit session object with each function call.
		 * But this functionality is not needed here.
		 */
		this.getSession = function(bclient, typeId, asyncResult) { 
			if (asyncResult) {
				asyncResult(null, null);
			}
		};
	};
	
	/**
	 * Initialize access to the JSFS Agent.
	 * This function connects to the JSFS Dispatcher and queries for the JSFS Agent interface.
	 * It sets the global variable bclient. The JSFS Agent interface is asynchronously received by
	 * callback functions and stored in the global variable jsfs.agent.
	 */
	this.init = function() {
		
		// Mabe the page was re-loaded: terminate previous connections 
		this.done();
		
		// Start background timer that keeps the application server session alive.
		this.keepAlive();
		
		// Initialize BYPS: 
		// - provide a BWire object
		// - provide a BTransportFactory
		// - create a BClient object
		// - supply a BAuthentication object
		// - start the BClient object
		
		var wire = new byps.BWireClient(jsfsDispatcherUrl, 0, 60);
		var transportFactory = new byps.BTransportFactory(
				com.wilutions.jsfs.BApiDescriptor_JSFS.instance(), 
				wire, 
				1); // = number of reverse connections (long-polls)
		this.bclient = com.wilutions.jsfs.createClient_JSFS(transportFactory);
		
		this.bclient.setAuthentication(new JsfsAuthentication());
		
		// Start BClient object and execute synchronously.
		// The object could also be started asynchronously.
		// This would require an asynchronous implementation of the BAuthentication object. 
		this.bclient.start();
		
		// Authentication has received a token which is the same for 
		// the Browser and the JSFS Agent
		var jsfsToken = this.bclient.getAuthentication().getToken();
		
		// Ask the JSFS Dispatcher for the JSFS Agent service interface
		this.agent = this.bclient.dispatcherService.getService(jsfsToken, false);
		
		// The BYPS connection should be closed, when the page is unloaded.
		// Otherwise a long-poll request might not be terminated.
		var me = this;
		window.onunload = function() {
			me.done();
		};
	};
	
	/**
	 * Cleanup resources (connections).
	 */
	this.done = function() {
		if (this.bclient) {
			var jsfsToken = this.bclient.getAuthentication().getToken();
			this.bclient.dispatcherService.unregisterNotifyService(jsfsToken);
			this.bclient.done();
		}
	};
	
	/**
	 * Keep the application server session alive.
	 * This keeps the jsfs.agent object valid.
	 */
	this.keepAlive = function() {
		if (this.bclient) {
			var auth = this.bclient.getAuthentication();
			if (auth) {
				var token = auth.getToken();
				this.bclient.dispatcherService.keepAlive(
						token, 
						function(ignored, ex) {});
			}
		}
		window.setTimeout("keepAlive()", 300 * 1000);
	};	
	
	/**
	 * Register notify service with JSFS Dispatcher. 
	 */
	this.registerNotify = function(notifyImpl) {
		
		// At first, the service object has to be added to the 
		// list of local available remote interfaces. This is done by
		// calling bclient.addRemote().
		this.bclient.addRemote(notifyImpl);
		
		// Secondly, the service object is published to the JSFS Dispatcher 
		// by calling bclient.dispatcherService.registernNotifyService.
		var jsfsToken = this.bclient.getAuthentication().getToken();
		this.bclient.dispatcherService.registerNotifyService(jsfsToken, notifyImpl);
	};
};
