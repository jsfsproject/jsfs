/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import java.io.Serializable;

/**
 * Base class for notifications.
 */
public class NotifyInfo implements Serializable {

  /**
   * Unused.
   */
  protected int id;
  
  /**
   * Application defined value.
   */
  protected String extraInfo;
  
  /**
   * Error message.
   */
  protected String error;

  public String getError() {
    return error;
  }

  public void setError(String error) {
    this.error = error;
  }

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public String getExtraInfo() {
    return extraInfo;
  }

  public void setExtraInfo(String extraInfo) {
    this.extraInfo = extraInfo;
  }

  private static final long serialVersionUID = 4523794025852024088L;

}
