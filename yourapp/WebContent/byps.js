var byps = byps || {};

// ------------------------------------------------------------------------------------------------

byps.BBinaryModel = function(v) {
	this.MEDIUM = "MEDIUM";
	this.JSON = "JSON";

	this._value = v;

	this.equals = function(rhs) {
		return this._value == rhs._value;
	};
};

// ------------------------------------------------------------------------------------------------

byps.BExceptionO = {
	formatMessage : function(code, msg, details, cause) {
		var s = "[BYPS:" + code + "]";
		if (msg) s += "[" + msg + "]";
		if (details) s += "[" + details + "]";
		if (cause) s += "[" + cause + "]";
		return s;
	}
};

// ------------------------------------------------------------------------------------------------

byps.BException = function(code, msg, details, cause) {
	this._typeId = 20;
	this.code = code;
	this.msg = msg;
	this.details = details;
	this.cause = cause;
};

byps.BException.prototype.toString = function() {
	var s = byps.BExceptionO.formatMessage(this.code, this.msg, this.details, this.cause);
	return s;
};

byps.throwExceptionFromStream = function(data) {
	var ex = data;
	if (data._typeId == 20) {
		ex = new byps.BException(data.code, data.msg, data.details, data.cause);
	}
	throw ex;
};

byps.throwBException = function(code, msg, details, cause) {
	throw new byps.BException(code, msg, details, cause);
};

byps.throwCORRUPT = function(msg, details) {
	throw new byps.BException(byps.BExceptionC.CORRUPT, msg, details);
};

byps.throwIOERROR = function(msg, details) {
	throw new byps.BException(byps.BExceptionC.IOERROR, msg, details);
};

byps.throwUNSUPPORTED = function(msg, details) {
	throw new byps.BException(byps.BExceptionC.UNSUPPORTED_METHOD, msg, details);
};

byps.throwINTERNAL = function(msg, details) {
	throw new byps.BException(byps.BExceptionC.INTERNAL, msg, details);
};

byps.throwTIMEOUT = function(msg, details) {
	throw new byps.BException(byps.BExceptionC.TIMEOUT, msg, details);
};

byps.BExceptionC = {

  /**
	 * Connection failed. A connection could not be established or a communication
	 * error occured (SocketException).
	 */
  CONNECTION_TO_SERVER_FAILED : 2,

  /**
	 * Internal error. Error code for unexpected internal error states. This
	 * errors are most likely caused due to a bug in byps.
	 */
  INTERNAL : 3,

  /**
	 * Corrupt stream data. The data to be deserialized is corrupt.
	 */
  CORRUPT : 8,

  /**
	 * Undeclared exception. If an undeclared exception is throw in a remote
	 * interface implementation, the peer receives a BException object with this
	 * code. An exception is undeclared if it is not defined in the API package
	 * and is not BException, e.g. NullPointerException.
	 */
  REMOTE_ERROR : 10,

  /**
	 * Service not implemented. This code is used, if a requested remote interface
	 * does not have an implementation.
	 */
  SERVICE_NOT_IMPLEMENTED : 11,

  /**
	 * Server cannot reach client for reverse request. This code is set in a call
	 * from server to client or from client to client, if the receiver is no more
	 * connected.
	 */
  CLIENT_DIED : 12,

  /**
	 * Communication error. This code is used, if a stream operation fails.
	 */
  IOERROR : 14,

  /**
	 * Too many requests. This code is used on the client side, if the thread pool
	 * for sending requests is exhausted.
	 */
  TOO_MANY_REQUESTS : 15,

  /**
	 * This code is used on the client size, if the BTransportFactory object does
	 * not support reverse connections.
	 */
  NO_REVERSE_CONNECTIONS : 16,

  /**
	 * This code is used, if a remote interface implementation does not support
	 * the requested method.
	 */
  UNSUPPORTED_METHOD : 17,

  /**
	 * Operation cancelled. This code is used, if an operation was cancelled or
	 * interrupted.
	 */
  CANCELLED : 19,

  /**
   * Reverse HTTP request should be sent again.
   * After HConstants#TIMEOUT_LONGPOLL_MILLIS, the server releases
   * a long-poll (reverse) request. The client should open 
   * a new long-poll. The server sends an empty response to the client.
   */
  RESEND_LONG_POLL : 204,
  
  /**
	 * This code can be used, if authentication is required for the method. Same
	 * as HttpURLConnection.HTTP_UNAUTHORIZED.
	 */
  UNAUTHORIZED : 401,

  /**
	 * Timeout. This code is used, if an operation exceeds its time limit.
	 * HWireClientR sends this code for expired long-polls. Same value as
	 * HttpURLConnection.HTTP_CLIENT_TIMEOUT.
	 */
  TIMEOUT : 408,

  /**
	 * Client has already invalidated the session. Same value as
	 * HttpURLConnection.HTTP_GONE.
	 */
  SESSION_CLOSED : 410,

};

// ------------------------------------------------------------------------------------------------

byps.BContentStream = function(streamId) {
	this._typeId = 15;
	this.streamId = streamId;
};

// ------------------------------------------------------------------------------------------------

byps.BSerializer = function(persistentNames, inlineNames, inlineInstance) {

	this.inlineInstance = inlineInstance;

	this.write = function(obj, bout) {
		for ( var ename in obj) {
			if (ename == '_typeId' || ename == '*i' || !obj.hasOwnProperty(ename)) {
				continue;
			}

			if (inlineNames) {
				var typeId = inlineNames[ename];
				if (typeId) {
					var ser = bout.registry.getSerializer(typeId);
					bout.writeElement(obj, ename, ser);
					continue;
				}
			}

			if (!persistentNames || persistentNames[ename]) {
				bout.writeElement(obj, ename);
				continue;
			}

			bout.saveTransient(obj, ename);
		}
	};

	this.read = function(obj, bin) {

		for ( var ename in obj) {

			if (ename == '_typeId' || ename == '*i' || !obj.hasOwnProperty(ename)) {
				continue;
			}

			if (inlineNames) {
				var typeId = inlineNames[ename];
				if (typeId) {
					var ser = bin.registry.getSerializer(typeId);
					bin.readElement(obj, ename, ser);
					continue;
				}
			}

			if (!persistentNames || persistentNames[ename]) {
				bin.readElement(obj, ename);
				continue;
			}
		}

		return obj;
	};

};

// ------------------------------------------------------------------------------------------------
// Serializer for arrays

byps.BSerializerArray = function(elementTypeId, nbOfDimensions) {

	var elementSerializer = undefined;

	var writeDim = function(obj, dim, bout, ser) {
		if (dim == 1) {
			for ( var i = 0; i < obj.length; i++) {
				bout.writeElement(obj, i, ser);
			}
		}
		else {
			for ( var i = 0; i < obj.length; i++) {
				writeDim(obj[i], dim - 1, bout, ser);
			}
		}
	};

	var getElementSerializer = function(registry) {
		if (elementSerializer === undefined) {
			elementSerializer = registry.getSerializer(elementTypeId);
		}
		return elementSerializer;
	};

	this.write = function(obj, bout) {
		var ser = getElementSerializer(bout.registry);
		writeDim(obj, nbOfDimensions, bout, ser);
	};

	var readDim = function(obj, dim, bin, ser) {
		if (dim == 1) {
			for ( var i = 0; i < obj.length; i++) {
				bin.readElement(obj, i, ser);
			}
		}
		else {
			for ( var i = 0; i < obj.length; i++) {
				readDim(obj[i], dim - 1, bin, ser);
			}
		}
	};

	this.read = function(obj, bin) {
		var ser = getElementSerializer(bin.registry);
		readDim(obj, nbOfDimensions, bin, ser);
		return obj;
	};

};

// ------------------------------------------------------------------------------------------------
// Serializer for Map

byps.BSerializerMap = function(valueTypeId) {

	var valueSerializer = undefined;

	var getValueSerializer = function(registry) {
		if (valueSerializer === undefined) {
			valueSerializer = registry.getSerializer(valueTypeId);
		}
		return valueSerializer;
	};

	this.write = function(obj, bout) {
		var ser = getValueSerializer(bout.registry);
		for ( var ename in obj) {
			if (ename == '_typeId' || ename == '*i' || !obj.hasOwnProperty(ename)) {
				continue;
			}
			bout.writeElement(obj, ename, ser);
		}
	};

	this.read = function(obj, bin) {
		var ser = getValueSerializer(bin.registry);
		for ( var ename in obj) {
			if (ename == '_typeId' || ename == '*i' || !obj.hasOwnProperty(ename)) {
				continue;
			}
			bin.readElement(obj, ename, ser);
		}
		return obj;
	};

};

//------------------------------------------------------------------------------------------------
//Serializer for streams

byps.BSerializer_15 = function() {

	this.write = function(obj, bout) {
	};
	
	this.read = function(obj, bin) {
	
		var url = bin.transport.wire.url;
		url += (url.indexOf('?') != url.length - 1) ? '?' : '&';
		obj.url = url + "messageid=" + bin.header.messageId + "&streamid=" + obj.streamId;
		return obj;
	
		return obj;
	};

};
byps.BSerializer_15.prototype = new byps.BSerializer();

//------------------------------------------------------------------------------------------------
//Serializer for Date

byps.BSerializer_17 = function() {
	
	this.inlineInstance = true;
	
	this.write = function(obj, bout) {
	};
	
	this.read = function(obj, bin) {
		
		// When restoring after write, obj is already a date object.
		// When reading data from the server, obj is an ISO representaion.
		var date = (obj.getUTCMonth) ? obj : new Date(obj);  
		return date;
	};

};
byps.BSerializer_17.prototype = new byps.BSerializer();

// ------------------------------------------------------------------------------------------------

byps.BSerializerRemote = function(clazz) {

	// When sending a remote, internal members are omitted.
	// The remote has a toJSON method that creates an
	// object that merly contains the type ID and the target ID.

	this.write = function(obj, bout) {
	};

	this.read = function(obj, bin) {
		if (obj.constructor !== Object) return obj;
		var transport = new byps.BTransport(bin.transport.apiDesc, bin.transport.wire, obj.targetId);
		obj = new clazz(transport);
		return obj;
	};

};

// ------------------------------------------------------------------------------------------------

byps.BRegistry = function() {

	// sublcass has to implement:
	// this._serializerMap

	this.getSerializer = function(typeId) {

		var ser = null;
		switch(typeId) {
		
		// bool, byte, short, int, ... String
		case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 10:
			break;
		case 15: 
			ser = this._streamSerializer; 
			break;
		case 17: 
			ser = this._dateSerializer; 
			break;
		default: 
			if (typeId >= 64) { 
					ser = this._serializerMap[typeId];
			}
			else {
					ser = this._defaultSerializer;
			}
			break;	
		}

		return ser;
	};

	this._defaultSerializer = new byps.BSerializer();
	this._streamSerializer = new byps.BSerializer_15();
	this._dateSerializer = new byps.BSerializer_17();
};

// ------------------------------------------------------------------------------------------------

byps.BApiDescriptor = function(name, basePackage, version, uniqueObjects, registry) {
	this.name = name;
	this.basePackage = basePackage;
	this.version = version;
	this.uniqueObjects = uniqueObjects;
	this.protocols = "J";
	this.registry = registry;
};

// ------------------------------------------------------------------------------------------------

byps.BNegotiate = function(apiDesc) {
	this.JSON = "J";

	this.protocols = this.JSON;
	this.version = apiDesc.version;
	this.targetId = "";

	this.toArray = function() {
		return [ "N", "J", this.version, "_", this.targetId ];
	};

	this.fromArray = function(arr) {
		if (!arr || arr.length < 5 || arr[0] != "N") throw new byps.BException(byps.BException_CORRUPT, "Invalid negotiate message.");
		this.targetId = arr[4];
	};
};

byps.BNegotiate_isNegotiateMessage = function(buf) {
	return buf.indexOf("[\"N\"") == 0;
};

// ------------------------------------------------------------------------------------------------

byps.BStreamRequest = function() {
	this.streamId = "";
	this.messageId = "";

	// JavaScript kennt keinen InputStream.
	// Man könnte hier mit HTML 5 Blobs arbeiten. Die sind aber noch sehr neu.
	// Statt des InputStream nehme ich für
	// den Download eine URL,
	// den Upload die Stream-ID.
	// Die Download-URL wird beim Deserialisieren aus messageId und streamId
	// gebildet.
	// Das Hochladen erfolgt über das HTML-file-Formular. Als Antwort wird eine
	// vom Server
	// gebildete streamId zurückgegeben. Diese Stream-ID nehme ich als
	// "InputStream".

	this.downloadUrl = "";
	this.uploadResult = "";
};

// ------------------------------------------------------------------------------------------------

byps.BMessage = function(jsonText, streams) {
	this.jsonText = jsonText; // Message object to be send: { header: [ ...
	// message header ... ], objectTable: [ ] }
	this.streams = streams || []; // Array of BStreamRequest
};

// ------------------------------------------------------------------------------------------------

byps.BMessageHeader = function(messageId_or_rhs) {

	this.error = 0;
	this.flags = 0;
	this.targetId = "";
	this.messageId = "";

	if (typeof messageId_or_rhs == 'string') {
		this.messageId = messageId_or_rhs;
	}
	else {
		this.error = messageId_or_rhs.error;
		this.flags = messageId_or_rhs.flags;
		this.messageId = messageId_or_rhs.messageId;
		this.targetId = messageId_or_rhs.targetId;
	}

	this.createResponse = function(rhs) {
		rhs = rhs || this;
		var resp = rhs.clone();
		return resp;
	};

};

byps.BMessageHeaderC = {
	FLAG_RESPONSE : 2
};

// ------------------------------------------------------------------------------------------------
// This is how an asyncResult function has to be defined.
byps.BAsyncResult = function(result, exception) {
};

// ------------------------------------------------------------------------------------------------

byps.BWireClient = function(url, flags, timeoutSeconds) {

	var me = this;
	this.url = url;
	this.flags = flags || 0;

	this.timeoutMillisClient = timeoutSeconds ? (timeoutSeconds * 1000) : (-1);

	this.openRequestsToCancel = {};

	// Send function.
	// The streams are already sent by a HTML file upload.
	this.send = function(requestMessage, asyncResult, processAsync) {
		this._internalSend(requestMessage, asyncResult, this.timeoutMillisClient, processAsync);
	};

	this.sendR = function(requestMessage, asyncResult) {
		this._internalSend(requestMessage, asyncResult, 60 * 60 * 1000, true);
	};

	this._internalSend = function(requestMessage, asyncResult, timeoutMillis, processAsync) {
		var requestId = Math.random();
		var xhr = new XMLHttpRequest();

		this.openRequestsToCancel[requestId] = xhr;

		var destUrl = me.url;

		var isNegotiate = byps.BNegotiate_isNegotiateMessage(requestMessage.jsonText);
		var isReverse = requestMessage.header && (requestMessage.header.flags & byps.BMessageHeaderC.FLAG_RESPONSE) != 0;

		if (isNegotiate) {

			var negoStr = requestMessage.jsonText;
			negoStr = encodeURIComponent(negoStr);

			var servletPath = me.getServletPathForNegotiationAndAuthentication();

			destUrl = me.makeUrl(servletPath, [ "negotiate", negoStr ]);
		}
		else if (isReverse) {

			var servletPath = me.getServletPathForReverseRequest();

			destUrl = me.makeUrl(servletPath);
		}

		destUrl += (destUrl.indexOf("?") < 0) ? "?" : "&";
		destUrl += "__ts=";
		destUrl += new Date().getTime();

		xhr.open(isNegotiate ? 'GET' : 'POST', destUrl, processAsync);

		// XHR supports timeout only for async requests
		if (processAsync && timeoutMillis > 0) {
			xhr.timeout = timeoutMillis;
		}

		if (processAsync) {

			xhr.onreadystatechange = function() {
				if (xhr.readyState != 4) return;
				if (!asyncResult) return;

				if (xhr.status == 200) {
					var responseMessage = new byps.BMessage();
					responseMessage.jsonText = xhr.responseText; 
					// msg.jsonText = { header: [...], objectTable: [...] }
					asyncResult(responseMessage, null);
				}
				else {
					var ex = new byps.BException(xhr.status, "HTTP status " + xhr.status, xhr.responseText);
					asyncResult(null, ex);
				}

				delete me.openRequestsToCancel[requestId];
				asyncResult = null;
			};
			
			xhr.onerror = function() {
				if (!asyncResult) return;
				
				var ex = new byps.BException(byps.BExceptionC.CONNECTION_TO_SERVER_FAILED, "Connection failed.");
				asyncResult(null, ex);
				
				delete me.openRequestsToCancel[requestId];
				asyncResult = null;
			};

			xhr.ontimeout = function() {
				if (!asyncResult) return;

				var ex = new byps.BException(byps.BExceptionC.TIMEOUT, "Timeout");
				asyncResult(null, ex);

				delete me.openRequestsToCancel[requestId];
				asyncResult = null;
			};
		}

		xhr.setRequestHeader("Content-type", "application/json");

		if (isNegotiate) {
			xhr.send();
		}
		else {
			xhr.send(requestMessage.jsonText);
		}

		if (!processAsync) {

			delete me.openRequestsToCancel[requestId];

			var result = new byps.BMessage();
			var exception = null;

			if (xhr.status == 200) {
				result.jsonText = xhr.responseText; // msg.jsonText = { header:
				// [ ... message header ...
				// ], objectTable: [ ] }
			}
			else {
				exception = new byps.BException(xhr.status, "HTTP status " + xhr.status, xhr.responseText);
			}

			asyncResult(result, exception);
		}

	};

	this.makeMessageId = function() {
		var v1 = Math.floor(Math.random() * Math.pow(10, 17));
		return v1.toString();
	};

	this.cancelAllRequests = function() {
		for (requestId in this.openRequestsToCancel) {
			var xhr = this.openRequestsToCancel[requestId];
			xhr.abort();
		}
		this.openRequestsToCancel = {};
	};

	this.getServletPathForNegotiationAndAuthentication = function() {
		var ret = this.url;
		var p = ret.lastIndexOf('/');
		if (p >= 0) {
			ret = ret.substring(p);
		}
		return ret;
	};

	this.getServletPathForReverseRequest = function() {
		var ret = this.url;
		var p = ret.lastIndexOf('/');
		if (p >= 0) {
			ret = ret.substring(p);
		}
		return ret;
	};

	this.makeUrl = function(servletPath, params) {
		var ret = this.url;
		var p = ret.lastIndexOf('/');
		if (p >= 0) ret = ret.substring(0, p);
		ret += servletPath;
		if (params) {
			for ( var i = 0; i < params.length; i += 2) {
				ret += (i == 0) ? "?" : "&";
				ret += params[i] + "=" + params[i + 1];
			}
		}
		return ret;
	};
};

// ------------------------------------------------------------------------------------------------

byps.BAuthentication = function() {
	this.authenticate = function(client, asyncResult) {
		;
	};
	this.isReloginException = function(client, ex, typeId) {
		return false;
	};
	this.getSession = function(client, typeId, asyncResult) {
	};
};

// ------------------------------------------------------------------------------------------------

byps.BTransport = function(apiDesc, wire, targetId) {

	this.apiDesc = apiDesc;
	this.wire = wire;
	this.targetId = targetId || "";

	this._authentication = null;
	this._lastAuthenticationTime = 0;
	this._lastAuthenticationException = null;
	this._asyncResultsWaitingForAuthentication = [];
	this._RETRY_AUTHENTICATION_AFTER_MILLIS = 1 * 1000;

	this.getOutput = function() {
		return new byps.BInputOutput(this);
	};

	this.getResponse = function(requestHeader) {
		var responseHeader = new byps.BMessageHeader(requestHeader);
		responseHeader.flags |= byps.BMessageHeaderC.FLAG_RESPONSE;

		var bout = new byps.BInputOutput(this, responseHeader);
		return bout;
	};

	this.getInput = function(jsonText) {
		return new byps.BInputOutput(this, null, jsonText);
	};

	this.sendMethod = function(methodRequest, asyncResult) {
		var ret = null;
		if (asyncResult) {

			this._assignSessionThenSendMethod(methodRequest, function(methodResult, ex) {
				var ret = methodResult ? methodResult.result : null;
				asyncResult(ret, ex);
			});

		}
		else {
			var methodResult = this._assignSessionThenSendMethod(methodRequest);
			ret = methodResult ? methodResult.result : null;
		}
		return ret;
	};

	this._assignSessionThenSendMethod = function(methodRequest, asyncResult) {
		var methodResult = null;

		if (this._authentication) {

			if (asyncResult) {

				var transport = this;

				this._authentication.getSession(null, methodRequest._typeId, function(session, ex) {

					if (ex) {

						var relogin = transport._internalIsReloginException(ex, typeId);
						if (relogin) {
							transport._reloginAndRetrySend(methodRequest, asyncResult);
						}
						else {
							asyncResult(null, ex);
						}

						asyncResult(null, ex);
					}
					else {

						transport._assignSessionInMethodRequest(methodRequest, session);
						transport.send(methodRequest, asyncResult);
					}
				});

			}
			else {
				var session = this._authentication.getSession(null, methodRequest._typeId);
				this._assignSessionInMethodRequest(methodRequest, session);
				methodResult = this.send(methodRequest);
			}
		}
		else {
			methodResult = this.send(methodRequest, asyncResult);
		}

		return methodResult;
	};

	this._assignSessionInMethodRequest = function(methodRequest, session) {
		// Replace session object element name
		// found in omethodRequestbj.__byps__sess with the session object.
		var sessElmName = methodRequest.__byps__sess;
		if (sessElmName) {
			methodRequest[sessElmName] = session;
			// delete methodRequest.__byps__sess; need this member in case of
			// re-login
		}
	};

	this.send = function(obj, asyncResult) {
		var processAsync = !!asyncResult;
		var methodResult = {};
		var exception = null;

		if (!processAsync) {
			asyncResult = function(result, ex) {
				methodResult = result;
				exception = ex;
			};
		}

		this._internalSend(obj, asyncResult, processAsync);

		if (!processAsync) {
			if (exception) throw exception;
		}

		return methodResult;
	};

	this._internalSend = function(obj, asyncResult, processAsync) {

		var me = this;
		var transport = this;

		var bout = transport.getOutput();
		var requestMessage = bout.store(obj);

		var outerResult = function(responseMessage, ex) {

			var methodResult = null;

			try {
				if (!ex) {
					var bin = transport.getInput(responseMessage.jsonText);
					methodResult = bin.load();
				}
			}
			catch (ex2) {
				ex = ex2;
			}
			;

			var relogin = me._internalIsReloginException(ex, 0);
			if (relogin) {

				me._reloginAndRetrySend(obj, asyncResult, processAsync);
			}
			else {

				asyncResult(methodResult, ex);
			}
		};

		wire.send(requestMessage, outerResult, processAsync);

	};

	this.recv = function(server, requestMessage, asyncResult) {
		var transport = this;
		var bin = this.getInput(requestMessage.jsonText);
		var methodObj = bin.load();

		var methodResult = function(obj, exception) {
			try {
				var bout = transport.getResponse(bin.header);
				if (exception) {
					bout.setException(exception);
				}
				else {
					bout.store(obj);
				}
				;
				var rmsg = bout.toMessage();
				asyncResult(rmsg, null);
			}
			catch (ex) {
				asyncResult(null, ex);
			}
		};

		var clientTargetId = bin.header.targetId;
		server.recv(clientTargetId, methodObj, methodResult);
	};

	this.negotiateProtocolClient = function(asyncResult, processAsync) { // BAsyncResult<Boolean>

		var me = this;

		var nego = new byps.BNegotiate(apiDesc);
		var jsonText = JSON.stringify(nego.toArray());
		var requestMessage = new byps.BMessage(jsonText);

		var outerResult = function(responseMessage, ex) {

			var exception = null;

			try {
				if (ex) {
					exception = ex;
				}
				else {
					var arr = JSON.parse(responseMessage.jsonText);
					nego.fromArray(arr);
					me.targetId = nego.targetId;
				}
			}
			catch (ex2) {
				exception = ex2;
			}
			;

			if (exception) {
				asyncResult(null, exception);
			}
			else {
				me._internalAuthenticate(asyncResult, processAsync);
			}
		};

		wire.send(requestMessage, outerResult, processAsync);

		return true;
	};

	this.createServerR = function(server) {
		return new byps.BServerR(this, server);
	};

	this.setAuthentication = function(auth, onlyIfNull) {
		if (onlyIfNull && this._authentication) return;
		this._authentication = auth;
		this._asyncResultsWaitingForAuthentication = [];
		this._lastAuthenticationTime = 0;
		this._lastAuthenticationException = null;
	};

	this._internalAuthenticate = function(asyncResult, processAsync) {

		if (this._authentication) {

			var assumeAuthenticationIsValid = this._lastAuthenticationTime + this._RETRY_AUTHENTICATION_AFTER_MILLIS >= ((new Date()).getTime());

			if (assumeAuthenticationIsValid) {
				asyncResult(true, this._lastAuthenticationException);
			}
			else {
				var first = this._asyncResultsWaitingForAuthentication.length == 0;
				this._asyncResultsWaitingForAuthentication.push(asyncResult);

				if (first) {

					var me = this;
					var authResult = function(result, ex) {
						var arr = me._asyncResultsWaitingForAuthentication;
						me._asyncResultsWaitingForAuthentication = [];
						me._lastAuthenticationTime = (new Date()).getTime();
						me._lastAuthenticationException = ex;

						for ( var i = 0; i < arr.length; i++) {
							var result_i = arr[i];
							result_i(result, ex);
						}
					};

					var result = null;
					var exception = null;

					try {
						result = this._authentication.authenticate(null, processAsync ? authResult : null);
					}
					catch (ex) {
						exception = ex;
					}

					if (!processAsync) {
						authResult(result, exception);
					}
				}
			}
		}
		else {
			asyncResult(true, null);
		}
	};

	this._internalIsReloginException = function(ex, typeId) {
		var ret = false;
		if (ex && this._authentication) {
			if (this._authentication.isReloginException) {
				ret = this._authentication.isReloginException(null, ex, typeId);
			}
			else {
				ret = this.isReloginException(ex, typeId);
			}
		}
		return ret;
	};

	this._reloginAndRetrySend = function(methodRequest, asyncResult, processAsync) {

		var transport = this;

		var authResult = function(result, ex) {
			if (ex) {
				asyncResult(result, ex);
			}
			else {
				// Send request again
				var messageResult = null;
				try {
					messageResult = transport._assignSessionThenSendMethod(methodRequest, processAsync ? asyncResult : null);
				}
				catch (ex2) {
					ex = ex2;
				}
				if (!processAsync) {
					asyncResult(messageResult, ex);
				}
			}
		};

		this.negotiateProtocolClient(authResult, processAsync);
	};

	this.isReloginException = function(ex, typeId) {
		var ret = false;
		if (ex && ex.code) {
			ret = ex.code == byps.BExceptionC.UNAUTHORIZED;
			if (!ret) {
				ret = ex.code == byps.BExceptionC.IOERROR && ("" + ex).indexOf("403") >= 0;
			}
		}
		return ret;
	};
};

// ------------------------------------------------------------------------------------------------

byps.BInputOutput = function(transport, header, jsonText) {

	this.transport = transport;
	this.registry = transport.apiDesc.registry;
	this.header = header || new byps.BMessageHeader(transport.wire.makeMessageId());
	this.header.targetId = transport.targetId;

	this.store = function(root) {
		this._root = root;
		return this.toMessage();
	};

	this.setException = function(ex) {
		this.header.error = ex.code || byps.BExceptionC.REMOTE_ERROR;
		this.store(ex);
	};

	this.load = function() {
		var msg = JSON.parse(this._jsonText);
		this.header = msg.header;
		this._objectTable = msg.objectTable;
		this._internalLoad();
		this._root = this._objectTable[1];
		if (this.header.error) {
			byps.throwExceptionFromStream(this._root);
		}
		return this._root;
	};

	this.toMessage = function() {

		// Replace object elements with references.
		this._internalStore();

		var msgObj = {};
		msgObj.header = this.header;
		msgObj.objectTable = this._objectTable;

		var jsonText = JSON.stringify(msgObj);
		var msg = new byps.BMessage(jsonText, null);

		// BSerializer.write removes transient objects.
		// Restore them ...
		this._restoreTransients();

		// Replace references with objects.
		this._internalLoad();

		return msg;
	};

	// this._isArray = function(obj) {
	// var ret = false;
	// try {
	// ret = Array.isArray(obj);
	// } catch (ignored) {
	// ret = Object.prototype.toString.call(obj) === '[object Array]';
	// }
	// return ret;
	// };

	this.writeElement = function(obj, ename, ser) {
		var elm = obj[ename];
		
		// Inline instance: write object instead of reference to object.
		if (ser && ser.inlineInstance) {
			ser.write(elm, this);
		}
		else if (elm && typeof elm === 'object') {

			var id = elm["*i"];
			if (!id) {

				// Element was not jet serialized.

				// Assign an ID
				id = this._objectTable.length;
				elm["*i"] = id;

				// Put element into the object table
				this._objectTable.push(elm);

				// Replace element with reference
				obj[ename] = {
					"*i" : -id
				};

				// A serializer is passed, if a set or list class is to be
				// serialized,
				// because the JSON representation of this classes is an array
				// without type information.
				// For all other classes, the serializer is determined by the
				// object's type ID.
				if (!ser) {
					ser = this.registry.getSerializer(elm._typeId);
					if (!ser) byps.throwCORRUPT("No serializer for typeId=" + elm._typeId);
				}

				var write = ser.write || this.registry._defaultSerializer.write;
				write(elm, this);
			}
			else if (id > 0) {
				// Element has already been serialized,
				// replace element with reference to object table.
				obj[ename] = {
					"*i" : -id
				};
			}
			else { // id < 0
				// Element is already a reference.
			}
		}
	};

	this._internalStore = function() {
		this._objectTable.push(null);
		this.writeElement(this, "_root");
		this._removeIds();
	};

	this.readElement = function(obj, ename, ser) {
		var elm = obj[ename];
		if (!elm) return;
		if (typeof elm == 'function') return;
		
		// If elm is an Object or if a serializer was 
		// explicitly passed, route the object through
		// its serializer.
		// For Date objects, typeof(elm) is not 'object'
		// but a ser is BSerializer_17
		
		// Inline instance: read object instead of reference to object.
		if (ser && ser.inlineInstance) {
			var nelm = ser.read(elm, this);
			
			// Date objects: elm is a String an the serializer converts
			// it into a Date object. Replace the String in the 
			// parent object by the new Date object.
			if (nelm != elm) {
				obj[ename] = nelm;
			}
		}
		else if (typeof elm === 'object') {

			// Ein Objekt-Element muss eine Referenz sein.
			// Andernfalls würden wir einen Serialisierer das zweite mal
			// durchlaufen.
			var id = elm["*i"];
			if (!id || id >= 0) {
				var msg = "Excpecting reference with \"*i\" < 0 but found " + id;
				byps.throwCORRUPT(msg);
			}

			id = -id;

			// Objekt zum Element aus der objectTable holen
			elm = this._objectTable[id];

			// Wenn es noch keine ID hat, dann wurde es noch nicht
			// deserialisiert.
			// (Objekt is null für ersten Longpoll.)
			if (elm && !elm["*i"]) {

				// Gib dem Objekt eine ID, damit ich weiß, dass ich es
				// deserialisiert habe.
				elm["*i"] = id;

				if (!ser) {
					ser = this.registry.getSerializer(elm._typeId);
					if (!ser) byps.throwCORRUPT("No serializer for typeId=" + elm._typeId);
				}

				var read = ser.read || this.registry._defaultSerializer.read;
				var nelm = read(elm, this);

				// Mglw wurde das Objekt in read ausgetauscht (Stub).
				if (elm !== nelm) {
					elm = nelm;
					elm["*i"] = id;
					this._objectTable[id] = elm;
				}
			}

			obj[ename] = elm;
		}
		;
	};

	this._internalLoad = function() {
		this["_root"] = {
			"*i" : -1
		};
		this.readElement(this, "_root");
		this._removeIds();
	};

	this._restoreTransients = function() {
		for ( var i = 0; i < this._restoreInfos.length; i++) {
			var restoreInfo = this._restoreInfos[i];
			var obj = restoreInfo[0];
			var elm = restoreInfo[1];
			var ename = restoreInfo[2];
			obj[ename] = elm;
		}
	};

	this.saveTransient = function(obj, ename) {
		var elm = obj[ename];
		if (elm) {
			obj[ename] = undefined;
			this._restoreInfos.push([ obj, elm, ename ]);
		}
	};

	this._removeIds = function() {
		for ( var i = 1; i < this._objectTable.length; i++) {
			var obj = this._objectTable[i];
			if (obj) { // obj is null for first longpoll.
				delete obj["*i"];
			}
		}
	};

	this._objectTable = [];
	this._streams = [];
	this._root = null;
	this._jsonText = jsonText || "";
	this._restoreInfos = [];
};

// ------------------------------------------------------------------------------------------------

byps.BClient = function() {

	// Implemented by subclass:
	// this.transport;
	// this._serverR;

	this.start = function(asyncResult) { // BAsyncResult<BClient>

		var processAsync = !!asyncResult;
		if (!processAsync) {
			asyncResult = function(result, ex) {
				if (ex) throw ex;
			};
		}

		this.setAuthentication(null);

		this.transport.negotiateProtocolClient(asyncResult, processAsync);
	};

	this.done = function() {
		this.transport.wire.cancelAllRequests();
	};

	this.addRemote = function(remoteImpl) {
		var remoteId = remoteImpl._typeId;
		if (!remoteId) {
			byps.throwBException(byps.BExceptionC.INTERNAL, "Missing interface type ID. The interface implementation must be inherited from a BSkeleton_ class.");
		}
		if (!this._serverR) {
			byps.throwBException(byps.BExceptionC.NO_REVERSE_CONNECTIONS, "No reverse connections.");
		}
		this._serverR.server.addRemote(remoteId, remoteImpl);
	};

	this.getAuthentication = function() {
		var auth = this.transport._authentication;
		if (auth) {
			auth = auth._innerAuth;
		}
		return auth;
	};

	this.setAuthentication = function(innerAuth) {
		var me = this;

		var authentication = {

		  _innerAuth : innerAuth,

		  authenticate : function(ignored, asyncResult) {

			  var processAsync = !!asyncResult;

			  var outerResult = function(result, ex) {

				  if (!ex) {
					  if (me._serverR) {
						  try {
							  me._serverR.start();
						  }
						  catch (ex2) {
							  ex = ex2;
						  }
					  }
				  }

				  if (processAsync) {
					  asyncResult(result, ex);
				  }
				  else if (ex) { throw ex; }
			  };

			  var result = true;
			  var exception = null;

			  if (innerAuth) {

				  try {
					  result = innerAuth.authenticate(me, processAsync ? outerResult : null);
				  }
				  catch (ex) {
					  exception = ex;
				  }

				  if (!processAsync) {
					  outerResult(result, exception);
				  }
			  }
			  else {
				  outerResult(result, null);
			  }

			  return result;
		  },

		  isReloginException : function(ignored, ex, typeId) {
			  var ret = false;
			  if (innerAuth != null) {
				  ret = innerAuth.isReloginException(me, ex, typeId);
			  }
			  else {
				  ret = me.transport.isReloginException(ex);
			  }
			  return ret;
		  },

		  getSession : function(ignored, typeId, asyncResult) {
			  var ret = null;
			  if (innerAuth && innerAuth.getSession) {
				  ret = innerAuth.getSession(this, typeId, asyncResult);
			  }
			  else if (asyncResult) {
				  asyncResult(null, null);
			  }
			  return ret;
		  }

		};

		this.transport.setAuthentication(authentication, innerAuth == null);
	};
};

byps.BClient_subclass = function(transport, serverR) {
	this.transport = transport;
	this._serverR = serverR;
};

byps.BClient_subclass.prototype = new byps.BClient();

// ------------------------------------------------------------------------------------------------

byps.BTransportFactory = function(apiDesc, wire, nbOfServerRConns) {

	this._nbOfServerRConns = nbOfServerRConns;
	this._transport = new byps.BTransport(apiDesc, wire, null);

	this.createClientTransport = function() {
		return this._transport;
	};
	this.createServerTransport = function() {
		return this._transport;
	};
	this.createClientR = function(client) {
		return null;
	};
	this.createServerR = function(server) {
		if (!this._nbOfServerRConns) return null;
		return new byps.BServerR(this._transport, server);
	};

};

// ------------------------------------------------------------------------------------------------

byps.BServer = function() {

	// Subclass must implement:
	// this.transport = transport;
	// this._remotes = {};
	// this._methodMap = {}; // request_typeId : [remote_typeId, result_typeId,
	// methodFunction]

	this.addRemote = function(remoteId, remoteImpl) {
		this._remotes[remoteId] = remoteImpl;
		remoteImpl.transport = this.transport;
	};

	this.recv = function(clientTargetId, methodObj, methodResultObj) {

		try {
			var requestTypeId = methodObj._typeId;
			var methodItem = this._methodMap[requestTypeId];
			if (!methodItem) {
				byps.throwUNSUPPORTED("Method not implemented: typeId=" + requestTypeId);
			}

			var remoteId = methodItem[0];
			var remote = this._remotes[remoteId];
			if (!remote) {
				byps.throwBException(byps.BExceptionC.SERVICE_NOT_IMPLEMENTED, "Service not implemented: remoteId=" + remoteId);
			}

			var resultTypeId = methodItem[1];

			var methodFnct = methodItem[2];

			var methodResult = function(obj, exception) {
				if (exception) {
					methodResultObj(null, exception);
				}
				else {
					var resultObj = {
					  _typeId : resultTypeId,
					  result : obj
					};
					methodResultObj(resultObj, null);
				}
			};

			methodFnct(remote, methodObj, methodResult);
		}
		catch (ex) {
			methodResultObj(null, ex);
		}

	};
};

// ------------------------------------------------------------------------------------------------

byps.BServerR = function(transport, server) {

	var me = this;
	this.transport = transport;
	this.server = server;
	this._isDone = false;

	this.start = function() {
		var methodResult = this._makeInitMessage();
		this._run(methodResult);
	};

	this._run = function(methodResult) {

		if (this._isDone) return;

		var asyncResult = function(message, exception) {
			if (exception) {
				var bout = me.transport.getOutput();
				bout.header.flags = byps.BMessageHeader.FLAG_RESPONSE;
				bout.setException(exception);
				message = bout.toMessage();
			}
			else if (!message) {
				message = me._makeInitMessage();
			}
			me._run(message);
		};

		var nextAsyncMethod = function(message, ex) {
			try {
				if (!ex) {

					me.transport.recv(me.server, message, asyncResult);

				}
				else {

					switch (ex.code) {

					case byps.BExceptionC.SESSION_CLOSED: // Session was invalidated.
					case byps.BExceptionC.UNAUTHORIZED: // Re-login required
					case byps.BExceptionC.CANCELLED:
						// no retry
						break;

					case byps.BExceptionC.RESEND_LONG_POLL:
						// HWireClientR has released the expried long-poll.
						// Ignore the error and send a new long-poll.
						asyncResult(null, null);
						break;

					default: // e.g. Socket error
						if (!me._isDone) {
							// Retry after 30s
							window.setTimeout(function() {
								asyncResult(null, null);
							}, 30 * 1000);
						}
					}

				}

			}
			catch (ex2) {
				asyncResult(null, ex2);
			}
		};

		transport.wire.sendR(methodResult, nextAsyncMethod);
	};

	this._makeInitMessage = function() {
		var outp = this.transport.getOutput();
		outp.header.flags |= byps.BMessageHeaderC.FLAG_RESPONSE;
		outp.store(null);
		return outp.toMessage();
	};

};
