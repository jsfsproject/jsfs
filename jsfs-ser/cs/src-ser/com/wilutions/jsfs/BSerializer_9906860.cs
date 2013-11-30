//
// Serializer for com.wilutions.jsfs.WatchFolderNotifyInfo
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_9906860 : com.wilutions.jsfs.BSerializer_1274131736 {
		
		public readonly static new BSerializer instance = new BSerializer_9906860();
		
		public BSerializer_9906860()
			: base(9906860) {}
		
		public BSerializer_9906860(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			base.write(obj1, bout1, version);			
			WatchFolderNotifyInfo obj = (WatchFolderNotifyInfo)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putInt((int)obj.Kind);
			// checkpoint byps.gen.cs.PrintContext:494
			bout.writeObj(obj.FileInfo, false, null);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			WatchFolderNotifyInfo obj = (WatchFolderNotifyInfo)(obj1 != null ? obj1 : bin.onObjectCreated(new WatchFolderNotifyInfo()));
			
			base.read(obj, bin1, version);			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Kind = (com.wilutions.jsfs.EWatchFolderNotifyKind)bbuf.getInt();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.FileInfo = (com.wilutions.jsfs.FileInfo)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
