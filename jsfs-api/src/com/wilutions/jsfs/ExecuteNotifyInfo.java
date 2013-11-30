package com.wilutions.jsfs;

/**
 * This class contains notification information generated from 
 * {@link FileSystemService#executeNotifyExit(String[], ExecuteOptions)}.
 */
public class ExecuteNotifyInfo extends NotifyInfo {

  /**
   * Process exit code.
   */
  protected int exitCode;

  /**
   * Characters printed on stdout, if {@link ExecuteOptions#captureOutput} was
   * set.
   */
  protected String standardOutput;
  
  /**
   * Characters printed on stderr, if {@link ExecuteOptions#captureError} was
   * set.
   */
  protected String standardError;

  public int getExitCode() {
    return exitCode;
  }

  public void setExitCode(int exitCode) {
    this.exitCode = exitCode;
  }

  public String getStandardOutput() {
    return standardOutput;
  }

  public void setStandardOutput(String standardOutput) {
    this.standardOutput = standardOutput;
  }

  public String getStandardError() {
    return standardError;
  }

  public void setStandardError(String standardError) {
    this.standardError = standardError;
  }

  private static final long serialVersionUID = 5102493464825214694L;

}
