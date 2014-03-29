//
// Serializer for byte[]
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1374008726 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1374008726();
		
		public BSerializer_1374008726() : 
			base(1374008726) {}
		
		public override Object read(Object obj1, BInput bin1, long version) {
			BInputBin bin = (BInputBin)bin1;
			BBufferBin bbuf = bin.bbuf;
			
			// lengths
			int n0 = bbuf.getLength();
			
			// create array
			byte[] arr =  new byte[n0];
			
			// read
			bbuf.getArrayByte(arr);
			
			return arr;
		}
		
		public override void write(Object obj1, BOutput bout1, long version) {
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			
			byte[] arr = (byte[])obj1;
			
			// lengths
			int n0 = arr.GetLength(0);
			bbuf.putLength(n0);
			
			// write
			bbuf.putArrayByte(arr);
		}
		
	}
} // namespace
