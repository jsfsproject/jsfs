//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_findFiles
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1131301080 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1131301080();
		
		public BSerializer_1131301080()
			: base(1131301080) {}
		
		public BSerializer_1131301080(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemService_findFiles obj = (BRequest_FileSystemService_findFiles)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.pathValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.findOptionsValue, false, null);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemService_findFiles obj = (BRequest_FileSystemService_findFiles)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemService_findFiles()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.pathValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.findOptionsValue = (com.wilutions.jsfs.FindOptions)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
