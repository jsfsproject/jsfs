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
	/// This class contains notification information generated from
	/// {@link FileSystemService#executeNotifyExit(String[], ExecuteOptions)}.
	/// </summary>
	public class ExecuteNotifyInfo : NotifyInfo, BSerializable
	{
	
		#region Constructors
		
		public ExecuteNotifyInfo() {
		}		
		
		public ExecuteNotifyInfo(int @exitCode, String @standardOutput, String @standardError) {
			this.exitCodeValue = @exitCode;
			this.standardOutputValue = @standardOutput;
			this.standardErrorValue = @standardError;
		}		
		
		public ExecuteNotifyInfo(ExecuteNotifyInfo rhs) : base(rhs)
		{
			this.exitCodeValue = rhs.exitCodeValue;
			this.standardOutputValue = rhs.standardOutputValue;
			this.standardErrorValue = rhs.standardErrorValue;
		}		
		
		#endregion
		
		#region Properties
		
		/// <summary>
		/// Process exit code.
		/// </summary>
		public int ExitCode
		{
			get
			{
				return exitCodeValue;
			}
			set
			{
				this.exitCodeValue = value;
			}
		}
		
		
		/// <summary>
		/// Characters printed on stdout, if {@link ExecuteOptions#captureOutput} was
		/// set.
		/// </summary>
		public String StandardOutput
		{
			get
			{
				return standardOutputValue;
			}
			set
			{
				this.standardOutputValue = value;
			}
		}
		
		
		/// <summary>
		/// Characters printed on stderr, if {@link ExecuteOptions#captureError} was
		/// set.
		/// </summary>
		public String StandardError
		{
			get
			{
				return standardErrorValue;
			}
			set
			{
				this.standardErrorValue = value;
			}
		}
		
		
		#endregion
		
		#region Fields
		
		protected int exitCodeValue;

		protected String standardOutputValue;

		protected String standardErrorValue;

		#endregion
		
		
		public static readonly new long serialVersionUID = 665368294L;		
	} // end class
}  // end namespace
