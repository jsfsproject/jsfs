package com.wilutions.jsfs;

import java.util.Arrays;

import javax.swing.SwingUtilities;
import javax.swing.UIManager;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import byps.BAsyncResult;
import byps.BLostConnectionHandler;
import byps.BMessage;
import byps.http.HTransportFactoryClient;
import byps.http.HWireClient;

/**
 * Main application class. Connects to the JSFS Dispatcher. Shows an icon in the
 * system tray.
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
  private static String jsfsDispatcherUrl = "http://localhost:8080/jsfs-dispatcher/jsfs";

  /**
   * URL to the token service of your web application.
   */
  private static String yourWebappUrl = "http://localhost:8080/yourapp/";
  private static String tokenServiceUrl = yourWebappUrl + "auth?jsfstoken=true";

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
  private static JsfsTrayIcon trayIcon = new JsfsTrayIcon() {
    public void showError(Throwable ex) { }
    public void showInfo(String msg) { }
    public void touch() { }
  };

  /**
   * Repeatedly check the connection to the JSFS Dispatcher. If the JSFS
   * Dispatcher is not used for some minutes, it discards the token and the
   * connection to the browser. A thread calls each
   * CHECK_CONNECTION_AFTER_MILLIS the keepAlive() function of the JSFS
   * Dispatcher to signal that the token is still in use. This value must be
   * shorter than the session lifetime in the JSFS Dispatcher and shorter than
   * the token lifetime in Your Web Application (see
   * JsfsToken.TOKEN_LIFETIME_MILLIS).
   */
  private final static long CHECK_CONNECTION_AFTER_MILLIS = (300 * 1000);

  private final static Log log = LogFactory.getLog(Main.class);

  public static void main(String[] args) {

    log.info("main args=" + Arrays.toString(args));
    
    // Get configuration from program arguments 
    if (args.length > 0) tokenServiceUrl = args[0];
    if (args.length > 1) jsfsDispatcherUrl = args[1];
    if (args.length > 2) userName = args[2]; // Should only be used for testing
    if (args.length > 3) userPwd = args[3]; // Should only be used for testing

    // Initialize Swing
    try {
      UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
      // UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
    } catch (Exception ex) {
      log.error(ex);
    }
    UIManager.put("swing.boldMetal", Boolean.FALSE);

    // Schedule a job for the event-dispatching thread:
    // adding TrayIcon and connecting to JSFS Dispatcher
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
        if (log.isInfoEnabled()) log.info("show tray icon");
        trayIcon = JsfsTrayIconImpl.createAndShowGUI();
        
        if (log.isInfoEnabled()) log.info("connect to JSFS Dispatcher");
        connectToJsfsDispatcherShowStatus();
      }
    });
  }

  /**
   * Connect to the JSFS Dispatcher and show status. The tray icon shows an
   * information or an error depending on a successful connection.
   */
  private static void connectToJsfsDispatcherShowStatus() {
    if (log.isDebugEnabled()) log.debug("connectToJsfsDispatcherShowStatus(");
    
    connectToJSFS(new BAsyncResult<BClient_JSFS>() {
      public void setAsyncResult(BClient_JSFS client, final Throwable e) {

        if (log.isDebugEnabled()) log.debug("connectToJSFS returns client=" + client + ", e=" + e);

        if (e != null) {
          trayIcon.showError(e);
        }
        else {
          trayIcon.showInfo("Connected to server.");
        }
      }
    });
    if (log.isDebugEnabled()) log.debug(")connectToJsfsDispatcherShowStatus");
  }

  /**
   * Asynchronously connect to the JFSF Dispatcher.
   * 
   * @param asyncResult
   *          Callback interface that receives the result.
   */
  private static void connectToJSFS(final BAsyncResult<BClient_JSFS> asyncResult) {
    if (log.isDebugEnabled()) log.debug("connectToJSFS(");

    // Initialize BYPS:
    // - provide a BWire object
    // - provide a BTransportFactory
    // - create a BClient object
    // - supply a BAuthentication object
    // - start the BClient object

    HWireClient wire = new HWireClient(jsfsDispatcherUrl, 0, 60, null) {
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
    if (log.isDebugEnabled()) log.debug("wire=" + wire);

    HTransportFactoryClient transportFactory = new HTransportFactoryClient(BApiDescriptor_JSFS.instance(), wire, 1);
    if (log.isDebugEnabled()) log.debug("transportFactory=" + transportFactory);

    final BClient_JSFS bclient = BClient_JSFS.createClient(transportFactory);
    if (log.isDebugEnabled()) log.debug("client=" + bclient);

    bclient.setAuthentication(new JsfsAuthentication(yourWebappUrl, tokenServiceUrl, userName, userPwd));

    bclient.setLostReverseConnectionHandler(new BLostConnectionHandler() {

      // This handler is called, if the connection to the server was lost.
      // It retries to connect after RECONNECT_AFTER_MILLIS.

      @Override
      public void onLostConnection(Throwable ex) {
        if (log.isDebugEnabled()) log.debug("lost connection", ex);
        reconnectToJSFS(bclient);
      }
    });

    if (log.isDebugEnabled()) log.debug("bclient.start...");

    bclient.start(new BAsyncResult<Boolean>() {

      public void setAsyncResult(Boolean succ, Throwable ex) {

        if (log.isDebugEnabled()) log.debug("bclient.start ex=" + ex);

        if (ex != null) {
          log.info("JSFS Agent failed to start", ex);
          reconnectToJSFS(bclient);
        }
        else {
          log.info("JSFS Agent started");
          // Start a thread to keep the token alive
          keepAlive(bclient);
        }

        asyncResult.setAsyncResult(bclient, ex);
      }

    });

    if (log.isDebugEnabled()) log.debug(")connectToJSFS");
  }

  /**
   * Connect to the JSFS Dispatcher after RECONNECT_AFTER_MILLIS. This function
   * is called if the connection to the JSFS Dispatcher is lost.
   */
  private static void reconnectToJSFS(final BClient_JSFS bclient) {
    if (log.isDebugEnabled()) log.debug("reconnectToJSFS(bclient=" + bclient);

    trayIcon.showInfo("Lost connection, retry after " + (RECONNECT_AFTER_MILLIS / 1000) + "s");

    if (log.isDebugEnabled()) log.debug("bclient.done");
    bclient.done();

    if (log.isDebugEnabled()) log.debug("start reconnect thread");
    Thread thread = new Thread() {
      public void run() {
        try {
          if (log.isDebugEnabled()) log.debug("sleep before reconnect, ms=" + RECONNECT_AFTER_MILLIS);
          Thread.sleep(RECONNECT_AFTER_MILLIS);
          connectToJsfsDispatcherShowStatus();
        } catch (InterruptedException e) {
          if (log.isDebugEnabled()) log.debug("reconnect interrupted");
        }
      }
    };
    thread.setName("reconnect");
    thread.setDaemon(true);
    thread.start();

    if (log.isDebugEnabled()) log.debug(")reconnectToJSFS");
  }

  /**
   * This function starts a thread that repeatedly calls keepAlive().
   * 
   * @param bclient
   *          Client object
   */
  private static void keepAlive(final BClient_JSFS bclient) {
    if (log.isDebugEnabled()) log.debug("keepAlive(" + bclient);

    Thread thread = new Thread() {

      public void run() {
        try {
          while (!isInterrupted()) {

            if (log.isDebugEnabled()) log.debug("wait before keep alive, ms=" + CHECK_CONNECTION_AFTER_MILLIS);
            Thread.sleep(CHECK_CONNECTION_AFTER_MILLIS);
            if (log.isDebugEnabled()) log.debug("send keep alive requests");

            JsfsAuthentication auth = (JsfsAuthentication) bclient.getAuthentication();
            final String oldToken = auth.getToken();
            if (log.isDebugEnabled()) log.debug("auth=" + auth + ", oldToken=" + oldToken);

            // Send a request to Your Web Application in order to keep the
            // application server session alive.
            // As long as JSFS Agent is running, the token should not change.
            // Otherwise the browser looses the connection to the agent.

            final Thread keepAliveThread = Thread.currentThread();
            if (log.isDebugEnabled()) log.debug("keepAliveThread=" + keepAliveThread);

            auth.keepAlive(new BAsyncResult<String>() {

              public void setAsyncResult(String newToken, Throwable e) {
                if (log.isDebugEnabled()) log.debug("KeepAlive.setAsyncResult(newToken=" + newToken + ", e=" + e);

                try {
                  if (e != null) throw e;

                  // Token has changed?
                  if (!oldToken.equals(newToken)) throw new IllegalStateException("Need to reconnect, oldToken=" + oldToken + ", newToken=" + newToken);

                  // Keep session in JSFS Dispatcher alive
                  if (log.isDebugEnabled()) log.debug("dispatcherService.keepAlive()");
                  bclient.dispatcherService.keepAlive(newToken);
                } catch (Throwable ex) {
                  if (log.isDebugEnabled()) log.debug("interrupt keepAliveThread" + keepAliveThread, ex);
                  keepAliveThread.interrupt();

                  if (log.isDebugEnabled()) log.debug("reconnectToJSFS");
                  reconnectToJSFS(bclient);
                }

                if (log.isDebugEnabled()) log.debug(")KeepAlive.setAsyncResult");
              }

            });

          } // while

          if (log.isDebugEnabled()) log.debug("keepAliveThread=" + Thread.currentThread() + " interrupted - 1");

        } catch (InterruptedException ignored) {
          if (log.isDebugEnabled()) log.debug("keepAliveThread=" + Thread.currentThread() + " interrupted - 2");
        }
      }
    };

    thread.setName("keep-alive");
    thread.setDaemon(true);
    thread.start();

    if (log.isDebugEnabled()) log.debug(")keepAlive");
  }
}
