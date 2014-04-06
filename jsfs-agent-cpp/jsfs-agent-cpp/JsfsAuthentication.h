/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
#pragma once

#include <Bypshttp.h>
#include <string>
using namespace std;
using namespace byps;
using namespace byps::http;

class JsfsAuthentication;
typedef byps_ptr<JsfsAuthentication> PJsfsAuthentication;

class JsfsAuthentication : public BAuthentication, public byps_enable_shared_from_this<JsfsAuthentication>
{
    wstring yourWebappUrl;
	wstring tokenServiceUrl;
	wstring userName;
	wstring userPwd;
	wstring token;
	PHttpClient httpClient;

public:
	JsfsAuthentication(const wstring& yourWebappUrl, const wstring& tokenServiceUrl, const wstring& userName, const wstring& userPwd);
	virtual ~JsfsAuthentication(void);

	wstring getToken() {
		return token;
	}

	virtual bool isReloginException(PClient bclient, BException ex, BTYPEID typeId);

	virtual void authenticate(PClient bclient, function<void (bool, BException)> asyncResult);

	virtual void getSession(PClient bclient, BTYPEID typeId, function<void (PSerializable, BException)> asyncResult);

	void keepAlive(function<void (wstring, BException)> asyncResult);

private:
	void internalAuthenticate(PClient bclient, function<void (wstring, BException)> asyncResult);

	friend class JsfsAuthentication_HttpGet;
};

