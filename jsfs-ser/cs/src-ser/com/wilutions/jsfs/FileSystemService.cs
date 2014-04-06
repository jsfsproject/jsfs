using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using byps;

namespace com.wilutions.jsfs
{
	
	/// <summary>
	/// This is the service interface of the JSFS Agent.
	/// </summary>
	// checkpoint byps.gen.cs.GenRemoteClass:93
	public interface FileSystemService : BRemote {
	
		/// <summary>
		/// List files in a directory.
		/// </summary>
		IList<FileInfo> FindFiles(String path, FindOptions findOptions);
		void FindFiles(String path, FindOptions findOptions, BAsyncResult<IList<FileInfo>> asyncResult) ;
		/// <summary>
		/// List files in a directory.
		/// </summary>
		Task<IList<FileInfo>> FindFilesAsync(String path, FindOptions findOptions);
		
		/// <summary>
		/// Read text file.
		/// </summary>
		/// <remarks>
		/// Read all text content from the given file.
		/// </remarks>
		String ReadAllText(String path);
		void ReadAllText(String path, BAsyncResult<String> asyncResult) ;
		/// <summary>
		/// Read text file.
		/// </summary>
		/// <remarks>
		/// Read all text content from the given file.
		/// </remarks>
		Task<String> ReadAllTextAsync(String path);
		
		/// <summary>
		/// Write text file.
		/// </summary>
		/// <remarks>
		/// Write the supplied text into the file. An existing file will be overwritten.
		/// </remarks>
		void WriteAllText(String path, String text);
		void WriteAllText(String path, String text, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Write text file.
		/// </summary>
		/// <remarks>
		/// Write the supplied text into the file. An existing file will be overwritten.
		/// </remarks>
		Task WriteAllTextAsync(String path, String text);
		
		/// <summary>
		/// Execute a program.
		/// </summary>
		/// <remarks>
		/// If opts is null, the process is started synchronously. Otherwise it is started in background and
		/// the JSFS Agent will notify the caller via the {@link FileSystemNotify#notify(NotifyInfo)} function
		/// when the process has terminated.
		/// The first element in args[] is assumed to be the application name to be started. If only
		/// {@link ExecuteOptions#extraInfo} is set in opts, the first element in args can also be a
		/// file name. In this case the file is opened via ShellExecute with verb "open".
		/// </remarks>
		void ExecuteNotifyExit(String[] args, ExecuteOptions opts);
		void ExecuteNotifyExit(String[] args, ExecuteOptions opts, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Execute a program.
		/// </summary>
		/// <remarks>
		/// If opts is null, the process is started synchronously. Otherwise it is started in background and
		/// the JSFS Agent will notify the caller via the {@link FileSystemNotify#notify(NotifyInfo)} function
		/// when the process has terminated.
		/// The first element in args[] is assumed to be the application name to be started. If only
		/// {@link ExecuteOptions#extraInfo} is set in opts, the first element in args can also be a
		/// file name. In this case the file is opened via ShellExecute with verb "open".
		/// </remarks>
		Task ExecuteNotifyExitAsync(String[] args, ExecuteOptions opts);
		
		/// <summary>
		/// Begin watching a folder.
		/// </summary>
		/// <remarks>
		/// Watch a folder and optional all sub-folders for changes.
		/// If a change occurs, the JSFS Agent invokes the {@link FileSystemNotify#notify(NotifyInfo)} function and
		/// passes a {@link WatchFolderNotifyInfo} object.
		/// </remarks>
		int BeginWatchFolder(String dir, bool recursive, String extraInfo);
		void BeginWatchFolder(String dir, bool recursive, String extraInfo, BAsyncResult<int> asyncResult) ;
		/// <summary>
		/// Begin watching a folder.
		/// </summary>
		/// <remarks>
		/// Watch a folder and optional all sub-folders for changes.
		/// If a change occurs, the JSFS Agent invokes the {@link FileSystemNotify#notify(NotifyInfo)} function and
		/// passes a {@link WatchFolderNotifyInfo} object.
		/// </remarks>
		Task<int> BeginWatchFolderAsync(String dir, bool recursive, String extraInfo);
		
		/// <summary>
		/// Stop watching a folder.
		/// </summary>
		/// <remarks>
		/// Call this function to stop watching a folder and to release resources in the JSFS Agent.
		/// </remarks>
		void EndWatchFolder(int handle);
		void EndWatchFolder(int handle, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Stop watching a folder.
		/// </summary>
		/// <remarks>
		/// Call this function to stop watching a folder and to release resources in the JSFS Agent.
		/// </remarks>
		Task EndWatchFolderAsync(int handle);
		
		/// <summary>
		/// Read file contents.
		/// </summary>
		/// <remarks>
		/// Returns an input stream for reading the contents of the given file.
		/// </remarks>
		System.IO.Stream ReadFile(String path);
		void ReadFile(String path, BAsyncResult<System.IO.Stream> asyncResult) ;
		/// <summary>
		/// Read file contents.
		/// </summary>
		/// <remarks>
		/// Returns an input stream for reading the contents of the given file.
		/// </remarks>
		Task<System.IO.Stream> ReadFileAsync(String path);
		
		/// <summary>
		/// Upload files to the given URL using multipart/form-data encoding.
		/// </summary>
		void UploadFilesMultipartFormdata(FormItem[] items, String url, String method);
		void UploadFilesMultipartFormdata(FormItem[] items, String url, String method, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Upload files to the given URL using multipart/form-data encoding.
		/// </summary>
		Task UploadFilesMultipartFormdataAsync(FormItem[] items, String url, String method);
		
		/// <summary>
		/// Upload a file to the given URL.
		/// </summary>
		void UploadFile(String path, String url);
		void UploadFile(String path, String url, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Upload a file to the given URL.
		/// </summary>
		Task UploadFileAsync(String path, String url);
		
		
	}
}  // end namespace
