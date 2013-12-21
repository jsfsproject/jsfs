/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import java.util.Collection;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.CountDownLatch;

import byps.BAsyncResult;
import byps.BClient;
import byps.BException;
import byps.BExceptionC;
import byps.RemoteException;


/**
 * Implementation of the JSFS Dispatcher.
 * This class stores for all subscribers the mapping between access tokens and service interfaces
 * in static hash maps. Each browser and each JSFS Agent has its own JSFS Dispatcher object which is  
 * linked to the application server session, respectively the BYPS session object.
 */
public class JsfsDispatcher extends BSkeleton_DispatcherService {
  
  /**
   * Maps token to FileSystemService object.
   * The JSFS Agent registers its FileSystemService with the JFSF Dispatcher.
   */
  private static ConcurrentHashMap<String, FileSystemService> map = new ConcurrentHashMap<String, FileSystemService>();
  
  /**
   * Maps token to FileSystemNotify object.
   * The browser registers its FileSystemNotify service with the JSFS Dispatcher.
   */
  private static ConcurrentHashMap<String, FileSystemNotify> mapNotify = new ConcurrentHashMap<String, FileSystemNotify>();
  
  /**
   * The token that has been passed to {@link #registerService(String, FileSystemService)} 
   * or {@link #registerNotifyService(String, FileSystemNotify)}.
   * This token is stored here in order to remove the mapping when the application
   * server session is invalidated.
   */
  private String myToken;
  
  /**
   * Back-reference to the BYPS session object.
   */
  private MySession mySession;
  
  public JsfsDispatcher(MySession sess) {
    this.mySession = sess;
  }

  @Override
  public void registerService(String token, FileSystemService service) throws RemoteException {
    myToken = token;
    map.put(token, service);
  }

  @Override
  public void unregisterService(String token) throws RemoteException {
    map.remove(token);
  }

  @Override
  public void getService(String token, boolean onlyHere, final BAsyncResult<FileSystemService> asyncResult) {
    
    FileSystemService ret = map.get(token);
    final BException exIfNotFound = new BException(BExceptionC.CLIENT_DIED, "JSFS Agent is not connected.");
    
    try {
      if (ret != null) {
        asyncResult.setAsyncResult(ret, null);
      }
      else if (onlyHere) {
        throw exIfNotFound;
      }
      else {
        
        // This block is reached, if the token cannot be found in the map and the 
        // request should be forwarded to other web applications that implement a
        // JSFS Dispatcher service.
        // The context.xml file in the Servers/Tomcatv7.0... folder describes
        // how to use multiple JSFS Dispatcher services.
        
        final Collection<BClient> clients = mySession.getForwardClientsToOtherServers();
        
        BAsyncResult<FileSystemService> outerResult = new BAsyncResult<FileSystemService>() {
          boolean finished;
          CountDownLatch cdl = new CountDownLatch(clients.size());
          public void setAsyncResult(FileSystemService fso, Throwable e) {
            if (finished) return;
            cdl.countDown();
            finished = fso != null;
            if (finished) {
              asyncResult.setAsyncResult(fso, e);
            }
            else if (cdl.getCount() == 0) {
              asyncResult.setAsyncResult(null, exIfNotFound);
            }
         }
        };
        
        if (clients.size() != 0) {
          for (BClient client : clients) {
            BClient_JSFS myclient = (BClient_JSFS)client;
            myclient.dispatcherService.getService(token, true, outerResult);
          }
        }
        else {
          throw exIfNotFound;
        }
      }       
    }
    catch (Throwable e) {
      asyncResult.setAsyncResult(null, e);
    }

  }

  @Override
  public void registerNotifyService(String token, FileSystemNotify service) throws RemoteException {
    myToken = token;
    mapNotify.put(token, service);
  }

  @Override
  public void unregisterNotifyService(String token) throws RemoteException {
    mapNotify.remove(token);
  }

  @Override
  public void getNotifyService(String token, boolean onlyHere, final BAsyncResult<FileSystemNotify> asyncResult) {
    FileSystemNotify ret = mapNotify.get(token);
    final BException exIfNotFound = new BException(BExceptionC.CLIENT_DIED, "JSFS browser module is not connected.");
    
    try {
      if (ret != null) {
        asyncResult.setAsyncResult(ret, null);
      }
      else if (onlyHere) {
        throw exIfNotFound;
      }
      else {
        
        final Collection<BClient> clients = mySession.getForwardClientsToOtherServers();
        
        BAsyncResult<FileSystemNotify> outerResult = new BAsyncResult<FileSystemNotify>() {
          boolean finished;
          CountDownLatch cdl = new CountDownLatch(clients.size());
          public void setAsyncResult(FileSystemNotify fso, Throwable e) {
            if (finished) return;
            cdl.countDown();
            finished = fso != null;
            if (finished) {
              asyncResult.setAsyncResult(fso, e);
            }
            else if (cdl.getCount() == 0) {
              asyncResult.setAsyncResult(null, exIfNotFound);
            }
         }
        };
        
        if (clients.size() != 0) {
          for (BClient client : clients) {
            BClient_JSFS myclient = (BClient_JSFS)client;
            myclient.dispatcherService.getNotifyService(token, true, outerResult);
          }
        }
        else {
          throw exIfNotFound;
        }
      }       
    }
    catch (Throwable e) {
      asyncResult.setAsyncResult(null, e);
    }
  }
  
  /**
   * Removes the mapping to the sessions token.
   * This function is called from class MySession if the 
   * application server session is invalidated.
   */
  public void removeMyTokenBecauseSessionWasInvalidated() {
    if (myToken != null) {
      mapNotify.remove(myToken);
      map.remove(myToken);
    }
  }

  @Override
  public void keepAlive(String token) throws RemoteException {
    
  }
  
  
}
