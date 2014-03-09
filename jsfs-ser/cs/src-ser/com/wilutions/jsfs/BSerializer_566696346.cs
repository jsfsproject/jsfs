//
// Serializer for com.wilutions.jsfs.FormItem[]
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_566696346 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_566696346();
		
		public BSerializer_566696346() : 
			base(566696346) {}
		
		public override Object read(Object obj1, BInput bin1, long version) {
			BInputBin bin = (BInputBin)bin1;
			BBufferBin bbuf = bin.bbuf;
			
			// lengths
			int n0 = bbuf.getLength();
			
			// create array
			FormItem[] arr =  new com.wilutions.jsfs.FormItem[n0];
			
			// read
			for (int i0 = 0; i0 < n0; i0++) {
				arr[i0] = (com.wilutions.jsfs.FormItem)bin.readObj(false, null);
			}
			
			return arr;
		}
		
		public override void write(Object obj1, BOutput bout1, long version) {
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			
			FormItem[] arr = (FormItem[])obj1;
			
			// lengths
			int n0 = arr.GetLength(0);
			bbuf.putLength(n0);
			
			// write
			for (int i0 = 0; i0 < n0; i0++) {
				bout.writeObj(arr[i0], false, null);
			}
		}
		
	}
} // namespace
