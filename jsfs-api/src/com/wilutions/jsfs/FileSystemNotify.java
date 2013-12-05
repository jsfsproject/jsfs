/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import byps.BRemote;
import byps.RemoteException;

/**
 * Notification interface.
 * This interface is used by the JFSF Agent to notify the browser about an event.
 * @BClientRemote
 */
public interface FileSystemNotify extends BRemote {

  /**
   * Notify the browser about an event.
   * @param notifyInfo NotifyInfo or ExecuteNotifyInfo object.
   * @throws RemoteException
   */
  public void notify(NotifyInfo notifyInfo) throws RemoteException;
  
}
