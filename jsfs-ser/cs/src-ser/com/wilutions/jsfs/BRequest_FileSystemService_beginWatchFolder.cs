//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public sealed class BRequest_FileSystemService_beginWatchFolder : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 336045129; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:406
			try {
				FileSystemService __byps__remoteT = (FileSystemService)__byps__remote;				
				BAsyncResultSendMethod<int> __byps__outerResult = new BAsyncResultSendMethod<int>(__byps__asyncResult, new BResult_5());				
				__byps__remoteT.BeginWatchFolder(dirValue, recursiveValue, extraInfoValue, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(0, e);
				throw e;
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal String dirValue;

		internal bool recursiveValue;

		internal String extraInfoValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 1762179110L;		
	} // end class
}  // end namespace
