//
// Serializer for com.wilutions.jsfs.BStub_FileSystemNotify
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1816639285 : BSerializer_16 {
		
		public readonly static BSerializer instance = new BSerializer_1816639285();
		
		public BSerializer_1816639285()
			: base(1816639285) {}
		
		protected override BRemote internalCreate(BTransport transport) {
			return new BStub_FileSystemNotify(transport);
		}
		
	}
} // namespace
