package com.wilutions.jsfs;

import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

import byps.BAsyncResult;
import byps.BLostConnectionHandler;
import byps.BMessage;
import byps.http.HTransportFactoryClient;
import byps.http.HWireClient;

/**
 * Main application class. 
 * Connects to the JSFS Dispatcher. 
 * Shows an icon in the system tray. 
 */
public class Main {
  
  /**
   * Re-connect after this pause time if the server is not available.
   * 
   */
  private final static long RECONNECT_AFTER_MILLIS = 30 * 1000;
  
  /**
   * JSFS Dispatcher URL
   */
  private static String jsfsDispatcherUrl = "http://localhost:5080/jsfs-dispatcher/jsfs";
    
  /**
   * URL to the token service of your web application.
   */
  private static String tokenServiceUrl = "http://localhost:5080/yourapp/fstokens";
  
  /**
   * User name to login to the token service.
   */
  private static String userName = "user";
  
  /**
   * Password for userName.
   */
  private static String userPwd = "pwd";
  
  /**
   * The system tray icon.
   */
  private static JsfsTrayIcon trayIcon; 
  
  /**
   * Repeatedly check the connection to the JSFS Dispatcher.
   * If the JSFS Dispatcher is not used for some minutes, it discards the token
   * and the connection to the browser. A thread calls each 
   * CHECK_CONNECTION_AFTER_MILLIS the keepAlive() function of the JSFS Dispatcher
   * to signal that the token is still in use.
   */
  private final static long CHECK_CONNECTION_AFTER_MILLIS = (300 * 1000);
  
  public static void main(String[] args) {

    // Initialize Swing
    try {
      UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
      // UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
    } catch (UnsupportedLookAndFeelException ex) {
      ex.printStackTrace();
    } catch (IllegalAccessException ex) {
      ex.printStackTrace();
    } catch (InstantiationException ex) {
      ex.printStackTrace();
    } catch (ClassNotFoundException ex) {
      ex.printStackTrace();
    }
    UIManager.put("swing.boldMetal", Boolean.FALSE);
    
    // Schedule a job for the event-dispatching thread:
    // adding TrayIcon and connecting to JSFS Dispatcher
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
        trayIcon = JsfsTrayIcon.createAndShowGUI();
        connectToJsfsDispatcherShowStatus();
      }
    });
  }
  
  /**
   * Connect to the JSFS Dispatcher and show status.
   * The tray icon shows an information or an error depending on a successful connection.
   */
  private static void connectToJsfsDispatcherShowStatus() {
    connectToJSFS(new BAsyncResult<BClient_JSFS>() {
      public void setAsyncResult(BClient_JSFS client, final Throwable e) {
        SwingUtilities.invokeLater(new Runnable() {
          public void run() {
            if (e != null) {
              trayIcon.showError(e);
            }
            else {
              trayIcon.showInfo("Connected to server.");
            }
          }
        });
      }
    });   
  }

  /**
   * Asynchronously connect to the JFSF Dispatcher.
   * @param asyncResult Callback interface that receives the result.
   */
  private static void connectToJSFS(final BAsyncResult<BClient_JSFS> asyncResult) {

    // Initialize BYPS: 
    // - provide a BWire object
    // - provide a BTransportFactory
    // - create a BClient object
    // - supply a BAuthentication object
    // - start the BClient object
 
    HWireClient wire = new HWireClient(jsfsDispatcherUrl, 0, 60, null, null) {
      @Override
      public synchronized void send(BMessage msg, BAsyncResult<BMessage> asyncResult) {
        trayIcon.touch();
        super.send(msg, asyncResult);
      }
      @Override
      public void sendR(BMessage msg, final BAsyncResult<BMessage> asyncResult) {
        BAsyncResult<BMessage> outerResult = new BAsyncResult<BMessage>() {
          public void setAsyncResult(BMessage result, Throwable ex) {
            trayIcon.touch();
            asyncResult.setAsyncResult(result, ex);
          }
        };
        super.sendR(msg, outerResult);
      }
    };
    
    HTransportFactoryClient transportFactory = new HTransportFactoryClient(BApiDescriptor_JSFS.instance(), wire, 1);

    final BClient_JSFS bclient = BClient_JSFS.createClient(transportFactory);

    bclient.setAuthentication(new JsfsAuthentication(tokenServiceUrl, userName, userPwd));
    
    bclient.setLostReverseConnectionHandler(new BLostConnectionHandler() {
      
      // This handler is called, if the connection to the server was lost.
      // It retries to connect after RECONNECT_AFTER_MILLIS.
      
      @Override
      public void onLostConnection(Throwable ex) {
         
        SwingUtilities.invokeLater(new Runnable() {
          public void run() {
            trayIcon.showInfo("Lost connection, retry after ms=" + RECONNECT_AFTER_MILLIS);
          }
        });
        
        bclient.done();
        reconnectToJSFS();
      }
    });

    bclient.start(new BAsyncResult<Boolean>() {

      public void setAsyncResult(Boolean succ, Throwable ex) {

        if (ex!= null) {
          reconnectToJSFS();
        }
        asyncResult.setAsyncResult(bclient, ex);
      }
      
    });
    
    // Start a thread to keep the token alive
    keepAlive(bclient);
  }
  
  
  /**
   * Connect to the JSFS Dispatcher after RECONNECT_AFTER_MILLIS.
   * This function is called if the connection to the JSFS Dispatcher is lost.
   */
  private static void reconnectToJSFS() {
    Thread thread = new Thread() {
      public void run() {
        try {
          Thread.sleep(RECONNECT_AFTER_MILLIS);
          connectToJsfsDispatcherShowStatus();
        }
        catch (InterruptedException ignored) {}
      }
    };
    thread.start();
  }
  
  
  /**
   * This function starts a thread that repeatedly calls keepAlive().
   * @param bclient Client object
   */
  private static void keepAlive(final BClient_JSFS bclient) {
    Thread thread = new Thread() {
      public void run() {
        try {
          Thread.sleep(CHECK_CONNECTION_AFTER_MILLIS);
          JsfsAuthentication auth = (JsfsAuthentication)bclient.getAuthentication();
          bclient.dispatcherService.keepAlive(auth.getToken());
        }
        catch (Throwable e) {
          e.printStackTrace();
        }
      }
    };
    thread.setDaemon(true);
    thread.start();
  }
}
