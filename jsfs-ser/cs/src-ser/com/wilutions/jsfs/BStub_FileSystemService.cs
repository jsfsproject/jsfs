using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BStub_FileSystemService : BStub, FileSystemService, BSerializable {	
		
		public readonly static long serialVersionUID = 145996442L;
		
		public BStub_FileSystemService(BTransport transport)
			: base(transport) {}			
		
		public virtual IList<FileInfo> FindFiles(String path, FindOptions findOptions) {
			BSyncResult<IList<FileInfo>> asyncResult = new BSyncResult<IList<FileInfo>>();			
			FindFiles(path, findOptions, BAsyncResultHelper.ToDelegate<IList<FileInfo>>(asyncResult));
			return asyncResult.GetResult();			
		}
		public virtual void FindFiles(String path, FindOptions findOptions, BAsyncResult<IList<FileInfo>> asyncResult) {
			BRequest_FileSystemService_findFiles req = new BRequest_FileSystemService_findFiles();			
			req.pathValue = path;
			req.findOptionsValue = findOptions;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task<IList<FileInfo>> FindFilesAsync(String path, FindOptions findOptions){
			BRequest_FileSystemService_findFiles req = new BRequest_FileSystemService_findFiles();			
			req.pathValue = path;
			req.findOptionsValue = findOptions;
			Task<IList<FileInfo>> task = Task<IList<FileInfo>>.Factory.FromAsync(transport.BeginSend<IList<FileInfo>>, transport.EndSend<IList<FileInfo>>, req, null);
			return await task;
		}
		
		public virtual String ReadAllText(String path) {
			BSyncResult<String> asyncResult = new BSyncResult<String>();			
			ReadAllText(path, BAsyncResultHelper.ToDelegate<String>(asyncResult));
			return asyncResult.GetResult();			
		}
		public virtual void ReadAllText(String path, BAsyncResult<String> asyncResult) {
			BRequest_FileSystemService_readAllText req = new BRequest_FileSystemService_readAllText();			
			req.pathValue = path;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task<String> ReadAllTextAsync(String path){
			BRequest_FileSystemService_readAllText req = new BRequest_FileSystemService_readAllText();			
			req.pathValue = path;
			Task<String> task = Task<String>.Factory.FromAsync(transport.BeginSend<String>, transport.EndSend<String>, req, null);
			return await task;
		}
		
		public virtual void WriteAllText(String path, String text) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			WriteAllText(path, text, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void WriteAllText(String path, String text, BAsyncResult<Object> asyncResult) {
			BRequest_FileSystemService_writeAllText req = new BRequest_FileSystemService_writeAllText();			
			req.pathValue = path;
			req.textValue = text;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task WriteAllTextAsync(String path, String text){
			BRequest_FileSystemService_writeAllText req = new BRequest_FileSystemService_writeAllText();			
			req.pathValue = path;
			req.textValue = text;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		public virtual void ExecuteNotifyExit(String[] args, ExecuteOptions opts) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			ExecuteNotifyExit(args, opts, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void ExecuteNotifyExit(String[] args, ExecuteOptions opts, BAsyncResult<Object> asyncResult) {
			BRequest_FileSystemService_executeNotifyExit req = new BRequest_FileSystemService_executeNotifyExit();			
			req.argsValue = args;
			req.optsValue = opts;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task ExecuteNotifyExitAsync(String[] args, ExecuteOptions opts){
			BRequest_FileSystemService_executeNotifyExit req = new BRequest_FileSystemService_executeNotifyExit();			
			req.argsValue = args;
			req.optsValue = opts;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		public virtual int BeginWatchFolder(String dir, bool recursive, String extraInfo) {
			BSyncResult<int> asyncResult = new BSyncResult<int>();			
			BeginWatchFolder(dir, recursive, extraInfo, BAsyncResultHelper.ToDelegate<int>(asyncResult));
			return asyncResult.GetResult();			
		}
		public virtual void BeginWatchFolder(String dir, bool recursive, String extraInfo, BAsyncResult<int> asyncResult) {
			BRequest_FileSystemService_beginWatchFolder req = new BRequest_FileSystemService_beginWatchFolder();			
			req.dirValue = dir;
			req.recursiveValue = recursive;
			req.extraInfoValue = extraInfo;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task<int> BeginWatchFolderAsync(String dir, bool recursive, String extraInfo){
			BRequest_FileSystemService_beginWatchFolder req = new BRequest_FileSystemService_beginWatchFolder();			
			req.dirValue = dir;
			req.recursiveValue = recursive;
			req.extraInfoValue = extraInfo;
			Task<int> task = Task<int>.Factory.FromAsync(transport.BeginSend<int>, transport.EndSend<int>, req, null);
			return await task;
		}
		
		public virtual void EndWatchFolder(int handle) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			EndWatchFolder(handle, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void EndWatchFolder(int handle, BAsyncResult<Object> asyncResult) {
			BRequest_FileSystemService_endWatchFolder req = new BRequest_FileSystemService_endWatchFolder();			
			req.handleValue = handle;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task EndWatchFolderAsync(int handle){
			BRequest_FileSystemService_endWatchFolder req = new BRequest_FileSystemService_endWatchFolder();			
			req.handleValue = handle;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		public virtual System.IO.Stream ReadFile(String path) {
			BSyncResult<System.IO.Stream> asyncResult = new BSyncResult<System.IO.Stream>();			
			ReadFile(path, BAsyncResultHelper.ToDelegate<System.IO.Stream>(asyncResult));
			return asyncResult.GetResult();			
		}
		public virtual void ReadFile(String path, BAsyncResult<System.IO.Stream> asyncResult) {
			BRequest_FileSystemService_readFile req = new BRequest_FileSystemService_readFile();			
			req.pathValue = path;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task<System.IO.Stream> ReadFileAsync(String path){
			BRequest_FileSystemService_readFile req = new BRequest_FileSystemService_readFile();			
			req.pathValue = path;
			Task<System.IO.Stream> task = Task<System.IO.Stream>.Factory.FromAsync(transport.BeginSend<System.IO.Stream>, transport.EndSend<System.IO.Stream>, req, null);
			return await task;
		}
		
		public virtual void UploadFiles(FormItem[] items, String url, String method, String encoding) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			UploadFiles(items, url, method, encoding, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void UploadFiles(FormItem[] items, String url, String method, String encoding, BAsyncResult<Object> asyncResult) {
			BRequest_FileSystemService_uploadFiles req = new BRequest_FileSystemService_uploadFiles();			
			req.itemsValue = items;
			req.urlValue = url;
			req.methodValue = method;
			req.encodingValue = encoding;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task UploadFilesAsync(FormItem[] items, String url, String method, String encoding){
			BRequest_FileSystemService_uploadFiles req = new BRequest_FileSystemService_uploadFiles();			
			req.itemsValue = items;
			req.urlValue = url;
			req.methodValue = method;
			req.encodingValue = encoding;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		
	}
}
