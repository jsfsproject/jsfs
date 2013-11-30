//
// Serializer for com.wilutions.jsfs.BResult_336045129
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1815527676 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1815527676();
		
		public BSerializer_1815527676()
			: base(1815527676) {}
		
		public BSerializer_1815527676(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BResult_336045129 obj = (BResult_336045129)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.resultValue, false, null);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BResult_336045129 obj = (BResult_336045129)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_336045129()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.resultValue = (com.wilutions.jsfs.FileSystemService)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
