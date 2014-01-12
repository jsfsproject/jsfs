using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using byps;

namespace com.wilutions.jsfs
{
	
	/// <summary>
	/// This class provides a skeleton implementation of the interface FileSystemNotify.
	/// </summary>
	/// <remark>
	/// Your interface implementation class has to be derived from this skeleton.
	/// Either provide an asynchronous or a synchronous function in your subclass.
	/// The framework calls only the asynchronous function.
	/// </remark>
	public class BSkeleton_FileSystemNotify : BSkeleton, FileSystemNotify {	
		
		public readonly static long serialVersionUID = 544795964L;
		
		public virtual void Notify(NotifyInfo notifyInfo) {
			throw new NotImplementedException();
		}
		public virtual async void Notify(NotifyInfo notifyInfo, BAsyncResult<Object> asyncResult) {
			Object __byps__ret = default(Object);
			Exception __byps__ex = null;
			bool __byps__callAsync = false;
			try {
				Notify(notifyInfo);
			}
			catch (NotImplementedException) { __byps__callAsync = true; }
			catch (Exception e) { __byps__ex = e; }
			if (__byps__callAsync) try {
				await NotifyAsync(notifyInfo);
			}
			catch (NotImplementedException) { __byps__ex = new BException(BExceptionC.UNSUPPORTED_METHOD, ""); }
			catch (Exception e) { __byps__ex = e; }
			asyncResult(__byps__ret, __byps__ex);
		}
		/// <summary>
		/// Notify the browser about an event.
		/// </summary>
		public virtual Task NotifyAsync(NotifyInfo notifyInfo){
			return BTaskConstants<Object>.NotImplemented;
		}
		
		
	}
}
