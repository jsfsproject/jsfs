#pragma once

#include "JSFS-api.h"

using namespace com::wilutions::jsfs;
using namespace byps;

class CWatchDir;
typedef byps_ptr<CWatchDir> PWatchDir;

struct CReadChangesContext;

class CWatchDir : public BRunnable, public byps_enable_shared_from_this<CWatchDir> {

	// Client object
	byps_weak_ptr<BClient_JSFS> client;

	int watchHandle;
	const wstring extraInfo;
	const wstring dir;
	bool recursive;
	HANDLE hDirectory;


public:
	CWatchDir(PClient_JSFS client, int watchHandle, const wstring& extraInfo, const wstring& dir, bool recursive);
	virtual ~CWatchDir(void);

	virtual void run();

	int getWatchHandle();
	const wstring& getDirectory();

	void start();
	void done();

private:
	BOOL beginRead();
	void processChanges(CReadChangesContext* ctxt);

	static VOID CALLBACK NotificationCompletion(
		DWORD dwErrorCode,									// completion code
		DWORD dwNumberOfBytesTransfered,					// number of bytes transferred
		LPOVERLAPPED lpOverlapped);							// I/O information buffer

};

