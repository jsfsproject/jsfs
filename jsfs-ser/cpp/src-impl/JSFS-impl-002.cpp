#include "JSFS-impl.h"
using namespace ::std;
using namespace ::byps;

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
void BSerializer_1153231042(BIO& bio, POBJECT& , PSerializable& pObjS, void* ){
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

namespace com { namespace wilutions { namespace jsfs { 

void BSkeleton_FileSystemNotify::notify(const PNotifyInfo& notifyInfo)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemNotify::notify(const PNotifyInfo& notifyInfo, ::std::function< void (bool, BException ex) > asyncResult)  {
	bool __byps__ret = false;
	try {
		notify(notifyInfo);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
}}}


namespace com { namespace wilutions { namespace jsfs { 

BStub_FileSystemNotify::BStub_FileSystemNotify(PTransport transport) 
	: BStub(transport) {}

void BStub_FileSystemNotify::notify(const PNotifyInfo& notifyInfo)  {
	BSyncResultT< bool > syncResult;	
	notify(notifyInfo, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_FileSystemNotify::notify(const PNotifyInfo& notifyInfo, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemNotify_notify(notifyInfo));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
}}}

// checkpoint byps.gen.cpp.GenRemoteStub:225
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_544795964(BIO& bio, POBJECT& , PSerializable& pObjS, void* ){
	BSerializable* p = pObjS.get();
	if (bio.is_loading) {
		if (p) return;
		BTargetId targetId;
		bio & targetId;
		PTransport transport(new BTransport(*bio.transport, targetId));
		pObjS = PSerializable(new com::wilutions::jsfs::BStub_FileSystemNotify(transport));
	}
	else {
		BRemote* r = dynamic_cast<BRemote*>(p);
		BTargetId targetId = r->BRemote_getTargetId();
		bio & targetId;
	}
}
}}}

namespace com { namespace wilutions { namespace jsfs { 

byps_ptr< ::std::vector< PFileInfo > > BSkeleton_FileSystemService::findFiles(const ::std::wstring& path, const PFindOptions& findOptions)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemService::findFiles(const ::std::wstring& path, const PFindOptions& findOptions, ::std::function< void (byps_ptr< ::std::vector< PFileInfo > >, BException ex) > asyncResult)  {
	byps_ptr< ::std::vector< PFileInfo > > __byps__ret = byps_ptr< ::std::vector< PFileInfo > >();
	try {
		__byps__ret = findFiles(path, findOptions);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
::std::wstring BSkeleton_FileSystemService::readAllText(const ::std::wstring& path)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemService::readAllText(const ::std::wstring& path, ::std::function< void (::std::wstring, BException ex) > asyncResult)  {
	::std::wstring __byps__ret = ::std::wstring();
	try {
		__byps__ret = readAllText(path);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
void BSkeleton_FileSystemService::writeAllText(const ::std::wstring& path, const ::std::wstring& text)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemService::writeAllText(const ::std::wstring& path, const ::std::wstring& text, ::std::function< void (bool, BException ex) > asyncResult)  {
	bool __byps__ret = false;
	try {
		writeAllText(path, text);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
void BSkeleton_FileSystemService::executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemService::executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts, ::std::function< void (bool, BException ex) > asyncResult)  {
	bool __byps__ret = false;
	try {
		executeNotifyExit(args, opts);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
int32_t BSkeleton_FileSystemService::beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemService::beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo, ::std::function< void (int32_t, BException ex) > asyncResult)  {
	int32_t __byps__ret = int32_t();
	try {
		__byps__ret = beginWatchFolder(dir, recursive, extraInfo);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
void BSkeleton_FileSystemService::endWatchFolder(int32_t handle)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemService::endWatchFolder(int32_t handle, ::std::function< void (bool, BException ex) > asyncResult)  {
	bool __byps__ret = false;
	try {
		endWatchFolder(handle);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
PContentStream BSkeleton_FileSystemService::readFile(const ::std::wstring& path)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemService::readFile(const ::std::wstring& path, ::std::function< void (PContentStream, BException ex) > asyncResult)  {
	PContentStream __byps__ret = PContentStream();
	try {
		__byps__ret = readFile(path);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
void BSkeleton_FileSystemService::uploadFiles(const byps_ptr< BArray1< PFormItem > >& items, const ::std::wstring& url, const ::std::wstring& method, const ::std::wstring& encoding)  {
	throw BException(EX_UNSUPPORTED_METHOD, L"");
}
void BSkeleton_FileSystemService::uploadFiles(const byps_ptr< BArray1< PFormItem > >& items, const ::std::wstring& url, const ::std::wstring& method, const ::std::wstring& encoding, ::std::function< void (bool, BException ex) > asyncResult)  {
	bool __byps__ret = false;
	try {
		uploadFiles(items, url, method, encoding);
		asyncResult(__byps__ret, BException());
	} catch (const std::exception& __byps__ex) {
		asyncResult(__byps__ret, __byps__ex);
	}
}
}}}


namespace com { namespace wilutions { namespace jsfs { 

BStub_FileSystemService::BStub_FileSystemService(PTransport transport) 
	: BStub(transport) {}

byps_ptr< ::std::vector< PFileInfo > > BStub_FileSystemService::findFiles(const ::std::wstring& path, const PFindOptions& findOptions)  {
	BSyncResultT< byps_ptr< ::std::vector< PFileInfo > > > syncResult;	
	findFiles(path, findOptions, [&syncResult](byps_ptr< ::std::vector< PFileInfo > > v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	return syncResult.getResult();
}
void BStub_FileSystemService::findFiles(const ::std::wstring& path, const PFindOptions& findOptions, ::std::function< void (byps_ptr< ::std::vector< PFileInfo > >, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemService_findFiles(path, findOptions));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< byps_ptr< ::std::vector< PFileInfo > >, BResult_1439246415 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
::std::wstring BStub_FileSystemService::readAllText(const ::std::wstring& path)  {
	BSyncResultT< ::std::wstring > syncResult;	
	readAllText(path, [&syncResult](::std::wstring v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	return syncResult.getResult();
}
void BStub_FileSystemService::readAllText(const ::std::wstring& path, ::std::function< void (::std::wstring, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemService_readAllText(path));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< ::std::wstring, BResult_10 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
void BStub_FileSystemService::writeAllText(const ::std::wstring& path, const ::std::wstring& text)  {
	BSyncResultT< bool > syncResult;	
	writeAllText(path, text, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_FileSystemService::writeAllText(const ::std::wstring& path, const ::std::wstring& text, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemService_writeAllText(path, text));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
void BStub_FileSystemService::executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts)  {
	BSyncResultT< bool > syncResult;	
	executeNotifyExit(args, opts, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_FileSystemService::executeNotifyExit(const byps_ptr< BArray1< ::std::wstring > >& args, const PExecuteOptions& opts, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemService_executeNotifyExit(args, opts));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
int32_t BStub_FileSystemService::beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo)  {
	BSyncResultT< int32_t > syncResult;	
	beginWatchFolder(dir, recursive, extraInfo, [&syncResult](int32_t v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	return syncResult.getResult();
}
void BStub_FileSystemService::beginWatchFolder(const ::std::wstring& dir, bool recursive, const ::std::wstring& extraInfo, ::std::function< void (int32_t, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemService_beginWatchFolder(dir, recursive, extraInfo));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< int32_t, BResult_5 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
void BStub_FileSystemService::endWatchFolder(int32_t handle)  {
	BSyncResultT< bool > syncResult;	
	endWatchFolder(handle, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_FileSystemService::endWatchFolder(int32_t handle, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemService_endWatchFolder(handle));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
PContentStream BStub_FileSystemService::readFile(const ::std::wstring& path)  {
	BSyncResultT< PContentStream > syncResult;	
	readFile(path, [&syncResult](PContentStream v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	return syncResult.getResult();
}
void BStub_FileSystemService::readFile(const ::std::wstring& path, ::std::function< void (PContentStream, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemService_readFile(path));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< PContentStream, BResult_15 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
void BStub_FileSystemService::uploadFiles(const byps_ptr< BArray1< PFormItem > >& items, const ::std::wstring& url, const ::std::wstring& method, const ::std::wstring& encoding)  {
	BSyncResultT< bool > syncResult;	
	uploadFiles(items, url, method, encoding, [&syncResult](bool v, BException ex) {
		syncResult.setAsyncResult(v, ex);
	});
	syncResult.getResult();
}
void BStub_FileSystemService::uploadFiles(const byps_ptr< BArray1< PFormItem > >& items, const ::std::wstring& url, const ::std::wstring& method, const ::std::wstring& encoding, ::std::function< void (bool, BException ex) > asyncResult)  {
	PMethodRequest req(new BRequest_FileSystemService_uploadFiles(items, url, method, encoding));
	PAsyncResult outerResult( new BAsyncResultReceiveMethodL< bool, BResult_19 >(asyncResult) );
	transport->sendMethod(req, outerResult);
}
}}}

// checkpoint byps.gen.cpp.GenRemoteStub:225
namespace com { namespace wilutions { namespace jsfs { 
void BSerializer_145996442(BIO& bio, POBJECT& , PSerializable& pObjS, void* ){
	BSerializable* p = pObjS.get();
	if (bio.is_loading) {
		if (p) return;
		BTargetId targetId;
		bio & targetId;
		PTransport transport(new BTransport(*bio.transport, targetId));
		pObjS = PSerializable(new com::wilutions::jsfs::BStub_FileSystemService(transport));
	}
	else {
		BRemote* r = dynamic_cast<BRemote*>(p);
		BTargetId targetId = r->BRemote_getTargetId();
		bio & targetId;
	}
}
}}}
//-------------------------------------------------
// Registry 

com::wilutions::jsfs::BRegistry_JSFS::BRegistry_JSFS()
{
	registerClass(typeid(com::wilutions::jsfs::BRequest_DispatcherService_getNotifyService), com::wilutions::jsfs::BSerializer_1090607752, 1090607752);
	registerClass(typeid(com::wilutions::jsfs::BRequest_DispatcherService_getService), com::wilutions::jsfs::BSerializer_575037953, 575037953);
	registerClass(typeid(com::wilutions::jsfs::BRequest_DispatcherService_keepAlive), com::wilutions::jsfs::BSerializer_1609273478, 1609273478);
	registerClass(typeid(com::wilutions::jsfs::BRequest_DispatcherService_registerNotifyService), com::wilutions::jsfs::BSerializer_1849102471, 1849102471);
	registerClass(typeid(com::wilutions::jsfs::BRequest_DispatcherService_registerService), com::wilutions::jsfs::BSerializer_1833696176, 1833696176);
	registerClass(typeid(com::wilutions::jsfs::BRequest_DispatcherService_unregisterNotifyService), com::wilutions::jsfs::BSerializer_1366717454, 1366717454);
	registerClass(typeid(com::wilutions::jsfs::BRequest_DispatcherService_unregisterService), com::wilutions::jsfs::BSerializer_1542825705, 1542825705);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemNotify_notify), com::wilutions::jsfs::BSerializer_481066845, 481066845);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemService_beginWatchFolder), com::wilutions::jsfs::BSerializer_1762179110, 1762179110);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemService_endWatchFolder), com::wilutions::jsfs::BSerializer_1124739608, 1124739608);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemService_executeNotifyExit), com::wilutions::jsfs::BSerializer_1824869366, 1824869366);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemService_findFiles), com::wilutions::jsfs::BSerializer_1131301080, 1131301080);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemService_readAllText), com::wilutions::jsfs::BSerializer_1078989294, 1078989294);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemService_readFile), com::wilutions::jsfs::BSerializer_706034600, 706034600);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemService_uploadFiles), com::wilutions::jsfs::BSerializer_1614176016, 1614176016);
	registerClass(typeid(com::wilutions::jsfs::BRequest_FileSystemService_writeAllText), com::wilutions::jsfs::BSerializer_1925305675, 1925305675);
	registerClass(typeid(com::wilutions::jsfs::BResult_10), com::wilutions::jsfs::BSerializer_964561600, 964561600);
	registerClass(typeid(com::wilutions::jsfs::BResult_1439246415), com::wilutions::jsfs::BSerializer_1733426638, 1733426638);
	registerClass(typeid(com::wilutions::jsfs::BResult_15), com::wilutions::jsfs::BSerializer_964561595, 964561595);
	registerClass(typeid(com::wilutions::jsfs::BResult_1816639285), com::wilutions::jsfs::BSerializer_1354059712, 1354059712);
	registerClass(typeid(com::wilutions::jsfs::BResult_19), com::wilutions::jsfs::BSerializer_964561591, 964561591);
	registerClass(typeid(com::wilutions::jsfs::BResult_336045129), com::wilutions::jsfs::BSerializer_1815527676, 1815527676);
	registerClass(typeid(com::wilutions::jsfs::BResult_5), com::wilutions::jsfs::BSerializer_169662220, 169662220);
	registerClass(typeid(com::wilutions::jsfs::BStub_DispatcherService), com::wilutions::jsfs::BSerializer_1153231042, 1153231042);
	registerClass(typeid(com::wilutions::jsfs::BStub_FileSystemNotify), com::wilutions::jsfs::BSerializer_544795964, 544795964);
	registerClass(typeid(com::wilutions::jsfs::BStub_FileSystemService), com::wilutions::jsfs::BSerializer_145996442, 145996442);
	registerClass(typeid(com::wilutions::jsfs::ExecuteNotifyInfo), com::wilutions::jsfs::BSerializer_665368294, 665368294);
	registerClass(typeid(com::wilutions::jsfs::ExecuteOptions), com::wilutions::jsfs::BSerializer_1032737639, 1032737639);
	registerClass(typeid(com::wilutions::jsfs::FileInfo), com::wilutions::jsfs::BSerializer_1100528120, 1100528120);
	registerClass(typeid(com::wilutions::jsfs::FindOptions), com::wilutions::jsfs::BSerializer_1092766252, 1092766252);
	registerClass(typeid(com::wilutions::jsfs::FormItem), com::wilutions::jsfs::BSerializer_979378962, 979378962);
	registerClass(typeid(BArray1< com::wilutions::jsfs::PFormItem > ), com::wilutions::jsfs::BSerializer_566696346, 566696346);
	registerClass(typeid(com::wilutions::jsfs::NotifyInfo), com::wilutions::jsfs::BSerializer_1274131736, 1274131736);
	registerClass(typeid(com::wilutions::jsfs::WatchFolderNotifyInfo), com::wilutions::jsfs::BSerializer_9906860, 9906860);
	registerClass(typeid(BArray1< ::std::wstring > ), com::wilutions::jsfs::BSerializer_1888107655, 1888107655);
	registerClass(typeid(::std::vector< com::wilutions::jsfs::PFileInfo >), com::wilutions::jsfs::BSerializer_1439246415, 1439246415);
}
namespace com { namespace wilutions { namespace jsfs { 

PApiDescriptor BApiDescriptor_JSFS::instance() {
	return PApiDescriptor((new BApiDescriptor(
	"JSFS",
	"com.wilutions.jsfs",
	VERSION,
	false)) // uniqueObjects
	->addRegistry(PRegistry(new BRegistry_JSFS()))
	);
};

}}}

namespace com { namespace wilutions { namespace jsfs { 

PClient_JSFS BClient_JSFS::createClient(PTransportFactory transportFactory) {
	return PClient_JSFS(new BClient_JSFS(transportFactory));
}
PClient_JSFS BClient_JSFS::createClientR(PTransport transport) {
	return PClient_JSFS(new BClient_JSFS(transport));
}
void BClient_JSFS::addRemote(PSkeleton_FileSystemNotify remoteSkeleton) {
	if (!serverR) throw BException(EX_NO_REVERSE_CONNECTIONS, L"No reverse connections.");
	serverR->server->addRemote(544795964, remoteSkeleton);
}

void BClient_JSFS::addRemote(PSkeleton_FileSystemService remoteSkeleton) {
	if (!serverR) throw BException(EX_NO_REVERSE_CONNECTIONS, L"No reverse connections.");
	serverR->server->addRemote(145996442, remoteSkeleton);
}

BClient_JSFS::BClient_JSFS(PTransportFactory transportFactory) 
	: BClient(
		transportFactory->createClientTransport(), 
		transportFactory->createServerR(
			BServer_JSFS::createServerR(transportFactory->createServerTransport())
		)
	)
	{
	initStubs(transport);
}
BClient_JSFS::BClient_JSFS(PTransport transport) 
	: BClient(transport, NULL)
	{
	initStubs(transport);
}
BINLINE com::wilutions::jsfs::PDispatcherService BClient_JSFS::getDispatcherService() {
	return dispatcherService;
}
BINLINE com::wilutions::jsfs::PFileSystemNotify BClient_JSFS::getFileSystemNotify() {
	return fileSystemNotify;
}
BINLINE com::wilutions::jsfs::PFileSystemService BClient_JSFS::getFileSystemService() {
	return fileSystemService;
}
PRemote BClient_JSFS::getStub(int remoteId) {
	if (remoteId == 1153231042) return dispatcherService;
	if (remoteId == 544795964) return fileSystemNotify;
	if (remoteId == 145996442) return fileSystemService;
	return PRemote();
}
BINLINE void BClient_JSFS::initStubs(PTransport transport) {
	dispatcherService = com::wilutions::jsfs::PDispatcherService(new BStub_DispatcherService(transport));
	fileSystemNotify = com::wilutions::jsfs::PFileSystemNotify(new BStub_FileSystemNotify(transport));
	fileSystemService = com::wilutions::jsfs::PFileSystemService(new BStub_FileSystemService(transport));
}
}}}

namespace com { namespace wilutions { namespace jsfs { 

PServer_JSFS BServer_JSFS::createServer(PTransportFactory transportFactory) {
	return PServer_JSFS(new BServer_JSFS(transportFactory));
}
PServer_JSFS BServer_JSFS::createServerR(PTransport transport) {
	return PServer_JSFS(new BServer_JSFS(transport));
}
void BServer_JSFS::addRemote(PSkeleton_FileSystemNotify remoteSkeleton) {
	BServer::addRemote(544795964, remoteSkeleton);
}

void BServer_JSFS::addRemote(PSkeleton_FileSystemService remoteSkeleton) {
	BServer::addRemote(145996442, remoteSkeleton);
}

BServer_JSFS::BServer_JSFS(PTransportFactory transportFactory) 
	: BServer(
		transportFactory->createServerTransport(), 
		transportFactory->createClientR(
			BClient_JSFS::createClientR(transportFactory->createClientTransport())
		)
	)
	{
}
BServer_JSFS::BServer_JSFS(PTransport transport) 
	: BServer(transport, NULL)
	{
}
}}}

