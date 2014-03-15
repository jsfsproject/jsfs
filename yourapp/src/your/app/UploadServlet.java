package your.app;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;

import org.apache.tomcat.util.http.fileupload.servlet.ServletFileUpload;

/**
 * Servlet implementation class UploadServlet
 * 
 */
@WebServlet("/upload")
@MultipartConfig(maxFileSize=1000000)
public class UploadServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UploadServlet() {
        super();
    }
    
    @Override
    protected void service(HttpServletRequest arg0, HttpServletResponse arg1) throws ServletException, IOException {
      super.service(arg0, arg1);
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    File tempFile = null;
    InputStream input = null;
    
    if (ServletFileUpload.isMultipartContent(request)) {
      Part filePart = request.getPart("mydoc");
      String filename = getFilename(filePart);
      System.out.println("filename=" + filename);
      input = filePart.getInputStream();
      tempFile = File.createTempFile("upload", filename.substring(filename.indexOf('.')+1));
    }
    else {
      String fname = request.getParameter("fname"); 
      System.out.println("fname=" + fname);
      tempFile = File.createTempFile("upload", ".tmp");
      input = request.getInputStream();
    }

    OutputStream output = new FileOutputStream(tempFile);
    try {
      byte[] buffer = new byte[1024];
      int length = 0;
      while ((length = input.read(buffer)) != -1) {
        output.write(buffer, 0, length);
      }
      output.flush(); 
    } finally {
      try {
        input.close();
      } catch (IOException ignored) {
      }
      try {
        output.close();
      } catch (IOException ignored) {
      }

    }

  }
	
	private static String getFilename(Part part) {
    for (String cd : part.getHeader("content-disposition").split(";")) {
        if (cd.trim().startsWith("filename")) {
            String filename = cd.substring(cd.indexOf('=') + 1).trim().replace("\"", "");
            return filename.substring(filename.lastIndexOf('/') + 1).substring(filename.lastIndexOf('\\') + 1); // MSIE fix.
        }
    }
    return null;
}

}
