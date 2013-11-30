//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public sealed class BRequest_FileSystemNotify_notify : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 1816639285; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:406
			try {
				FileSystemNotify __byps__remoteT = (FileSystemNotify)__byps__remote;				
				BAsyncResultSendMethod<Object> __byps__outerResult = new BAsyncResultSendMethod<Object>(__byps__asyncResult, new BResult_19());				
				__byps__remoteT.Notify(notifyInfoValue, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(null, e);
				throw e;
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal NotifyInfo notifyInfoValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 481066845L;		
	} // end class
}  // end namespace
