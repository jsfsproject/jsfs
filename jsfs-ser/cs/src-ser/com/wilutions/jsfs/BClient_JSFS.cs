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
		
		public virtual BClient_JSFS addRemote(BSkeleton_FileSystemNotify remoteSkeleton) {
			if (serverR == null) throw new BException(BExceptionC.NO_REVERSE_CONNECTIONS, "No reverse connections.");
			serverR.server.addRemote(544795964, remoteSkeleton);
			return this;
		}
		
		public virtual BClient_JSFS addRemote(BSkeleton_FileSystemService remoteSkeleton) {
			if (serverR == null) throw new BException(BExceptionC.NO_REVERSE_CONNECTIONS, "No reverse connections.");
			serverR.server.addRemote(145996442, remoteSkeleton);
			return this;
		}
		
		public virtual DispatcherService DispatcherService
		{
			get { return dispatcherServiceVal; }
		}
		public virtual FileSystemNotify FileSystemNotify
		{
			get { return fileSystemNotifyVal; }
		}
		public virtual FileSystemService FileSystemService
		{
			get { return fileSystemServiceVal; }
		}
		
		public override BRemote getStub(int remoteId) {
			if (remoteId == 1153231042) return dispatcherServiceVal;
			if (remoteId == 544795964) return fileSystemNotifyVal;
			if (remoteId == 145996442) return fileSystemServiceVal;
			return null;
		}
		
		protected BClient_JSFS(BTransportFactory transportFactory)
			: base(
				transportFactory.createClientTransport(), 
				transportFactory.createServerR(
					BServer_JSFS.createServerR(transportFactory.createServerTransport())
				)
			)
		{
			initStubs(transportVal);
		}
		
		protected BClient_JSFS(BTransport transport) 
			: base(transport, null)
		{
			initStubs(transportVal);
		}
		
		protected DispatcherService dispatcherServiceVal;
		protected FileSystemNotify fileSystemNotifyVal;
		protected FileSystemService fileSystemServiceVal;
		
		private void initStubs(BTransport transport) {
			dispatcherServiceVal = new BStub_DispatcherService(transport);
			fileSystemNotifyVal = new BStub_FileSystemNotify(transport);
			fileSystemServiceVal = new BStub_FileSystemService(transport);
		}
		
	}
}
