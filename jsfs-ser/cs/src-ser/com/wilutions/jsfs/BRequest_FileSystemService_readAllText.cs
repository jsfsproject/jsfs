//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public sealed class BRequest_FileSystemService_readAllText : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 145996442; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:406
			try {
				FileSystemService __byps__remoteT = (FileSystemService)__byps__remote;				
				BAsyncResultSendMethod<String> __byps__outerResult = new BAsyncResultSendMethod<String>(__byps__asyncResult, new BResult_10());				
				__byps__remoteT.ReadAllText(pathValue, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult("", e);
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal String pathValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 1078989294L;		
	} // end class
}  // end namespace
