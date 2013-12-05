/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
#include "stdafx.h"
#include "JsfsWireClient.h"


JsfsWireClient::JsfsWireClient(void* app, const std::wstring& url, int32_t flags, int32_t timeoutSeconds, PThreadPool tpool)
	: HWireClient(app, url, flags, timeoutSeconds, tpool)
{
}


JsfsWireClient::~JsfsWireClient(void)
{
}


void JsfsWireClient::send(const PMessage& msg, PAsyncResult asyncResult) {
	HWireClient::send(msg, asyncResult);
}

void JsfsWireClient::sendR(const PMessage& msg, PAsyncResult asyncResult) {
	HWireClient::sendR(msg, asyncResult);
}

PWire JsfsWireClient::create(void* app, const std::wstring& url, int32_t flags, int32_t timeoutSeconds, PThreadPool tpool) {
	JsfsWireClient* pThis = new JsfsWireClient(app, url, flags, timeoutSeconds, tpool);
	pThis->init();
    PWire ret = PWire(pThis);
    return ret;
}
