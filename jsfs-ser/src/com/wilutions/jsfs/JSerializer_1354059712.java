package com.wilutions.jsfs;

/*
 * Serializer for com.wilutions.jsfs.BResult_1816639285
 * 
 * THIS FILE HAS BEEN GENERATED BY class byps.gen.j.GenSerStructJson DO NOT MODIFY.
 */

import byps.*;

// DEBUG
// isEnum=false
// isFinal=true
// isInline=false
// #members=1

// checkpoint byps.gen.j.GenSerStruct:274
@SuppressWarnings("all")
public class JSerializer_1354059712 extends JSerializer_Object {
	
	public final static BSerializer instance = new JSerializer_1354059712();
	
	public JSerializer_1354059712() {
		super(1354059712);
	}
	
	public JSerializer_1354059712(int typeId) {
		super(typeId);
	}
	
	
	@Override
	public void internalWrite(final Object obj1, final BOutputJson bout, final BBufferJson bbuf) throws BException {
		final BResult_1816639285 obj = (BResult_1816639285)obj1;		
		bout.writeObj("result",obj.result, false, null);
	}
	
	@Override
	public Object internalRead(final Object obj1, final BInputJson bin) throws BException {
		final BResult_1816639285 obj = (BResult_1816639285)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_1816639285()));
		
		final BJsonObject js = bin.currentObject;
		obj.result = (com.wilutions.jsfs.FileSystemNotify)bin.readObj("result", false, null);
		
		return obj;
	}
	
}