#include "stdafx.h"
#include "JsfsAuthentication.h"
#include "Bypshttp.h"
#include "FileSystemServiceImpl.h"

using namespace byps::http;

JsfsAuthentication::JsfsAuthentication(wstring appUrl, wstring userName, wstring userPwd)
	: appUrl(appUrl), userName(userName), userPwd(userPwd)
{
	httpClient = HttpClient_create(NULL);
}


JsfsAuthentication::~JsfsAuthentication(void)
{
	httpClient->done();
}


bool JsfsAuthentication::isReloginException(PClient client, BException ex, BTYPEID typeId) {
	return client->transport->isReloginException(ex, typeId);
}

class JsfsAuthentication_HttpGet : public BAsyncResult {
	PJsfsAuthentication auth;
	function<void (bool, BException)> innerResult;
public:
	JsfsAuthentication_HttpGet(PJsfsAuthentication auth, function<void (bool, BException)> innerResult) 
		: auth(auth), innerResult(innerResult) {
	}

	virtual ~JsfsAuthentication_HttpGet() {}

	virtual void setAsyncResult(const BVariant& var) {
		if (var.isException()) {
			innerResult(false, var.getException());
		}
		else {
			PBytes bytes = NULL;
			var.get(bytes);
			if (bytes) {
				std::string body((char*)bytes->data, bytes->length);
				auth->token = BToStdWString(body);
			}
			innerResult(true, BException());
		}
		delete this; 
	}
};

void JsfsAuthentication::internalAuthenticate(PClient bclient, function<void (bool, BException)> asyncResult) {
		
	PHttpCredentials creds(new HHttpCredentials());
	creds->name = userName;
	creds->pwd = userPwd;
	httpClient->init(appUrl, creds);

	PHttpGet get = httpClient->get(appUrl);

	PAsyncResult outerResult(new JsfsAuthentication_HttpGet(shared_from_this(), asyncResult));
	get->send(outerResult);
}

void JsfsAuthentication::authenticate(PClient bclient, function<void (bool, BException)> asyncResult) {

	PClient_JSFS jsfsClient = byps_ptr_cast<BClient_JSFS>(bclient);
	PJsfsAuthentication auth = shared_from_this();

	internalAuthenticate(bclient, [jsfsClient, auth, asyncResult](bool, BException ex) {

		PSkeleton_FileSystemService jsfsService = PSkeleton_FileSystemService(new CFileSystemServiceImpl(jsfsClient));
		jsfsClient->addRemote(jsfsService);

		std::wstring token = auth->getToken();

		jsfsClient->dispatcherService->registerService(token, jsfsService, [asyncResult](bool ignored, BException ex) {
			asyncResult(ignored, ex);
		});
	});

}

void JsfsAuthentication::getSession(PClient , BTYPEID , function<void (PSerializable, BException)> asyncResult) {
	asyncResult(PSerializable(), BException());
}

