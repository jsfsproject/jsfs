using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using byps;

namespace com.wilutions.jsfs
{
	
	/// <summary>
	/// This class defines the interface of the JSFS Dispatcher.
	/// </summary>
	/// <remarks>
	/// The functions in this interface have to be called with a token obtained from an
	/// authentication process with the token service of "Your Web Application".
	/// </remarks>
	// checkpoint byps.gen.cs.GenRemoteClass:93
	public interface DispatcherService : BRemote {
	
		/// <summary>
		/// Register a file system service.
		/// </summary>
		/// <remarks>
		/// This function is called from the JSFS Agent when it starts.
		/// The JSFS Dispatcher maps the given token on the given service. The browser
		/// requests this service by a call to {@link #getService(String, boolean)}.
		/// </remarks>
		void RegisterService(String token, FileSystemService service);
		void RegisterService(String token, FileSystemService service, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Register a file system service.
		/// </summary>
		/// <remarks>
		/// This function is called from the JSFS Agent when it starts.
		/// The JSFS Dispatcher maps the given token on the given service. The browser
		/// requests this service by a call to {@link #getService(String, boolean)}.
		/// </remarks>
		Task RegisterServiceAsync(String token, FileSystemService service);
		
		/// <summary>
		/// Unregister a file system service.
		/// </summary>
		/// <remarks>
		/// This function is called from the JSFS Agent if it terminates.
		/// </remarks>
		void UnregisterService(String token);
		void UnregisterService(String token, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Unregister a file system service.
		/// </summary>
		/// <remarks>
		/// This function is called from the JSFS Agent if it terminates.
		/// </remarks>
		Task UnregisterServiceAsync(String token);
		
		/// <summary>
		/// Get the file system service for the given token.
		/// </summary>
		FileSystemService GetService(String token, bool onlyHere);
		void GetService(String token, bool onlyHere, BAsyncResult<FileSystemService> asyncResult) ;
		/// <summary>
		/// Get the file system service for the given token.
		/// </summary>
		Task<FileSystemService> GetServiceAsync(String token, bool onlyHere);
		
		/// <summary>
		/// Register a notify service.
		/// </summary>
		/// <remarks>
		/// The notify service is implemented by JavaScript inside the web page. The JSFS Agent requests
		/// the notify service in order to send messages to the browser.
		/// </remarks>
		void RegisterNotifyService(String token, FileSystemNotify service);
		void RegisterNotifyService(String token, FileSystemNotify service, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Register a notify service.
		/// </summary>
		/// <remarks>
		/// The notify service is implemented by JavaScript inside the web page. The JSFS Agent requests
		/// the notify service in order to send messages to the browser.
		/// </remarks>
		Task RegisterNotifyServiceAsync(String token, FileSystemNotify service);
		
		/// <summary>
		/// Unregister a notify service.
		/// </summary>
		/// <remarks>
		/// This function should be called by the browser when the web page is unloaded.
		/// </remarks>
		void UnregisterNotifyService(String token);
		void UnregisterNotifyService(String token, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Unregister a notify service.
		/// </summary>
		/// <remarks>
		/// This function should be called by the browser when the web page is unloaded.
		/// </remarks>
		Task UnregisterNotifyServiceAsync(String token);
		
		/// <summary>
		/// Get the notify service interface for a given token.
		/// </summary>
		FileSystemNotify GetNotifyService(String token, bool onlyHere);
		void GetNotifyService(String token, bool onlyHere, BAsyncResult<FileSystemNotify> asyncResult) ;
		/// <summary>
		/// Get the notify service interface for a given token.
		/// </summary>
		Task<FileSystemNotify> GetNotifyServiceAsync(String token, bool onlyHere);
		
		/// <summary>
		/// Keep the token-to-services-associations alive.
		/// </summary>
		/// <remarks>
		/// Keeps the application server session alive. If the session has already been invalidated,
		/// the BYPS framework triggers a re-login. This will cause an authentication with "Your Web Application"
		/// and the services will be registered again.
		/// </remarks>
		void KeepAlive(String token);
		void KeepAlive(String token, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Keep the token-to-services-associations alive.
		/// </summary>
		/// <remarks>
		/// Keeps the application server session alive. If the session has already been invalidated,
		/// the BYPS framework triggers a re-login. This will cause an authentication with "Your Web Application"
		/// and the services will be registered again.
		/// </remarks>
		Task KeepAliveAsync(String token);
		
		
	}
}  // end namespace
