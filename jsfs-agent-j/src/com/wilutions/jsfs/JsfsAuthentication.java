package com.wilutions.jsfs;

import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.net.Authenticator;
import java.net.PasswordAuthentication;
import java.net.URL;

import javax.activation.DataHandler;

import byps.BAsyncResult;
import byps.BAuthentication;
import byps.BClient;

/**
 * This class performs the authentication to the JSFS Dispatcher. 
 *
 */
public class JsfsAuthentication implements BAuthentication {
  
  private String appUrl, userName, userPwd;
  private String token;

  /**
   * Constructor
   * @param appUrl URL to the token service of "Your Web Application"
   * @param userName User name
   * @param userPwd Password
   */
  public JsfsAuthentication(String appUrl, String userName, String userPwd) {
    super();
    this.appUrl = appUrl;
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
   * @param client Unused
   * @param asyncResult Callback object
   */
  private void internalAuthenticate(BClient client, BAsyncResult<Boolean> asyncResult) {
    
    try {
      
      // Create an Authenticator object that is used to send the credentials
      // during BASIC authentication.
      Authenticator.setDefault( new Authenticator() {
        @Override 
        protected PasswordAuthentication getPasswordAuthentication() {
          return new PasswordAuthentication( userName, userPwd.toCharArray() );
        }
      });

      // The easiest way to send a GET is by using the DataHandler class.
      DataHandler dh = new DataHandler(new URL(appUrl));
      LineNumberReader rd = null;
      try {
        rd = new LineNumberReader(new InputStreamReader(dh.getInputStream()));
        token = rd.readLine();
        if (token == null) {
          asyncResult.setAsyncResult(Boolean.FALSE, new IllegalStateException("No token returned from " + appUrl));
        }
        else {
          asyncResult.setAsyncResult(Boolean.TRUE, null);
        }
      }
      finally {
        if (rd != null) {
          try { rd.close(); } catch (Throwable e) {}
        }
      }
    } catch (Throwable e) {
      asyncResult.setAsyncResult(Boolean.FALSE, e);
    }
    
  }
  
  @Override
  public void authenticate(BClient bclient1, final BAsyncResult<Boolean> asyncResult) {
    
    final BClient_JSFS bclient = (BClient_JSFS)bclient1;
    
    BAsyncResult<Boolean> outerResult = new BAsyncResult<Boolean>() {
      public void setAsyncResult(Boolean ignored, Throwable ex) {
        
        try {
          // Required by BYPS: add the implementation of a service that is
          // called via reverse HTTP to the client object.
          final FileSystemImpl fssrv = new FileSystemImpl(bclient);
          bclient.addRemote(fssrv);

          // Publish the service to the JSFS Dispatcher.
          String token = ((JsfsAuthentication) bclient.getAuthentication()).getToken();
          bclient.dispatcherService.registerService(token, fssrv, new BAsyncResult<Object>() {
            public void setAsyncResult(Object ignored, Throwable ex) {
              asyncResult.setAsyncResult(Boolean.TRUE, ex);
            }
          });

        } catch (Throwable ex2) {
          asyncResult.setAsyncResult(null, ex2);
        }

      }
    };
    
    internalAuthenticate(bclient1, outerResult);
  }

  @Override
  public boolean isReloginException(BClient client, Throwable ex, int typeId) {
    return client.transport.isReloginException(ex, typeId);
  }

  @Override
  public void getSession(BClient client, int typeId, BAsyncResult<Object> asyncResult) {
    asyncResult.setAsyncResult(null, null);
  }


  
}
