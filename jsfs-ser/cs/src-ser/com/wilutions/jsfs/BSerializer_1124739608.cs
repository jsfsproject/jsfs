//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_endWatchFolder
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1124739608 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1124739608();
		
		public BSerializer_1124739608()
			: base(1124739608) {}
		
		public BSerializer_1124739608(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemService_endWatchFolder obj = (BRequest_FileSystemService_endWatchFolder)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putInt(obj.handleValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemService_endWatchFolder obj = (BRequest_FileSystemService_endWatchFolder)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemService_endWatchFolder()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.handleValue = bbuf.getInt();
			
			return obj;
		}
		
	}
} // namespace
