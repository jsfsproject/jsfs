/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
#pragma once

//http://dotnet-snippets.de/snippet/gdi-speichern-eines-png/814

#include "WinHttpClient.h"
#include "JSFS-api.h"
#include "WatchDir.h"

using namespace com::wilutions::jsfs;
using namespace byps;
using namespace byps::http;

#define BEXCEPTION_CODE_MIN 10000

/**
 * JSFS Agent implementation
 */

class CFileSystemServiceImpl;
typedef byps_ptr<CFileSystemServiceImpl> PFileSystemServiceImpl;

class CFileSystemServiceImpl : 
	public BSkeleton_FileSystemService, 
	public byps_enable_shared_from_this<CFileSystemServiceImpl>
{

	// Notify service interface
	PFileSystemNotify notifyService;

	// Client object
	byps_weak_ptr<BClient_JSFS> bclient;

	PThreadPool tpool;

	// Directory watchers, map key is a watchHandle
	map<int32_t, PWatchDir> watchers;

	// Generate notifyIDs 
	byps_atomic<int32_t> nextNotifyId;

public:
	CFileSystemServiceImpl(PClient_JSFS bclient);
	virtual ~CFileSystemServiceImpl(void);

	virtual byps_ptr< vector<PFileInfo> > CFileSystemServiceImpl::findFiles(const wstring& path, const PFindOptions& findOptions);

	virtual wstring readAllText(const wstring& path) ;
	virtual void writeAllText(const wstring& path, const wstring& text) ;

	virtual void executeNotifyExit(const PArrayString& args, const PExecuteOptions& opts);

	virtual int32_t beginWatchFolder(const wstring& dir, bool recursive, const wstring& extraInfo) ;
	virtual void endWatchFolder(int32_t handle) ;

	virtual void uploadFile(const ::std::wstring& path, const ::std::wstring& url, const ::std::wstring& method) ;

	virtual PContentStream readFile(const wstring& path);

	static BException createException(DWORD winErrorCode);
	static BException createException(const wstring& msg, DWORD winErrorCode);

	static PFileInfo makeFileInfo(const wstring& path);
	static PFileSystemNotify getNotifyService(PClient_JSFS bclient);

private:
	friend class BAsyncResult_CFileSystemServiceImpl_init;
	friend class WaitForProcessExit_Job;
	friend class WriteStringToPipe_Job;
	friend class ReadStringFromPipe_Job;

	static wstring toISO(const FILETIME& ft);	
	static BDateTime toDateTime(const FILETIME& ft);
	int32_t makeExceptionCodeFromWinError(DWORD winErrorCode);
	wstring checkValidEncoding(const wstring& encoding);
	wstring internalReadAllText(const wstring& path, const wstring& encoding);
	void internalWriteAllText(const wstring& path, const wstring& text, const wstring& encoding);
	void internalExecute(const PArrayString& args, const PExecuteOptions& opts, bool notify);
	static PFileInfo fileInfoFromWin32FindData(const wstring& dir, const WIN32_FIND_DATA& fd);
	static wstring makeValidPath(const wstring& path);
	PFileSystemNotify getNotifyService();
	int64_t getFileContentLength(const wstring& path);
	wstring getFileContentType(const wstring& path);

};

