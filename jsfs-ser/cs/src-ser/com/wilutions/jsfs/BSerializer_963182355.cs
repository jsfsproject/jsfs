//
// Serializer for com.wilutions.jsfs.BStub_DispatcherService
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_963182355 : BSerializer_16 {
		
		public readonly static BSerializer instance = new BSerializer_963182355();
		
		public BSerializer_963182355()
			: base(963182355) {}
		
		protected override BRemote internalCreate(BTransport transport) {
			return new BStub_DispatcherService(transport);
		}
		
	}
} // namespace
