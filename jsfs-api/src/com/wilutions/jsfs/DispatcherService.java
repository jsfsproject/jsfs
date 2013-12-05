/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import byps.BRemote;
import byps.RemoteException;


/**
 * This class defines the interface of the JSFS Dispatcher.
 * The functions in this interface have to be called with a token obtained from an 
 * authentication process with the token service of "Your Web Application".
 */
public interface DispatcherService extends BRemote {
  
  /**
   * Register a file system service.
   * This function is called from the JSFS Agent when it starts. 
   * The JSFS Dispatcher maps the given token on the given service. The browser
   * requests this service by a call to {@link #getService(String, boolean)}.
   * @param token Token obtained from authentication.
   * @param service Service object.
   * @throws RemoteException
   */
  public void registerService(String token, FileSystemService service) throws RemoteException;
  
  /**
   * Unregister a file system service.
   * This function is called from the JSFS Agent if it terminates.
   * @param token Token obtained from authentication.
   * @throws RemoteException
   */
  public void unregisterService(String token) throws RemoteException;
  
  /**
   * Get the file system service for the given token.
   * @param token Token obtained from authentication.
   * @param onlyHere false, if other JSFS Dispatcher services should be asked for the file system service too.
   * @return File system service.
   * @throws RemoteException
   */
  public FileSystemService getService(String token, boolean onlyHere) throws RemoteException;
  
  /**
   * Register a notify service.
   * The notify service is implemented by JavaScript inside the web page. The JSFS Agent requests
   * the notify service in order to send messages to the browser.
   * @param token Token obtained from authentication. 
   * @param service Notify service.
   * @throws RemoteException
   */
  public void registerNotifyService(String token, FileSystemNotify service) throws RemoteException;
  
  /**
   * Unregister a notify service.
   * This function should be called by the browser when the web page is unloaded.
   * @param token Token obtained from authentication.
   * @throws RemoteException
   */
  public void unregisterNotifyService(String token) throws RemoteException;
  
  /**
   * Get the notify service interface for a given token.
   * @param token Token obtained from authentication.
   * @param onlyHere false, if other JSFS Dispatcher services should be asked for the notify service too.
   * @return Notify service.
   * @throws RemoteException
   */
  public FileSystemNotify getNotifyService(String token, boolean onlyHere) throws RemoteException;
 
  /**
   * Keep the token-to-services-associations alive.
   * Keeps the application server session alive. If the session has already been invalidated,
   * the BYPS framework triggers a re-login. This will cause an authentication with "Your Web Application"
   * and the services will be registered again.
   * @param token Token obtained from authentication.
   * @throws RemoteException
   */
  public void keepAlive(String token) throws RemoteException;
  
}
