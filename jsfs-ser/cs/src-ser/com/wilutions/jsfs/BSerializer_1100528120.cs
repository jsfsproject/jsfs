//
// Serializer for com.wilutions.jsfs.FileInfo
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1100528120 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1100528120();
		
		public BSerializer_1100528120()
			: base(1100528120) {}
		
		public BSerializer_1100528120(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			FileInfo obj = (FileInfo)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putBoolean(obj.Directory);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putDate(obj.LastModified);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putString(obj.Name);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putBoolean(obj.Readonly);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putInt(obj.Size);
			// checkpoint byps.gen.cs.PrintContext:494
			bbuf.putLong(obj.SizeL);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			FileInfo obj = (FileInfo)(obj1 != null ? obj1 : bin.onObjectCreated(new FileInfo()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Directory = bbuf.getBoolean();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.LastModified = bbuf.getDate();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Name = bbuf.getString();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Readonly = bbuf.getBoolean();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.Size = bbuf.getInt();
			// checkpoint byps.gen.cs.PrintContext:449
			obj.SizeL = bbuf.getLong();
			
			return obj;
		}
		
	}
} // namespace
