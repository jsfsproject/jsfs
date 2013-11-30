package com.wilutions.jsfs;

/**
 * Notification information about a change in a watched folder. 
 *
 */
public class WatchFolderNotifyInfo extends NotifyInfo {

  /**
   * Information about the related file.
   */
  protected FileInfo fileInfo;

  /**
   * Kind of change.
   */
  protected EWatchFolderNotifyKind kind;

  public FileInfo getFileInfo() {
    return fileInfo;
  }

  public void setFileInfo(FileInfo fileInfo) {
    this.fileInfo = fileInfo;
  }

  public EWatchFolderNotifyKind getKind() {
    return kind;
  }

  public void setKind(EWatchFolderNotifyKind kind) {
    this.kind = kind;
  }

  private static final long serialVersionUID = -3764007444400362836L;

}
