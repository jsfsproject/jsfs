using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using byps;

namespace com.wilutions.jsfs
{
	
	/// <summary>
	/// This class provides a skeleton implementation of the interface FileSystemService.
	/// </summary>
	/// <remark>
	/// Your interface implementation class has to be derived from this skeleton.
	/// Either provide an asynchronous or a synchronous function in your subclass.
	/// The framework calls only the asynchronous function.
	/// </remark>
	public class BSkeleton_FileSystemService : BSkeleton, FileSystemService {	
		
		public readonly static long serialVersionUID = 145996442L;
		
		public virtual IList<FileInfo> FindFiles(String path, FindOptions findOptions) {
			throw new NotImplementedException();
		}
		public virtual async void FindFiles(String path, FindOptions findOptions, BAsyncResult<IList<FileInfo>> asyncResult) {
			IList<FileInfo> __byps__ret = default(IList<FileInfo>);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				__byps__ret = FindFiles(path, findOptions);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				__byps__ret = await FindFilesAsync(path, findOptions);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// List files in a directory.
		/// </summary>
		public virtual Task<IList<FileInfo>> FindFilesAsync(String path, FindOptions findOptions){
			return BTaskConstants<IList<FileInfo>>.NotImplemented;
		}
		
		public virtual String ReadAllText(String path) {
			throw new NotImplementedException();
		}
		public virtual async void ReadAllText(String path, BAsyncResult<String> asyncResult) {
			String __byps__ret = default(String);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				__byps__ret = ReadAllText(path);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				__byps__ret = await ReadAllTextAsync(path);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// Read text file.
		/// </summary>
		/// <remarks>
		/// Read all text content from the given file.
		/// </remarks>
		public virtual Task<String> ReadAllTextAsync(String path){
			return BTaskConstants<String>.NotImplemented;
		}
		
		public virtual void WriteAllText(String path, String text) {
			throw new NotImplementedException();
		}
		public virtual async void WriteAllText(String path, String text, BAsyncResult<Object> asyncResult) {
			Object __byps__ret = default(Object);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				WriteAllText(path, text);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				await WriteAllTextAsync(path, text);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// Write text file.
		/// </summary>
		/// <remarks>
		/// Write the supplied text into the file. An existing file will be overwritten.
		/// </remarks>
		public virtual Task WriteAllTextAsync(String path, String text){
			return BTaskConstants<Object>.NotImplemented;
		}
		
		public virtual void ExecuteNotifyExit(String[] args, ExecuteOptions opts) {
			throw new NotImplementedException();
		}
		public virtual async void ExecuteNotifyExit(String[] args, ExecuteOptions opts, BAsyncResult<Object> asyncResult) {
			Object __byps__ret = default(Object);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				ExecuteNotifyExit(args, opts);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				await ExecuteNotifyExitAsync(args, opts);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
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
		public virtual Task ExecuteNotifyExitAsync(String[] args, ExecuteOptions opts){
			return BTaskConstants<Object>.NotImplemented;
		}
		
		public virtual int BeginWatchFolder(String dir, bool recursive, String extraInfo) {
			throw new NotImplementedException();
		}
		public virtual async void BeginWatchFolder(String dir, bool recursive, String extraInfo, BAsyncResult<int> asyncResult) {
			int __byps__ret = default(int);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				__byps__ret = BeginWatchFolder(dir, recursive, extraInfo);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				__byps__ret = await BeginWatchFolderAsync(dir, recursive, extraInfo);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// Begin watching a folder.
		/// </summary>
		/// <remarks>
		/// Watch a folder and optional all sub-folders for changes.
		/// If a change occurs, the JSFS Agent invokes the {@link FileSystemNotify#notify(NotifyInfo)} function and
		/// passes a {@link WatchFolderNotifyInfo} object.
		/// </remarks>
		public virtual Task<int> BeginWatchFolderAsync(String dir, bool recursive, String extraInfo){
			return BTaskConstants<int>.NotImplemented;
		}
		
		public virtual void EndWatchFolder(int handle) {
			throw new NotImplementedException();
		}
		public virtual async void EndWatchFolder(int handle, BAsyncResult<Object> asyncResult) {
			Object __byps__ret = default(Object);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				EndWatchFolder(handle);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				await EndWatchFolderAsync(handle);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// Stop watching a folder.
		/// </summary>
		/// <remarks>
		/// Call this function to stop watching a folder and to release resources in the JSFS Agent.
		/// </remarks>
		public virtual Task EndWatchFolderAsync(int handle){
			return BTaskConstants<Object>.NotImplemented;
		}
		
		public virtual System.IO.Stream ReadFile(String path) {
			throw new NotImplementedException();
		}
		public virtual async void ReadFile(String path, BAsyncResult<System.IO.Stream> asyncResult) {
			System.IO.Stream __byps__ret = default(System.IO.Stream);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				__byps__ret = ReadFile(path);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				__byps__ret = await ReadFileAsync(path);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// Read file contents.
		/// </summary>
		/// <remarks>
		/// Returns an input stream for reading the contents of the given file.
		/// </remarks>
		public virtual Task<System.IO.Stream> ReadFileAsync(String path){
			return BTaskConstants<System.IO.Stream>.NotImplemented;
		}
		
		public virtual void UploadFilesMultipartFormdata(FormItem[] items, String url, String method) {
			throw new NotImplementedException();
		}
		public virtual async void UploadFilesMultipartFormdata(FormItem[] items, String url, String method, BAsyncResult<Object> asyncResult) {
			Object __byps__ret = default(Object);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				UploadFilesMultipartFormdata(items, url, method);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				await UploadFilesMultipartFormdataAsync(items, url, method);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// Upload files to the given URL using multipart/form-data encoding.
		/// </summary>
		public virtual Task UploadFilesMultipartFormdataAsync(FormItem[] items, String url, String method){
			return BTaskConstants<Object>.NotImplemented;
		}
		
		public virtual void UploadFile(String path, String url, String method) {
			throw new NotImplementedException();
		}
		public virtual async void UploadFile(String path, String url, String method, BAsyncResult<Object> asyncResult) {
			Object __byps__ret = default(Object);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				UploadFile(path, url, method);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				await UploadFileAsync(path, url, method);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// Upload a file to the given URL.
		/// </summary>
		public virtual Task UploadFileAsync(String path, String url, String method){
			return BTaskConstants<Object>.NotImplemented;
		}
		
		
	}
}
