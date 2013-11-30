//
// Serializer for java.util.List<com.wilutions.jsfs.FileInfo>
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BSerializer_1439246415 : BSerializer_12 {
		
		public readonly static new BSerializer instance = new BSerializer_1439246415();
		
		public BSerializer_1439246415() 
			: base(1439246415) {}
		
		public override Object read(object obj1, BInput bin1, long version) {
			BInputBin bin = ((BInputBin)bin1);
			BBufferBin bbuf = bin.bbuf;
			int n = bbuf.getLength();
			List<com.wilutions.jsfs.FileInfo> arr = new List<com.wilutions.jsfs.FileInfo>(n);
			bin.onObjectCreated(arr);
			for (int i = 0; i < n; i++) {
				com.wilutions.jsfs.FileInfo obj = (com.wilutions.jsfs.FileInfo)bin.readObj(false, null);
				arr.Add(obj);
			}
			return arr;
		}
		
		public override void write(Object obj1, BOutput bout1, long version)  {
			BOutputBin bout = ((BOutputBin)bout1);
			BBufferBin bbuf = bout.bbuf;
			IList<com.wilutions.jsfs.FileInfo> arr = (IList<com.wilutions.jsfs.FileInfo>)obj1;
			int n = arr.Count;
			bout.bbuf.putLength(n);
			foreach (com.wilutions.jsfs.FileInfo obj in arr) {
				bout.writeObj(obj, false, null);
			}
		}
		
	}
} // namespace
