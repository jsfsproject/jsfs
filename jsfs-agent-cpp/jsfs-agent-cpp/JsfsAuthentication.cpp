/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
#include "stdafx.h"
#include "JsfsAuthentication.h"
#include "Bypshttp.h"
#include "FileSystemServiceImpl.h"

using namespace byps::http;

JsfsAuthentication::JsfsAuthentication(wstring tokenServiceUrl, wstring userName, wstring userPwd)
	: tokenServiceUrl(tokenServiceUrl), userName(userName), userPwd(userPwd)
{
	httpClient = HttpClient_create(NULL);
}


JsfsAuthentication::~JsfsAuthentication(void)
{
	httpClient->done();
}


bool JsfsAuthentication::isReloginException(PClient client, BException ex, BTYPEID typeId) {
	return client->getTransport()->isReloginException(ex, typeId);
}

void JsfsAuthentication::keepAlive(function<void (wstring, BException)> asyncResult) {

}

class JsfsAuthentication_HttpGet : public BAsyncResult {
	PJsfsAuthentication auth;
	function<void (wstring, BException)> innerResult;
public:
	JsfsAuthentication_HttpGet(PJsfsAuthentication auth, function<void (wstring, BException)> innerResult) 
		: auth(auth), innerResult(innerResult) {
	}

	virtual ~JsfsAuthentication_HttpGet() {}

	virtual void setAsyncResult(const BVariant& var) {
		wstring token;
		BException ex;
		if (var.isException()) {
			ex = var.getException();
		}
		else {
			PBytes bytes = NULL;
			var.get(bytes);
			if (bytes) {
				std::string body((char*)bytes->data, bytes->length);
				token = BToStdWString(body);
			}
			else {
				ex = BException(EX_UNAUTHORIZED);
			}
		}

		innerResult(token, ex);
		
		delete this; 
	}
};

void JsfsAuthentication::internalAuthenticate(PClient bclient, function<void (wstring, BException)> asyncResult) {
		
	PHttpCredentials creds(new HHttpCredentials());
	creds->name = userName;
	creds->pwd = userPwd;
	httpClient->init(tokenServiceUrl, creds);

	PHttpGet get = httpClient->get(tokenServiceUrl);

	PAsyncResult outerResult(new JsfsAuthentication_HttpGet(shared_from_this(), asyncResult));
	get->send(outerResult);
}

void JsfsAuthentication::authenticate(PClient bclient, function<void (bool, BException)> asyncResult) {

	PClient_JSFS jsfsClient = byps_ptr_cast<BClient_JSFS>(bclient);
	PJsfsAuthentication auth = shared_from_this();

	internalAuthenticate(bclient, [jsfsClient, auth, asyncResult](wstring token, BException ex) {

		PSkeleton_FileSystemService jsfsService = PSkeleton_FileSystemService(new CFileSystemServiceImpl(jsfsClient));
		jsfsClient->addRemote(jsfsService);

		auth->token = token;

		jsfsClient->getDispatcherService()->registerService(token, jsfsService, [asyncResult](bool ignored, BException ex) {
			asyncResult(ignored, ex);
		});
	});

}

void JsfsAuthentication::getSession(PClient , BTYPEID , function<void (PSerializable, BException)> asyncResult) {
	asyncResult(PSerializable(), BException());
}

