//
// Serializer for com.wilutions.jsfs.BResult_1816639285
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1354059712 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1354059712();
		
		public BSerializer_1354059712()
			: base(1354059712) {}
		
		public BSerializer_1354059712(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BResult_1816639285 obj = (BResult_1816639285)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.resultValue, false, null);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BResult_1816639285 obj = (BResult_1816639285)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_1816639285()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.resultValue = (com.wilutions.jsfs.FileSystemNotify)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
