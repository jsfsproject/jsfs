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
	
	public class BSerializer_544795964 : BSerializer_16 {
		
		public readonly static BSerializer instance = new BSerializer_544795964();
		
		public BSerializer_544795964()
			: base(544795964) {}
		
		protected override BRemote internalCreate(BTransport transport) {
			return new BStub_FileSystemNotify(transport);
		}
		
	}
} // namespace
