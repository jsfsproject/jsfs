//
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_getService
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_575037953 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_575037953();
		
		public BSerializer_575037953()
			: base(575037953) {}
		
		public BSerializer_575037953(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_DispatcherService_getService obj = (BRequest_DispatcherService_getService)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putBoolean(obj.onlyHereValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.tokenValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_DispatcherService_getService obj = (BRequest_DispatcherService_getService)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_DispatcherService_getService()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.onlyHereValue = bbuf.getBoolean();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.tokenValue = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
