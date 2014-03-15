//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public sealed class BRequest_FileSystemService_uploadFilesMultipartFormdata : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 145996442; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:406
			try {
				FileSystemService __byps__remoteT = (FileSystemService)__byps__remote;				
				BAsyncResultSendMethod<Object> __byps__outerResult = new BAsyncResultSendMethod<Object>(__byps__asyncResult, new BResult_19());				
				__byps__remoteT.UploadFilesMultipartFormdata(itemsValue, urlValue, methodValue, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(null, e);
				throw e;
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal FormItem[] itemsValue;

		internal String urlValue;

		internal String methodValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 240503306L;		
	} // end class
}  // end namespace
