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
	/// This class contains additional parameters for
	/// {@link FileSystemService#executeNotifyExit(String[], ExecuteOptions)}.
	/// </summary>
	public class ExecuteOptions : BSerializable
	{
	
		#region Constructors
		
		public ExecuteOptions() {
		}		
		
		public ExecuteOptions(String @extraInfo, String @standardInput, bool @captureOutput, bool @captureError) {
			this.extraInfoValue = @extraInfo;
			this.standardInputValue = @standardInput;
			this.captureOutputValue = @captureOutput;
			this.captureErrorValue = @captureError;
		}		
		
		public ExecuteOptions(ExecuteOptions rhs)
		{
			this.extraInfoValue = rhs.extraInfoValue;
			this.standardInputValue = rhs.standardInputValue;
			this.captureOutputValue = rhs.captureOutputValue;
			this.captureErrorValue = rhs.captureErrorValue;
		}		
		
		#endregion
		
		#region Properties
		
		/// <summary>
		/// Application defined field.
		/// </summary>
		/// <remarks>
		/// This value is passed to the field {@link NotifyInfo#extraInfo}.
		/// </remarks>
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
		/// Send this text to the standard input pipe of the process.
		/// </summary>
		public String StandardInput
		{
			get
			{
				return standardInputValue;
			}
			set
			{
				this.standardInputValue = value;
			}
		}
		
		
		/// <summary>
		/// Read characters from the processes standard output pipe.
		/// </summary>
		public bool CaptureOutput
		{
			get
			{
				return captureOutputValue;
			}
			set
			{
				this.captureOutputValue = value;
			}
		}
		
		
		/// <summary>
		/// Read characters from  the processes standard error pipe.
		/// </summary>
		public bool CaptureError
		{
			get
			{
				return captureErrorValue;
			}
			set
			{
				this.captureErrorValue = value;
			}
		}
		
		
		#endregion
		
		#region Fields
		
		protected String extraInfoValue;

		protected String standardInputValue;

		protected bool captureOutputValue;

		protected bool captureErrorValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 1032737639L;		
	} // end class
}  // end namespace
