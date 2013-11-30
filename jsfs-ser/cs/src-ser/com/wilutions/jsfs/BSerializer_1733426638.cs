//
// Serializer for com.wilutions.jsfs.BResult_1439246415
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1733426638 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1733426638();
		
		public BSerializer_1733426638()
			: base(1733426638) {}
		
		public BSerializer_1733426638(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BResult_1439246415 obj = (BResult_1439246415)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.resultValue, false, com.wilutions.jsfs.BSerializer_1439246415.instance);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BResult_1439246415 obj = (BResult_1439246415)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_1439246415()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.resultValue = (IList<com.wilutions.jsfs.FileInfo>)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
