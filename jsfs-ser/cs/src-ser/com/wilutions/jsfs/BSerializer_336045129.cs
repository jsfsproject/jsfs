//
// Serializer for com.wilutions.jsfs.BStub_FileSystemService
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_336045129 : BSerializer_16 {
		
		public readonly static BSerializer instance = new BSerializer_336045129();
		
		public BSerializer_336045129()
			: base(336045129) {}
		
		protected override BRemote internalCreate(BTransport transport) {
			return new BStub_FileSystemService(transport);
		}
		
	}
} // namespace
