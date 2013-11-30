package com.wilutions.jsfs;

/**
 * Kinds of changes in a watched folder.
 */
public enum EWatchFolderNotifyKind {
  /**
   * Nothing changed.
   */
  Nothing,
  /**
   * New file or directory has been created.
   */
  EntryCreated,
  /**
   * File or directory attributes have been modified.
   */
  EntryModified,
  /**
   * File or directory has been deleted.
   */
  EntryDeleted
}
