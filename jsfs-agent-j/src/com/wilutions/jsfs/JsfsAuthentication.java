package com.wilutions.jsfs;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.net.Authenticator;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.PasswordAuthentication;
import java.net.URL;
import java.util.concurrent.atomic.AtomicInteger;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import byps.BAsyncResult;
import byps.BAuthentication;
import byps.BClient;

/**
 * This class performs the authentication to the JSFS Dispatcher. 
 *
 */
public class JsfsAuthentication implements BAuthentication {
  
  private String yourWebappUrl, tokenServiceUrl, userName, userPwd;
  private volatile String token;
  
  private Log log = LogFactory.getLog(JsfsAuthentication.class);

  /**
   * Constructor
   * @param tokenServiceUrl URL to the token service of "Your Web Application"
   * @param userName User name
   * @param userPwd Password
   */
  public JsfsAuthentication(String yourWebappUrl, String tokenServiceUrl, String userName, String userPwd) {
    super();
    this.yourWebappUrl = yourWebappUrl;
    this.tokenServiceUrl = tokenServiceUrl;
    this.userName = userName;
    this.userPwd = userPwd;
  }
  
  /**
   * Return the token received from the token service.
   * @return Token
   */
  public String getToken() {
    return token;
  }

  /**
   * Send a GET request to the URL of the token service.
   * @param asyncResult Callback object
   */
  private void internalAuthenticateRetry(BAsyncResult<String> asyncResult) {
    if (log.isDebugEnabled()) log.debug("internalAuthenticate(");
    
    Throwable ex = null;
    String token = null;
    int retryCount = 0;
    
    while (true) {
      
      try {
        
        token = internalAuthenticate2();
        ex = null;
        break;
        
      } catch (Exception e) {
        
        if (log.isDebugEnabled()) log.debug("internalAuthenticate failed", e);
        ex = e;

        if (++retryCount == 3) break;
        if (e.toString().indexOf("403") < 0) break; 
        
        // Assume name/password wrong
        String[] args = new String[2];
        if (DlgCredentials.showDialog(args)) {
          userName = args[0];
          userPwd = args[1];
        }
        else {
          System.exit(-1);
        }
      }
    }
    
    asyncResult.setAsyncResult(token, ex);
    
    if (log.isDebugEnabled()) log.debug(")internalAuthenticate");
  }

  private String internalAuthenticate2() throws IOException, MalformedURLException {
    
    final AtomicInteger retryLogin = new AtomicInteger();
    
    // Create an Authenticator object that is used to send the credentials
    // during BASIC authentication.
    Authenticator.setDefault( new Authenticator() {
      @Override 
      protected PasswordAuthentication getPasswordAuthentication() {
        if (log.isDebugEnabled()) log.debug("getPasswordAuthentication(), userName=" + userName);
        
        // If authentication fails, Tomcat returns 401 with BASIC authentication
        // and the JVM retries to login.
        // This causes an endless loop that is broken by the exception
        // "java.net.ProtocolException: Server redirected too many times". 
        // Tomcat should return 403 if authentication was unsuccessful.
        
        // Try to authenticate only once 
        if (retryLogin.incrementAndGet() > 1) {
          throw new IllegalStateException("HTTP 403");
        }
        
        return new PasswordAuthentication( userName, userPwd.toCharArray() );
      }
    });

    if (log.isDebugEnabled()) log.debug("GET appUrl=" + tokenServiceUrl);
    HttpURLConnection conn = null;
    LineNumberReader rd = null;
    try {
      conn = (HttpURLConnection) new URL(tokenServiceUrl).openConnection();
      rd = new LineNumberReader(new InputStreamReader(conn.getInputStream()));
      String token = rd.readLine();
      if (log.isDebugEnabled()) log.debug("token=" + token);
      if (token == null) {
        throw new IOException("No token returned from " + tokenServiceUrl);
      }
      return token;
    }
    catch (Exception e) {
      InputStream es = conn.getErrorStream();
      if (es != null) {
        while (es.read() != -1) {}
      }
      throw e;
    }
    finally {
      if (rd != null) {
        try { rd.close(); } catch (Throwable e) {}
      }
      if (conn != null) {
        conn.disconnect();
      }
    }
  }
  
  @Override
  public void authenticate(BClient bclient1, final BAsyncResult<Boolean> asyncResult) {
    if (log.isDebugEnabled()) log.debug("authenticate(bclient1=" + bclient1);
    
    final BClient_JSFS bclient = (BClient_JSFS)bclient1;
    
    BAsyncResult<String> outerResult = new BAsyncResult<String>() {
      
      public void setAsyncResult(String token, Throwable ex) {
        if (log.isDebugEnabled()) log.debug("setAsyncResult(token=" + token + ", ex=" + ex);
        
        if (ex != null) {
          asyncResult.setAsyncResult(Boolean.FALSE, ex);
        }
        else {
          JsfsAuthentication.this.token = token;
       
          try {
            // Required by BYPS: add the implementation of a service that is
            // called via reverse HTTP to the client object.
            final FileSystemImpl fssrv = new FileSystemImpl(bclient, yourWebappUrl);
            bclient.addRemote(fssrv);
            if (log.isDebugEnabled()) log.debug("fssrv=" + fssrv);
 
            // Publish the service to the JSFS Dispatcher.
            bclient.dispatcherService.registerService(token, fssrv, new BAsyncResult<Object>() {
              public void setAsyncResult(Object ignored, Throwable ex) {
                if (log.isDebugEnabled()) log.debug("registerService asyncResult: ex=" + ex);
                asyncResult.setAsyncResult(Boolean.TRUE, ex);
              }
            });
  
          } catch (Throwable ex2) {
            if (log.isDebugEnabled()) log.debug("authentication failed", ex2);
            asyncResult.setAsyncResult(Boolean.FALSE, ex2);
          }
        }

        if (log.isDebugEnabled()) log.debug(")setAsyncResult");
      }
    };
    
    internalAuthenticateRetry(outerResult);
    
    if (log.isDebugEnabled()) log.debug(")authenticate");
  }

  @Override
  public boolean isReloginException(BClient client, Throwable ex, int typeId) {
    boolean ret = client.getTransport().isReloginException(ex, typeId);
    if (log.isDebugEnabled()) log.debug("isReloginException(client="+ client +", ex=" + ex + ", typeId=" + typeId + ")=" + ret);
    return ret;
  }

  @Override
  public void getSession(BClient client, int typeId, BAsyncResult<Object> asyncResult) {
    if (log.isDebugEnabled()) log.debug("getSession(client=" + client + ", typeId=" + typeId + ")");
    asyncResult.setAsyncResult(null, null);
  }

  /**
   * Requests the token from Your Web Application
   * @param asyncResult The token is supplied in the result parameter.
   */
  public void keepAlive(BAsyncResult<String> asyncResult) {
    if (log.isDebugEnabled()) log.debug("keepAlive()");
    internalAuthenticateRetry(asyncResult);
  }
  
}
