package com.wilutions.jsfs;

import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.util.concurrent.ConcurrentHashMap;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

public class IconCache {
  
  private static ConcurrentHashMap<String, byte[]> map = new ConcurrentHashMap<String, byte[]>();
  
  private IconCache() {}
  
  private static String getMapKey(File file) {
    String ext = ".";
    String fname = file.getName();
    int p = fname.lastIndexOf('.');
    if (p >= 0) {
      ext = fname.substring(p);
    }
    return ext;
  }
  
	public static byte[] getPngIcon(File file) {
	  String key = getMapKey(file);
	  byte[] ret = map.get(key);
	  if (ret == null) {
  		try {
  			sun.awt.shell.ShellFolder sf = sun.awt.shell.ShellFolder.getShellFolder(file);
  			ImageIcon icon = new ImageIcon(sf.getIcon(true));
  			ByteArrayOutputStream bos = new ByteArrayOutputStream();
  			ImageIO.write((BufferedImage)icon.getImage(), "PNG", bos);
  			ret = bos.toByteArray();
  			map.put(key, ret);
  		} catch (IOException e) {
  		  System.out.println(e);
  		}
	  }
		return ret;
	}
}
