#ifndef __JSFS_api_H__
#define __JSFS_api_H__

#include <Byps.h>

//-------------------------------------------------
// Forward Declaration of class BStub_DispatcherService

namespace com { namespace wilutions { namespace jsfs { 

class BStub_DispatcherService; 
typedef byps_ptr< BStub_DispatcherService > PStub_DispatcherService; 

}}}

//-------------------------------------------------
// Forward Declaration of class BStub_FileSystemNotify

namespace com { namespace wilutions { namespace jsfs { 

class BStub_FileSystemNotify; 
typedef byps_ptr< BStub_FileSystemNotify > PStub_FileSystemNotify; 

}}}

//-------------------------------------------------
// Forward Declaration of class BStub_FileSystemService

namespace com { namespace wilutions { namespace jsfs { 

class BStub_FileSystemService; 
typedef byps_ptr< BStub_FileSystemService > PStub_FileSystemService; 

}}}

//-------------------------------------------------
// Forward Declaration of class NotifyInfo

namespace com { namespace wilutions { namespace jsfs { 

class NotifyInfo; 
typedef byps_ptr< NotifyInfo > PNotifyInfo; 

}}}

//-------------------------------------------------
// Forward Declaration of class ExecuteNotifyInfo

namespace com { namespace wilutions { namespace jsfs { 

class ExecuteNotifyInfo; 
typedef byps_ptr< ExecuteNotifyInfo > PExecuteNotifyInfo; 

}}}

//-------------------------------------------------
// Forward Declaration of class ExecuteOptions

namespace com { namespace wilutions { namespace jsfs { 

class ExecuteOptions; 
typedef byps_ptr< ExecuteOptions > PExecuteOptions; 

}}}

//-------------------------------------------------
// Forward Declaration of class FileInfo

namespace com { namespace wilutions { namespace jsfs { 

class FileInfo; 
typedef byps_ptr< FileInfo > PFileInfo; 

}}}

//-------------------------------------------------
// Forward Declaration of class FindOptions

namespace com { namespace wilutions { namespace jsfs { 

class FindOptions; 
typedef byps_ptr< FindOptions > PFindOptions; 

}}}

//-------------------------------------------------
// Forward Declaration of class WatchFolderNotifyInfo

namespace com { namespace wilutions { namespace jsfs { 

class WatchFolderNotifyInfo; 
typedef byps_ptr< WatchFolderNotifyInfo > PWatchFolderNotifyInfo; 

}}}

//-------------------------------------------------
// EWatchFolderNotifyKind
// typeId=508262806

namespace com { namespace wilutions { namespace jsfs { 


using namespace ::byps;

/// <summary>
/// Kinds of changes in a watched folder.
/// </summary>
enum EWatchFolderNotifyKind : int32_t  {
	/// <summary>
	/// Nothing changed.
	/// </summary>
	Nothing = 0,
	/// <summary>
	/// New file or directory has been created.
	/// </summary>
	EntryCreated = 1,
	/// <summary>
	/// File or directory attributes have been modified.
	/// </summary>
	EntryModified = 2,
	/// <summary>
	/// File or directory has been deleted.
	/// </summary>
	EntryDeleted = 3,
	
};

void operator & (BIO& ar, EWatchFolderNotifyKind& e);

}}}

//-------------------------------------------------
// NotifyInfo
// typeId=1274131736

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// Base class for notifications.
/// </summary>
class NotifyInfo : public BSerializable {
	/// <summary>
	/// Unused.
	/// </summary>
	protected: int32_t id;
	/// <summary>
	/// Application defined value.
	/// </summary>
	protected: ::std::wstring extraInfo;
	/// <summary>
	/// Error message.
	/// </summary>
	protected: ::std::wstring error;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: NotifyInfo();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: NotifyInfo(int32_t id, const ::std::wstring& extraInfo, const ::std::wstring& error);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1274131736; }
	
	public: int32_t getId() { return id; }
	public: void setId(int32_t v);
	public: ::std::wstring getExtraInfo() { return extraInfo; }
	public: void setExtraInfo(::std::wstring v);
	public: ::std::wstring getError() { return error; }
	public: void setError(::std::wstring v);
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// ExecuteNotifyInfo
// typeId=665368294

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// This class contains notification information generated from
/// {@link FileSystemService#executeNotifyExit(String[], ExecuteOptions)}.
/// </summary>
class ExecuteNotifyInfo : public NotifyInfo {
	/// <summary>
	/// Process exit code.
	/// </summary>
	protected: int32_t exitCode;
	/// <summary>
	/// Characters printed on stdout, if {@link ExecuteOptions#captureOutput} was
	/// set.
	/// </summary>
	protected: ::std::wstring standardOutput;
	/// <summary>
	/// Characters printed on stderr, if {@link ExecuteOptions#captureError} was
	/// set.
	/// </summary>
	protected: ::std::wstring standardError;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: ExecuteNotifyInfo();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: ExecuteNotifyInfo(int32_t exitCode, const ::std::wstring& standardOutput, const ::std::wstring& standardError);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 665368294; }
	
	public: int32_t getExitCode() { return exitCode; }
	public: void setExitCode(int32_t v);
	public: ::std::wstring getStandardOutput() { return standardOutput; }
	public: void setStandardOutput(::std::wstring v);
	public: ::std::wstring getStandardError() { return standardError; }
	public: void setStandardError(::std::wstring v);
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// ExecuteOptions
// typeId=1032737639

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// This class contains additional parameters for
/// {@link FileSystemService#executeNotifyExit(String[], ExecuteOptions)}.
/// </summary>
class ExecuteOptions : public BSerializable {
	/// <summary>
	/// Application defined field.
	/// </summary>
	/// <remarks>
	/// This value is passed to the field {@link NotifyInfo#extraInfo}.
	/// </remarks>
	protected: ::std::wstring extraInfo;
	/// <summary>
	/// Send this text to the standard input pipe of the process.
	/// </summary>
	protected: ::std::wstring standardInput;
	/// <summary>
	/// Read characters from the processes standard output pipe.
	/// </summary>
	protected: bool captureOutput;
	/// <summary>
	/// Read characters from  the processes standard error pipe.
	/// </summary>
	protected: bool captureError;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: ExecuteOptions();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: ExecuteOptions(const ::std::wstring& extraInfo, const ::std::wstring& standardInput, bool captureOutput, bool captureError);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1032737639; }
	
	public: ::std::wstring getExtraInfo() { return extraInfo; }
	public: void setExtraInfo(::std::wstring v);
	public: ::std::wstring getStandardInput() { return standardInput; }
	public: void setStandardInput(::std::wstring v);
	public: bool getCaptureOutput() { return captureOutput; }
	public: void setCaptureOutput(bool v);
	public: bool getCaptureError() { return captureError; }
	public: void setCaptureError(bool v);
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// FileInfo
// typeId=1100528120

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// This class contains information about a file or directory.
/// </summary>
class FileInfo : public BSerializable {
	/// <summary>
	/// File name.
	/// </summary>
	protected: ::std::wstring name;
	/// <summary>
	/// File size if less than 2^31.
	/// </summary>
	/// <remarks>
	/// This member is negative if the file size is greater than or equal to 2^31.
	/// </remarks>
	protected: int32_t size;
	/// <summary>
	/// File size.
	/// </summary>
	/// <remarks>
	/// (This member is a string value in JavaScript)
	/// </remarks>
	protected: int64_t sizeL;
	/// <summary>
	/// True for directory.
	/// </summary>
	protected: bool directory;
	/// <summary>
	/// True for read-only file.
	/// </summary>
	protected: bool readonly;
	/// <summary>
	/// Last modified date.
	/// </summary>
	protected: BDateTime lastModified;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: FileInfo();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: FileInfo(const ::std::wstring& name, int32_t size, int64_t sizeL, bool directory, bool readonly, const BDateTime& lastModified);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1100528120; }
	
	public: ::std::wstring getName() { return name; }
	public: void setName(::std::wstring v);
	public: int32_t getSize() { return size; }
	public: void setSize(int32_t v);
	public: int64_t getSizeL() { return sizeL; }
	public: void setSizeL(int64_t v);
	public: bool getDirectory() { return directory; }
	public: void setDirectory(bool v);
	public: bool getReadonly() { return readonly; }
	public: void setReadonly(bool v);
	public: BDateTime getLastModified() { return lastModified; }
	public: void setLastModified(BDateTime v);
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// FindOptions
// typeId=1092766252

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// Unused.
/// </summary>
class FindOptions : public BSerializable {
	protected: ::std::wstring reserved;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: FindOptions();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: FindOptions(const ::std::wstring& reserved);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1092766252; }
	
	public: ::std::wstring getReserved() { return reserved; }
	public: void setReserved(::std::wstring v);
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// WatchFolderNotifyInfo
// typeId=9906860

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// Notification information about a change in a watched folder.
/// </summary>
class WatchFolderNotifyInfo : public NotifyInfo {
	/// <summary>
	/// Information about the related file.
	/// </summary>
	protected: PFileInfo fileInfo;
	/// <summary>
	/// Kind of change.
	/// </summary>
	protected: EWatchFolderNotifyKind kind;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: WatchFolderNotifyInfo();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: WatchFolderNotifyInfo(const PFileInfo& fileInfo, EWatchFolderNotifyKind kind);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 9906860; }
	
	public: PFileInfo getFileInfo() { return fileInfo; }
	public: void setFileInfo(PFileInfo v);
	public: EWatchFolderNotifyKind getKind() { return kind; }
	public: void setKind(EWatchFolderNotifyKind v);
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// Forward Declaration of class DispatcherService

namespace com { namespace wilutions { namespace jsfs { 

class DispatcherService; 
typedef byps_ptr< DispatcherService > PDispatcherService; 

}}}

//-------------------------------------------------
// Forward Declaration of class FileSystemNotify

namespace com { namespace wilutions { namespace jsfs { 

class FileSystemNotify; 
typedef byps_ptr< FileSystemNotify > PFileSystemNotify; 

}}}

//-------------------------------------------------
// Forward Declaration of class FileSystemService

namespace com { namespace wilutions { namespace jsfs { 

class FileSystemService; 
typedef byps_ptr< FileSystemService > PFileSystemService; 

}}}

//-------------------------------------------------
// DispatcherService

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// This class defines the interface of the JSFS Dispatcher.
/// </summary>
/// <remarks>
/// The functions in this interface have to be called with a token obtained from an
/// authentication process with the token service of "Your Web Application".
/// </remarks>
class DispatcherService : public virtual BRemote {
	
	/// <summary>
	/// Register a file system service.
	/// </summary>
	/// <remarks>
	/// This function is called from the JSFS Agent when it starts.
	/// The JSFS Dispatcher maps the given token on the given service. The browser
	/// requests this service by a call to {@link #getService(String, boolean)}.
	/// </remarks>
	public: virtual void registerService(const ::std::wstring& token, const PFileSystemService& service)  = 0;
	public: virtual void registerService(const ::std::wstring& token, const PFileSystemService& service, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Unregister a file system service.
	/// </summary>
	/// <remarks>
	/// This function is called from the JSFS Agent if it terminates.
	/// </remarks>
	public: virtual void unregisterService(const ::std::wstring& token)  = 0;
	public: virtual void unregisterService(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Get the file system service for the given token.
	/// </summary>
	public: virtual PFileSystemService getService(const ::std::wstring& token, bool onlyHere)  = 0;
	public: virtual void getService(const ::std::wstring& token, bool onlyHere, ::std::function< void (PFileSystemService, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Register a notify service.
	/// </summary>
	/// <remarks>
	/// The notify service is implemented by JavaScript inside the web page. The JSFS Agent requests
	/// the notify service in order to send messages to the browser.
	/// </remarks>
	public: virtual void registerNotifyService(const ::std::wstring& token, const PFileSystemNotify& service)  = 0;
	public: virtual void registerNotifyService(const ::std::wstring& token, const PFileSystemNotify& service, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Unregister a notify service.
	/// </summary>
	/// <remarks>
	/// This function should be called by the browser when the web page is unloaded.
	/// </remarks>
	public: virtual void unregisterNotifyService(const ::std::wstring& token)  = 0;
	public: virtual void unregisterNotifyService(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Get the notify service interface for a given token.
	/// </summary>
	public: virtual PFileSystemNotify getNotifyService(const ::std::wstring& token, bool onlyHere)  = 0;
	public: virtual void getNotifyService(const ::std::wstring& token, bool onlyHere, ::std::function< void (PFileSystemNotify, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Keep the token-to-services-associations alive.
	/// </summary>
	/// <remarks>
	/// Keeps the application server session alive. If the session has already been invalidated,
	/// the BYPS framework triggers a re-login. This will cause an authentication with "Your Web Application"
	/// and the services will be registered again.
	/// </remarks>
	public: virtual void keepAlive(const ::std::wstring& token)  = 0;
	public: virtual void keepAlive(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	
};

}}}
//-------------------------------------------------
// Stub class BStub_DispatcherService

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BStub_DispatcherService;
typedef byps_ptr<BStub_DispatcherService> PStub_DispatcherService;

class BStub_DispatcherService : public BStub, public virtual DispatcherService {
	
	public: BStub_DispatcherService(PTransport transport);	
	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1153231042; }
	
	public: virtual void registerService(const ::std::wstring& token, const PFileSystemService& service) ;
	public: virtual void registerService(const ::std::wstring& token, const PFileSystemService& service, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual void unregisterService(const ::std::wstring& token) ;
	public: virtual void unregisterService(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual PFileSystemService getService(const ::std::wstring& token, bool onlyHere) ;
	public: virtual void getService(const ::std::wstring& token, bool onlyHere, ::std::function< void (PFileSystemService, BException ex) > asyncResult) ;
	
	public: virtual void registerNotifyService(const ::std::wstring& token, const PFileSystemNotify& service) ;
	public: virtual void registerNotifyService(const ::std::wstring& token, const PFileSystemNotify& service, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual void unregisterNotifyService(const ::std::wstring& token) ;
	public: virtual void unregisterNotifyService(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual PFileSystemNotify getNotifyService(const ::std::wstring& token, bool onlyHere) ;
	public: virtual void getNotifyService(const ::std::wstring& token, bool onlyHere, ::std::function< void (PFileSystemNotify, BException ex) > asyncResult) ;
	
	public: virtual void keepAlive(const ::std::wstring& token) ;
	public: virtual void keepAlive(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	
};
}}}


//-------------------------------------------------
// FileSystemNotify

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// Notification interface.
/// </summary>
/// <remarks>
/// This interface is used by the JFSF Agent to notify the browser about an event.
/// </remarks>
class FileSystemNotify : public virtual BRemote {
	
	/// <summary>
	/// Notify the browser about an event.
	/// </summary>
	public: virtual void notify(const PNotifyInfo& notifyInfo)  = 0;
	public: virtual void notify(const PNotifyInfo& notifyInfo, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	
};

}}}
//-------------------------------------------------
// Skeleton class BSkeleton_FileSystemNotify
// Your interface implementation class has to be derived from this skeleton.
// Either provide an asynchronous or a synchronous function in your subclass.

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BSkeleton_FileSystemNotify;
typedef byps_ptr<BSkeleton_FileSystemNotify> PSkeleton_FileSystemNotify;

class BSkeleton_FileSystemNotify : public BSkeleton, public virtual FileSystemNotify {
	
	public: virtual BTYPEID BSerializable_getTypeId() { return 544795964; }
	
	public: virtual void notify(const PNotifyInfo& notifyInfo) ;
	public: virtual void notify(const PNotifyInfo& notifyInfo, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	
};
}}}

//-------------------------------------------------
// Stub class BStub_FileSystemNotify

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BStub_FileSystemNotify;
typedef byps_ptr<BStub_FileSystemNotify> PStub_FileSystemNotify;

class BStub_FileSystemNotify : public BStub, public virtual FileSystemNotify {
	
	public: BStub_FileSystemNotify(PTransport transport);	
	
	public: virtual BTYPEID BSerializable_getTypeId() { return 544795964; }
	
	public: virtual void notify(const PNotifyInfo& notifyInfo) ;
	public: virtual void notify(const PNotifyInfo& notifyInfo, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	
};
}}}


//-------------------------------------------------
// FileSystemService

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

/// <summary>
/// This is the service interface of the JSFS Agent.
/// </summary>
class FileSystemService : public virtual BRemote {
	
	/// <summary>
	/// List files in a directory.
	/// </summary>
	public: virtual byps_ptr< ::std::vector< PFileInfo > > findFiles(const ::std::wstring& path, const PFindOptions& findOptions)  = 0;
	public: virtual void findFiles(const ::std::wstring& path, const PFindOptions& findOptions, ::std::function< void (byps_ptr< ::std::vector< PFileInfo > >, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Read text file.
	/// </summary>
	/// <remarks>
	/// Read all text content from the given file.
	/// </remarks>
	public: virtual ::std::wstring readAllText(const ::std::wstring& path)  = 0;
	public: virtual void readAllText(const ::std::wstring& path, ::std::function< void (::std::wstring, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Write text file.
	/// </summary>
	/// <remarks>
	/// Write the supplied text into the file. An existing file will be overwritten.
	/// </remarks>
	public: virtual void writeAllText(const ::std::wstring& path, const ::std::wstring& text)  = 0;
	public: virtual void writeAllText(const ::std::wstring& path, const ::std::wstring& text, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Execute a program.
	/// </summary>
	/// <remarks>
	/// If opts is null, the process is started synchronously. Otherwise it is started in background and
	/// the JSFS Agent will notify the caller via the {@link FileSystemNotify#notify(NotifyInfo)} function
	/// when the process has terminated.
	/// The first element in args[] is assumed to be the application name to be started. If only
	/// {@link ExecuteOptions#extraInfo} is set in opts, the first element in args can also be a
	/// file name. In this case the file is opened via ShellExecute with verb "open".
	/// </remarks>
	public: virtual void executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts)  = 0;
	public: virtual void executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Begin watching a folder.
	/// </summary>
	/// <remarks>
	/// Watch a folder and optional all sub-folders for changes.
	/// If a change occurs, the JSFS Agent invokes the {@link FileSystemNotify#notify(NotifyInfo)} function and
	/// passes a {@link WatchFolderNotifyInfo} object.
	/// </remarks>
	public: virtual int32_t beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo)  = 0;
	public: virtual void beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo, ::std::function< void (int32_t, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Stop watching a folder.
	/// </summary>
	/// <remarks>
	/// Call this function to stop watching a folder and to release resources in the JSFS Agent.
	/// </remarks>
	public: virtual void endWatchFolder(int32_t handle)  = 0;
	public: virtual void endWatchFolder(int32_t handle, ::std::function< void (bool, BException ex) > asyncResult)  = 0;
	
	/// <summary>
	/// Read file contents.
	/// </summary>
	/// <remarks>
	/// Returns an input stream for reading the contents of the given file.
	/// </remarks>
	public: virtual PContentStream readFile(const ::std::wstring& path)  = 0;
	public: virtual void readFile(const ::std::wstring& path, ::std::function< void (PContentStream, BException ex) > asyncResult)  = 0;
	
	
};

}}}
//-------------------------------------------------
// Skeleton class BSkeleton_FileSystemService
// Your interface implementation class has to be derived from this skeleton.
// Either provide an asynchronous or a synchronous function in your subclass.

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BSkeleton_FileSystemService;
typedef byps_ptr<BSkeleton_FileSystemService> PSkeleton_FileSystemService;

class BSkeleton_FileSystemService : public BSkeleton, public virtual FileSystemService {
	
	public: virtual BTYPEID BSerializable_getTypeId() { return 145996442; }
	
	public: virtual byps_ptr< ::std::vector< PFileInfo > > findFiles(const ::std::wstring& path, const PFindOptions& findOptions) ;
	public: virtual void findFiles(const ::std::wstring& path, const PFindOptions& findOptions, ::std::function< void (byps_ptr< ::std::vector< PFileInfo > >, BException ex) > asyncResult) ;
	
	public: virtual ::std::wstring readAllText(const ::std::wstring& path) ;
	public: virtual void readAllText(const ::std::wstring& path, ::std::function< void (::std::wstring, BException ex) > asyncResult) ;
	
	public: virtual void writeAllText(const ::std::wstring& path, const ::std::wstring& text) ;
	public: virtual void writeAllText(const ::std::wstring& path, const ::std::wstring& text, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual void executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts) ;
	public: virtual void executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual int32_t beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo) ;
	public: virtual void beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo, ::std::function< void (int32_t, BException ex) > asyncResult) ;
	
	public: virtual void endWatchFolder(int32_t handle) ;
	public: virtual void endWatchFolder(int32_t handle, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual PContentStream readFile(const ::std::wstring& path) ;
	public: virtual void readFile(const ::std::wstring& path, ::std::function< void (PContentStream, BException ex) > asyncResult) ;
	
	
};
}}}

//-------------------------------------------------
// Stub class BStub_FileSystemService

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BStub_FileSystemService;
typedef byps_ptr<BStub_FileSystemService> PStub_FileSystemService;

class BStub_FileSystemService : public BStub, public virtual FileSystemService {
	
	public: BStub_FileSystemService(PTransport transport);	
	
	public: virtual BTYPEID BSerializable_getTypeId() { return 145996442; }
	
	public: virtual byps_ptr< ::std::vector< PFileInfo > > findFiles(const ::std::wstring& path, const PFindOptions& findOptions) ;
	public: virtual void findFiles(const ::std::wstring& path, const PFindOptions& findOptions, ::std::function< void (byps_ptr< ::std::vector< PFileInfo > >, BException ex) > asyncResult) ;
	
	public: virtual ::std::wstring readAllText(const ::std::wstring& path) ;
	public: virtual void readAllText(const ::std::wstring& path, ::std::function< void (::std::wstring, BException ex) > asyncResult) ;
	
	public: virtual void writeAllText(const ::std::wstring& path, const ::std::wstring& text) ;
	public: virtual void writeAllText(const ::std::wstring& path, const ::std::wstring& text, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual void executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts) ;
	public: virtual void executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual int32_t beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo) ;
	public: virtual void beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo, ::std::function< void (int32_t, BException ex) > asyncResult) ;
	
	public: virtual void endWatchFolder(int32_t handle) ;
	public: virtual void endWatchFolder(int32_t handle, ::std::function< void (bool, BException ex) > asyncResult) ;
	
	public: virtual PContentStream readFile(const ::std::wstring& path) ;
	public: virtual void readFile(const ::std::wstring& path, ::std::function< void (PContentStream, BException ex) > asyncResult) ;
	
	
};
}}}


//-------------------------------------------------
namespace com { namespace wilutions { namespace jsfs { 

class BRegistry_JSFS : public BRegistry { 
public:
	BRegistry_JSFS();
	virtual ~BRegistry_JSFS() {}
};

}}}

namespace com { namespace wilutions { namespace jsfs { 
using namespace ::byps;

class BApiDescriptor_JSFS { 
	/**
	 * API serialisation version: 1.0.0.0
	 */
	public: const static int64_t VERSION = 100000000000000LL;
	public: static PApiDescriptor instance();
};

}}}

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BClient_JSFS;
typedef byps_ptr<BClient_JSFS> PClient_JSFS;

class BClient_JSFS : public BClient { 

	public: static PClient_JSFS createClient(PTransportFactory transportFactory);
	
	public: static PClient_JSFS createClientR(PTransport transport);
	
	public: void addRemote(PSkeleton_FileSystemNotify remoteSkeleton);
	
	public: void addRemote(PSkeleton_FileSystemService remoteSkeleton);
	
	protected: BClient_JSFS(PTransportFactory transportFactory); 
	
	protected: BClient_JSFS(PTransport transport); 
	
	public: virtual ~BClient_JSFS() {}
	
	public: virtual PRemote getStub(int remoteId);
	
	public: const com::wilutions::jsfs::PDispatcherService dispatcherService;
	public: const com::wilutions::jsfs::PFileSystemNotify fileSystemNotify;
	public: const com::wilutions::jsfs::PFileSystemService fileSystemService;
	
};

}}}

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BServer_JSFS;
typedef byps_ptr<BServer_JSFS> PServer_JSFS;

class BServer_JSFS : public BServer { 

	public: static PServer_JSFS createServer(PTransportFactory transportFactory);
	
	public: static PServer_JSFS createServerR(PTransport transport);
	
	public: void addRemote(PSkeleton_FileSystemNotify remoteSkeleton);
	
	public: void addRemote(PSkeleton_FileSystemService remoteSkeleton);
	
	protected: BServer_JSFS(PTransportFactory transportFactory); 
	
	protected: BServer_JSFS(PTransport transport); 
	
};

}}}


#endif
