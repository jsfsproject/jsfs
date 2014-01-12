package com.wilutions.jsfs;

/*
 * 
 * THIS FILE HAS BEEN GENERATED BY class byps.gen.j.GenServer DO NOT MODIFY.
 */

import byps.*;

@SuppressWarnings("all")
public class BServer_JSFS extends BServer { 

	public static BServer_JSFS createServer(BTransportFactory transportFactory) {
		return new BServer_JSFS(transportFactory);
	}
	
	public static BServer_JSFS createServerR(BTransport transport) {
		return new BServer_JSFS(transport);
	}
	
	public BServer_JSFS(BTransport transport) {
		super(transport, null);
	}
	
	public BServer_JSFS(BTransportFactory transportFactory) {
		super(
			transportFactory.createServerTransport(),
			transportFactory.createClientR(
				BClient_JSFS.createClientR(
					transportFactory.createClientTransport()
				)
			)
		);
	}
	
	public BServer_JSFS addRemote(BSkeleton_DispatcherService remoteSkeleton) {
		addRemote(1153231042, remoteSkeleton);
		return this;
	}
	
	public BServer_JSFS addRemote(BSkeleton_FileSystemNotify remoteSkeleton) {
		addRemote(544795964, remoteSkeleton);
		return this;
	}
	
	public BServer_JSFS addRemote(BSkeleton_FileSystemService remoteSkeleton) {
		addRemote(145996442, remoteSkeleton);
		return this;
	}
	
}
