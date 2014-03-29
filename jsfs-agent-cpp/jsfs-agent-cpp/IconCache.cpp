#include "stdafx.h"
#include "IconCache.h"
#include <gdiplus.h>


using namespace std;
using namespace byps;
using namespace Gdiplus;

static unordered_map<wstring, PBytes> g_map;
static byps_mutex g_mutex;
static CLSID g_pngClsid = GUID_NULL;

IconCache::IconCache(void)
{
}

static wstring getMapKey(const std::wstring& fname) {
	wstring ext = L".";
	size_t p = fname.find_last_of(L".");
	if (p != wstring::npos) {
		ext = fname.substr(p);
	}
	return ext;
}

static int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	// http://msdn.microsoft.com/en-us/library/windows/desktop/ms533843(v=vs.85).aspx

   UINT  num = 0;          // number of image encoders
   UINT  size = 0;         // size of the image encoder array in bytes

   ImageCodecInfo* pImageCodecInfo = NULL;

   Gdiplus::GetImageEncodersSize(&num, &size);
   if(size == 0)
      return -1;  // Failure

   pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
   if(pImageCodecInfo == NULL)
      return -1;  // Failure

   Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);

   for(UINT j = 0; j < num; ++j)
   {
      if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
      {
         *pClsid = pImageCodecInfo[j].Clsid;
         free(pImageCodecInfo);
         return j;  // Success
      }    
   }

   free(pImageCodecInfo);
   return -1;  // Failure
}

static PBytes createPngIcon(const std::wstring& fname) {

	PBytes ret;
	UINT flags = SHGFI_ICON|SHGFI_SMALLICON|SHGFI_ADDOVERLAYS|SHGFI_SYSICONINDEX;
	SHFILEINFO fi = {0};

	if (SHGetFileInfo(fname.c_str(), 0, &fi, sizeof(fi), flags) != 0 && fi.hIcon) {

		Gdiplus::Bitmap* bmp = Gdiplus::Bitmap::FromHICON(fi.hIcon);
		if (bmp) {

			IStream* strm  = NULL;
			::CreateStreamOnHGlobal(NULL, TRUE, &strm);

			if (strm) {

				bmp->Save(strm, &g_pngClsid, NULL);

				LARGE_INTEGER move = {0};
				ULARGE_INTEGER pos = {0};
				strm->Seek(move, STREAM_SEEK_CUR, &pos);

				ret = BBytes::create((size_t)pos.QuadPart);
				strm->Seek(move, STREAM_SEEK_SET, &pos);

				ULONG bytesRead = 0;
				strm->Read(ret->data, ret->length, &bytesRead);
				
				ret->length = (size_t)bytesRead;
			
				strm->Release();
			}
		}

		DestroyIcon(fi.hIcon);
	}
	return ret;
}

byps::PBytes IconCache::getPngIcon(const std::wstring& fname) {
	PBytes ret;
	wstring ext = getMapKey(fname);

	byps_unique_lock lock(g_mutex);
	auto it = g_map.find(ext);
	if (it != g_map.end()) {
		ret = (*it).second;
	}
	else {

		if (IsEqualGUID(g_pngClsid, GUID_NULL)) {
			GetEncoderClsid(L"image/png", &g_pngClsid);
		}

		ret = createPngIcon(fname);
		g_map[ext] = ret;
	}

	return ret;
}