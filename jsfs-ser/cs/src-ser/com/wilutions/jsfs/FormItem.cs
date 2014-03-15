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
	/// This class defines an item of a file upload request in {@link FileSystemService#uploadFilesMultipartFormdata}.
	/// </summary>
	/// <remarks>
	/// A FormData object corresponds to an input field in a HTML file upload form.
	/// It can specify a file to be uploaded as with HTML input field type "file".
	/// Or it can hold a simple value as with HTML input field type "text".
	/// </remarks>
	public class FormItem : BSerializable
	{
	
		#region Constructors
		
		public FormItem() {
		}		
		
		public FormItem(String @name, String @type, String @value) {
			this.nameValue = @name;
			this.typeValue = @type;
			this.valueValue = @value;
		}		
		
		public FormItem(FormItem rhs)
		{
			this.nameValue = rhs.nameValue;
			this.typeValue = rhs.typeValue;
			this.valueValue = rhs.valueValue;
		}		
		
		#endregion
		
		#region Properties
		
		/// <summary>
		/// Item name.
		/// </summary>
		/// <remarks>
		/// This value corresponds to HTML input field name.
		/// </remarks>
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
		/// Item type.
		/// </summary>
		/// <remarks>
		/// Optional. Either "text" or "file".
		/// </remarks>
		public String Type
		{
			get
			{
				return typeValue;
			}
			set
			{
				this.typeValue = value;
			}
		}
		
		
		/// <summary>
		/// Item value.
		/// </summary>
		/// <remarks>
		/// If type is empty or equals to "text", this member holds an input field value.
		/// If type equals to "file", this member contains the file path to be uploaded.
		/// </remarks>
		public String Value
		{
			get
			{
				return valueValue;
			}
			set
			{
				this.valueValue = value;
			}
		}
		
		
		#endregion
		
		#region Fields
		
		protected String nameValue;

		protected String typeValue;

		protected String valueValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 979378962L;		
	} // end class
}  // end namespace
