//
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_unregisterService
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1542825705 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1542825705();
		
		public BSerializer_1542825705()
			: base(1542825705) {}
		
		public BSerializer_1542825705(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_DispatcherService_unregisterService obj = (BRequest_DispatcherService_unregisterService)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.tokenValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_DispatcherService_unregisterService obj = (BRequest_DispatcherService_unregisterService)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_DispatcherService_unregisterService()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.tokenValue = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
