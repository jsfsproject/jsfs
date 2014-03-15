//
// Serializer for com.wilutions.jsfs.FormItem
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_979378962 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_979378962();
		
		public BSerializer_979378962()
			: base(979378962) {}
		
		public BSerializer_979378962(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			FormItem obj = (FormItem)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.Name);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.Type);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.Value);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			FormItem obj = (FormItem)(obj1 != null ? obj1 : bin.onObjectCreated(new FormItem()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Name = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Type = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Value = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
