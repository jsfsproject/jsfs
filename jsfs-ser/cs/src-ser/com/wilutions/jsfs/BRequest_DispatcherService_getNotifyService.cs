//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public sealed class BRequest_DispatcherService_getNotifyService : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 1153231042; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:406
			try {
				DispatcherService __byps__remoteT = (DispatcherService)__byps__remote;				
				BAsyncResultSendMethod<FileSystemNotify> __byps__outerResult = new BAsyncResultSendMethod<FileSystemNotify>(__byps__asyncResult, new BResult_1816639285());				
				__byps__remoteT.GetNotifyService(tokenValue, onlyHereValue, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(null, e);
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal String tokenValue;

		internal bool onlyHereValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 1090607752L;		
	} // end class
}  // end namespace
