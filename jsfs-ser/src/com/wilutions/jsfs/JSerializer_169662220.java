package com.wilutions.jsfs;

/*
 * Serializer for com.wilutions.jsfs.BResult_5
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
public class JSerializer_169662220 extends JSerializer_Object {
	
	public final static BSerializer instance = new JSerializer_169662220();
	
	public JSerializer_169662220() {
		super(169662220);
	}
	
	public JSerializer_169662220(int typeId) {
		super(typeId);
	}
	
	
	@Override
	public void internalWrite(final Object obj1, final BOutputJson bout, final BBufferJson bbuf) throws BException {
		final BResult_5 obj = (BResult_5)obj1;		
		bbuf.putInt("result", obj.result);
	}
	
	@Override
	public Object internalRead(final Object obj1, final BInputJson bin) throws BException {
		final BResult_5 obj = (BResult_5)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_5()));
		
		final BJsonObject js = bin.currentObject;
		obj.result = js.getInt("result");
		
		return obj;
	}
	
}
