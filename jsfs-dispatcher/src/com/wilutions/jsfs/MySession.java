/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import java.io.File;

import javax.servlet.http.HttpSession;

import byps.BApiDescriptor;
import byps.BServer;
import byps.BServerRegistry;
import byps.BTransportFactory;
import byps.http.HSession;

/**
 * BYPS session class.
 *
 */
public class MySession extends HSession {

  /**
   * Server class that gives BYPS access to the interface implementations.
   */
  private final BServer_JSFS server;
  
  /**
   * Associated JSFS Dispatcher object.
   * @see JsfsDispatcher
   */
  private final JsfsDispatcher jsfsDispatcher;
  
  /**
   * API descriptor with JSON serializers.
   */
  public final static BApiDescriptor apiDesc = BApiDescriptor_JSFS.instance().addRegistry(new JRegistry_JSFS());

	public MySession(HttpSession hsess, String remoteUser, File tempDir,
			BServerRegistry stubRegistry) {
		super(hsess, remoteUser, tempDir, stubRegistry);
    
		// Initialize objects required by BYPS 
    BTransportFactory transportFactory = getTransportFactory(apiDesc);
    server = BServer_JSFS.createServer(transportFactory);
    
    // Assign a JSFS Dispatcher to this session and 
    // add it to the interfaces managed by the server object.
    jsfsDispatcher = new JsfsDispatcher(this);
    server.addRemote(jsfsDispatcher);

    // The session is now valid for 10s. 
    // If the session is created for JSFS Agent, the lifetime will be extended
    // in the subsequent JsfsDispatcher.registerService call.
    // If the session is created for the browser, the lifetime will be extended
    // if JsfsDispatcher.getService returns not null.
    
	}
	
	@Override
	public BServer getServer() {
		return server;
	}
	
	@Override
	public void done() {
	  jsfsDispatcher.removeMyTokenBecauseSessionWasInvalidated();
	  super.done();
	}

}
