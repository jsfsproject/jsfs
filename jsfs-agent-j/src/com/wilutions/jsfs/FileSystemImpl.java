package com.wilutions.jsfs;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

import byps.BContentStreamWrapper;
import byps.BException;
import byps.BExceptionC;
import byps.RemoteException;

/**
 * This class implements the JSFS Agent interface.
 */
public class FileSystemImpl extends BSkeleton_FileSystemService {

  public FileSystemImpl(BClient_JSFS client) {
    this.bclient = client;
  }

  @Override
  public List<FileInfo> findFiles(String path, FindOptions findOptions) throws RemoteException {
    File file = getFile(path);
    String name = file.getName();
    name = name.replaceAll("\\.", "\\\\.");
    name = name.replaceAll("\\*", ".*");
    name = name.replaceAll("\\?", ".?");
    File dir = file.getParentFile();
    if (!dir.exists()) throw createBException(WindowsErrorCode.ERROR_PATH_NOT_FOUND, dir.getAbsolutePath());
    File[] files = dir.listFiles();
    ArrayList<FileInfo> fileInfos = new ArrayList<FileInfo>();
    for (File f : files) {
      if (f.getName().matches(name)) {
        fileInfos.add(FileInfoHelper.makeFileInfo(f));
      }
    }
    return fileInfos;
  }

  @Override
  public String readAllText(String path) throws RemoteException {
    return internalReadAllText(path, null);
  }

  public String internalReadAllText(String path, String defaultCharset) throws RemoteException {
    File file = getExistingFile(path);
    Reader rd = null;
    try {
      BufferedInputStream fis = new BufferedInputStream(new FileInputStream(file));
      fis.mark(3);

      int byte1 = fis.read();
      int byte2 = byte1 != -1 ? fis.read() : -1;

      if (byte1 == 0xFE && byte2 == 0xFF) {
        rd = new InputStreamReader(fis, "UTF-16BE");
      }
      else if (byte1 == 0xFF && byte2 == 0xFE) {
        rd = new InputStreamReader(fis, "UTF-16LE");
      }
      else {
        int byte3 = byte2 != -1 ? fis.read() : -1;
        if (byte1 == 0xEF && byte2 == 0xBB && byte3 == 0xBF) {
          rd = new InputStreamReader(fis, "UTF-8");
        }
        else {
          fis.reset();
          if (defaultCharset != null) {
            rd = new InputStreamReader(fis, defaultCharset);
          }
          else {
            rd = new InputStreamReader(fis);
          }
        }
      }

      char[] buf = new char[(int) file.length()];
      int len = rd.read(buf);

      return new String(buf, 0, len);

    } catch (Throwable e) {
      throw createBException(WindowsErrorCode.ERROR_INVALID_HANDLE, path + ", " + e.toString());
    } finally {
      if (rd != null) {
        try {
          rd.close();
        } catch (Exception e) {
        }
      }
    }
  }

  @Override
  public void writeAllText(String path, String text) throws RemoteException {
    internalWriteAllText(path, text, false);
  }

  private void internalWriteAllText(String path, String text, boolean utf8) throws RemoteException {
    PrintWriter pr = null;
    File file = getFile(path);
    try {
      FileOutputStream fos = new FileOutputStream(file);
      Writer wr = null;
      if (utf8) {
        fos.write(0xEF);
        fos.write(0xBB);
        fos.write(0xBF);
        wr = new OutputStreamWriter(fos, "UTF-8");
      }
      else {
        wr = new OutputStreamWriter(fos);
      }
      pr = new PrintWriter(wr);
      pr.print(text);
    } catch (Throwable e) {
      throw createBException(WindowsErrorCode.ERROR_INVALID_HANDLE, path + ", " + e.toString());
    } finally {
      if (pr != null) {
        try {
          pr.close();
        } catch (Exception e) {
        }
      }
    }
  }


  @Override
  public void executeNotifyExit(final String[] args, ExecuteOptions opts) throws RemoteException {
    internalExecuteNotifyExit(args, opts, opts != null);
  }

  public void internalExecuteNotifyExit(final String[] args, final ExecuteOptions execOpts, final boolean notify) throws RemoteException {
    if (args == null || args.length == 0) throw createBException(WindowsErrorCode.ERROR_INVALID_PARAMETER, "args must not be null or empty");

    final File file = getExistingFile(args[0]);
    final BException[] rex = new BException[1];
    final long sleepMillisToOpenInForeground = 300;

    Thread thread = new Thread() {
      public void run() {

        if (notify) {

          final ExecuteNotifyInfo notifyInfo = new ExecuteNotifyInfo();
          notifyInfo.setExtraInfo(execOpts.getExtraInfo());

          ProcessBuilder pb = new ProcessBuilder(args);
          try {

            final Process process = pb.start();

            final String stdin = execOpts.getStandardInput();
            if (stdin != null && stdin.length() != 0) {
              Thread thread = new Thread() {
                public void run() {
                  Writer wr = null;
                  try {
                    wr = new OutputStreamWriter(process.getOutputStream());
                    wr.write(stdin);
                  } catch (Throwable ignored) {
                  } finally {
                    if (wr != null) {
                      try {
                        wr.close();
                      } catch (IOException ignored) {
                      }
                    }
                  }
                }
              };
              thread.start();
            }

            if (execOpts.isCaptureOutput()) {
              Thread thread = new Thread() {
                public void run() {
                  StringBuilder sbuf = new StringBuilder();
                  InputStream is = process.getInputStream();
                  Reader rd = null;
                  try {
                    rd = new InputStreamReader(is);
                    char[] buf = new char[1000];
                    int len = -1;
                    while ((len = rd.read(buf)) != -1) {
                      sbuf.append(buf, 0, len);
                    }
                  } catch (Throwable ignroed) {
                  } finally {
                    if (rd != null) {
                      try {
                        rd.close();
                      } catch (IOException ignored) {
                      }
                    }
                  }
                  notifyInfo.setStandardOutput(sbuf.toString());
                }
              };
              thread.start();
            }

            if (execOpts.isCaptureError()) {
              Thread thread = new Thread() {
                public void run() {
                  StringBuilder sbuf = new StringBuilder();
                  InputStream is = process.getErrorStream();
                  Reader rd = null;
                  try {
                    rd = new InputStreamReader(is);
                    char[] buf = new char[1000];
                    int len = -1;
                    while ((len = rd.read(buf)) != -1) {
                      sbuf.append(buf, 0, len);
                    }
                  } catch (Throwable ignroed) {
                  } finally {
                    if (rd != null) {
                      try {
                        rd.close();
                      } catch (IOException ignored) {
                      }
                    }
                  }
                  notifyInfo.setStandardError(sbuf.toString());
                }
              };
              thread.start();
            }

            process.waitFor();

            int exitCode = process.exitValue();
            notifyInfo.setExitCode(exitCode);

          } catch (Exception e) {

            BException ex = createBException(WindowsErrorCode.ERROR_INVALID_HANDLE, args[0] + ", " + e.toString());
            notifyInfo.setError(ex.toString());
          }

          try {
            getNotifyService().notify(notifyInfo);
          } catch (RemoteException e) {
          }

        }

        else if (args.length == 1) {
          try {
            java.awt.Desktop.getDesktop().open(file);
          } catch (Exception e) {
            synchronized (rex) {
              rex[0] = createBException(WindowsErrorCode.ERROR_INVALID_HANDLE, args[0] + ", " + e.toString());
            }
          }
        }

        else {
          ProcessBuilder pb = new ProcessBuilder(args);
          try {
            pb.start();
          } catch (Exception e) {
            synchronized (rex) {
              rex[0] = createBException(WindowsErrorCode.ERROR_INVALID_HANDLE, args[0] + ", " + e.toString());
            }
          }
        }
      }

    };

    thread.start();

    if (!notify) {
      try {
        thread.join();
        synchronized (rex) {
          if (rex[0] != null) throw rex[0];
        }
      } catch (InterruptedException e) {
        throw createBException(BExceptionC.CANCELLED, args[0] + ", " + e.toString());
      }
    }
  }

  @Override
  public int beginWatchFolder(String dir, boolean recursive, String extraInfo) throws RemoteException {
    try {
      dir = FileInfoHelper.makeValidPath(dir);
      int watchHandle = nextNotifyId.incrementAndGet();
      WatchDir watcher;
      watcher = new WatchDir(getNotifyService(), watchHandle, extraInfo, Paths.get(dir), recursive);
      watcher.start();
      watchers.put(watchHandle, watcher);
      return watchHandle;
    } catch (IOException e) {
      throw new BException(BExceptionC.INTERNAL, "Failed to create directory watcher.", e);
    }
  }

  @Override
  public void endWatchFolder(int handle) throws RemoteException {
    WatchDir watcher = watchers.get(handle);
    if (watcher != null) {
      watcher.done();
    }
  }

  private BException createBException(int err, String details) {
    return new BException(10000 + err, WindowsErrorCode.toString(err), details);
  }

  private File getExistingFile(String path) throws BException {
    return internalGetExistingFile(path, true);
  }

  private File internalGetExistingFile(String path, boolean mustExist) throws BException {
    File file = getFile(path);
    if (file.exists()) {
      if (!mustExist) throw createBException(WindowsErrorCode.ERROR_ALREADY_EXISTS, path);
    }
    else {
      if (mustExist) {
        boolean found = false;

        File dir = file.getParentFile();
        if (dir == null) {
          String libpath = System.getProperty("java.library.path");
          String[] dirs = libpath.split("\\" + File.pathSeparator);
          for (String sdir : dirs) {
            file = new File(new File(sdir), path);
            found = file.exists();
            if (found) break;
          }
        }

        if (!found) {
          throw createBException(WindowsErrorCode.ERROR_FILE_NOT_FOUND, path);
        }
      }
    }
    return file;
  }

  private File getFile(String path) throws BException {
    path = FileInfoHelper.makeValidPath(path);
    File file = new File(path);
    return file;
  }

  private FileSystemNotify getNotifyService() throws RemoteException {
    String token = ((JsfsAuthentication) bclient.getAuthentication()).getToken();
    FileSystemNotify ns = bclient.dispatcherService.getNotifyService(token, false);
    return ns;
  }
  
  @Override
  public InputStream readFile(String path) throws RemoteException {
    File file = internalGetExistingFile(path, true);
    try {
      BContentStreamWrapper cstream = new BContentStreamWrapper(file);
      return cstream;
    }
    catch (FileNotFoundException e) {
      throw createBException(WindowsErrorCode.ERROR_FILE_NOT_FOUND, e.toString());
    }
  }

  private final BClient_JSFS bclient;
  private final ConcurrentHashMap<Integer, WatchDir> watchers = new ConcurrentHashMap<Integer, WatchDir>();
  private final AtomicInteger nextNotifyId = new AtomicInteger();
}
