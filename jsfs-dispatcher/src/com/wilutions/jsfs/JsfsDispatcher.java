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
 * Each JSFS Agent and each browser has its own JsfsDispacher object as they have their own BYPS session.
 * This concept allows to store the token inside the JsfsDispatcher object 
 * which in turn allows to remove the mappings to the token if the session is invalidated.
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
   * or {@link #registerNotifyService(String, FileSystemNotify)}
   */
  private String myToken;
  
  /**
   * Back-reference to the session object.
   */
  private MySession mySession;
  
  public JsfsDispatcher(MySession sess) {
    this.mySession = sess;
  }

  @Override
  public void registerService(String token, FileSystemService service) throws RemoteException {
    myToken = token;
    mySession.setSessionAuthenticated();
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
    mySession.setSessionAuthenticated();
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
  
  
  public void removeMyTokenOfInvalidatedSession() {
    if (myToken != null) {
      mapNotify.remove(myToken);
      map.remove(myToken);
    }
  }

  /**
   * Keep session alive.
   * The application server session has already been touched so that the 
   * idle interval starts again. 
   * That is all what has to be done to keep the token-to-services associations valid.
   */
  @Override
  public void keepAlive(String token) throws RemoteException {
    
  }
  
  
}
