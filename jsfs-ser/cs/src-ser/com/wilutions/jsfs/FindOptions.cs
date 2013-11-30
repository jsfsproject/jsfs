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
	/// Unused.
	/// </summary>
	public class FindOptions : BSerializable
	{
	
		#region Constructors
		
		public FindOptions() {
		}		
		
		public FindOptions(String @reserved) {
			this.reservedValue = @reserved;
		}		
		
		public FindOptions(FindOptions rhs)
		{
			this.reservedValue = rhs.reservedValue;
		}		
		
		#endregion
		
		#region Properties
		
		public String Reserved
		{
			get
			{
				return reservedValue;
			}
			set
			{
				this.reservedValue = value;
			}
		}
		
		
		#endregion
		
		#region Fields
		
		protected String reservedValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 1092766252L;		
	} // end class
}  // end namespace
