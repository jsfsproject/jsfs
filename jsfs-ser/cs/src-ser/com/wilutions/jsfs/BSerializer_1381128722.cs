//
// Serializer for com.wilutions.jsfs.FileSystemServiceC
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1381128722 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1381128722();
		
		public BSerializer_1381128722()
			: base(1381128722) {}
		
		public BSerializer_1381128722(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			FileSystemServiceC obj = (FileSystemServiceC)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			FileSystemServiceC obj = (FileSystemServiceC)(obj1 != null ? obj1 : bin.onObjectCreated(new FileSystemServiceC()));
			
			BBufferBin bbuf = bin.bbuf;
			
			return obj;
		}
		
	}
} // namespace
