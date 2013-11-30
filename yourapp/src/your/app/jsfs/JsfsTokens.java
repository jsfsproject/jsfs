package your.app.jsfs;

import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class JsfsTokens {
  
  private HashMap<String,JsfsToken> mapKey2Session = new HashMap<String,JsfsToken>();
  private SecureRandom rand = new SecureRandom();
  private CleanupThread cleanupThread = new CleanupThread();
  private final static long CLEANUP_INTERVAL_MILLIS = 10 * 1000;
  
  public JsfsTokens() {
    cleanupThread.start();
  }
  
  public void done() {
    cleanupThread.interrupt();
    try {
      cleanupThread.join(CLEANUP_INTERVAL_MILLIS + 1000);
    } catch (InterruptedException ignored) {}
  }
  
  private JsfsToken createToken(String sessKey) {
    StringBuilder sbuf = new StringBuilder();
    sbuf.append(rand.nextLong()).append(".").append(rand.nextLong());
    JsfsToken token = new JsfsToken(sbuf.toString());
    mapKey2Session.put(sessKey, token);
    return token;
  }
  
  /**
   * Gets or creates a token.
   * @param userName user name from HttpServletRequest.getRemoteUser
   * @param remoteAddr  remote address from HttpServletRequest.getRemoteAddr
   * @param createIfNotEx true in order to create a token, if no token is assigned to userName/remoteAddr
   * @return token or null.
   */
  public JsfsToken getOrCreateToken(String userName, String remoteAddr, boolean createIfNotEx) {
    String sessKey = makeKey(userName, remoteAddr);
    synchronized (mapKey2Session) {
      JsfsToken token = mapKey2Session.get(sessKey);
      if (token == null) {
        token = createToken(sessKey);
      }
      return token;
    }
  }
  
  public String makeKey(String userName, String remoteAddr) {
    String sessKey = userName + "/" + remoteAddr;
    return sessKey;
  }
  
  public void removeToken(String userName, String remoteAddr) {
    String sessKey = makeKey(userName, remoteAddr);
    synchronized (mapKey2Session) {
      mapKey2Session.remove(sessKey);
    }
  }
  
  /**
   * This background thread removes expired tokens. 
   *
   */
  private class CleanupThread extends Thread {
    CleanupThread() {
      setName("cleanup-jsfs-tokens");
    }
    public void run() {
      try {
        while(!isInterrupted()) {
          sleep(CLEANUP_INTERVAL_MILLIS);
          synchronized(mapKey2Session) {
            ArrayList<String> keysToRemove = new ArrayList<String>(mapKey2Session.size());
            for (Map.Entry<String, JsfsToken> e : mapKey2Session.entrySet()) {
              if (e.getValue().isExpired()) keysToRemove.add(e.getKey());
            }
            for (String k : keysToRemove) {
              mapKey2Session.remove(k);
            }
          }
        }
      }
      catch (Throwable ignored) {}
    }
  }

}
