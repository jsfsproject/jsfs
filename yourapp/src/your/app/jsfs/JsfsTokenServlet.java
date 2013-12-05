/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package your.app.jsfs;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import your.app.YourWebApplication;

/**
 * Servlet implementation class LoginServlet
 */

public class JsfsTokenServlet extends HttpServlet {
  
  private static final long serialVersionUID = 1L;

  /**
   * @see HttpServlet#HttpServlet()
   */
  public JsfsTokenServlet() {
    super();
  }
  
  @Override
  public void destroy() {
    YourWebApplication.doneJsfsSessions();
    super.destroy();
  }

  /**
   * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
   *      response)
   */
  protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    String userName = request.getRemoteUser();
    
    if (userName != null && userName.length() != 0) {
      String remoteAddr = request.getRemoteAddr();
      JsfsTokens jsfs = YourWebApplication.getJsfsSessions();
      JsfsToken token = jsfs.getOrCreateToken(userName, remoteAddr, true);
      
      String removeToken = request.getParameter("removeToken");
      if (removeToken != null) {
        jsfs.removeToken(userName, remoteAddr);
      }
      else {
        response.setContentType("text/plain");
        response.getWriter().print(token.getValue());
      }
    }
    else {
      response.sendError(HttpServletResponse.SC_UNAUTHORIZED);
    }
  }

}
