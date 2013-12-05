/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import java.io.Serializable;

/**
 * This class contains additional parameters for 
 * {@link FileSystemService#executeNotifyExit(String[], ExecuteOptions)}.
 *
 */
public class ExecuteOptions implements Serializable {

  /**
   * Application defined field.
   * This value is passed to the field {@link NotifyInfo#extraInfo}.
   */
  protected String extraInfo;
  
  /**
   * Send this text to the standard input pipe of the process.
   */
  protected String standardInput;

  /**
   * Read characters from the processes standard output pipe.
   */
  protected boolean captureOutput;
  
  /**
   * Read characters from  the processes standard error pipe.
   */
  protected boolean captureError;

  public String getExtraInfo() {
    return extraInfo;
  }

  public void setExtraInfo(String extraInfo) {
    this.extraInfo = extraInfo;
  }

  public String getStandardInput() {
    return standardInput;
  }

  public void setStandardInput(String standardInput) {
    this.standardInput = standardInput;
  }

  public boolean isCaptureOutput() {
    return captureOutput;
  }

  public void setCaptureOutput(boolean captureOutput) {
    this.captureOutput = captureOutput;
  }

  public boolean isCaptureError() {
    return captureError;
  }

  public void setCaptureError(boolean captureError) {
    this.captureError = captureError;
  }



  private static final long serialVersionUID = -5757395919724194969L;

}
