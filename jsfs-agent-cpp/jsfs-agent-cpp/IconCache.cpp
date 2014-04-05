#include "stdafx.h"
#include "IconCache.h"
#include <gdiplus.h>
#include <commoncontrols.h>
#include <comip.h>
#include <comdef.h>

_COM_SMARTPTR_TYPEDEF(IImageList, __uuidof(IImageList));


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

static HICON getShellIconByIndex(int imageList, int iImage)
{
  IImageListPtr spiml;
  SHGetImageList(imageList, IID_PPV_ARGS(&spiml));

  HICON hico;
  spiml->GetIcon(iImage, ILD_TRANSPARENT, &hico);
  return hico;
}

static HICON getShellIcon(int imageListId, const std::wstring& fname) {
	UINT flags = SHGFI_SYSICONINDEX;
	SHFILEINFO fi = {0};
	HICON hIcon = NULL;

	if (SHGetFileInfo(fname.c_str(), 0, &fi, sizeof(fi), flags) != 0) {
		hIcon = getShellIconByIndex(imageListId, fi.iIcon);
	}

	return hIcon;
}

struct BITMAP_AND_BYTES {
	Gdiplus::Bitmap* bmp;
	int32_t* bytes;
};

static BITMAP_AND_BYTES createAlphaChannelBitmapFromIcon(HICON hIcon) {

	// Get the icon info
	ICONINFO iconInfo;
	GetIconInfo(hIcon, &iconInfo);
	// Get the screen DC
	HDC dc = GetDC(NULL);
       
	BITMAP bm = {0};
	GetObject( iconInfo.hbmColor, sizeof( BITMAP ), &bm );
	int iconSize = bm.bmWidth;

    // Set up BITMAPINFO
    BITMAPINFO bmi;
    memset(&bmi, 0, sizeof(BITMAPINFO));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = iconSize;
    bmi.bmiHeader.biHeight = -iconSize;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    // Extract the color bitmap
    int nBits = iconSize * iconSize;
	int32_t* colorBits = new int32_t[nBits];
    GetDIBits(dc, iconInfo.hbmColor, 0, iconSize, colorBits, &bmi, DIB_RGB_COLORS);
 
	// Release DC
    ReleaseDC(NULL, dc); 
	::DeleteObject(iconInfo.hbmColor);
    ::DeleteObject(iconInfo.hbmMask); 

	Gdiplus::Bitmap* bmp = new Gdiplus::Bitmap(iconSize, iconSize, iconSize*4, PixelFormat32bppARGB, (BYTE*)colorBits);

	BITMAP_AND_BYTES ret = {bmp, colorBits};
	return ret;
}

static PBytes createPngIcon(const std::wstring& fname) {

	PBytes ret;
	HICON hIcon = getShellIcon(SHIL_LARGE, fname);

	if (hIcon) {

		BITMAP_AND_BYTES bbs = createAlphaChannelBitmapFromIcon(hIcon);
	
		IStream* strm  = NULL;
		::CreateStreamOnHGlobal(NULL, TRUE, &strm);

		if (strm) {

			bbs.bmp->Save(strm, &g_pngClsid, NULL);

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

		delete bbs.bmp;
		delete[] bbs.bytes;
		DestroyIcon(hIcon);
		
	}

	//wstring iconPath = L"d:\\icons\\";
	//size_t p = fname.find_last_of(L'\\');
	//iconPath += p != wstring::npos ? fname.substr(p+1) : fname;
	//iconPath += L".png";
	//HANDLE file  = ::CreateFile(iconPath.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	//DWORD bytesWritten;
	//::WriteFile(file, ret->data, ret->length, &bytesWritten, 0);
	//::CloseHandle(file);

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