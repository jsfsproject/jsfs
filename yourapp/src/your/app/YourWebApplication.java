package your.app;

import your.app.jsfs.JsfsTokens;


public class YourWebApplication {

  private final static JsfsTokens jsfsSessions = new JsfsTokens();
  
  private YourWebApplication() {
  }
  
  public static JsfsTokens getJsfsSessions() {
    return jsfsSessions;
  }
  
  public static void doneJsfsSessions() {
    jsfsSessions.done();
  }
}
