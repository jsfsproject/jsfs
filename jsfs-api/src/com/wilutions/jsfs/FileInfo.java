/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
package com.wilutions.jsfs;

import java.io.Serializable;
import java.util.Date;

/**
 * This class contains information about a file or directory.
 */
public class FileInfo implements Serializable {

	private static final long serialVersionUID = 4940296793433356792L;

	/**
	 * File name.
	 */
	protected String name;
	
	/**
	 * File size if less than 2^31.
	 * This member is negative if the file size is greater than or equal to 2^31.
	 */
	protected int size;
	
	/**
	 * File size.
	 * (This member is a string value in JavaScript)
	 */
	protected long sizeL;
	
	/**
	 * True for directory.
	 */
	protected boolean directory;
	
	/**
	 * True for read-only file.
	 */
	protected boolean readonly;	
	
	/**
	 * Last modified date.
	 */
	protected Date lastModified;
	
  public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getSize() {
		return size;
	}
	public void setSize(int size) {
		this.size = size;
	}
	public long getSizeL() {
		return sizeL;
	}
	public void setSizeL(long sizeL) {
		this.sizeL = sizeL;
	}
	public boolean isDirectory() {
		return directory;
	}
	public void setDirectory(boolean directory) {
		this.directory = directory;
	}
  public boolean isReadonly() {
    return readonly;
  }
  public void setReadonly(boolean readonly) {
    this.readonly = readonly;
  }
  public Date getLastModified() {
    return lastModified;
  }
  public void setLastModified(Date lastModified) {
    this.lastModified = lastModified;
  }
	
	
}
