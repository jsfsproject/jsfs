/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import byps.BApiDescriptor;
import byps.BClient;
import byps.BException;
import byps.BServerRegistry;
import byps.BTransport;
import byps.http.HConfig;
import byps.http.HConfigImpl;
import byps.http.HHttpServlet;
import byps.http.HSession;

/**
 * Servlet implementation class for the JSFS Dispatcher
 */
@WebServlet(
// mandatory: must be true
asyncSupported = true,

// optional: load servlet on startup
loadOnStartup = 1,

// mandatory: server URL pattern
urlPatterns = { "/jsfs" })
public class JsfsDispatcherServlet extends HHttpServlet {

  private static final long serialVersionUID = 1L;
  private static Log log = LogFactory.getLog(JsfsDispatcherServlet.class);
  private final HConfigImpl config = new HConfigImpl();

  /**
   * @see HttpServlet#HttpServlet()
   */
  public JsfsDispatcherServlet() {
    super();
  }

  /**
   * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse
   *      response)
   */
  protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    super.service(request, response);
  }

  /**
   * Create a session object.
   * Required by BYPS.
   * This function is called after the protocol has been negotiated. 
   * It must return a session object. Via this object, BYPS accesses the JSFS Dispatcher service.
   */
   @Override
  protected HSession createSession(HttpServletRequest request, HttpServletResponse response, HttpSession hsess, BServerRegistry stubRegistry) {
    if (log.isDebugEnabled()) log.debug("createSession(");
    String remoteUser = request.getRemoteUser();
    if (log.isDebugEnabled()) log.debug("remoteUser=" + remoteUser);

    HSession sess = new MySession(hsess, remoteUser, null, stubRegistry);
    if (log.isDebugEnabled()) log.debug(")createSession=" + sess);
    return sess;
  }

   /**
    * Create a client object to forward requests to other servers.
    * This client object is used, if more than one JSFS Dispatcher is used and 
    * the browser is connected to a different JSFS Dispatcher than the JSFS Agent.
    * In this case, BYPS forwards the requests between the JSFS Dispatcher services.
    */
  @Override
  protected BClient createForwardClientToOtherServer(BTransport transport) throws BException {
    return BClient_JSFS.createClientR(transport);
  }

  /**
   * BApi descriptor.
   * This object describes the JSFS Dispatcher interface. 
   * BYPS needs this descriptor e.g. during protocol negotiation.
   */
   @Override
  protected BApiDescriptor getApiDescriptor() {
    return MySession.apiDesc;
  }

   /**
    * Get the configuration.
    */
  @Override
  protected HConfig getConfig() {
    return config;
  }

  /**
   * Called if BYPS has finished initialization. 
   */
  @Override
  protected void initializationFinished() {
  }
}
