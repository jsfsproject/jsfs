package com.wilutions.jsfs;

import java.io.Serializable;

/**
 * This class defines an item of a file upload request in {@link FileSystemService#uploadFiles}.
 * A FormData object corresponds to an input field in a HTML file upload form. 
 * It can specify files to be uploaded as with HTML input field type "file".
 * Or it can hold a simple value as with HTML input field type "text".
 */
public class FormItem implements Serializable {
  
  private final static long serialVersionUID = 979378962L;

  /**
   * Item name.
   * This value corresponds to HTML input field name.
   */
  public String name;
  
  /**
   * Item type.
   * Optional. Either "text" or "file".
   */
  public String type;
  
  /**
   * Item value.
   * If type is empty or equals to "text", this array contains one item.
   * If type equals to "file", this array contains the file paths to be uploaded.
   */
  public String[] values;
  
}
