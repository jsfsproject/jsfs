using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BApiDescriptor_JSFS { 
	
		/**
		 * API serialisation version: 1.0.0.1
		 */
		public const long VERSION = 100000000000001L;
		
		public readonly static BApiDescriptor instance = new BApiDescriptor(
			"JSFS",
			"com.wilutions.jsfs",
			VERSION,
			false) // uniqueObjects
			.addRegistry(new BRegistry_JSFS());
		
		
	}
}
