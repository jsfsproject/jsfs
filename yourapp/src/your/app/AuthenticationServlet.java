/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package your.app;

import java.io.IOException;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * This servlet generates the tokens used to connect the browser with JSFS Agent.
 * The web.xml constrains access to the servlet by an authentication mechanism.
 */
public class AuthenticationServlet extends HttpServlet {
  
  private static final long serialVersionUID = -3891364599072873699L;
  
  /**
   * A secret value used to compute the token.
   */
  private long secret = new SecureRandom().nextLong();

  /**
   * @see HttpServlet#HttpServlet()
   */
  public AuthenticationServlet() {
    super();
  }
  
  @Override
  public void destroy() {
    super.destroy();
  }
  
  /**
   * Create JSFS token.
   * @param userName User name
   * @param remoteAddr Remote address
   * @return MD5 hash of user + address + secret
   */
  private String createToken(String userName, String remoteAddr) {
    String token = null;
    if (userName != null && userName.length() != 0 && remoteAddr != null && remoteAddr.length() != 0) {
      String plaintext = userName + "*" + remoteAddr + "*" + secret;
            
      try {
        MessageDigest m = MessageDigest.getInstance("MD5");
        m.reset();
        m.update(plaintext.getBytes());
        byte[] digest = m.digest();
        BigInteger bigInt = new BigInteger(1,digest);
        token = bigInt.toString(16);
      }
      catch (NoSuchAlgorithmException e) {
        e.printStackTrace();
      }
    }
    return token;
  }

  /**
   * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
   *      response)
   */
  protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    
    // Create a JSFS Token?
    if (request.getParameter("jsfstoken") != null) {
      
      String token = createToken(request.getRemoteUser(), request.getRemoteAddr());
      if (token != null) {
        
        // JSFS does not require a HttpSession.
        
        // If a session is created here, the browser and JSFS agent will 
        // receive different sessions, unless you use your own session manager.
        // http://tomcat.apache.org/tomcat-7.0-doc/config/manager.html
        
        response.setContentType("text/plain");
        response.getWriter().print(token);
      }
      else {
        response.sendError(HttpServletResponse.SC_UNAUTHORIZED);
      }
      
    }
    else {
      
      // Your servlet implementation.
      // Maybe create a HttpSession...
      super.doGet(request, response);
    }
  }

}
