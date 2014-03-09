package com.wilutions.jsfs;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

public class MultipartFormDataInputStream extends InputStream {
 
  /*
   
<FORM action="http://server.com/cgi/handle"
       enctype="multipart/form-data"
       method="post">
   <P>
   What is your name? <INPUT type="text" name="submit-name"><BR>
   What files are you sending? <INPUT type="file" name="files"><BR>
   <INPUT type="submit" value="Send"> <INPUT type="reset">
 </FORM>
 
   */

/*
   Content-Type: multipart/form-data; boundary=AaB03x

   --AaB03x
   Content-Disposition: form-data; name="submit-name"

   Larry
   --AaB03x
   Content-Disposition: form-data; name="files"
   Content-Type: multipart/mixed; boundary=BbC04y

   --BbC04y
   Content-Disposition: file; filename="file1.txt"
   Content-Type: text/plain

   ... contents of file1.txt ...
   --BbC04y
   Content-Disposition: file; filename="file2.gif"
   Content-Type: image/gif
   Content-Transfer-Encoding: binary

   ...contents of file2.gif...
   --BbC04y--
   --AaB03x--  
 */
  
  FormItem[] items;
  int itemIdx = -1;
  InputStream itemStream;
  String boundary;
 
  MultipartFormDataInputStream(FormItem[] items) {
    this.items = items;
    this.boundary = Long.toString(System.nanoTime(), 16);
    final String s = "Content-Type: multipart/form-data; boundary=" + boundary + "\r\n\r\n";
    itemStream = new ByteArrayInputStream(s.getBytes());
  }
  
  @Override
  public int read() throws IOException {
    
    int c = itemStream.read();
    if (c == -1) {
      itemIdx++;
      if (itemIdx < items.length){
        itemStream = new FormItemInputStream(items[itemIdx]);
        c = itemStream.read();
      }
      else if (itemIdx == items.length) {
        final String s = "--" + boundary + "--\r\n";
        itemStream = new ByteArrayInputStream(s.getBytes());
      }
    }
    
    return c;
  }
  
  private static class FormItemInputStream extends InputStream {
    
    FormItem item;
    InputStream itemStream;
    
    FormItemInputStream(FormItem item) {
      this.item = item;
    }

    @Override
    public int read() throws IOException {
     
      return 0;
    }
    
  }
}
