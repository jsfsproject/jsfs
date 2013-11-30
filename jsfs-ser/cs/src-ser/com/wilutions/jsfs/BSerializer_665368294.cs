//
// Serializer for com.wilutions.jsfs.ExecuteNotifyInfo
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_665368294 : com.wilutions.jsfs.BSerializer_1274131736 {
		
		public readonly static new BSerializer instance = new BSerializer_665368294();
		
		public BSerializer_665368294()
			: base(665368294) {}
		
		public BSerializer_665368294(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			base.write(obj1, bout1, version);			
			ExecuteNotifyInfo obj = (ExecuteNotifyInfo)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putInt(obj.ExitCode);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.StandardError);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.StandardOutput);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			ExecuteNotifyInfo obj = (ExecuteNotifyInfo)(obj1 != null ? obj1 : bin.onObjectCreated(new ExecuteNotifyInfo()));
			
			base.read(obj, bin1, version);			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.ExitCode = bbuf.getInt();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.StandardError = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.StandardOutput = bbuf.getString();
			
			return obj;
		}
		
	}
} // namespace
