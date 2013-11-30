#include "JSFS-impl.h"
using namespace ::std;
using namespace ::byps;


namespace com { namespace wilutions { namespace jsfs { 

void operator & (BIO& ar, EWatchFolderNotifyKind& e) {
	int32_t v = static_cast<int32_t>(e);
	ar & v;
	if (ar.is_loading) e = static_cast<EWatchFolderNotifyKind>(v);
}

}}}

namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_DispatcherService_getNotifyService
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_DispatcherService_getNotifyService::BRequest_DispatcherService_getNotifyService() : BMethodRequest(963182355) {
	onlyHere = false;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_DispatcherService_getNotifyService::BRequest_DispatcherService_getNotifyService(const ::std::wstring& token, bool onlyHere)
	: BMethodRequest(963182355) 
	, token(token)
	, onlyHere(onlyHere)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_DispatcherService_getNotifyService::serialize(BIO& ar, const BVERSION version) {
	ar & this->onlyHere;
	ar & this->token;
}
void com::wilutions::jsfs::BRequest_DispatcherService_getNotifyService::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PDispatcherService __byps__remoteT = byps_ptr_cast<DispatcherService>(__byps__remote);
	__byps__remoteT->getNotifyService(token, onlyHere, [__byps__asyncResult](PFileSystemNotify __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_1816639285(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1090607752(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_DispatcherService_getNotifyService& r = * dynamic_cast< com::wilutions::jsfs::BRequest_DispatcherService_getNotifyService*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_DispatcherService_getNotifyService());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_DispatcherService_getService
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_DispatcherService_getService::BRequest_DispatcherService_getService() : BMethodRequest(963182355) {
	onlyHere = false;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_DispatcherService_getService::BRequest_DispatcherService_getService(const ::std::wstring& token, bool onlyHere)
	: BMethodRequest(963182355) 
	, token(token)
	, onlyHere(onlyHere)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_DispatcherService_getService::serialize(BIO& ar, const BVERSION version) {
	ar & this->onlyHere;
	ar & this->token;
}
void com::wilutions::jsfs::BRequest_DispatcherService_getService::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PDispatcherService __byps__remoteT = byps_ptr_cast<DispatcherService>(__byps__remote);
	__byps__remoteT->getService(token, onlyHere, [__byps__asyncResult](PFileSystemService __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_336045129(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_575037953(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_DispatcherService_getService& r = * dynamic_cast< com::wilutions::jsfs::BRequest_DispatcherService_getService*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_DispatcherService_getService());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_DispatcherService_keepAlive
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_DispatcherService_keepAlive::BRequest_DispatcherService_keepAlive() : BMethodRequest(963182355) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_DispatcherService_keepAlive::BRequest_DispatcherService_keepAlive(const ::std::wstring& token)
	: BMethodRequest(963182355) 
	, token(token)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_DispatcherService_keepAlive::serialize(BIO& ar, const BVERSION version) {
	ar & this->token;
}
void com::wilutions::jsfs::BRequest_DispatcherService_keepAlive::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PDispatcherService __byps__remoteT = byps_ptr_cast<DispatcherService>(__byps__remote);
	__byps__remoteT->keepAlive(token, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1609273478(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_DispatcherService_keepAlive& r = * dynamic_cast< com::wilutions::jsfs::BRequest_DispatcherService_keepAlive*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_DispatcherService_keepAlive());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_DispatcherService_registerNotifyService
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_DispatcherService_registerNotifyService::BRequest_DispatcherService_registerNotifyService() : BMethodRequest(963182355) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_DispatcherService_registerNotifyService::BRequest_DispatcherService_registerNotifyService(const ::std::wstring& token, const PFileSystemNotify& service)
	: BMethodRequest(963182355) 
	, token(token)
	, service(service)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_DispatcherService_registerNotifyService::serialize(BIO& ar, const BVERSION version) {
	ar & this->token;
	ar & this->service;
}
void com::wilutions::jsfs::BRequest_DispatcherService_registerNotifyService::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PDispatcherService __byps__remoteT = byps_ptr_cast<DispatcherService>(__byps__remote);
	__byps__remoteT->registerNotifyService(token, service, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1849102471(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_DispatcherService_registerNotifyService& r = * dynamic_cast< com::wilutions::jsfs::BRequest_DispatcherService_registerNotifyService*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_DispatcherService_registerNotifyService());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_DispatcherService_registerService
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_DispatcherService_registerService::BRequest_DispatcherService_registerService() : BMethodRequest(963182355) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_DispatcherService_registerService::BRequest_DispatcherService_registerService(const ::std::wstring& token, const PFileSystemService& service)
	: BMethodRequest(963182355) 
	, token(token)
	, service(service)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_DispatcherService_registerService::serialize(BIO& ar, const BVERSION version) {
	ar & this->token;
	ar & this->service;
}
void com::wilutions::jsfs::BRequest_DispatcherService_registerService::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PDispatcherService __byps__remoteT = byps_ptr_cast<DispatcherService>(__byps__remote);
	__byps__remoteT->registerService(token, service, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1833696176(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_DispatcherService_registerService& r = * dynamic_cast< com::wilutions::jsfs::BRequest_DispatcherService_registerService*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_DispatcherService_registerService());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_DispatcherService_unregisterNotifyService
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_DispatcherService_unregisterNotifyService::BRequest_DispatcherService_unregisterNotifyService() : BMethodRequest(963182355) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_DispatcherService_unregisterNotifyService::BRequest_DispatcherService_unregisterNotifyService(const ::std::wstring& token)
	: BMethodRequest(963182355) 
	, token(token)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_DispatcherService_unregisterNotifyService::serialize(BIO& ar, const BVERSION version) {
	ar & this->token;
}
void com::wilutions::jsfs::BRequest_DispatcherService_unregisterNotifyService::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PDispatcherService __byps__remoteT = byps_ptr_cast<DispatcherService>(__byps__remote);
	__byps__remoteT->unregisterNotifyService(token, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1366717454(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_DispatcherService_unregisterNotifyService& r = * dynamic_cast< com::wilutions::jsfs::BRequest_DispatcherService_unregisterNotifyService*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_DispatcherService_unregisterNotifyService());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_DispatcherService_unregisterService
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_DispatcherService_unregisterService::BRequest_DispatcherService_unregisterService() : BMethodRequest(963182355) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_DispatcherService_unregisterService::BRequest_DispatcherService_unregisterService(const ::std::wstring& token)
	: BMethodRequest(963182355) 
	, token(token)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_DispatcherService_unregisterService::serialize(BIO& ar, const BVERSION version) {
	ar & this->token;
}
void com::wilutions::jsfs::BRequest_DispatcherService_unregisterService::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PDispatcherService __byps__remoteT = byps_ptr_cast<DispatcherService>(__byps__remote);
	__byps__remoteT->unregisterService(token, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1542825705(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_DispatcherService_unregisterService& r = * dynamic_cast< com::wilutions::jsfs::BRequest_DispatcherService_unregisterService*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_DispatcherService_unregisterService());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_FileSystemNotify_notify
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_FileSystemNotify_notify::BRequest_FileSystemNotify_notify() : BMethodRequest(1816639285) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_FileSystemNotify_notify::BRequest_FileSystemNotify_notify(const PNotifyInfo& notifyInfo)
	: BMethodRequest(1816639285) 
	, notifyInfo(notifyInfo)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_FileSystemNotify_notify::serialize(BIO& ar, const BVERSION version) {
	ar & this->notifyInfo;
}
void com::wilutions::jsfs::BRequest_FileSystemNotify_notify::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PFileSystemNotify __byps__remoteT = byps_ptr_cast<FileSystemNotify>(__byps__remote);
	__byps__remoteT->notify(notifyInfo, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_481066845(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_FileSystemNotify_notify& r = * dynamic_cast< com::wilutions::jsfs::BRequest_FileSystemNotify_notify*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_FileSystemNotify_notify());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_FileSystemService_beginWatchFolder
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_FileSystemService_beginWatchFolder::BRequest_FileSystemService_beginWatchFolder() : BMethodRequest(336045129) {
	recursive = false;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_FileSystemService_beginWatchFolder::BRequest_FileSystemService_beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo)
	: BMethodRequest(336045129) 
	, dir(dir)
	, recursive(recursive)
	, extraInfo(extraInfo)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_FileSystemService_beginWatchFolder::serialize(BIO& ar, const BVERSION version) {
	ar & this->dir;
	ar & this->extraInfo;
	ar & this->recursive;
}
void com::wilutions::jsfs::BRequest_FileSystemService_beginWatchFolder::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PFileSystemService __byps__remoteT = byps_ptr_cast<FileSystemService>(__byps__remote);
	__byps__remoteT->beginWatchFolder(dir, recursive, extraInfo, [__byps__asyncResult](int32_t __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_5(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1762179110(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_FileSystemService_beginWatchFolder& r = * dynamic_cast< com::wilutions::jsfs::BRequest_FileSystemService_beginWatchFolder*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_FileSystemService_beginWatchFolder());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_FileSystemService_endWatchFolder
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_FileSystemService_endWatchFolder::BRequest_FileSystemService_endWatchFolder() : BMethodRequest(336045129) {
	handle = 0;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_FileSystemService_endWatchFolder::BRequest_FileSystemService_endWatchFolder(int32_t handle)
	: BMethodRequest(336045129) 
	, handle(handle)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_FileSystemService_endWatchFolder::serialize(BIO& ar, const BVERSION version) {
	ar & this->handle;
}
void com::wilutions::jsfs::BRequest_FileSystemService_endWatchFolder::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PFileSystemService __byps__remoteT = byps_ptr_cast<FileSystemService>(__byps__remote);
	__byps__remoteT->endWatchFolder(handle, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1124739608(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_FileSystemService_endWatchFolder& r = * dynamic_cast< com::wilutions::jsfs::BRequest_FileSystemService_endWatchFolder*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_FileSystemService_endWatchFolder());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_FileSystemService_executeNotifyExit
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_FileSystemService_executeNotifyExit::BRequest_FileSystemService_executeNotifyExit() : BMethodRequest(336045129) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_FileSystemService_executeNotifyExit::BRequest_FileSystemService_executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts)
	: BMethodRequest(336045129) 
	, args(args)
	, opts(opts)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_FileSystemService_executeNotifyExit::serialize(BIO& ar, const BVERSION version) {
	ar & this->args;
	ar & this->opts;
}
void com::wilutions::jsfs::BRequest_FileSystemService_executeNotifyExit::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PFileSystemService __byps__remoteT = byps_ptr_cast<FileSystemService>(__byps__remote);
	__byps__remoteT->executeNotifyExit(args, opts, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1824869366(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_FileSystemService_executeNotifyExit& r = * dynamic_cast< com::wilutions::jsfs::BRequest_FileSystemService_executeNotifyExit*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_FileSystemService_executeNotifyExit());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_FileSystemService_findFiles
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_FileSystemService_findFiles::BRequest_FileSystemService_findFiles() : BMethodRequest(336045129) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_FileSystemService_findFiles::BRequest_FileSystemService_findFiles(const ::std::wstring& path, const PFindOptions& findOptions)
	: BMethodRequest(336045129) 
	, path(path)
	, findOptions(findOptions)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_FileSystemService_findFiles::serialize(BIO& ar, const BVERSION version) {
	ar & this->path;
	ar & this->findOptions;
}
void com::wilutions::jsfs::BRequest_FileSystemService_findFiles::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PFileSystemService __byps__remoteT = byps_ptr_cast<FileSystemService>(__byps__remote);
	__byps__remoteT->findFiles(path, findOptions, [__byps__asyncResult](byps_ptr< ::std::vector< PFileInfo > > __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_1439246415(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1131301080(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_FileSystemService_findFiles& r = * dynamic_cast< com::wilutions::jsfs::BRequest_FileSystemService_findFiles*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_FileSystemService_findFiles());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_FileSystemService_readAllText
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_FileSystemService_readAllText::BRequest_FileSystemService_readAllText() : BMethodRequest(336045129) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_FileSystemService_readAllText::BRequest_FileSystemService_readAllText(const ::std::wstring& path)
	: BMethodRequest(336045129) 
	, path(path)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_FileSystemService_readAllText::serialize(BIO& ar, const BVERSION version) {
	ar & this->path;
}
void com::wilutions::jsfs::BRequest_FileSystemService_readAllText::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PFileSystemService __byps__remoteT = byps_ptr_cast<FileSystemService>(__byps__remote);
	__byps__remoteT->readAllText(path, [__byps__asyncResult](::std::wstring __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_10(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1078989294(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_FileSystemService_readAllText& r = * dynamic_cast< com::wilutions::jsfs::BRequest_FileSystemService_readAllText*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_FileSystemService_readAllText());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_FileSystemService_readFile
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_FileSystemService_readFile::BRequest_FileSystemService_readFile() : BMethodRequest(336045129) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_FileSystemService_readFile::BRequest_FileSystemService_readFile(const ::std::wstring& path)
	: BMethodRequest(336045129) 
	, path(path)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_FileSystemService_readFile::serialize(BIO& ar, const BVERSION version) {
	ar & this->path;
}
void com::wilutions::jsfs::BRequest_FileSystemService_readFile::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PFileSystemService __byps__remoteT = byps_ptr_cast<FileSystemService>(__byps__remote);
	__byps__remoteT->readFile(path, [__byps__asyncResult](PContentStream __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_15(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_706034600(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_FileSystemService_readFile& r = * dynamic_cast< com::wilutions::jsfs::BRequest_FileSystemService_readFile*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_FileSystemService_readFile());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BRequest_FileSystemService_writeAllText
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
BRequest_FileSystemService_writeAllText::BRequest_FileSystemService_writeAllText() : BMethodRequest(336045129) {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::BRequest_FileSystemService_writeAllText::BRequest_FileSystemService_writeAllText(const ::std::wstring& path, const ::std::wstring& text)
	: BMethodRequest(336045129) 
	, path(path)
	, text(text)
	{}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BRequest_FileSystemService_writeAllText::serialize(BIO& ar, const BVERSION version) {
	ar & this->path;
	ar & this->text;
}
void com::wilutions::jsfs::BRequest_FileSystemService_writeAllText::execute(PRemote __byps__remote, PAsyncResult __byps__asyncResult) {
	PFileSystemService __byps__remoteT = byps_ptr_cast<FileSystemService>(__byps__remote);
	__byps__remoteT->writeAllText(path, text, [__byps__asyncResult](bool __byps__result, BException __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1925305675(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BRequest_FileSystemService_writeAllText& r = * dynamic_cast< com::wilutions::jsfs::BRequest_FileSystemService_writeAllText*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BRequest_FileSystemService_writeAllText());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BResult_10
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BResult_10::serialize(BIO& ar, const BVERSION version) {
	ar & this->result;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_964561600(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BResult_10& r = * dynamic_cast< com::wilutions::jsfs::BResult_10*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BResult_10());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BResult_1439246415
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BResult_1439246415::serialize(BIO& ar, const BVERSION version) {
	ar & this->result;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1733426638(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BResult_1439246415& r = * dynamic_cast< com::wilutions::jsfs::BResult_1439246415*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BResult_1439246415());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BResult_15
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BResult_15::serialize(BIO& ar, const BVERSION version) {
	ar & this->result;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_964561595(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BResult_15& r = * dynamic_cast< com::wilutions::jsfs::BResult_15*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BResult_15());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BResult_1816639285
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BResult_1816639285::serialize(BIO& ar, const BVERSION version) {
	ar & this->result;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1354059712(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BResult_1816639285& r = * dynamic_cast< com::wilutions::jsfs::BResult_1816639285*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BResult_1816639285());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BResult_19
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BResult_19::serialize(BIO& ar, const BVERSION version) {
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_964561591(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BResult_19& r = * dynamic_cast< com::wilutions::jsfs::BResult_19*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BResult_19());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BResult_336045129
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BResult_336045129::serialize(BIO& ar, const BVERSION version) {
	ar & this->result;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1815527676(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BResult_336045129& r = * dynamic_cast< com::wilutions::jsfs::BResult_336045129*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BResult_336045129());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class BResult_5
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::BResult_5::serialize(BIO& ar, const BVERSION version) {
	ar & this->result;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_169662220(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::BResult_5& r = * dynamic_cast< com::wilutions::jsfs::BResult_5*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::BResult_5());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class NotifyInfo
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
NotifyInfo::NotifyInfo() {
	id = 0;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::NotifyInfo::NotifyInfo(int32_t id, const ::std::wstring& extraInfo, const ::std::wstring& error)
	: id(id)
	, extraInfo(extraInfo)
	, error(error)
	{}
void NotifyInfo::setId(int32_t v) {
	id = v;
}
void NotifyInfo::setExtraInfo(::std::wstring v) {
	extraInfo = v;
}
void NotifyInfo::setError(::std::wstring v) {
	error = v;
}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::NotifyInfo::serialize(BIO& ar, const BVERSION version) {
	ar & this->error;
	ar & this->extraInfo;
	ar & this->id;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1274131736(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::NotifyInfo& r = * dynamic_cast< com::wilutions::jsfs::NotifyInfo*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::NotifyInfo());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class ExecuteNotifyInfo
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
ExecuteNotifyInfo::ExecuteNotifyInfo() {
	exitCode = 0;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::ExecuteNotifyInfo::ExecuteNotifyInfo(int32_t exitCode, const ::std::wstring& standardOutput, const ::std::wstring& standardError)
	: exitCode(exitCode)
	, standardOutput(standardOutput)
	, standardError(standardError)
	{}
void ExecuteNotifyInfo::setExitCode(int32_t v) {
	exitCode = v;
}
void ExecuteNotifyInfo::setStandardOutput(::std::wstring v) {
	standardOutput = v;
}
void ExecuteNotifyInfo::setStandardError(::std::wstring v) {
	standardError = v;
}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::ExecuteNotifyInfo::serialize(BIO& ar, const BVERSION version) {
	NotifyInfo::serialize(ar, version);
	ar & this->exitCode;
	ar & this->standardError;
	ar & this->standardOutput;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_665368294(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::ExecuteNotifyInfo& r = * dynamic_cast< com::wilutions::jsfs::ExecuteNotifyInfo*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::ExecuteNotifyInfo());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class ExecuteOptions
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
ExecuteOptions::ExecuteOptions() {
	captureOutput = false;
	captureError = false;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::ExecuteOptions::ExecuteOptions(const ::std::wstring& extraInfo, const ::std::wstring& standardInput, bool captureOutput, bool captureError)
	: extraInfo(extraInfo)
	, standardInput(standardInput)
	, captureOutput(captureOutput)
	, captureError(captureError)
	{}
void ExecuteOptions::setExtraInfo(::std::wstring v) {
	extraInfo = v;
}
void ExecuteOptions::setStandardInput(::std::wstring v) {
	standardInput = v;
}
void ExecuteOptions::setCaptureOutput(bool v) {
	captureOutput = v;
}
void ExecuteOptions::setCaptureError(bool v) {
	captureError = v;
}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::ExecuteOptions::serialize(BIO& ar, const BVERSION version) {
	ar & this->captureError;
	ar & this->captureOutput;
	ar & this->extraInfo;
	ar & this->standardInput;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1032737639(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::ExecuteOptions& r = * dynamic_cast< com::wilutions::jsfs::ExecuteOptions*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::ExecuteOptions());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class FileInfo
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
FileInfo::FileInfo() {
	size = 0;
	sizeL = 0;
	directory = false;
	readonly = false;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::FileInfo::FileInfo(const ::std::wstring& name, int32_t size, int64_t sizeL, bool directory, bool readonly, const BDateTime& lastModified)
	: name(name)
	, size(size)
	, sizeL(sizeL)
	, directory(directory)
	, readonly(readonly)
	, lastModified(lastModified)
	{}
void FileInfo::setName(::std::wstring v) {
	name = v;
}
void FileInfo::setSize(int32_t v) {
	size = v;
}
void FileInfo::setSizeL(int64_t v) {
	sizeL = v;
}
void FileInfo::setDirectory(bool v) {
	directory = v;
}
void FileInfo::setReadonly(bool v) {
	readonly = v;
}
void FileInfo::setLastModified(BDateTime v) {
	lastModified = v;
}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::FileInfo::serialize(BIO& ar, const BVERSION version) {
	ar & this->directory;
	ar & this->lastModified;
	ar & this->name;
	ar & this->readonly;
	ar & this->size;
	ar & this->sizeL;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1100528120(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::FileInfo& r = * dynamic_cast< com::wilutions::jsfs::FileInfo*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::FileInfo());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class FindOptions
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
FindOptions::FindOptions() {
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::FindOptions::FindOptions(const ::std::wstring& reserved)
	: reserved(reserved)
	{}
void FindOptions::setReserved(::std::wstring v) {
	reserved = v;
}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::FindOptions::serialize(BIO& ar, const BVERSION version) {
	ar & this->reserved;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1092766252(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::FindOptions& r = * dynamic_cast< com::wilutions::jsfs::FindOptions*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::FindOptions());
	}
}
}}}
namespace com { namespace wilutions { namespace jsfs { 

//-------------------------------------------------
// Implementation of class WatchFolderNotifyInfo
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:489
WatchFolderNotifyInfo::WatchFolderNotifyInfo() {
	kind = com::wilutions::jsfs::EWatchFolderNotifyKind::Nothing;
}
// checkpoint byps.gen.cpp.GenApiClass:536
com::wilutions::jsfs::WatchFolderNotifyInfo::WatchFolderNotifyInfo(const PFileInfo& fileInfo, EWatchFolderNotifyKind kind)
	: fileInfo(fileInfo)
	, kind(kind)
	{}
void WatchFolderNotifyInfo::setFileInfo(PFileInfo v) {
	fileInfo = v;
}
void WatchFolderNotifyInfo::setKind(EWatchFolderNotifyKind v) {
	kind = v;
}
// checkpoint byps.gen.cpp.GenApiClass:877
void com::wilutions::jsfs::WatchFolderNotifyInfo::serialize(BIO& ar, const BVERSION version) {
	NotifyInfo::serialize(ar, version);
	ar & this->kind;
	ar & this->fileInfo;
}
}}}

// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_9906860(BIO& bio, POBJECT& , PSerializable& pObjS, void* pBase) {
	BSerializable* p = pBase ? reinterpret_cast<BSerializable*>(pBase) : pObjS.get();
	if (p) { 
		com::wilutions::jsfs::WatchFolderNotifyInfo& r = * dynamic_cast< com::wilutions::jsfs::WatchFolderNotifyInfo*>(p);
		bio & r;
	} else {
		pObjS = PSerializable(new com::wilutions::jsfs::WatchFolderNotifyInfo());
	}
}
}}}
// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1888107655(BIO& bio, POBJECT& pObj, PSerializable& , void* ) {
	void* p = pObj.get();
	if (p) { 
		BArray1< ::std::wstring > & r = * reinterpret_cast< BArray1< ::std::wstring > *>(p);
		bio & r;
	} else {
		pObj = POBJECT(new BArray1< ::std::wstring > ());
	}
}
}}}
// checkpoint byps.gen.cpp.GenApiClass:934
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_1439246415(BIO& bio, POBJECT& pObj, PSerializable& , void* ) {
	void* p = pObj.get();
	if (p) { 
		::std::vector< com::wilutions::jsfs::PFileInfo >& r = * reinterpret_cast< ::std::vector< com::wilutions::jsfs::PFileInfo >*>(p);
		bio & r;
	} else {
		pObj = POBJECT(new ::std::vector< com::wilutions::jsfs::PFileInfo >());
	}
}
}}}

namespace com { namespace wilutions { namespace jsfs { 

BStub_DispatcherService::BStub_DispatcherService(PTransport transport) 
	: BStub(transport) {}

void BStub_DispatcherService::registerService(const ::std::wstring& token, const PFileSystemService& service)  {
	BSyncResultT< bool > syncResult;	
	registerService(token, service, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_DispatcherService::registerService(const ::std::wstring& token, const PFileSystemService& service, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_DispatcherService_registerService(token, service));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
void BStub_DispatcherService::unregisterService(const ::std::wstring& token)  {
	BSyncResultT< bool > syncResult;	
	unregisterService(token, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_DispatcherService::unregisterService(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_DispatcherService_unregisterService(token));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
PFileSystemService BStub_DispatcherService::getService(const ::std::wstring& token, bool onlyHere)  {
	BSyncResultT< PFileSystemService > syncResult;	
	getService(token, onlyHere, [&syncResult](PFileSystemService v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	return syncResult.getResult();
}
void BStub_DispatcherService::getService(const ::std::wstring& token, bool onlyHere, ::std::function< void (PFileSystemService, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_DispatcherService_getService(token, onlyHere));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< PFileSystemService, BResult_336045129 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
void BStub_DispatcherService::registerNotifyService(const ::std::wstring& token, const PFileSystemNotify& service)  {
	BSyncResultT< bool > syncResult;	
	registerNotifyService(token, service, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_DispatcherService::registerNotifyService(const ::std::wstring& token, const PFileSystemNotify& service, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_DispatcherService_registerNotifyService(token, service));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
void BStub_DispatcherService::unregisterNotifyService(const ::std::wstring& token)  {
	BSyncResultT< bool > syncResult;	
	unregisterNotifyService(token, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_DispatcherService::unregisterNotifyService(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_DispatcherService_unregisterNotifyService(token));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
PFileSystemNotify BStub_DispatcherService::getNotifyService(const ::std::wstring& token, bool onlyHere)  {
	BSyncResultT< PFileSystemNotify > syncResult;	
	getNotifyService(token, onlyHere, [&syncResult](PFileSystemNotify v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	return syncResult.getResult();
}
void BStub_DispatcherService::getNotifyService(const ::std::wstring& token, bool onlyHere, ::std::function< void (PFileSystemNotify, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_DispatcherService_getNotifyService(token, onlyHere));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< PFileSystemNotify, BResult_1816639285 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
void BStub_DispatcherService::keepAlive(const ::std::wstring& token)  {
	BSyncResultT< bool > syncResult;	
	keepAlive(token, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_DispatcherService::keepAlive(const ::std::wstring& token, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_DispatcherService_keepAlive(token));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
}}}

// checkpoint byps.gen.cpp.GenRemoteStub:225
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_963182355(BIO& bio, POBJECT& , PSerializable& pObjS, void* ){
	BSerializable* p = pObjS.get();
	if (bio.is_loading) {
		if (p) return;
		BTargetId targetId;
		bio & targetId;
		PTransport transport(new BTransport(*bio.transport, targetId));
		pObjS = PSerializable(new com::wilutions::jsfs::BStub_DispatcherService(transport));
	}
	else {
		BRemote* r = dynamic_cast<BRemote*>(p);
		BTargetId targetId = r->BRemote_getTargetId();
		bio & targetId;
	}
}
}}}
