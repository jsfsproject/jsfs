//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_uploadFile
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_744806851 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_744806851();
		
		public BSerializer_744806851()
			: base(744806851) {}
		
		public BSerializer_744806851(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemService_uploadFile obj = (BRequest_FileSystemService_uploadFile)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.methodValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.pathValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.urlValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemService_uploadFile obj = (BRequest_FileSystemService_uploadFile)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemService_uploadFile()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.methodValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.pathValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.urlValue = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
