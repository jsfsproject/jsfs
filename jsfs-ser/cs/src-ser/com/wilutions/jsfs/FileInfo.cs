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
	/// This class contains information about a file or directory.
	/// </summary>
	public class FileInfo : BSerializable
	{
	
		#region Constructors
		
		public FileInfo() {
		}		
		
		public FileInfo(String @name, int @size, long @sizeL, bool @directory, bool @readonly, DateTime @lastModified) {
			this.nameValue = @name;
			this.sizeValue = @size;
			this.sizeLValue = @sizeL;
			this.directoryValue = @directory;
			this.readonlyValue = @readonly;
			this.lastModifiedValue = @lastModified;
		}		
		
		public FileInfo(FileInfo rhs)
		{
			this.nameValue = rhs.nameValue;
			this.sizeValue = rhs.sizeValue;
			this.sizeLValue = rhs.sizeLValue;
			this.directoryValue = rhs.directoryValue;
			this.readonlyValue = rhs.readonlyValue;
			this.lastModifiedValue = rhs.lastModifiedValue;
		}		
		
		#endregion
		
		#region Properties
		
		/// <summary>
		/// File name.
		/// </summary>
		public String Name
		{
			get
			{
				return nameValue;
			}
			set
			{
				this.nameValue = value;
			}
		}
		
		
		/// <summary>
		/// File size if less than 2^31.
		/// </summary>
		/// <remarks>
		/// This member is negative if the file size is greater than or equal to 2^31.
		/// </remarks>
		public int Size
		{
			get
			{
				return sizeValue;
			}
			set
			{
				this.sizeValue = value;
			}
		}
		
		
		/// <summary>
		/// File size.
		/// </summary>
		/// <remarks>
		/// (This member is a string value in JavaScript)
		/// </remarks>
		public long SizeL
		{
			get
			{
				return sizeLValue;
			}
			set
			{
				this.sizeLValue = value;
			}
		}
		
		
		/// <summary>
		/// True for directory.
		/// </summary>
		public bool Directory
		{
			get
			{
				return directoryValue;
			}
			set
			{
				this.directoryValue = value;
			}
		}
		
		
		/// <summary>
		/// True for read-only file.
		/// </summary>
		public bool Readonly
		{
			get
			{
				return readonlyValue;
			}
			set
			{
				this.readonlyValue = value;
			}
		}
		
		
		/// <summary>
		/// Last modified date.
		/// </summary>
		public DateTime LastModified
		{
			get
			{
				return lastModifiedValue;
			}
			set
			{
				this.lastModifiedValue = value;
			}
		}
		
		
		#endregion
		
		#region Fields
		
		protected String nameValue;

		protected int sizeValue;

		protected long sizeLValue;

		protected bool directoryValue;

		protected bool readonlyValue;

		protected DateTime lastModifiedValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 1100528120L;		
	} // end class
}  // end namespace
