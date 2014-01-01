package com.wilutions.jsfs;

public interface JsfsTrayIcon {

  public void showError(Throwable ex);

  public void showInfo(String msg);

  public void touch();

}