//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_readFile
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_706034600 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_706034600();
		
		public BSerializer_706034600()
			: base(706034600) {}
		
		public BSerializer_706034600(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemService_readFile obj = (BRequest_FileSystemService_readFile)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.pathValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemService_readFile obj = (BRequest_FileSystemService_readFile)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemService_readFile()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.pathValue = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
