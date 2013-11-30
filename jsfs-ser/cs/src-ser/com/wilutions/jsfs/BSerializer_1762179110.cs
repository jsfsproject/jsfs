//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_beginWatchFolder
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1762179110 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1762179110();
		
		public BSerializer_1762179110()
			: base(1762179110) {}
		
		public BSerializer_1762179110(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemService_beginWatchFolder obj = (BRequest_FileSystemService_beginWatchFolder)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.dirValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.extraInfoValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putBoolean(obj.recursiveValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemService_beginWatchFolder obj = (BRequest_FileSystemService_beginWatchFolder)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemService_beginWatchFolder()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.dirValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.extraInfoValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.recursiveValue = bbuf.getBoolean();
			
			return obj;
		}
		
	}
} // namespace
