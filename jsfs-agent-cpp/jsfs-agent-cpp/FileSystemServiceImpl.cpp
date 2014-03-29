/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 
#include "stdafx.h"
#include "FileSystemServiceImpl.h"
#include "JsfsAuthentication.h"
#include "IconCache.h"
#include "resource.h"
#include <thread>

//static PBytes iconDocument;

CFileSystemServiceImpl::CFileSystemServiceImpl(PClient_JSFS bclient)
	: bclient(bclient)
{
	tpool = BThreadPool::create(NULL, 100);

	//if (!iconDocument) {
	//	HRSRC hRes = ::FindResource(NULL, MAKEINTRESOURCE(IDB_DOCUMENT_PNG), L"PNG");
	//	if (hRes) {
	//		HGLOBAL hGlobal = ::LoadResource(NULL, hRes);
	//		if (hGlobal) {
	//			void* pRes = ::LockResource(hGlobal);
	//			if (pRes) {
	//				size_t nSize = ::SizeofResource(NULL, hRes);
	//				iconDocument = BBytes::create(nSize);
	//				memcpy(iconDocument->data, pRes, nSize);
	//			}
	//		}
	//	}
	//}
}

CFileSystemServiceImpl::~CFileSystemServiceImpl(void)
{
	tpool->done();
}

int32_t CFileSystemServiceImpl::makeExceptionCodeFromWinError(DWORD winErrorCode) {
	return BEXCEPTION_CODE_MIN + winErrorCode;
}

BException CFileSystemServiceImpl::createException(DWORD winErrorCode) {
	return createException(L"", winErrorCode);
}

BException CFileSystemServiceImpl::createException(const wstring& msg, DWORD winErrorCode) {

	LPWSTR lpMsgBuf = NULL;

	FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        winErrorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPWSTR)&lpMsgBuf,
        0, NULL );

	wstring serr = lpMsgBuf;
	if (serr.length()) {
		wchar_t c = 0;
		while ((c = serr[serr.length()-1]), c == L'\n' || c == L'\r') {
			serr.resize(serr.length()-1);
		}
	}

	LocalFree(lpMsgBuf);

	return BException(BEXCEPTION_CODE_MIN + winErrorCode, msg, serr);
}

wstring CFileSystemServiceImpl::toISO(const FILETIME& ft) {
	wstringstream wss;
	SYSTEMTIME st = {0};
	FileTimeToSystemTime(&ft, &st);
	wss << st.wYear << L'.' << (st.wMonth + 1) << L'.' << st.wDay << L' ' 
		<< st.wHour << L':' << st.wMinute << L':' << st.wSecond << ',' << st.wMilliseconds;
	return wss.str();
}

BDateTime CFileSystemServiceImpl::toDateTime(const FILETIME& ft) {
	SYSTEMTIME st = {0};
	FileTimeToSystemTime(&ft, &st);
	return BDateTime((int32_t)st.wYear, (int32_t)st.wMonth+1, (int32_t)st.wDay, 
		(int32_t)st.wHour, (int32_t)st.wMinute, (int32_t)st.wSecond, 
		(int32_t)st.wMilliseconds);
}

PFileInfo CFileSystemServiceImpl::fileInfoFromWin32FindData(const wstring& dir, const WIN32_FIND_DATA& fd) {
	
	if (fd.cFileName[0] == '.') {
		if (fd.cFileName[1] == 0) return PFileInfo();
		if (fd.cFileName[1] == '.' && fd.cFileName[2] == 0) return PFileInfo();
	}

	FileInfo* fi = new FileInfo();
	fi->setName(dir + wstring(fd.cFileName));

	fi->setDirectory((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
	fi->setReadonly((fd.dwFileAttributes & FILE_ATTRIBUTE_READONLY) != 0);
	//fi->setHidden((fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) != 0);

	LARGE_INTEGER sizeL;
	sizeL.LowPart = fd.nFileSizeLow;
	sizeL.HighPart = fd.nFileSizeHigh;
	fi->setSize(fd.nFileSizeHigh == 0 ? (int32_t)fd.nFileSizeLow : (-1)); // use fi.sizeL if fi.size < 0
	fi->setSizeL(sizeL.QuadPart);

	fi->setLastModified(toDateTime(fd.ftLastWriteTime));

	fi->setIcon(IconCache::getPngIcon(fi->getName()));

	return PFileInfo(fi);
}

static wstring dirFromPath(const wstring& path) {
	WCHAR dir[_MAX_DIR] = {0};
	_wsplitpath_s(path.c_str(), NULL, 0, dir, _MAX_DIR, NULL, 0, NULL, 0);
	return dir;
}

 PFileInfo CFileSystemServiceImpl::makeFileInfo(const wstring& path) {
	WIN32_FIND_DATA fd;
	HANDLE hfind = ::FindFirstFile(path.c_str(), &fd);
	if (hfind == INVALID_HANDLE_VALUE) throw createException(::GetLastError());
	::FindClose(hfind);

	PFileInfo fi = fileInfoFromWin32FindData(std::wstring(), fd);
	return fi;
}

static wstring getDir(const wstring& path) {
	wchar_t drive[_MAX_DRIVE] = {0}, dir[_MAX_DIR] = {0};
	_wsplitpath_s(path.c_str(), drive, _MAX_DRIVE, dir, _MAX_DIR, NULL, 0, NULL, 0);
	return wstring(drive) + wstring(dir);
}

byps_ptr< vector<PFileInfo> > CFileSystemServiceImpl::findFiles(const wstring& path, const PFindOptions& ) {

	wstring search = makeValidPath(path);
	wstring dir = getDir(search);

	WIN32_FIND_DATA fd;
	HANDLE hfind = ::FindFirstFile(search.c_str(), &fd);
	if (hfind == INVALID_HANDLE_VALUE) throw createException(::GetLastError());

	vector<PFileInfo>* fileInfos = new vector<PFileInfo>();

	for (int32_t i = 0; i < 1000*1000; i++) {
		if (i != 0) {
			if (!::FindNextFile(hfind, &fd)) break;
		}

		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;

		PFileInfo fi = fileInfoFromWin32FindData(dir, fd);
		if (fi) {
			fileInfos->push_back(fi);
		}
	}
	::FindClose(hfind);

	return byps_ptr< vector<PFileInfo> >(fileInfos);
}

wstring CFileSystemServiceImpl::checkValidEncoding(const wstring& encoding) {
	if (encoding == L"UTF-8") return encoding;
	if (encoding == L"UTF-16LE") return encoding;
	if (encoding == L"UNICODE") return encoding;

	wstringstream wss;
	wss << L"Unsupported encoding=" << encoding << L", must be UTF-8, UTF-16LE or UNICODE.";
	throw BException(EX_INTERNAL, wss.str());
	//return encoding;
}

wstring CFileSystemServiceImpl::internalReadAllText(const wstring& path1, const wstring& encoding) {
	BException ex;
	wstring ret;

	wstring path = makeValidPath(path1);
	FILE* file = NULL;

	wstringstream ssmode;
	ssmode << L"r"; 
	if (encoding.size()) {
		ssmode << L", ccs=" << checkValidEncoding(encoding);
	}

	errno_t err = _wfopen_s(&file, path.c_str(), ssmode.str().c_str());
	if (err) {
		wstringstream wss;
		wss << L"Failed to open file \"" << path << L"\".";
		ex = createException(wss.str(), err);
		goto leave;
	}

	{
		wstringstream wss;

		//if (fseek(file, 0L, SEEK_END)) {
		//	wstringstream wss;
		//	wss << L"Failed to get size of file \"" << path << L"\".";
		//	ex = createException(wss.str(), err);
		//	goto leave;
		//}

		//int32_t size = ftell(file);	
		//if (size < 0) {
		//	wstringstream wss;
		//	wss << L"Failed to get size of file \"" << path << L"\", size < 0.";
		//	ex = createException(wss.str(), err);
		//	goto leave;
		//}

		//fseek(file, 0L, SEEK_SET);

		WCHAR buf[10*1000];
		while (fgetws(buf, ARRAYSIZE(buf), file) != NULL) {
			wss << buf;
		}
		
		ret = wss.str();
	}
leave:
	if (file) fclose(file);

	if (ex) throw ex;
	return ret;
}

void CFileSystemServiceImpl::internalWriteAllText(const wstring& path1, const wstring& text, const wstring& encoding) {
	BException ex;
	wstring ret;

	wstring path = makeValidPath(path1);
	FILE* file = NULL;

	wstringstream ssmode;
	ssmode << L"w"; 
	if (encoding.size()) ssmode << L", ccs=" << checkValidEncoding(encoding);

	errno_t err = _wfopen_s(&file, path.c_str(), ssmode.str().c_str());
	if (err) {
		wstringstream wss;
		wss << L"Failed to open file \"" << path << L"\".";
		ex = createException(wss.str(), err);
		goto leave;
	}

	err = fputws(text.c_str(), file);
	if (err) {
		wstringstream wss;
		wss << L"Failed to write file \"" << path << L"\".";
		ex = createException(wss.str(), err);
		goto leave;
	}

leave:
	if (file) fclose(file);
	
	if (ex) throw ex;
}

wstring CFileSystemServiceImpl::readAllText(const wstring& path)  {
	return internalReadAllText(path, L"");
}
void CFileSystemServiceImpl::writeAllText(const wstring& path, const wstring& text)  {
	internalWriteAllText(path, text, L"");
}

void CFileSystemServiceImpl::executeNotifyExit(const PArrayString& args, const PExecuteOptions& opts) {
	internalExecute(args, opts, opts != NULL);
}

// http://msdn.microsoft.com/en-us/library/windows/desktop/ms682499(v=vs.85).aspx

class WriteStringToPipe_Job : public BRunnable, public byps_enable_shared_from_this<WriteStringToPipe_Job> {
	wstring text;
	HANDLE hWrite;
	HANDLE hFinished;
public:
	WriteStringToPipe_Job(const wstring& text, HANDLE hFinished) : text(text), hWrite(NULL), hFinished(hFinished) {
	}
	virtual ~WriteStringToPipe_Job() {
		if (hWrite) ::CloseHandle(hWrite);
	}
	HANDLE start(PThreadPool tpool) {
		HANDLE hRead;
		SECURITY_ATTRIBUTES saAttr = {0}; 
 		saAttr.nLength = sizeof(SECURITY_ATTRIBUTES); 
		saAttr.bInheritHandle = TRUE; 
		if (CreatePipe(&hRead, &hWrite, &saAttr, 0)) {
			SetHandleInformation(hWrite, HANDLE_FLAG_INHERIT, 0);
			tpool->execute(shared_from_this());
		}
		return hRead;
	}
	virtual void run() {
		int clen = ::WideCharToMultiByte(CP_ACP, 0, text.c_str(), text.length(), NULL, 0, NULL, NULL);
		char* cbuf = new char[clen];
		::WideCharToMultiByte(CP_ACP, 0, text.c_str(), text.length(), cbuf, clen, NULL, NULL);
		int pos = 0;
		DWORD bytesWritten = 0;
		while (::WriteFile(hWrite, cbuf + pos, (DWORD)(clen - pos), &bytesWritten, NULL) && bytesWritten) {
			pos += (int)bytesWritten;
		}
		delete[] cbuf;
		::SetEvent(hFinished);
	}

};

typedef byps_ptr<wstring> pwstring;

class ReadStringFromPipe_Job : public BRunnable, public byps_enable_shared_from_this<ReadStringFromPipe_Job> {
	pwstring ptext;
	HANDLE hRead;
	HANDLE hFinished;
public:
	ReadStringFromPipe_Job(pwstring ptext, HANDLE hFinished) : ptext(ptext), hRead(NULL), hFinished(hFinished) {
	}
	virtual ~ReadStringFromPipe_Job() {
		if (hRead) ::CloseHandle(hRead);
	}
	HANDLE start(PThreadPool tpool) {
		HANDLE hWrite;
		SECURITY_ATTRIBUTES saAttr = {0}; 
 		saAttr.nLength = sizeof(SECURITY_ATTRIBUTES); 
		saAttr.bInheritHandle = TRUE; 
		if (CreatePipe(&hRead, &hWrite, &saAttr, 0)) {
			SetHandleInformation(hRead, HANDLE_FLAG_INHERIT, 0);
			tpool->execute(shared_from_this());
		}
		return hWrite;
	}
	virtual void run() {
		char buf[1000];
		wchar_t wbuf[1000];
		DWORD bytesRead = 0;
		while (::ReadFile(hRead, buf, sizeof(buf), &bytesRead, NULL) && bytesRead) {
			int wlen = MultiByteToWideChar(CP_ACP, 0, buf, bytesRead, wbuf, ARRAYSIZE(wbuf));
			*ptext += std::wstring(wbuf, wlen);
		}
		::SetEvent(hFinished);
	}
};

class WaitForProcessExit_Job : public BRunnable {
	PFileSystemServiceImpl jsfs;
	PArrayString args;
	PExecuteOptions execOpts;
	bool notify;

public:
	WaitForProcessExit_Job(PFileSystemServiceImpl jsfs, const PArrayString& args, const PExecuteOptions& execOpts, bool notify) 
		: jsfs(jsfs)
		, args(args)
		, execOpts(execOpts)
		, notify(notify) {
	}
	virtual ~WaitForProcessExit_Job() {
	}

	virtual void run() {
		BException rex;
		HANDLE hProcess = NULL;

		try {

			wstring params = makeValidParams(args);

			wstring fileToOpen = jsfs->makeValidPath(args->at(0));

			PExecuteNotifyInfo notifyInfo;
			pwstring pstandardOut, pstandardError;
			if (notify) {
				notifyInfo = PExecuteNotifyInfo(new ExecuteNotifyInfo());
			}

			if (execOpts->getStandardInput().size() || (notifyInfo && (execOpts->getCaptureOutput() || execOpts->getCaptureError()))) {

				if (notifyInfo && execOpts->getCaptureOutput()) pstandardOut = pwstring(new wstring());
				if (notifyInfo && execOpts->getCaptureError()) pstandardError = pwstring(new wstring());

				createProcess(fileToOpen, params, execOpts->getStandardInput(), pstandardOut, pstandardError);
			}
			else {
				shellExecute(fileToOpen, params);
			}

			if (notifyInfo) {
				PFileSystemNotify notifyService = jsfs->getNotifyService();
				if (notifyService) {
					notifyInfo->setExtraInfo(execOpts->getExtraInfo());

					if (pstandardOut) notifyInfo->setStandardOutput(*pstandardOut);
					if (pstandardError) notifyInfo->setStandardError(*pstandardError);

					notifyService->notify(notifyInfo);
				}
			}
		}
		catch (const BException& ex) {
			rex = ex;
		}
	
		if (hProcess) ::CloseHandle(hProcess);

		if (rex) {
			throw rex;
		}
	}

	wstring makeValidParams(const PArrayString& args) {

		wstringstream ssparams;
		for (size_t i = 1; i < args->length(); i++) {

			if (i > 1) ssparams << L" ";

			wstring param = args->at(i);

			bool hasBlank = (param.find(L' ') != wstring::npos);
			if (hasBlank) ssparams << L"\"";
			
			// Write param, double quotes
			for (size_t k = 0; k < param.length(); k++) {
				ssparams << param[k];
				if (param[k] == L'\"') ssparams << L'\"';
			}

			if (hasBlank) ssparams << L"\"";
		}

		return ssparams.str();
	}

	void shellExecute(const wstring& fileToOpen, const wstring& params) {
		SHELLEXECUTEINFO execInfo = {0};
		execInfo.cbSize = sizeof(execInfo);
		execInfo.lpVerb = L"open";
		execInfo.nShow = SW_SHOW;
		execInfo.lpFile = fileToOpen.c_str();
		execInfo.lpParameters = params.c_str();

		execInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	
		if (!::ShellExecuteEx(&execInfo)) {
			DWORD err = ::GetLastError();
			throw CFileSystemServiceImpl::createException(L"Failed to execute " + fileToOpen, err);
		}
	
		DWORD wait = ::WaitForSingleObject(execInfo.hProcess, INFINITE);
		DWORD err = ::GetLastError();
		::CloseHandle(execInfo.hProcess);

		if (wait == WAIT_TIMEOUT) {
			throw BException(EX_TIMEOUT, L"Timeout while waiting for " + args->at(0));
		}
		else if (wait != WAIT_OBJECT_0) {
			throw CFileSystemServiceImpl::createException(L"Error while waiting for " + args->at(0), err);
		}
	}

	void createProcess(const wstring& fileToOpen, const wstring& params, const wstring& standardInput, pwstring pstandardOutput, pwstring pstandardError) {
		STARTUPINFO startupInfo = {0};
		PROCESS_INFORMATION processInfo = {0};

		startupInfo.cb = sizeof(startupInfo);

		HANDLE hWriteStdinFinished = NULL;
		HANDLE hReadStdoutFinished = NULL;
		HANDLE hReadStderrFinished = NULL;

		if (standardInput.size()) {
			hWriteStdinFinished = ::CreateEvent(NULL, TRUE, FALSE, NULL);
			byps_ptr<WriteStringToPipe_Job> job(new WriteStringToPipe_Job(standardInput, hWriteStdinFinished));
			startupInfo.hStdInput = job->start(jsfs->tpool);
			startupInfo.dwFlags |= STARTF_USESTDHANDLES;
		}

		if (pstandardOutput) {
			hReadStdoutFinished = ::CreateEvent(NULL, TRUE, FALSE, NULL);
			byps_ptr<ReadStringFromPipe_Job> job(new ReadStringFromPipe_Job(pstandardOutput, hReadStdoutFinished));
			startupInfo.hStdOutput = job->start(jsfs->tpool);
			startupInfo.dwFlags |= STARTF_USESTDHANDLES;
		}

		if (pstandardError) {
			hReadStderrFinished = ::CreateEvent(NULL, TRUE, FALSE, NULL);
			byps_ptr<ReadStringFromPipe_Job> job(new ReadStringFromPipe_Job(pstandardError, hReadStderrFinished));
			startupInfo.hStdError = job->start(jsfs->tpool);
			startupInfo.dwFlags |= STARTF_USESTDHANDLES;
		}

		DWORD cmdlen = fileToOpen.length() + 1 + params.length() + 1;
		LPWSTR cmd = new WCHAR[cmdlen];
		wcscpy_s(cmd, cmdlen, fileToOpen.c_str());
		wcscat_s(cmd, cmdlen, L" ");
		wcscat_s(cmd, cmdlen, params.c_str());

		BOOL succ = ::CreateProcess(NULL, cmd, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &startupInfo, &processInfo);		
		DWORD err = ::GetLastError();
		
		delete[] cmd;

		if (startupInfo.hStdInput) ::CloseHandle(startupInfo.hStdInput);
		if (startupInfo.hStdOutput) ::CloseHandle(startupInfo.hStdOutput);
		if (startupInfo.hStdError) ::CloseHandle(startupInfo.hStdError);

		if (!succ) {
			throw CFileSystemServiceImpl::createException(L"Failed to execute " + fileToOpen, err);
		}

		HANDLE waitHandles[4] = { 0 };
		DWORD nbOfHandles = 0;
		waitHandles[nbOfHandles++] = processInfo.hProcess;
		if (hReadStdoutFinished) waitHandles[nbOfHandles++] = hReadStdoutFinished;
		if (hReadStderrFinished) waitHandles[nbOfHandles++] = hReadStderrFinished;
		if (hWriteStdinFinished) waitHandles[nbOfHandles++] = hWriteStdinFinished;

		DWORD wait = ::WaitForMultipleObjects(nbOfHandles, waitHandles, TRUE, INFINITE);
		err = ::GetLastError();

		::CloseHandle(processInfo.hProcess);
		::CloseHandle(processInfo.hThread);
		if (hWriteStdinFinished) ::CloseHandle(hWriteStdinFinished);
		if (hReadStdoutFinished) ::CloseHandle(hReadStdoutFinished);
		if (hReadStderrFinished) ::CloseHandle(hReadStderrFinished);

		if (wait == WAIT_TIMEOUT) {
			throw BException(EX_TIMEOUT, L"Timeout while waiting for " + args->at(0));
		}
		else if (wait == WAIT_FAILED) {
			throw CFileSystemServiceImpl::createException(L"Error while waiting for " + args->at(0), err);
		}
	}

	HANDLE createTempFile() {
		WCHAR tempDir[MAX_PATH] = {0}, tempPath[MAX_PATH] = {0};
		GetTempPath(MAX_PATH, tempDir);
		GetTempFileName(tempDir, L"jsfs", 0, tempPath);
		DWORD attrs = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_DELETE_ON_CLOSE;
		HANDLE file = CreateFile(tempPath, GENERIC_ALL, FILE_SHARE_READ, NULL, CREATE_ALWAYS, attrs, NULL);
		if (file == INVALID_HANDLE_VALUE) {
			DWORD err = ::GetLastError();
			throw CFileSystemServiceImpl::createException(L"Failed to create file " + std::wstring(tempPath), err);
		}
		return file;
	}



};

PFileSystemNotify CFileSystemServiceImpl::getNotifyService() {
	PClient_JSFS bclient = this->bclient.lock();
	return getNotifyService(bclient);
}

PFileSystemNotify CFileSystemServiceImpl::getNotifyService(PClient_JSFS bclient) {
	if (!bclient) return PFileSystemNotify();
	JsfsAuthentication* auth = static_cast<JsfsAuthentication*>(bclient->getAuthentication().get());
	std::wstring token = auth->getToken();
	PFileSystemNotify ns = bclient->getDispatcherService()->getNotifyService(token, false);
	return ns;
}


void CFileSystemServiceImpl::internalExecute(const PArrayString& args, const PExecuteOptions& opts, bool notify) {

	if (!args || args->length() == 0) throw BException(EX_INTERNAL, L"Parameter args must not be empty");

	PRunnable job(new WaitForProcessExit_Job(shared_from_this(), args, opts, notify));
	if (notify) {
		tpool->execute(job);
	}
	else {
		job->run();
	}

}

static wstring getenv(const std::wstring& variableName) {
	wstring value;
	size_t ret = 0;
	wchar_t buf[MAX_PATH+1] = {0};
	_wgetenv_s(&ret, buf, variableName.c_str());
	return buf;
}

static void replaceStringInPlace(std::wstring& subject, const std::wstring& search,
                          const std::wstring& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::wstring::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

wstring CFileSystemServiceImpl::makeValidPath(const wstring& path1) {
	wstring path = path1;
	size_t p = path.find(L'%');
	while (p != wstring::npos) {
		size_t e = path.find(L'%', p+1);
		if (e == wstring::npos) break;
		wstring variableName = path.substr(p+1, e-p-1);
		wstring variableValue = getenv(variableName);
		replaceStringInPlace(path, path.substr(p, e+1-p), variableValue);
		p = path.find(L'%');
	}

	p = path.find(L'{');
	while (p != wstring::npos) {
		size_t e = path.find(L'}', p+1);
		if (e == wstring::npos) break;
		wstring variableName = path.substr(p, e-p+1);
		GUID guid;
		if (CLSIDFromString(variableName.c_str(), &guid) == S_OK) {
			LPWSTR folderPath = NULL;
			SHGetKnownFolderPath(guid, 0, NULL, &folderPath);
			if (folderPath) {
				replaceStringInPlace(path, path.substr(p, e+1-p), folderPath);
				CoTaskMemFree(folderPath);
			}
		}
		p = path.find(L'{');
	}		

	return path;
}

int32_t CFileSystemServiceImpl::beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo) {
	
	PClient_JSFS bclient = this->bclient.lock();
	if (!bclient) {
		throw BException(EX_CANCELLED, L"Application already stopped");
	}

	std::wstring watchDirectory = makeValidPath(dir);

	PWatchDir existingWatcher;
	for (map<int32_t, PWatchDir>::iterator it = watchers.begin(); it != watchers.end(); it++) {
		PWatchDir w = (*it).second;
		wstring wdir = w->getDirectory();
		if (_wcsicmp(wdir.c_str(), watchDirectory.c_str()) == 0) {
			existingWatcher = w;
			break;
		}
	}

	if (!existingWatcher) {
		existingWatcher =  PWatchDir(new CWatchDir(bclient, ++nextNotifyId, extraInfo, makeValidPath(dir), recursive));
		existingWatcher->start();
	}

	int32_t handle = existingWatcher->getWatchHandle();
	watchers[handle] = existingWatcher;

	return handle;
}

void CFileSystemServiceImpl::endWatchFolder(int32_t handle)  {
	PWatchDir watchDir = watchers[handle]; // adds a NULL value if handle not found.
	if (watchDir) {
		watchDir->done();
	}
	watchers.erase(handle);
}

wstring CFileSystemServiceImpl::getFileContentType(const wstring& path) {
	wstring contentType = L"application/octet-stream";
	WCHAR fext[_MAX_EXT];
	_wsplitpath_s(path.c_str(), NULL, 0, NULL, 0, NULL, 0, fext, ARRAYSIZE(fext));
	HKEY hkey = NULL;
	if (::RegOpenKeyEx(HKEY_CLASSES_ROOT, fext, 0, KEY_READ, &hkey) == ERROR_SUCCESS) {
		WCHAR buf[100] = {0};
		DWORD len = sizeof(buf)-2;
		DWORD err = ::RegQueryValueEx(hkey, L"Content Type", NULL, NULL, (LPBYTE)buf, &len);
		if (err == ERROR_SUCCESS) {
			contentType = wstring(buf);
		}
		::RegCloseKey(hkey);
	}
	return contentType;
}

int64_t CFileSystemServiceImpl::getFileContentLength(const wstring& path) {
	HANDLE hFile = ::CreateFile(path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		DWORD err = ::GetLastError();
		throw createException(err);
	}
	LARGE_INTEGER fsize = {0};
	::GetFileSizeEx(hFile, &fsize);
	::CloseHandle(hFile);
	return fsize.QuadPart;
}

PContentStream CFileSystemServiceImpl::readFile(const wstring& path1) {
	wstring path = makeValidPath(path1);
	wstring contentType = getFileContentType(path);
	int64_t contentLength = getFileContentLength(path);
	PContentStream cstream(new BContentStreamFile(path, contentType, contentLength));
	return cstream;
}

void CFileSystemServiceImpl::uploadFile(const ::std::wstring& path, const ::std::wstring& url, const ::std::wstring& method) {
	BSkeleton_FileSystemService::uploadFile(path, url, method);
}
