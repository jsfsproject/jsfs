using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BClient_JSFS : BClient { 
	
		public static BClient_JSFS createClient(BTransportFactory transportFactory) {
			return new BClient_JSFS(transportFactory);
		}
		
		public static BClient_JSFS createClientR(BTransport transport) {
			return new BClient_JSFS(transport);
		}
		
		protected BClient_JSFS(BTransportFactory transportFactory)
			: base(
				transportFactory.createClientTransport(), 
				transportFactory.createServerR(
					BServer_JSFS.createServerR(transportFactory.createServerTransport())
				)
			)
		{
			DispatcherService = new BStub_DispatcherService(transport);
			FileSystemNotify = new BStub_FileSystemNotify(transport);
			FileSystemService = new BStub_FileSystemService(transport);
		}
		
		public BClient_JSFS addRemote(BSkeleton_FileSystemNotify remoteSkeleton) {
			if (serverR == null) throw new BException(BExceptionC.NO_REVERSE_CONNECTIONS, "No reverse connections.");
			serverR.server.addRemote(1816639285, remoteSkeleton);
			return this;
		}
		
		public BClient_JSFS addRemote(BSkeleton_FileSystemService remoteSkeleton) {
			if (serverR == null) throw new BException(BExceptionC.NO_REVERSE_CONNECTIONS, "No reverse connections.");
			serverR.server.addRemote(336045129, remoteSkeleton);
			return this;
		}
		
		protected BClient_JSFS(BTransport transport) 
			: base(transport, null)
		{
			DispatcherService = new BStub_DispatcherService(transport);
			FileSystemNotify = new BStub_FileSystemNotify(transport);
			FileSystemService = new BStub_FileSystemService(transport);
		}
		
		public override BRemote getStub(int remoteId) {
			if (remoteId == 963182355) return DispatcherService;
			if (remoteId == 1816639285) return FileSystemNotify;
			if (remoteId == 336045129) return FileSystemService;
			return null;
		}
		
		public readonly DispatcherService DispatcherService;
		public readonly FileSystemNotify FileSystemNotify;
		public readonly FileSystemService FileSystemService;
		
	}
}
