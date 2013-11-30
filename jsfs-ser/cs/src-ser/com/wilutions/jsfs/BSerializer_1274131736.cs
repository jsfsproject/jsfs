//
// Serializer for com.wilutions.jsfs.NotifyInfo
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1274131736 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1274131736();
		
		public BSerializer_1274131736()
			: base(1274131736) {}
		
		public BSerializer_1274131736(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			NotifyInfo obj = (NotifyInfo)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.Error);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.ExtraInfo);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putInt(obj.Id);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			NotifyInfo obj = (NotifyInfo)(obj1 != null ? obj1 : bin.onObjectCreated(new NotifyInfo()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Error = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.ExtraInfo = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Id = bbuf.getInt();
			
			return obj;
		}
		
	}
} // namespace
