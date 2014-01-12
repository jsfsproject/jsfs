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
public final class BRequest_FileSystemService_beginWatchFolder extends BMethodRequest implements Serializable {

	public java.lang.String dir;
	public boolean recursive;
	public java.lang.String extraInfo;
	
	public final static long serialVersionUID = 1762179110L;
	
	public int getRemoteId() { return 145996442; }
	
	public void execute(BRemote __byps__remote, BAsyncResult<Object> __byps__asyncResult) throws Throwable {
		try {
			final FileSystemServiceAsync __byps__remoteT = (FileSystemServiceAsync)__byps__remote;			
			BAsyncResultSendMethod<Integer> __byps__outerResult = new BAsyncResultSendMethod<Integer>(__byps__asyncResult, new BResult_5());			
			__byps__remoteT.beginWatchFolder(dir, recursive, extraInfo, __byps__outerResult);
		} catch (Throwable e) {
			__byps__asyncResult.setAsyncResult(null, e);
			throw e;
		}
	}	
	
	public String toString() {
		StringBuilder s = new StringBuilder();
		s.append("[FileSystemService.beginWatchFolder(");
		s.append(dir);
		s.append(",").append(recursive);
		s.append(",").append(extraInfo);
		s.append(")]");
		return s.toString();
	}
	
}
