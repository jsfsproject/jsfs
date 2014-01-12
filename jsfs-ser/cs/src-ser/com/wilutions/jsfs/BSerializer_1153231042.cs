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
	
	public class BSerializer_1153231042 : BSerializer_16 {
		
		public readonly static BSerializer instance = new BSerializer_1153231042();
		
		public BSerializer_1153231042()
			: base(1153231042) {}
		
		protected override BRemote internalCreate(BTransport transport) {
			return new BStub_DispatcherService(transport);
		}
		
	}
} // namespace
