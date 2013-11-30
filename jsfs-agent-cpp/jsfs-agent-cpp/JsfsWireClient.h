#pragma once

#include <Bypshttp.h>

using namespace std;
using namespace byps;
using namespace byps::http;

class JsfsWireClient :
	public HWireClient
{
public:
	static PWire JsfsWireClient::create(void* app, const std::wstring& url, int32_t flags, int32_t timeoutSeconds, PThreadPool tpool);

	virtual ~JsfsWireClient(void);
    virtual void send(const PMessage& msg, PAsyncResult asyncResult);
    virtual void sendR(const PMessage& msg, PAsyncResult asyncResult);
protected:
	JsfsWireClient(void* app, const std::wstring& url, int32_t flags, int32_t timeoutSeconds, PThreadPool tpool);
};

