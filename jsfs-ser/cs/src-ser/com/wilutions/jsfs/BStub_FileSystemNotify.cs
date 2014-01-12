using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BStub_FileSystemNotify : BStub, FileSystemNotify, BSerializable {	
		
		public readonly static long serialVersionUID = 544795964L;
		
		public BStub_FileSystemNotify(BTransport transport)
			: base(transport) {}			
		
		public virtual void Notify(NotifyInfo notifyInfo) {
			BSyncResult<Object> asyncResult = new BSyncResult<Object>();			
			Notify(notifyInfo, BAsyncResultHelper.ToDelegate<Object>(asyncResult));
			asyncResult.GetResult();			
		}
		public virtual void Notify(NotifyInfo notifyInfo, BAsyncResult<Object> asyncResult) {
			BRequest_FileSystemNotify_notify req = new BRequest_FileSystemNotify_notify();			
			req.notifyInfoValue = notifyInfo;
			transport.sendMethod(req, asyncResult);
		}
		// checkpoint byps.gen.cs.GenRemoteStub:133
		public async Task NotifyAsync(NotifyInfo notifyInfo){
			BRequest_FileSystemNotify_notify req = new BRequest_FileSystemNotify_notify();			
			req.notifyInfoValue = notifyInfo;
			Task<Object> task = Task<Object>.Factory.FromAsync(transport.BeginSend<Object>, transport.EndSend<Object>, req, null);
			await task;
		}
		
		
	}
}
