/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import java.io.InputStream;
import java.util.List;

import byps.BRemote;
import byps.RemoteException;

/**
 * This is the service interface of the JSFS Agent.
 * @BClientRemote
 */
public interface FileSystemService extends BRemote {
  
  /**
   * List files in a directory.
   * @param path Directory of path with wildcards * or ?
   * @param findOptions unused
   * @return List of files.
   * @throws RemoteException
   */
	public List<FileInfo> findFiles(String path, FindOptions findOptions) throws RemoteException;
	
	/**
	 * Read text file.
	 * Read all text content from the given file.
	 * @param path File path.
	 * @return Text content
	 * @throws RemoteException
	 */
  public String readAllText(String path) throws RemoteException;
  
  /**
   * Write text file.
   * Write the supplied text into the file. An existing file will be overwritten. 
   * @param path File path.
   * @param text Text content
   * @throws RemoteException
   */
  public void writeAllText(String path, String text) throws RemoteException;
  
  /**
   * Execute a program.
   * If opts is null, the process is started synchronously. Otherwise it is started in background and
   * the JSFS Agent will notify the caller via the {@link FileSystemNotify#notify(NotifyInfo)} function 
   * when the process has terminated. 
   * The first element in args[] is assumed to be the application name to be started. If only 
   * {@link ExecuteOptions#extraInfo} is set in opts, the first element in args can also be a 
   * file name. In this case the file is opened via ShellExecute with verb "open".
   * @param args Arguments
   * @param opts Options
   * @throws RemoteException
   */
  public void executeNotifyExit(String[] args, ExecuteOptions opts) throws RemoteException;
  
  /**
   * Begin watching a folder.
   * Watch a folder and optional all sub-folders for changes.
   * If a change occurs, the JSFS Agent invokes the {@link FileSystemNotify#notify(NotifyInfo)} function and 
   * passes a {@link WatchFolderNotifyInfo} object.
   * @param dir Folder to be watched.
   * @param recursive True, if sub-folders should also be watched.
   * @param extraInfo Application defined value passed to the {@link NotifyInfo#extraInfo} element.
   * @return Watch handle. Use this handle in {@link #endWatchFolder(int)} to stop watching the folder.
   * @throws RemoteException
   */
  public int beginWatchFolder(String dir, boolean recursive, String extraInfo) throws RemoteException;
 
  /**
   * Stop watching a folder.
   * Call this function to stop watching a folder and to release resources in the JSFS Agent.
   * @param handle Watch handle returned from {@link #beginWatchFolder(String, boolean, String)}.
   * @throws RemoteException
   */
  public void endWatchFolder(int handle) throws RemoteException;
  
  /**
   * Read file contents.
   * Returns an input stream for reading the contents of the given file.
   * @param path File path
   * @return InputStream object
   * @throws RemoteException
   */
  public InputStream readFile(String path) throws RemoteException;
  
  /**
   * Upload files to server(s).
   * @param items Form data items, file paths or name/value pairs.
   * @param url Target URL. Authentication information should be included, e.g. the JSFS authentication token.
   * @param method HTTP method, can be POST or PUT. If this parameter is null or empty, method POST is used.
   * @param encoding Request encoding, can be multipart/form-data or null or empty. If this parameter is null or empty, the 
   * request body does merely contain the file bytes. 
   * @throws RemoteException
   */
  public void uploadFiles(FormItem[] items, String url, String method, String encoding) throws RemoteException;
}
