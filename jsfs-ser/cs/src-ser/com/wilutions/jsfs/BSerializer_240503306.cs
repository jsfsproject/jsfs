//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_uploadFilesMultipartFormdata
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_240503306 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_240503306();
		
		public BSerializer_240503306()
			: base(240503306) {}
		
		public BSerializer_240503306(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemService_uploadFilesMultipartFormdata obj = (BRequest_FileSystemService_uploadFilesMultipartFormdata)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.methodValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.urlValue);
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.itemsValue, false, com.wilutions.jsfs.BSerializer_566696346.instance);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemService_uploadFilesMultipartFormdata obj = (BRequest_FileSystemService_uploadFilesMultipartFormdata)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemService_uploadFilesMultipartFormdata()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.methodValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.urlValue = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.itemsValue = (com.wilutions.jsfs.FormItem[])bin.readObj(false, com.wilutions.jsfs.BSerializer_566696346.instance);
			
			return obj;
		}
		
	}
} // namespace
