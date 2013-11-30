//
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_keepAlive
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1609273478 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1609273478();
		
		public BSerializer_1609273478()
			: base(1609273478) {}
		
		public BSerializer_1609273478(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_DispatcherService_keepAlive obj = (BRequest_DispatcherService_keepAlive)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.tokenValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_DispatcherService_keepAlive obj = (BRequest_DispatcherService_keepAlive)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_DispatcherService_keepAlive()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.tokenValue = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
