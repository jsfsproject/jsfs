//
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_registerNotifyService
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1849102471 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1849102471();
		
		public BSerializer_1849102471()
			: base(1849102471) {}
		
		public BSerializer_1849102471(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_DispatcherService_registerNotifyService obj = (BRequest_DispatcherService_registerNotifyService)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.tokenValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.serviceValue, false, null);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_DispatcherService_registerNotifyService obj = (BRequest_DispatcherService_registerNotifyService)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_DispatcherService_registerNotifyService()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.tokenValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.serviceValue = (com.wilutions.jsfs.FileSystemNotify)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
