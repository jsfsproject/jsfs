/**
 * ----------------------------------------------
 * Declare packages.
 * ----------------------------------------------
*/
var com = com || {};
com.wilutions = com.wilutions || {};
com.wilutions.jsfs = com.wilutions.jsfs || {};

/**
 * ----------------------------------------------
 * API Descriptor
 * ----------------------------------------------
*/
com.wilutions.jsfs.BApiDescriptor_JSFS = {
	/**
	 * API serialisation version: 1.0.0.0
	 */
	VERSION : "1.0.0.0",
	
	/**
	 * Internal used API Desciptor.
	*/
	instance : function() {
		return new byps.BApiDescriptor(
			"JSFS",
			"com.wilutions.jsfs",
			"1.0.0.0",
			false, // uniqueObjects
			new com.wilutions.jsfs.BRegistry_JSFS()
		);
	}
};


/**
 * ----------------------------------------------
 * Client class
 * ----------------------------------------------
*/

com.wilutions.jsfs.createClient_JSFS = function(transportFactory) {
	return new com.wilutions.jsfs.BClient_JSFS(transportFactory);
};

com.wilutions.jsfs.BClient_JSFS = function(transportFactory) { 

	this.transport = transportFactory.createClientTransport();
	
	this._serverR = transportFactory.createServerR(
		new com.wilutions.jsfs.BServer_JSFS(transportFactory.createServerTransport())
	);
	
	this.dispatcherService = new com.wilutions.jsfs.BStub_DispatcherService(this.transport);
	this.fileSystemNotify = new com.wilutions.jsfs.BStub_FileSystemNotify(this.transport);
	this.fileSystemService = new com.wilutions.jsfs.BStub_FileSystemService(this.transport);
};
com.wilutions.jsfs.BClient_JSFS.prototype = new byps.BClient();


/**
 * ----------------------------------------------
 * API value classes
 * ----------------------------------------------
*/

/**
 * This class contains notification information generated from
 * {@link FileSystemService#executeNotifyExit(String[], ExecuteOptions)}.
*/
com.wilutions.jsfs.ExecuteNotifyInfo = function(id, extraInfo, error, exitCode, standardOutput, standardError) {
	this._typeId = 665368294;
	this.id = id || 0;
	this.extraInfo = extraInfo || "";
	this.error = error || "";
	this.exitCode = exitCode || 0;
	this.standardOutput = standardOutput || "";
	this.standardError = standardError || "";
};


/**
 * This class contains additional parameters for
 * {@link FileSystemService#executeNotifyExit(String[], ExecuteOptions)}.
*/
com.wilutions.jsfs.ExecuteOptions = function(extraInfo, standardInput, captureOutput, captureError) {
	this._typeId = 1032737639;
	this.extraInfo = extraInfo || "";
	this.standardInput = standardInput || "";
	this.captureOutput = captureOutput || false;
	this.captureError = captureError || false;
};


/**
 * This class contains information about a file or directory.
*/
com.wilutions.jsfs.FileInfo = function(name, size, sizeL, directory, readonly, lastModified) {
	this._typeId = 1100528120;
	this.name = name || "";
	this.size = size || 0;
	this.sizeL = sizeL || '0.';
	this.directory = directory || false;
	this.readonly = readonly || false;
	this.lastModified = lastModified || null;
};


/**
 * Unused.
*/
com.wilutions.jsfs.FindOptions = function(reserved) {
	this._typeId = 1092766252;
	this.reserved = reserved || "";
};


/**
 * This class defines an item of a file upload request in {@link FileSystemService#uploadFiles}.
 * A FormData object corresponds to an input field in a HTML file upload form.
 * It can specify files to be uploaded as with HTML input field type "file".
 * Or it can hold a simple value as with HTML input field type "text".
*/
com.wilutions.jsfs.FormItem = function(name, type, values) {
	this._typeId = 979378962;
	this.name = name || "";
	this.type = type || "";
	this.values = values || null;
};


/**
 * Base class for notifications.
*/
com.wilutions.jsfs.NotifyInfo = function(id, extraInfo, error) {
	this._typeId = 1274131736;
	this.id = id || 0;
	this.extraInfo = extraInfo || "";
	this.error = error || "";
};


/**
 * Notification information about a change in a watched folder.
*/
com.wilutions.jsfs.WatchFolderNotifyInfo = function(id, extraInfo, error, fileInfo, kind) {
	this._typeId = 9906860;
	this.id = id || 0;
	this.extraInfo = extraInfo || "";
	this.error = error || "";
	this.fileInfo = fileInfo || null;
	this.kind = kind || null;
};



/**
 * ----------------------------------------------
 * API constant types
 * ----------------------------------------------
*/

com.wilutions.jsfs.EWatchFolderNotifyKind = {
	/**
	 * Nothing changed.
	*/
	Nothing : 0,
	/**
	 * New file or directory has been created.
	*/
	EntryCreated : 1,
	/**
	 * File or directory attributes have been modified.
	*/
	EntryModified : 2,
	/**
	 * File or directory has been deleted.
	*/
	EntryDeleted : 3
};


/**
 * ----------------------------------------------
 * API constants
 * ----------------------------------------------
*/


/**
 * ----------------------------------------------
 * Skeleton classes
 * ----------------------------------------------
*/

/**
 * This class provides a skeleton implementation of the interface FileSystemNotify.
 * Use an object of this class as the prototype of your interface implementation.
 * Either provide an asynchronous or a synchronous function in your implementation.
 * The framework calls only the asynchronous function.
 */
com.wilutions.jsfs.BSkeleton_FileSystemNotify = function() {
	
	this._typeId = 544795964;
	
	this.transport = null; // is set in BServer.addRemote
	
	this.toJSON = function (key) {
		return { _typeId : 544795964, targetId : this.transport.targetId };
	};
	
	
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Notify the browser about an event.
 * @param notifyInfo NotifyInfo or ExecuteNotifyInfo object.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemNotify.prototype.notify = function(notifyInfo) /* returns void , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * Notify the browser about an event.
 * @param notifyInfo NotifyInfo or ExecuteNotifyInfo object.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemNotify.prototype.async_notify = function(notifyInfo, __byps__asyncResult){
	try {
		this.notify(notifyInfo);
		__byps__asyncResult(null, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};

/**
 * This class provides a skeleton implementation of the interface FileSystemService.
 * Use an object of this class as the prototype of your interface implementation.
 * Either provide an asynchronous or a synchronous function in your implementation.
 * The framework calls only the asynchronous function.
 */
com.wilutions.jsfs.BSkeleton_FileSystemService = function() {
	
	this._typeId = 145996442;
	
	this.transport = null; // is set in BServer.addRemote
	
	this.toJSON = function (key) {
		return { _typeId : 145996442, targetId : this.transport.targetId };
	};
	
	
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * List files in a directory.
 * @param path Directory of path with wildcards * or ?
 * @param findOptions unused
 * @return List of files.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.findFiles = function(path, findOptions) /* returns java.util.List<com.wilutions.jsfs.FileInfo> , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * List files in a directory.
 * @param path Directory of path with wildcards * or ?
 * @param findOptions unused
 * @return List of files.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.async_findFiles = function(path, findOptions, __byps__asyncResult){
	try {
		var __byps__ret = this.findFiles(path, findOptions);
		__byps__asyncResult(__byps__ret, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Read text file.
 * Read all text content from the given file.
 * @param path File path.
 * @return Text content
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.readAllText = function(path) /* returns java.lang.String , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * Read text file.
 * Read all text content from the given file.
 * @param path File path.
 * @return Text content
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.async_readAllText = function(path, __byps__asyncResult){
	try {
		var __byps__ret = this.readAllText(path);
		__byps__asyncResult(__byps__ret, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Write text file.
 * Write the supplied text into the file. An existing file will be overwritten.
 * @param path File path.
 * @param text Text content
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.writeAllText = function(path, text) /* returns void , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * Write text file.
 * Write the supplied text into the file. An existing file will be overwritten.
 * @param path File path.
 * @param text Text content
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.async_writeAllText = function(path, text, __byps__asyncResult){
	try {
		this.writeAllText(path, text);
		__byps__asyncResult(null, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Execute a program.
 * If opts is null, the process is started synchronously. Otherwise it is started in background and
 * the JSFS Agent will notify the caller via the {@link FileSystemNotify#notify(NotifyInfo)} function
 * when the process has terminated.
 * The first element in args[] is assumed to be the application name to be started. If only
 * {@link ExecuteOptions#extraInfo} is set in opts, the first element in args can also be a
 * file name. In this case the file is opened via ShellExecute with verb "open".
 * @param args Arguments
 * @param opts Options
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.executeNotifyExit = function(args, opts) /* returns void , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * Execute a program.
 * If opts is null, the process is started synchronously. Otherwise it is started in background and
 * the JSFS Agent will notify the caller via the {@link FileSystemNotify#notify(NotifyInfo)} function
 * when the process has terminated.
 * The first element in args[] is assumed to be the application name to be started. If only
 * {@link ExecuteOptions#extraInfo} is set in opts, the first element in args can also be a
 * file name. In this case the file is opened via ShellExecute with verb "open".
 * @param args Arguments
 * @param opts Options
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.async_executeNotifyExit = function(args, opts, __byps__asyncResult){
	try {
		this.executeNotifyExit(args, opts);
		__byps__asyncResult(null, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Begin watching a folder.
 * Watch a folder and optional all sub-folders for changes.
 * If a change occurs, the JSFS Agent invokes the {@link FileSystemNotify#notify(NotifyInfo)} function and
 * passes a {@link WatchFolderNotifyInfo} object.
 * @param dir Folder to be watched.
 * @param recursive True, if sub-folders should also be watched.
 * @param extraInfo Application defined value passed to the {@link NotifyInfo#extraInfo} element.
 * @return Watch handle. Use this handle in {@link #endWatchFolder(int)} to stop watching the folder.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.beginWatchFolder = function(dir, recursive, extraInfo) /* returns int , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * Begin watching a folder.
 * Watch a folder and optional all sub-folders for changes.
 * If a change occurs, the JSFS Agent invokes the {@link FileSystemNotify#notify(NotifyInfo)} function and
 * passes a {@link WatchFolderNotifyInfo} object.
 * @param dir Folder to be watched.
 * @param recursive True, if sub-folders should also be watched.
 * @param extraInfo Application defined value passed to the {@link NotifyInfo#extraInfo} element.
 * @return Watch handle. Use this handle in {@link #endWatchFolder(int)} to stop watching the folder.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.async_beginWatchFolder = function(dir, recursive, extraInfo, __byps__asyncResult){
	try {
		var __byps__ret = this.beginWatchFolder(dir, recursive, extraInfo);
		__byps__asyncResult(__byps__ret, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Stop watching a folder.
 * Call this function to stop watching a folder and to release resources in the JSFS Agent.
 * @param handle Watch handle returned from {@link #beginWatchFolder(String, boolean, String)}.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.endWatchFolder = function(handle) /* returns void , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * Stop watching a folder.
 * Call this function to stop watching a folder and to release resources in the JSFS Agent.
 * @param handle Watch handle returned from {@link #beginWatchFolder(String, boolean, String)}.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.async_endWatchFolder = function(handle, __byps__asyncResult){
	try {
		this.endWatchFolder(handle);
		__byps__asyncResult(null, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Read file contents.
 * Returns an input stream for reading the contents of the given file.
 * @param path File path
 * @return InputStream object
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.readFile = function(path) /* returns java.io.InputStream , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * Read file contents.
 * Returns an input stream for reading the contents of the given file.
 * @param path File path
 * @return InputStream object
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.async_readFile = function(path, __byps__asyncResult){
	try {
		var __byps__ret = this.readFile(path);
		__byps__asyncResult(__byps__ret, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Upload files to server(s).
 * @param items Form data items, file paths or name/value pairs.
 * @param url Target URL. Authentication information should be included, e.g. the JSFS authentication token.
 * @param method HTTP method, can be POST or PUT. If this parameter is null or empty, method POST is used.
 * @param encoding Request encoding, can be multipart/form-data or null or empty. If this parameter is null or empty, the
 * @param request body does merely contain the file bytes.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.uploadFiles = function(items, url, method, encoding) /* returns void , throws BException, InterruptedException*/  {
	byps.throwUNSUPPORTED("");
};
// checkpoint byps.gen.js.PrintContext:133
/**
 * Upload files to server(s).
 * @param items Form data items, file paths or name/value pairs.
 * @param url Target URL. Authentication information should be included, e.g. the JSFS authentication token.
 * @param method HTTP method, can be POST or PUT. If this parameter is null or empty, method POST is used.
 * @param encoding Request encoding, can be multipart/form-data or null or empty. If this parameter is null or empty, the
 * @param request body does merely contain the file bytes.
 * @throws RemoteException
*/
com.wilutions.jsfs.BSkeleton_FileSystemService.prototype.async_uploadFiles = function(items, url, method, encoding, __byps__asyncResult){
	try {
		this.uploadFiles(items, url, method, encoding);
		__byps__asyncResult(null, null);
	} catch (e) {
		__byps__asyncResult(null, e);
	};
};


/**
 * ----------------------------------------------
 * Stub classes
 * ----------------------------------------------
*/

/**
 * This class defines the interface of the JSFS Dispatcher.
 * The functions in this interface have to be called with a token obtained from an
 * authentication process with the token service of "Your Web Application".
*/
com.wilutions.jsfs.BStub_DispatcherService = function(transport) {
	
	this._typeId = 1153231042;
	
	this.transport = transport;
	
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Register a file system service.
 * This function is called from the JSFS Agent when it starts.
 * The JSFS Dispatcher maps the given token on the given service. The browser
 * requests this service by a call to {@link #getService(String, boolean)}.
 * @param token Token obtained from authentication.
 * @param service Service object.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_DispatcherService.prototype.registerService = function(token, service, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1833696176, token : token, service : service };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Unregister a file system service.
 * This function is called from the JSFS Agent if it terminates.
 * @param token Token obtained from authentication.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_DispatcherService.prototype.unregisterService = function(token, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1542825705, token : token };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Get the file system service for the given token.
 * @param token Token obtained from authentication.
 * @param onlyHere false, if other JSFS Dispatcher services should be asked for the file system service too.
 * @return File system service.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_DispatcherService.prototype.getService = function(token, onlyHere, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 575037953, token : token, onlyHere : onlyHere };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Register a notify service.
 * The notify service is implemented by JavaScript inside the web page. The JSFS Agent requests
 * the notify service in order to send messages to the browser.
 * @param token Token obtained from authentication.
 * @param service Notify service.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_DispatcherService.prototype.registerNotifyService = function(token, service, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1849102471, token : token, service : service };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Unregister a notify service.
 * This function should be called by the browser when the web page is unloaded.
 * @param token Token obtained from authentication.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_DispatcherService.prototype.unregisterNotifyService = function(token, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1366717454, token : token };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Get the notify service interface for a given token.
 * @param token Token obtained from authentication.
 * @param onlyHere false, if other JSFS Dispatcher services should be asked for the notify service too.
 * @return Notify service.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_DispatcherService.prototype.getNotifyService = function(token, onlyHere, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1090607752, token : token, onlyHere : onlyHere };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Keep the token-to-services-associations alive.
 * Keeps the application server session alive. If the session has already been invalidated,
 * the BYPS framework triggers a re-login. This will cause an authentication with "Your Web Application"
 * and the services will be registered again.
 * @param token Token obtained from authentication.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_DispatcherService.prototype.keepAlive = function(token, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1609273478, token : token };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

/**
 * Notification interface.
 * This interface is used by the JFSF Agent to notify the browser about an event.
 * @BClientRemote 
 * @BClientRemote 
*/
com.wilutions.jsfs.BStub_FileSystemNotify = function(transport) {
	
	this._typeId = 544795964;
	
	this.transport = transport;
	
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Notify the browser about an event.
 * @param notifyInfo NotifyInfo or ExecuteNotifyInfo object.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemNotify.prototype.notify = function(notifyInfo, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 481066845, notifyInfo : notifyInfo };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

/**
 * This is the service interface of the JSFS Agent.
 * @BClientRemote 
 * @BClientRemote 
*/
com.wilutions.jsfs.BStub_FileSystemService = function(transport) {
	
	this._typeId = 145996442;
	
	this.transport = transport;
	
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * List files in a directory.
 * @param path Directory of path with wildcards * or ?
 * @param findOptions unused
 * @return List of files.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemService.prototype.findFiles = function(path, findOptions, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1131301080, path : path, findOptions : findOptions };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Read text file.
 * Read all text content from the given file.
 * @param path File path.
 * @return Text content
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemService.prototype.readAllText = function(path, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1078989294, path : path };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Write text file.
 * Write the supplied text into the file. An existing file will be overwritten.
 * @param path File path.
 * @param text Text content
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemService.prototype.writeAllText = function(path, text, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1925305675, path : path, text : text };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Execute a program.
 * If opts is null, the process is started synchronously. Otherwise it is started in background and
 * the JSFS Agent will notify the caller via the {@link FileSystemNotify#notify(NotifyInfo)} function
 * when the process has terminated.
 * The first element in args[] is assumed to be the application name to be started. If only
 * {@link ExecuteOptions#extraInfo} is set in opts, the first element in args can also be a
 * file name. In this case the file is opened via ShellExecute with verb "open".
 * @param args Arguments
 * @param opts Options
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemService.prototype.executeNotifyExit = function(args, opts, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1824869366, args : args, opts : opts };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Begin watching a folder.
 * Watch a folder and optional all sub-folders for changes.
 * If a change occurs, the JSFS Agent invokes the {@link FileSystemNotify#notify(NotifyInfo)} function and
 * passes a {@link WatchFolderNotifyInfo} object.
 * @param dir Folder to be watched.
 * @param recursive True, if sub-folders should also be watched.
 * @param extraInfo Application defined value passed to the {@link NotifyInfo#extraInfo} element.
 * @return Watch handle. Use this handle in {@link #endWatchFolder(int)} to stop watching the folder.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemService.prototype.beginWatchFolder = function(dir, recursive, extraInfo, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1762179110, dir : dir, recursive : recursive, extraInfo : extraInfo };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Stop watching a folder.
 * Call this function to stop watching a folder and to release resources in the JSFS Agent.
 * @param handle Watch handle returned from {@link #beginWatchFolder(String, boolean, String)}.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemService.prototype.endWatchFolder = function(handle, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1124739608, handle : handle };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Read file contents.
 * Returns an input stream for reading the contents of the given file.
 * @param path File path
 * @return InputStream object
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemService.prototype.readFile = function(path, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 706034600, path : path };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};

// checkpoint byps.gen.js.PrintContext:133
/**
 * Upload files to server(s).
 * @param items Form data items, file paths or name/value pairs.
 * @param url Target URL. Authentication information should be included, e.g. the JSFS authentication token.
 * @param method HTTP method, can be POST or PUT. If this parameter is null or empty, method POST is used.
 * @param encoding Request encoding, can be multipart/form-data or null or empty. If this parameter is null or empty, the
 * @param request body does merely contain the file bytes.
 * @throws RemoteException
*/
com.wilutions.jsfs.BStub_FileSystemService.prototype.uploadFiles = function(items, url, method, encoding, __byps__asyncResult) {
	// checkpoint byps.gen.js.GenRemoteStub:40
	var req =  { _typeId : 1614176016, items : items, url : url, method : method, encoding : encoding };
	var ret = this.transport.sendMethod(req, __byps__asyncResult);
	return ret;
};


/**
 * ----------------------------------------------
 * Server class
 * ----------------------------------------------
*/

com.wilutions.jsfs.BServer_JSFS = function(transport) { 

	this.transport = transport;
	this._remotes = {};
	
	this._methodMap = {
		
		// Remote Interface DispatcherService			
			// Method registerService
			1833696176 : [ // _typeId of request class
				1153231042, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_registerService(methodObj.token, methodObj.service, methodResult);
				}
			],
			
			// Method unregisterService
			1542825705 : [ // _typeId of request class
				1153231042, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_unregisterService(methodObj.token, methodResult);
				}
			],
			
			// Method getService
			575037953 : [ // _typeId of request class
				1153231042, // _typeId of remote interface
				1815527676, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_getService(methodObj.token, methodObj.onlyHere, methodResult);
				}
			],
			
			// Method registerNotifyService
			1849102471 : [ // _typeId of request class
				1153231042, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_registerNotifyService(methodObj.token, methodObj.service, methodResult);
				}
			],
			
			// Method unregisterNotifyService
			1366717454 : [ // _typeId of request class
				1153231042, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_unregisterNotifyService(methodObj.token, methodResult);
				}
			],
			
			// Method getNotifyService
			1090607752 : [ // _typeId of request class
				1153231042, // _typeId of remote interface
				1354059712, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_getNotifyService(methodObj.token, methodObj.onlyHere, methodResult);
				}
			],
			
			// Method keepAlive
			1609273478 : [ // _typeId of request class
				1153231042, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_keepAlive(methodObj.token, methodResult);
				}
			],
		
		
		// Remote Interface FileSystemNotify			
			// Method notify
			481066845 : [ // _typeId of request class
				544795964, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_notify(methodObj.notifyInfo, methodResult);
				}
			],
		
		
		// Remote Interface FileSystemService			
			// Method findFiles
			1131301080 : [ // _typeId of request class
				145996442, // _typeId of remote interface
				1733426638, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_findFiles(methodObj.path, methodObj.findOptions, methodResult);
				}
			],
			
			// Method readAllText
			1078989294 : [ // _typeId of request class
				145996442, // _typeId of remote interface
				964561600, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_readAllText(methodObj.path, methodResult);
				}
			],
			
			// Method writeAllText
			1925305675 : [ // _typeId of request class
				145996442, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_writeAllText(methodObj.path, methodObj.text, methodResult);
				}
			],
			
			// Method executeNotifyExit
			1824869366 : [ // _typeId of request class
				145996442, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_executeNotifyExit(methodObj.args, methodObj.opts, methodResult);
				}
			],
			
			// Method beginWatchFolder
			1762179110 : [ // _typeId of request class
				145996442, // _typeId of remote interface
				169662220, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_beginWatchFolder(methodObj.dir, methodObj.recursive, methodObj.extraInfo, methodResult);
				}
			],
			
			// Method endWatchFolder
			1124739608 : [ // _typeId of request class
				145996442, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_endWatchFolder(methodObj.handle, methodResult);
				}
			],
			
			// Method readFile
			706034600 : [ // _typeId of request class
				145996442, // _typeId of remote interface
				964561595, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_readFile(methodObj.path, methodResult);
				}
			],
			
			// Method uploadFiles
			1614176016 : [ // _typeId of request class
				145996442, // _typeId of remote interface
				964561591, // _typeId of result class
				function(remote, methodObj, methodResult) {
					remote.async_uploadFiles(methodObj.items, methodObj.url, methodObj.method, methodObj.encoding, methodResult);
				}
			],
		
	};
};
com.wilutions.jsfs.BServer_JSFS.prototype = new byps.BServer();


/**
 * ----------------------------------------------
 * Registry
 * ----------------------------------------------
*/

com.wilutions.jsfs.BRegistry_JSFS = function() { 
	
	this._serializerMap = {
		
		// com.wilutions.jsfs.BRequest_DispatcherService_getNotifyService
		1090607752 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"token":10, // java.lang.String
				// names of persistent elements
				"onlyHere":1 // boolean
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_DispatcherService_getService
		575037953 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"token":10, // java.lang.String
				// names of persistent elements
				"onlyHere":1 // boolean
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_DispatcherService_keepAlive
		1609273478 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"token":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_DispatcherService_registerNotifyService
		1849102471 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"token":10, // java.lang.String
				// names of persistent elements
				"service":544795964 // com.wilutions.jsfs.FileSystemNotify
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_DispatcherService_registerService
		1833696176 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"token":10, // java.lang.String
				// names of persistent elements
				"service":145996442 // com.wilutions.jsfs.FileSystemService
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_DispatcherService_unregisterNotifyService
		1366717454 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"token":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_DispatcherService_unregisterService
		1542825705 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"token":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemNotify_notify
		481066845 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"notifyInfo":1274131736 // com.wilutions.jsfs.NotifyInfo
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemService_beginWatchFolder
		1762179110 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"dir":10, // java.lang.String
				// names of persistent elements
				"recursive":1, // boolean
				// names of persistent elements
				"extraInfo":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemService_endWatchFolder
		1124739608 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"handle":5 // int
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemService_executeNotifyExit
		1824869366 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"args":1888107655, // java.lang.String[]
				// names of persistent elements
				"opts":1032737639 // com.wilutions.jsfs.ExecuteOptions
			},
			// checkpoint byps.gen.js.GenRegistry:138
			// names of inline elements
			{
				"args":1888107655, // java.lang.String[]
			},
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemService_findFiles
		1131301080 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"path":10, // java.lang.String
				// names of persistent elements
				"findOptions":1092766252 // com.wilutions.jsfs.FindOptions
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemService_readAllText
		1078989294 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"path":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemService_readFile
		706034600 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"path":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemService_uploadFiles
		1614176016 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"items":566696346, // com.wilutions.jsfs.FormItem[]
				// names of persistent elements
				"url":10, // java.lang.String
				// names of persistent elements
				"method":10, // java.lang.String
				// names of persistent elements
				"encoding":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			// names of inline elements
			{
				"items":566696346, // com.wilutions.jsfs.FormItem[]
			},
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BRequest_FileSystemService_writeAllText
		1925305675 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"path":10, // java.lang.String
				// names of persistent elements
				"text":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BResult_10
		964561600 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"result":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BResult_1439246415
		1733426638 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"result":1439246415 // java.util.List<com.wilutions.jsfs.FileInfo>
			},
			// checkpoint byps.gen.js.GenRegistry:138
			// names of inline elements
			{
				"result":1439246415 // java.util.List<com.wilutions.jsfs.FileInfo>
			},
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BResult_15
		964561595 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"result":15 // java.io.InputStream
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BResult_1816639285
		1354059712 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"result":544795964 // com.wilutions.jsfs.FileSystemNotify
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BResult_19
		964561591 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"result":19 // void
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BResult_336045129
		1815527676 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"result":145996442 // com.wilutions.jsfs.FileSystemService
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BResult_5
		169662220 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"result":5 // int
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.BStub_DispatcherService
		1153231042 : new byps.BSerializerRemote(com.wilutions.jsfs.BStub_DispatcherService),
		
		// com.wilutions.jsfs.BStub_FileSystemNotify
		544795964 : new byps.BSerializerRemote(com.wilutions.jsfs.BStub_FileSystemNotify),
		
		// com.wilutions.jsfs.BStub_FileSystemService
		145996442 : new byps.BSerializerRemote(com.wilutions.jsfs.BStub_FileSystemService),
		
		// com.wilutions.jsfs.ExecuteNotifyInfo
		665368294 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"exitCode":5, // int
				// names of persistent elements
				"standardOutput":10, // java.lang.String
				// names of persistent elements
				"standardError":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.ExecuteOptions
		1032737639 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"extraInfo":10, // java.lang.String
				// names of persistent elements
				"standardInput":10, // java.lang.String
				// names of persistent elements
				"captureOutput":1, // boolean
				// names of persistent elements
				"captureError":1 // boolean
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.FileInfo
		1100528120 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"name":10, // java.lang.String
				// names of persistent elements
				"size":5, // int
				// names of persistent elements
				"sizeL":6, // long
				// names of persistent elements
				"directory":1, // boolean
				// names of persistent elements
				"readonly":1, // boolean
				// names of persistent elements
				"lastModified":17 // java.util.Date
			},
			// checkpoint byps.gen.js.GenRegistry:138
			// names of inline elements
			{
				"lastModified":17 // java.util.Date
			},
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.FindOptions
		1092766252 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"reserved":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.FormItem
		979378962 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"name":10, // java.lang.String
				// names of persistent elements
				"type":10, // java.lang.String
				// names of persistent elements
				"values":1888107655 // java.lang.String[]
			},
			// checkpoint byps.gen.js.GenRegistry:138
			// names of inline elements
			{
				"values":1888107655 // java.lang.String[]
			},
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.FormItem[]
		566696346 : new byps.BSerializerArray(
			979378962, // Element type: com.wilutions.jsfs.FormItem
			1
		),
		
		// com.wilutions.jsfs.NotifyInfo
		1274131736 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"id":5, // int
				// names of persistent elements
				"extraInfo":10, // java.lang.String
				// names of persistent elements
				"error":10 // java.lang.String
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// com.wilutions.jsfs.WatchFolderNotifyInfo
		9906860 : new byps.BSerializer(
			// checkpoint byps.gen.js.GenRegistry:138
			// names of persistent elements
			{
				"fileInfo":1100528120, // com.wilutions.jsfs.FileInfo
				// names of persistent elements
				"kind":508262806 // com.wilutions.jsfs.EWatchFolderNotifyKind
			},
			// checkpoint byps.gen.js.GenRegistry:138
			null,
			// inlineInstance
			false
		),
		
		// String[]
		1888107655 : new byps.BSerializerArray(
			10, // Element type: String
			1
		),
		
		// java.util.List<com.wilutions.jsfs.FileInfo>
		1439246415 : new byps.BSerializerArray(
			1100528120, // Element type: com.wilutions.jsfs.FileInfo
			1
		),
	};
};
com.wilutions.jsfs.BRegistry_JSFS.prototype = new byps.BRegistry();
