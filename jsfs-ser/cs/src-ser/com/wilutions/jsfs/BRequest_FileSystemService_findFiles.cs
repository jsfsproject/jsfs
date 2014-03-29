//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public sealed class BRequest_FileSystemService_findFiles : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 145996442; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:406
			try {
				FileSystemService __byps__remoteT = (FileSystemService)__byps__remote;				
				BAsyncResultSendMethod<IList<FileInfo>> __byps__outerResult = new BAsyncResultSendMethod<IList<FileInfo>>(__byps__asyncResult, new BResult_1439246415());				
				__byps__remoteT.FindFiles(pathValue, findOptionsValue, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(null, e);
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal String pathValue;

		internal FindOptions findOptionsValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 1131301080L;		
	} // end class
}  // end namespace
