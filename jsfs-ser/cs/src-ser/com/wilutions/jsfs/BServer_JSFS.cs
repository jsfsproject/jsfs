using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BServer_JSFS : BServer { 
	
		public static BServer_JSFS createServer(BTransportFactory transportFactory) {
			return new BServer_JSFS(transportFactory);
		}
		
		public static BServer_JSFS createServerR(BTransport transport) {
			return new BServer_JSFS(transport);
		}
		
		public BServer_JSFS(BTransport transport) 
			: base(transport, null)
		{
		}
		
		public BServer_JSFS(BTransportFactory transportFactory) 
			: base(
				transportFactory.createServerTransport(),
				transportFactory.createClientR(
					BClient_JSFS.createClientR(
						transportFactory.createClientTransport()
					)
				)
			)
		{
		}
		
		public BServer_JSFS addRemote(BSkeleton_FileSystemNotify remoteSkeleton) {
			addRemote(1816639285, remoteSkeleton);
			return this;
		}
		
		public BServer_JSFS addRemote(BSkeleton_FileSystemService remoteSkeleton) {
			addRemote(336045129, remoteSkeleton);
			return this;
		}
		
	}
}
