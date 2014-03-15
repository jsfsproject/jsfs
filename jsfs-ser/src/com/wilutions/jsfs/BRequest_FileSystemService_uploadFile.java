package com.wilutions.jsfs;

/*
 * 
 * THIS FILE HAS BEEN GENERATED BY class byps.gen.j.GenApiClass DO NOT MODIFY.
 */

import byps.*;
import java.io.Serializable;

/**
*/
@SuppressWarnings("all")
public final class BRequest_FileSystemService_uploadFile extends BMethodRequest implements Serializable {

	public java.lang.String path;
	public java.lang.String url;
	public java.lang.String method;
	
	public final static long serialVersionUID = 744806851L;
	
	public int getRemoteId() { return 145996442; }
	
	public void execute(BRemote __byps__remote, BAsyncResult<Object> __byps__asyncResult) throws Throwable {
		try {
			final FileSystemServiceAsync __byps__remoteT = (FileSystemServiceAsync)__byps__remote;			
			BAsyncResultSendMethod<Object> __byps__outerResult = new BAsyncResultSendMethod<Object>(__byps__asyncResult, new BResult_19());			
			__byps__remoteT.uploadFile(path, url, method, __byps__outerResult);
		} catch (Throwable e) {
			__byps__asyncResult.setAsyncResult(null, e);
			throw e;
		}
	}	
	
	public String toString() {
		StringBuilder s = new StringBuilder();
		s.append("[FileSystemService.uploadFile(");
		s.append(path);
		s.append(",").append(url);
		s.append(",").append(method);
		s.append(")]");
		return s.toString();
	}
	
}