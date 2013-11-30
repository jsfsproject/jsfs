//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_executeNotifyExit
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1824869366 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1824869366();
		
		public BSerializer_1824869366()
			: base(1824869366) {}
		
		public BSerializer_1824869366(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemService_executeNotifyExit obj = (BRequest_FileSystemService_executeNotifyExit)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.argsValue, true, com.wilutions.jsfs.BSerializer_1888107655.instance);
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.optsValue, false, null);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemService_executeNotifyExit obj = (BRequest_FileSystemService_executeNotifyExit)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemService_executeNotifyExit()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.argsValue = (String[])bin.readObj(false, com.wilutions.jsfs.BSerializer_1888107655.instance);
			// checkpoint byps.gen.cs.PrintContext:449
			obj.optsValue = (com.wilutions.jsfs.ExecuteOptions)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
