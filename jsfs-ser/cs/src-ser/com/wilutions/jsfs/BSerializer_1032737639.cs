//
// Serializer for com.wilutions.jsfs.ExecuteOptions
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1032737639 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1032737639();
		
		public BSerializer_1032737639()
			: base(1032737639) {}
		
		public BSerializer_1032737639(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			ExecuteOptions obj = (ExecuteOptions)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putBoolean(obj.CaptureError);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putBoolean(obj.CaptureOutput);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.ExtraInfo);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.StandardInput);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			ExecuteOptions obj = (ExecuteOptions)(obj1 != null ? obj1 : bin.onObjectCreated(new ExecuteOptions()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.CaptureError = bbuf.getBoolean();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.CaptureOutput = bbuf.getBoolean();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.ExtraInfo = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.StandardInput = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
