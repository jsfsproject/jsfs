//
// Serializer for com.wilutions.jsfs.BRequest_FileSystemNotify_notify
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_481066845 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_481066845();
		
		public BSerializer_481066845()
			: base(481066845) {}
		
		public BSerializer_481066845(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_FileSystemNotify_notify obj = (BRequest_FileSystemNotify_notify)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.notifyInfoValue, false, null);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_FileSystemNotify_notify obj = (BRequest_FileSystemNotify_notify)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_FileSystemNotify_notify()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.notifyInfoValue = (com.wilutions.jsfs.NotifyInfo)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
