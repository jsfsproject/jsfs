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
	/// Kinds of changes in a watched folder.
	/// </summary>
	public enum EWatchFolderNotifyKind
	{
		/// <summary>
		/// Nothing changed.
		/// </summary>
		Nothing, // ordinal=0
		/// <summary>
		/// New file or directory has been created.
		/// </summary>
		EntryCreated, // ordinal=1
		/// <summary>
		/// File or directory attributes have been modified.
		/// </summary>
		EntryModified, // ordinal=2
		/// <summary>
		/// File or directory has been deleted.
		/// </summary>
		EntryDeleted, // ordinal=3
	}  // end enum
}  // end namespace
