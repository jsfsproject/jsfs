#include "stdafx.h"
#include "WatchDir.h"
#include "FileSystemServiceImpl.h"

struct CReadChangesContext {

	byps_weak_ptr<CWatchDir> watchDir;

	union {
		LONGLONG align8;
		char buf[10*1000];
	};

	DWORD bytesReturned;
	OVERLAPPED overlapped;

	CReadChangesContext(PWatchDir watchDir) : watchDir(watchDir), bytesReturned(0) {
		memset(buf, 0, sizeof(buf));
		memset(&overlapped, 0, sizeof(overlapped));
		overlapped.hEvent = (HANDLE)this;
	}
};

CWatchDir::CWatchDir(PClient_JSFS client, int watchHandle, const wstring& extraInfo, const wstring& dir, bool recursive)
	: client(client)
	, watchHandle(watchHandle)
	, extraInfo(extraInfo)
	, dir(dir)
	, recursive(recursive)
	, hDirectory(INVALID_HANDLE_VALUE)
{
}


CWatchDir::~CWatchDir(void)
{
	if (hDirectory != INVALID_HANDLE_VALUE) {
		::CloseHandle(hDirectory);
	}
}

void CWatchDir::start() {

	hDirectory = ::CreateFile(
		dir.c_str(),						// pointer to the file name
		FILE_LIST_DIRECTORY,                // access (read/write) mode
		FILE_SHARE_READ						// share mode
		 | FILE_SHARE_WRITE
		 | FILE_SHARE_DELETE,
		NULL,                               // security descriptor
		OPEN_EXISTING,                      // how to create
		FILE_FLAG_BACKUP_SEMANTICS			// file attributes
		 | FILE_FLAG_OVERLAPPED,
		NULL);                              // file with attributes to copy

	if (hDirectory == INVALID_HANDLE_VALUE) {
		DWORD err = ::GetLastError();
		throw CFileSystemServiceImpl::createException(L"Failed to watch directory " + std::wstring(dir), err);
	}

	if (!beginRead()) {
		DWORD err = ::GetLastError();
		throw CFileSystemServiceImpl::createException(L"Failed to read directory changes, " + std::wstring(dir), err);
	}
}

BOOL CWatchDir::beginRead() {

	CReadChangesContext* ctxt = new CReadChangesContext(shared_from_this());

	DWORD filter = 
		FILE_NOTIFY_CHANGE_FILE_NAME | 
		FILE_NOTIFY_CHANGE_DIR_NAME |
		FILE_NOTIFY_CHANGE_ATTRIBUTES |
		FILE_NOTIFY_CHANGE_SIZE |
		FILE_NOTIFY_CHANGE_LAST_WRITE |
		FILE_NOTIFY_CHANGE_LAST_ACCESS |
		FILE_NOTIFY_CHANGE_CREATION |
		FILE_NOTIFY_CHANGE_SECURITY;
	
	// This call needs to be reissued after every APC.
	BOOL success = ::ReadDirectoryChangesW(
		hDirectory,							// handle to directory
		ctxt->buf,							// read results buffer
		sizeof(ctxt->buf),					// length of buffer
		(BOOL)recursive,                    // monitoring option
		filter,								// filter conditions
		&ctxt->bytesReturned,				// bytes returned
		&ctxt->overlapped,                  // overlapped buffer
		NotificationCompletion);            // completion routine

	return success;
}

void CWatchDir::run() {
}

VOID CALLBACK CWatchDir::NotificationCompletion(
	DWORD dwErrorCode,									// completion code
	DWORD dwNumberOfBytesTransfered,					// number of bytes transferred
	LPOVERLAPPED lpOverlapped)							// I/O information buffer
{
	CReadChangesContext* ctxt = (CReadChangesContext*)lpOverlapped->hEvent;

	if (dwErrorCode != ERROR_OPERATION_ABORTED) {

		PWatchDir watchDir = ctxt->watchDir.lock();
		if (watchDir) {

			if (watchDir->hDirectory != INVALID_HANDLE_VALUE) {
				watchDir->beginRead();
			}

			if (dwNumberOfBytesTransfered) {
				watchDir->processChanges(ctxt);
			}
		}

	}

	delete ctxt;
}

void CWatchDir::processChanges(CReadChangesContext* ctxt) {

	PClient_JSFS client = this->client.lock();
	PFileSystemNotify notifyService = CFileSystemServiceImpl::getNotifyService(client);
	if (!notifyService) return;

	char* pBase = ctxt->buf;

	for (;;)
	{
		FILE_NOTIFY_INFORMATION& fni = (FILE_NOTIFY_INFORMATION&)*pBase;

		wstring fname(fni.FileName, fni.FileNameLength/sizeof(wchar_t));
		
		wchar_t path[MAX_PATH] = {0};
		_wmakepath_s(path, MAX_PATH, L"", this->dir.c_str(), fname.c_str(), L"");

		if (fname.length() <= 12 && fname.find(L'~') != wstring::npos) {
			wchar_t longPath[MAX_PATH];
			if (::GetLongPathName(path, longPath, ARRAYSIZE(longPath)) > 0) {
				wcscpy_s(path, longPath);
			}
		}

		PWatchFolderNotifyInfo ni(new WatchFolderNotifyInfo());

		EWatchFolderNotifyKind kind = EWatchFolderNotifyKind::Nothing;
		PFileInfo fileInfo;
		
		switch (fni.Action) {
		case FILE_ACTION_ADDED:
			kind = EWatchFolderNotifyKind::EntryCreated;
			fileInfo = CFileSystemServiceImpl::makeFileInfo(path);
			break;
		case FILE_ACTION_REMOVED:
			kind = EWatchFolderNotifyKind::EntryDeleted; 
			break;
		case FILE_ACTION_MODIFIED:
			kind = EWatchFolderNotifyKind::EntryModified; 
			fileInfo = CFileSystemServiceImpl::makeFileInfo(path);
			break;
		case FILE_ACTION_RENAMED_OLD_NAME:
			kind = EWatchFolderNotifyKind::EntryDeleted; 
			break;
		case FILE_ACTION_RENAMED_NEW_NAME:
			kind = EWatchFolderNotifyKind::EntryCreated; 
			break;
		}

		switch (kind) {
		case EWatchFolderNotifyKind::EntryCreated:
		case EWatchFolderNotifyKind::EntryModified:
			try {
				fileInfo = CFileSystemServiceImpl::makeFileInfo(path);
			}
			catch (const BException& ex) {
				ni->setError(ex.toString());
			}
			break;

		default:
			fileInfo = PFileInfo(new FileInfo());
			fileInfo->setName(path);
			break;
		}

		ni->setFileInfo(fileInfo);
		ni->setKind(kind);
		ni->setExtraInfo(this->extraInfo);
		ni->setId(this->watchHandle);

		notifyService->notify(ni);

		if (!fni.NextEntryOffset) break;
		pBase += fni.NextEntryOffset;
	};
}

void CWatchDir::done() {
	HANDLE h = hDirectory;
	hDirectory = INVALID_HANDLE_VALUE;
	if (h != INVALID_HANDLE_VALUE) {
		::CloseHandle(h);
	}
}

int CWatchDir::getWatchHandle() {
	return watchHandle;
}

const wstring& CWatchDir::getDirectory() {
	return dir;
}

