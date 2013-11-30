using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using byps;

namespace com.wilutions.jsfs
{
	
	/// <summary>
	/// Notification interface.
	/// </summary>
	/// <remarks>
	/// This interface is used by the JFSF Agent to notify the browser about an event.
	/// </remarks>
	// checkpoint byps.gen.cs.GenRemoteClass:93
	public interface FileSystemNotify : BRemote {
	
		/// <summary>
		/// Notify the browser about an event.
		/// </summary>
		void Notify(NotifyInfo notifyInfo);
		void Notify(NotifyInfo notifyInfo, BAsyncResult<Object> asyncResult) ;
		/// <summary>
		/// Notify the browser about an event.
		/// </summary>
		Task NotifyAsync(NotifyInfo notifyInfo);
		
		
	}
}  // end namespace
