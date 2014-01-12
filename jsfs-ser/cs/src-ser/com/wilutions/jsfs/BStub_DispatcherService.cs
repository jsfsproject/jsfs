using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BStub_DispatcherService : BStub, DispatcherService, BSerializable {	
		
		public readonly static long serialVersionUID = 1153231042L;
		
		public BStub_DispatcherService(BTransport transport)
			: base(transport) {}			
		
		public virtual void RegisterService(String token, FileSystemService service) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			RegisterService(token, service, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void RegisterService(String token, FileSystemService service, BAsyncResult<Object> asyncResult) {
			BRequest_DispatcherService_registerService req = new BRequest_DispatcherService_registerService();			
			req.tokenValue = token;
			req.serviceValue = service;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task RegisterServiceAsync(String token, FileSystemService service){
			BRequest_DispatcherService_registerService req = new BRequest_DispatcherService_registerService();			
			req.tokenValue = token;
			req.serviceValue = service;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		public virtual void UnregisterService(String token) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			UnregisterService(token, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void UnregisterService(String token, BAsyncResult<Object> asyncResult) {
			BRequest_DispatcherService_unregisterService req = new BRequest_DispatcherService_unregisterService();			
			req.tokenValue = token;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task UnregisterServiceAsync(String token){
			BRequest_DispatcherService_unregisterService req = new BRequest_DispatcherService_unregisterService();			
			req.tokenValue = token;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		public virtual FileSystemService GetService(String token, bool onlyHere) {
			BSyncResult<FileSystemService> asyncResult = new BSyncResult<FileSystemService>();			
			GetService(token, onlyHere, BAsyncResultHelper.ToDelegate<FileSystemService>(asyncResult));
			return asyncResult.GetResult();			
		}
		public virtual void GetService(String token, bool onlyHere, BAsyncResult<FileSystemService> asyncResult) {
			BRequest_DispatcherService_getService req = new BRequest_DispatcherService_getService();			
			req.tokenValue = token;
			req.onlyHereValue = onlyHere;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task<FileSystemService> GetServiceAsync(String token, bool onlyHere){
			BRequest_DispatcherService_getService req = new BRequest_DispatcherService_getService();			
			req.tokenValue = token;
			req.onlyHereValue = onlyHere;
			Task<FileSystemService> task = Task<FileSystemService>.Factory.FromAsync(transport.BeginSend<FileSystemService>, transport.EndSend<FileSystemService>, req, null);
			return await task;
		}
		
		public virtual void RegisterNotifyService(String token, FileSystemNotify service) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			RegisterNotifyService(token, service, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void RegisterNotifyService(String token, FileSystemNotify service, BAsyncResult<Object> asyncResult) {
			BRequest_DispatcherService_registerNotifyService req = new BRequest_DispatcherService_registerNotifyService();			
			req.tokenValue = token;
			req.serviceValue = service;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task RegisterNotifyServiceAsync(String token, FileSystemNotify service){
			BRequest_DispatcherService_registerNotifyService req = new BRequest_DispatcherService_registerNotifyService();			
			req.tokenValue = token;
			req.serviceValue = service;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		public virtual void UnregisterNotifyService(String token) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			UnregisterNotifyService(token, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void UnregisterNotifyService(String token, BAsyncResult<Object> asyncResult) {
			BRequest_DispatcherService_unregisterNotifyService req = new BRequest_DispatcherService_unregisterNotifyService();			
			req.tokenValue = token;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task UnregisterNotifyServiceAsync(String token){
			BRequest_DispatcherService_unregisterNotifyService req = new BRequest_DispatcherService_unregisterNotifyService();			
			req.tokenValue = token;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		public virtual FileSystemNotify GetNotifyService(String token, bool onlyHere) {
			BSyncResult<FileSystemNotify> asyncResult = new BSyncResult<FileSystemNotify>();			
			GetNotifyService(token, onlyHere, BAsyncResultHelper.ToDelegate<FileSystemNotify>(asyncResult));
			return asyncResult.GetResult();			
		}
		public virtual void GetNotifyService(String token, bool onlyHere, BAsyncResult<FileSystemNotify> asyncResult) {
			BRequest_DispatcherService_getNotifyService req = new BRequest_DispatcherService_getNotifyService();			
			req.tokenValue = token;
			req.onlyHereValue = onlyHere;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task<FileSystemNotify> GetNotifyServiceAsync(String token, bool onlyHere){
			BRequest_DispatcherService_getNotifyService req = new BRequest_DispatcherService_getNotifyService();			
			req.tokenValue = token;
			req.onlyHereValue = onlyHere;
			Task<FileSystemNotify> task = Task<FileSystemNotify>.Factory.FromAsync(transport.BeginSend<FileSystemNotify>, transport.EndSend<FileSystemNotify>, req, null);
			return await task;
		}
		
		public virtual void KeepAlive(String token) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			KeepAlive(token, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void KeepAlive(String token, BAsyncResult<Object> asyncResult) {
			BRequest_DispatcherService_keepAlive req = new BRequest_DispatcherService_keepAlive();			
			req.tokenValue = token;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task KeepAliveAsync(String token){
			BRequest_DispatcherService_keepAlive req = new BRequest_DispatcherService_keepAlive();			
			req.tokenValue = token;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		
	}
}
