//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_writeAllText
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1925305675 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1925305675();
		
		public BSerializer_1925305675()
			: base(1925305675) {}
		
		public BSerializer_1925305675(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemService_writeAllText obj = (BRequest_FileSystemService_writeAllText)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.pathValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.textValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemService_writeAllText obj = (BRequest_FileSystemService_writeAllText)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemService_writeAllText()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.pathValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.textValue = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
