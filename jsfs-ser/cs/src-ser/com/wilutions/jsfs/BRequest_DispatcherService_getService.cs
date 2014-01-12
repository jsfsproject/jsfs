//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public sealed class BRequest_DispatcherService_getService : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 1153231042; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:406
			try {
				DispatcherService __byps__remoteT = (DispatcherService)__byps__remote;				
				BAsyncResultSendMethod<FileSystemService> __byps__outerResult = new BAsyncResultSendMethod<FileSystemService>(__byps__asyncResult, new BResult_336045129());				
				__byps__remoteT.GetService(tokenValue, onlyHereValue, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(null, e);
				throw e;
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal String tokenValue;

		internal bool onlyHereValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 575037953L;		
	} // end class
}  // end namespace
