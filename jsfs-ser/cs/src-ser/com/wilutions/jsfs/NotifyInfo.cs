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
	/// Base class for notifications.
	/// </summary>
	public class NotifyInfo : BSerializable
	{
	
		#region Constructors
		
		public NotifyInfo() {
		}		
		
		public NotifyInfo(int @id, String @extraInfo, String @error) {
			this.idValue = @id;
			this.extraInfoValue = @extraInfo;
			this.errorValue = @error;
		}		
		
		public NotifyInfo(NotifyInfo rhs)
		{
			this.idValue = rhs.idValue;
			this.extraInfoValue = rhs.extraInfoValue;
			this.errorValue = rhs.errorValue;
		}		
		
		#endregion
		
		#region Properties
		
		/// <summary>
		/// Unused.
		/// </summary>
		public int Id
		{
			get
			{
				return idValue;
			}
			set
			{
				this.idValue = value;
			}
		}
		
		
		/// <summary>
		/// Application defined value.
		/// </summary>
		public String ExtraInfo
		{
			get
			{
				return extraInfoValue;
			}
			set
			{
				this.extraInfoValue = value;
			}
		}
		
		
		/// <summary>
		/// Error message.
		/// </summary>
		public String Error
		{
			get
			{
				return errorValue;
			}
			set
			{
				this.errorValue = value;
			}
		}
		
		
		#endregion
		
		#region Fields
		
		protected int idValue;

		protected String extraInfoValue;

		protected String errorValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 1274131736L;		
	} // end class
}  // end namespace
