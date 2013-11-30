//
// Serializer for com.wilutions.jsfs.FindOptions
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1092766252 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1092766252();
		
		public BSerializer_1092766252()
			: base(1092766252) {}
		
		public BSerializer_1092766252(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			FindOptions obj = (FindOptions)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.Reserved);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			FindOptions obj = (FindOptions)(obj1 != null ? obj1 : bin.onObjectCreated(new FindOptions()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Reserved = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
