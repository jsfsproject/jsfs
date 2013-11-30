//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	/// <summary>
	/// Notification information about a change in a watched folder.
	/// </summary>
	public class WatchFolderNotifyInfo : NotifyInfo, BSerializable
	{
	
		#region Constructors
		
		public WatchFolderNotifyInfo() {
		}		
		
		public WatchFolderNotifyInfo(FileInfo @fileInfo, EWatchFolderNotifyKind @kind) {
			this.fileInfoValue = @fileInfo;
			this.kindValue = @kind;
		}		
		
		public WatchFolderNotifyInfo(WatchFolderNotifyInfo rhs) : base(rhs)
		{
			this.fileInfoValue = rhs.fileInfoValue;
			this.kindValue = rhs.kindValue;
		}		
		
		#endregion
		
		#region Properties
		
		/// <summary>
		/// Information about the related file.
		/// </summary>
		public FileInfo FileInfo
		{
			get
			{
				return fileInfoValue;
			}
			set
			{
				this.fileInfoValue = value;
			}
		}
		
		
		/// <summary>
		/// Kind of change.
		/// </summary>
		public EWatchFolderNotifyKind Kind
		{
			get
			{
				return kindValue;
			}
			set
			{
				this.kindValue = value;
			}
		}
		
		
		#endregion
		
		#region Fields
		
		protected FileInfo fileInfoValue;

		protected EWatchFolderNotifyKind kindValue;

		#endregion
		
		
		public static readonly new long serialVersionUID = 9906860L;		
	} // end class
}  // end namespace
