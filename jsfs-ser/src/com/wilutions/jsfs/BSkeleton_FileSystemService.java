package com.wilutions.jsfs;

/*
 * 
 * THIS FILE HAS BEEN GENERATED BY class byps.gen.j.GenRemoteSkeleton DO NOT MODIFY.
 */

import byps.*;

/**
 * This class provides a skeleton implementation of the interface FileSystemService.
 * Your interface implementation class has to be derived from this skeleton.
 * Either provide an asynchronous or a synchronous function in your subclass.
 * The framework calls only the asynchronous function.
 */
@SuppressWarnings("all")
public class BSkeleton_FileSystemService extends BSkeleton implements FileSystemServiceAsync {
	
	public final static long serialVersionUID = 145996442L;
	
	// checkpoint byps.gen.j.PrintContext:365
	public java.util.List<FileInfo> findFiles(java.lang.String path, FindOptions findOptions) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void findFiles(java.lang.String path, FindOptions findOptions, final BAsyncResult<java.util.List<FileInfo>> asyncResult) {
		try {
			java.util.List<FileInfo> ret = findFiles(path, findOptions);
			asyncResult.setAsyncResult(ret, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	// checkpoint byps.gen.j.PrintContext:365
	public java.lang.String readAllText(java.lang.String path) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void readAllText(java.lang.String path, final BAsyncResult<String> asyncResult) {
		try {
			java.lang.String ret = readAllText(path);
			asyncResult.setAsyncResult(ret, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	// checkpoint byps.gen.j.PrintContext:365
	public void writeAllText(java.lang.String path, java.lang.String text) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void writeAllText(java.lang.String path, java.lang.String text, final BAsyncResult<Object> asyncResult) {
		try {
			writeAllText(path, text);
			asyncResult.setAsyncResult(null, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	// checkpoint byps.gen.j.PrintContext:365
	public void executeNotifyExit(java.lang.String[] args, ExecuteOptions opts) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void executeNotifyExit(java.lang.String[] args, ExecuteOptions opts, final BAsyncResult<Object> asyncResult) {
		try {
			executeNotifyExit(args, opts);
			asyncResult.setAsyncResult(null, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	// checkpoint byps.gen.j.PrintContext:365
	public int beginWatchFolder(java.lang.String dir, boolean recursive, java.lang.String extraInfo) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void beginWatchFolder(java.lang.String dir, boolean recursive, java.lang.String extraInfo, final BAsyncResult<Integer> asyncResult) {
		try {
			int ret = beginWatchFolder(dir, recursive, extraInfo);
			asyncResult.setAsyncResult(ret, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	// checkpoint byps.gen.j.PrintContext:365
	public void endWatchFolder(int handle) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void endWatchFolder(int handle, final BAsyncResult<Object> asyncResult) {
		try {
			endWatchFolder(handle);
			asyncResult.setAsyncResult(null, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	// checkpoint byps.gen.j.PrintContext:365
	public java.io.InputStream readFile(java.lang.String path) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void readFile(java.lang.String path, final BAsyncResult<java.io.InputStream> asyncResult) {
		try {
			java.io.InputStream ret = readFile(path);
			asyncResult.setAsyncResult(ret, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	// checkpoint byps.gen.j.PrintContext:365
	public void uploadFilesMultipartFormdata(FormItem[] items, java.lang.String url, java.lang.String method) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void uploadFilesMultipartFormdata(FormItem[] items, java.lang.String url, java.lang.String method, final BAsyncResult<Object> asyncResult) {
		try {
			uploadFilesMultipartFormdata(items, url, method);
			asyncResult.setAsyncResult(null, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	// checkpoint byps.gen.j.PrintContext:365
	public void uploadFile(java.lang.String path, java.lang.String url) throws RemoteException {
		throw new BException(BExceptionC.UNSUPPORTED_METHOD, "");
	}
	// checkpoint byps.gen.j.PrintContext:409
	public void uploadFile(java.lang.String path, java.lang.String url, final BAsyncResult<Object> asyncResult) {
		try {
			uploadFile(path, url);
			asyncResult.setAsyncResult(null, null);
		} catch (Throwable e) {
			asyncResult.setAsyncResult(null, e);
		}
	}
	
	
}
