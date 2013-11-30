package com.wilutions.jsfs;

import java.io.File;
import java.util.Date;

/**
 * Utility class.
 *
 */
public class FileInfoHelper {
  
  /**
   * Create a FileInfo object.
   * @param file File object
   * @return FileInfo object
   */
  public static FileInfo makeFileInfo(File file) {
    FileInfo fi = new FileInfo();
    fi.setName(file.getAbsolutePath());
    fi.setSizeL(file.length());
    fi.setSize(fi.getSizeL() > 0x7FFFFFFF ? -1 : (int) fi.getSizeL());
    fi.setDirectory(file.isDirectory());
    fi.setReadonly(!file.canWrite());
    //fi.setHidden(file.isHidden());
    fi.setLastModified(new Date(file.lastModified()));
    return fi;
  }

  /**
   * Make valid path.
   * @param path File system path that might contain environment variables.
   * @return File system path with replaced variables.
   */
  public static String makeValidPath(String path) {

    int p = path.indexOf('%');
    while (p >= 0) {
      
      int e = path.indexOf('%', p + 1);
      String variableName = path.substring(p + 1, e);
      String variableValue = System.getenv(variableName);
      if (variableValue == null) variableValue = "";
      path = path.replace(path.substring(p, e + 1), variableValue);
      
      p = path.indexOf('%');
    }

    return path;
  }


}
