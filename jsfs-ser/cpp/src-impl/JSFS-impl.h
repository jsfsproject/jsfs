#ifndef __JSFS_impl_H__
#define __JSFS_impl_H__

#include <Byps-impl.h>
#include <JSFS-api.h>


//-------------------------------------------------
// Forward Declaration of class BRequest_DispatcherService_getNotifyService

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_DispatcherService_getNotifyService; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_DispatcherService_getService

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_DispatcherService_getService; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_DispatcherService_keepAlive

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_DispatcherService_keepAlive; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_DispatcherService_registerNotifyService

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_DispatcherService_registerNotifyService; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_DispatcherService_registerService

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_DispatcherService_registerService; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_DispatcherService_unregisterNotifyService

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_DispatcherService_unregisterNotifyService; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_DispatcherService_unregisterService

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_DispatcherService_unregisterService; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemNotify_notify

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemNotify_notify; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_beginWatchFolder

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_beginWatchFolder; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_endWatchFolder

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_endWatchFolder; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_executeNotifyExit

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_executeNotifyExit; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_findFiles

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_findFiles; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_readAllText

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_readAllText; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_readFile

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_readFile; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_uploadFile

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_uploadFile; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_uploadFilesMultipartFormdata

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_uploadFilesMultipartFormdata; 

}}}

//-------------------------------------------------
// Forward Declaration of class BRequest_FileSystemService_writeAllText

namespace com { namespace wilutions { namespace jsfs { 

class BRequest_FileSystemService_writeAllText; 

}}}

//-------------------------------------------------
// BRequest_DispatcherService_getNotifyService
// typeId=1090607752

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_DispatcherService_getNotifyService : public BMethodRequest {
	public: ::std::wstring token;
	public: bool onlyHere;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_DispatcherService_getNotifyService();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_DispatcherService_getNotifyService(const ::std::wstring& token, bool onlyHere);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1090607752; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_DispatcherService_getService
// typeId=575037953

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_DispatcherService_getService : public BMethodRequest {
	public: ::std::wstring token;
	public: bool onlyHere;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_DispatcherService_getService();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_DispatcherService_getService(const ::std::wstring& token, bool onlyHere);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 575037953; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_DispatcherService_keepAlive
// typeId=1609273478

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_DispatcherService_keepAlive : public BMethodRequest {
	public: ::std::wstring token;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_DispatcherService_keepAlive();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_DispatcherService_keepAlive(const ::std::wstring& token);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1609273478; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_DispatcherService_registerNotifyService
// typeId=1849102471

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_DispatcherService_registerNotifyService : public BMethodRequest {
	public: ::std::wstring token;
	public: PFileSystemNotify service;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_DispatcherService_registerNotifyService();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_DispatcherService_registerNotifyService(const ::std::wstring& token, const PFileSystemNotify& service);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1849102471; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_DispatcherService_registerService
// typeId=1833696176

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_DispatcherService_registerService : public BMethodRequest {
	public: ::std::wstring token;
	public: PFileSystemService service;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_DispatcherService_registerService();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_DispatcherService_registerService(const ::std::wstring& token, const PFileSystemService& service);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1833696176; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_DispatcherService_unregisterNotifyService
// typeId=1366717454

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_DispatcherService_unregisterNotifyService : public BMethodRequest {
	public: ::std::wstring token;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_DispatcherService_unregisterNotifyService();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_DispatcherService_unregisterNotifyService(const ::std::wstring& token);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1366717454; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_DispatcherService_unregisterService
// typeId=1542825705

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_DispatcherService_unregisterService : public BMethodRequest {
	public: ::std::wstring token;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_DispatcherService_unregisterService();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_DispatcherService_unregisterService(const ::std::wstring& token);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1542825705; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemNotify_notify
// typeId=481066845

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemNotify_notify : public BMethodRequest {
	public: PNotifyInfo notifyInfo;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemNotify_notify();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemNotify_notify(const PNotifyInfo& notifyInfo);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 481066845; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_beginWatchFolder
// typeId=1762179110

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_beginWatchFolder : public BMethodRequest {
	public: ::std::wstring dir;
	public: bool recursive;
	public: ::std::wstring extraInfo;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_beginWatchFolder();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1762179110; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_endWatchFolder
// typeId=1124739608

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_endWatchFolder : public BMethodRequest {
	public: int32_t handle;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_endWatchFolder();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_endWatchFolder(int32_t handle);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1124739608; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_executeNotifyExit
// typeId=1824869366

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_executeNotifyExit : public BMethodRequest {
	public: byps_ptr< BArray1< ::std::wstring > > args;
	public: PExecuteOptions opts;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_executeNotifyExit();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1824869366; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_findFiles
// typeId=1131301080

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_findFiles : public BMethodRequest {
	public: ::std::wstring path;
	public: PFindOptions findOptions;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_findFiles();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_findFiles(const ::std::wstring& path, const PFindOptions& findOptions);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1131301080; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_readAllText
// typeId=1078989294

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_readAllText : public BMethodRequest {
	public: ::std::wstring path;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_readAllText();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_readAllText(const ::std::wstring& path);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1078989294; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_readFile
// typeId=706034600

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_readFile : public BMethodRequest {
	public: ::std::wstring path;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_readFile();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_readFile(const ::std::wstring& path);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 706034600; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_uploadFile
// typeId=744806851

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_uploadFile : public BMethodRequest {
	public: ::std::wstring path;
	public: ::std::wstring url;
	public: ::std::wstring method;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_uploadFile();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_uploadFile(const ::std::wstring& path, const ::std::wstring& url, const ::std::wstring& method);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 744806851; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_uploadFilesMultipartFormdata
// typeId=240503306

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_uploadFilesMultipartFormdata : public BMethodRequest {
	public: byps_ptr< BArray1< PFormItem > > items;
	public: ::std::wstring url;
	public: ::std::wstring method;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_uploadFilesMultipartFormdata();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_uploadFilesMultipartFormdata(const byps_ptr< BArray1< PFormItem > >& items, const ::std::wstring& url, const ::std::wstring& method);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 240503306; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BRequest_FileSystemService_writeAllText
// typeId=1925305675

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BRequest_FileSystemService_writeAllText : public BMethodRequest {
	public: ::std::wstring path;
	public: ::std::wstring text;
	
	// checkpoint byps.gen.cpp.GenApiClass:488
	public: BRequest_FileSystemService_writeAllText();
	// checkpoint byps.gen.cpp.GenApiClass:535
	public: BRequest_FileSystemService_writeAllText(const ::std::wstring& path, const ::std::wstring& text);	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1925305675; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
	public: virtual void execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult);
};

}}}

//-------------------------------------------------
// BResult_10
// typeId=964561600

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BResult_10 : public BSerializable {
	public: ::std::wstring result;
	// checkpoint byps.gen.cpp.GenApiClass:473
	public: BResult_10(::std::wstring result = ::std::wstring()) : result(result) {}	
	public: virtual BTYPEID BSerializable_getTypeId() { return 964561600; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// BResult_1439246415
// typeId=1733426638

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BResult_1439246415 : public BSerializable {
	public: byps_ptr< ::std::vector< com::wilutions::jsfs::PFileInfo > > result;
	// checkpoint byps.gen.cpp.GenApiClass:473
	public: BResult_1439246415(byps_ptr< ::std::vector< com::wilutions::jsfs::PFileInfo > > result = byps_ptr< ::std::vector< com::wilutions::jsfs::PFileInfo > >()) : result(result) {}	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1733426638; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// BResult_15
// typeId=964561595

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BResult_15 : public BSerializable {
	public: PContentStream result;
	// checkpoint byps.gen.cpp.GenApiClass:473
	public: BResult_15(PContentStream result = PContentStream()) : result(result) {}	
	public: virtual BTYPEID BSerializable_getTypeId() { return 964561595; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// BResult_1816639285
// typeId=1354059712

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BResult_1816639285 : public BSerializable {
	public: com::wilutions::jsfs::PFileSystemNotify result;
	// checkpoint byps.gen.cpp.GenApiClass:473
	public: BResult_1816639285(com::wilutions::jsfs::PFileSystemNotify result = com::wilutions::jsfs::PFileSystemNotify()) : result(result) {}	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1354059712; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// BResult_19
// typeId=964561591

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BResult_19 : public BSerializable {
	public: bool result;
	// checkpoint byps.gen.cpp.GenApiClass:473
	public: BResult_19(bool result = bool()) : result(result) {}	
	public: virtual BTYPEID BSerializable_getTypeId() { return 964561591; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// BResult_336045129
// typeId=1815527676

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BResult_336045129 : public BSerializable {
	public: com::wilutions::jsfs::PFileSystemService result;
	// checkpoint byps.gen.cpp.GenApiClass:473
	public: BResult_336045129(com::wilutions::jsfs::PFileSystemService result = com::wilutions::jsfs::PFileSystemService()) : result(result) {}	
	public: virtual BTYPEID BSerializable_getTypeId() { return 1815527676; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

//-------------------------------------------------
// BResult_5
// typeId=169662220

namespace com { namespace wilutions { namespace jsfs { 

using namespace ::byps;

class BResult_5 : public BSerializable {
	public: int32_t result;
	// checkpoint byps.gen.cpp.GenApiClass:473
	public: BResult_5(int32_t result = int32_t()) : result(result) {}	
	public: virtual BTYPEID BSerializable_getTypeId() { return 169662220; }
	
	// checkpoint byps.gen.cpp.GenApiClass:871
	public: void serialize(BIO& ar, const BVERSION version);
};

}}}

namespace com { namespace wilutions { namespace jsfs { 

// Serializer for byte[]
void BSerializer_1374008726(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_getNotifyService
void BSerializer_1090607752(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_getService
void BSerializer_575037953(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_keepAlive
void BSerializer_1609273478(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_registerNotifyService
void BSerializer_1849102471(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_registerService
void BSerializer_1833696176(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_unregisterNotifyService
void BSerializer_1366717454(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_DispatcherService_unregisterService
void BSerializer_1542825705(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemNotify_notify
void BSerializer_481066845(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_beginWatchFolder
void BSerializer_1762179110(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_endWatchFolder
void BSerializer_1124739608(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_executeNotifyExit
void BSerializer_1824869366(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_findFiles
void BSerializer_1131301080(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_readAllText
void BSerializer_1078989294(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_readFile
void BSerializer_706034600(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_uploadFile
void BSerializer_744806851(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_uploadFilesMultipartFormdata
void BSerializer_240503306(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BRequest_FileSystemService_writeAllText
void BSerializer_1925305675(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BResult_10
void BSerializer_964561600(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BResult_1439246415
void BSerializer_1733426638(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BResult_15
void BSerializer_964561595(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BResult_1816639285
void BSerializer_1354059712(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BResult_19
void BSerializer_964561591(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BResult_336045129
void BSerializer_1815527676(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BResult_5
void BSerializer_169662220(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BStub_DispatcherService
void BSerializer_1153231042(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BStub_FileSystemNotify
void BSerializer_544795964(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.BStub_FileSystemService
void BSerializer_145996442(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.ExecuteNotifyInfo
void BSerializer_665368294(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.ExecuteOptions
void BSerializer_1032737639(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.FileInfo
void BSerializer_1100528120(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.FileSystemServiceC
void BSerializer_1381128722(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.FindOptions
void BSerializer_1092766252(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.FormItem
void BSerializer_979378962(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.FormItem[]
void BSerializer_566696346(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.NotifyInfo
void BSerializer_1274131736(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for com.wilutions.jsfs.WatchFolderNotifyInfo
void BSerializer_9906860(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for java.lang.String[]
void BSerializer_1888107655(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);
// Serializer for java.util.List<com.wilutions.jsfs.FileInfo>
void BSerializer_1439246415(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase);

}}}


#endif
