/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package your.app.jsfs;

public class JsfsToken {

  /**
   * Token lifetime.
   * The lifetime must be at least as long as the time the application server 
   * allows a session in the JSFS-Dispatcher application to be idle. In other words:
   * TOKEN_LIFETIME_MILLIS >= HttpSession.getMaxInactiveInterval().
   */
  private static final long TOKEN_LIFETIME_MILLIS = 30 * 60 * 1000;

  private final String value;
  
  private volatile long bestBefore;
  
  public JsfsToken(String value) {
    this.value = value;
    this.bestBefore = System.currentTimeMillis() + TOKEN_LIFETIME_MILLIS;
  }
  
  public boolean isExpired() {
    return bestBefore < System.currentTimeMillis();
  }
  
  public String getValue() {
    this.bestBefore = System.currentTimeMillis() + TOKEN_LIFETIME_MILLIS;
    return value;
  }

  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((value == null) ? 0 : value.hashCode());
    return result;
  }

  @Override
  public boolean equals(Object obj) {
    if (this == obj) return true;
    if (obj == null) return false;
    if (getClass() != obj.getClass()) return false;
    JsfsToken other = (JsfsToken) obj;
    if (value == null) {
      if (other.value != null) return false;
    }
    else if (!value.equals(other.value)) return false;
    return true;
  }

  
  
}
