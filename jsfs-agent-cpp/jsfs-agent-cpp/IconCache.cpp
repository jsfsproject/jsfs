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

    static HICON getShellIconByIndex(int shilsize, int iImage)
    {
	    IImageListPtr spiml;
	    SHGetImageList(shilsize, IID_PPV_ARGS(&spiml));

	    HICON hico;
	    spiml->GetIcon(iImage, ILD_TRANSPARENT, &hico);
	    return hico;
    }

    static HICON getShellIcon(int shilsize, const std::wstring& fname) {
	    UINT flags = SHGFI_SYSICONINDEX;
	    SHFILEINFO fi = {0};
	    HICON hIcon = NULL;

	    if (SHGetFileInfo(fname.c_str(), 0, &fi, sizeof(fi), flags) != 0) {
		    hIcon = getShellIconByIndex(shilsize, fi.iIcon);
	    }

	    return hIcon;
    }

    struct BITMAP_AND_BYTES {
	    Gdiplus::Bitmap* bmp;
	    int32_t* bytes;
    };

    static BITMAP_AND_BYTES createAlphaChannelBitmapFromIcon(HICON hIcon) {

	    // Get the icon info
	    ICONINFO iconInfo = {0};
	    GetIconInfo(hIcon, &iconInfo);

	    // Get the screen DC
	    HDC dc = GetDC(NULL);
       
	    // Get icon size info
	    BITMAP bm = {0};
	    GetObject( iconInfo.hbmColor, sizeof( BITMAP ), &bm );

	    // Set up BITMAPINFO
	    BITMAPINFO bmi = {0};
	    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	    bmi.bmiHeader.biWidth = bm.bmWidth;
	    bmi.bmiHeader.biHeight = -bm.bmHeight;
	    bmi.bmiHeader.biPlanes = 1;
	    bmi.bmiHeader.biBitCount = 32;
	    bmi.bmiHeader.biCompression = BI_RGB;

	    // Extract the color bitmap
	    int nBits = bm.bmWidth * bm.bmHeight;
	    int32_t* colorBits = new int32_t[nBits];
	    GetDIBits(dc, iconInfo.hbmColor, 0, bm.bmHeight, colorBits, &bmi, DIB_RGB_COLORS);
 
	    // Check whether the color bitmap has an alpha channel.
	    BOOL hasAlpha = FALSE;
	    for (int i = 0; i < nBits; i++) {
		    if ((colorBits[i] & 0xff000000) != 0) {
			    hasAlpha = TRUE;
			    break;
		    }
	    }
            
	    // If no alpha values available, apply the mask bitmap
	    if (!hasAlpha) {
		    // Extract the mask bitmap
		    int32_t* maskBits = new int32_t[nBits];
		    GetDIBits(dc, iconInfo.hbmMask, 0, bm.bmHeight, maskBits, &bmi, DIB_RGB_COLORS);
		    // Copy the mask alphas into the color bits
		    for (int i = 0; i < nBits; i++) {
			    if (maskBits[i] == 0) {
				    colorBits[i] |= 0xff000000;
			    }
		    }
		    delete maskBits;
	    } 

	    // Release DC and GDI bitmaps
	    ReleaseDC(NULL, dc); 
	    ::DeleteObject(iconInfo.hbmColor);
	    ::DeleteObject(iconInfo.hbmMask); 

	    // Create GDI+ Bitmap
	    Gdiplus::Bitmap* bmp = new Gdiplus::Bitmap(bm.bmWidth, bm.bmHeight, bm.bmWidth*4, PixelFormat32bppARGB, (BYTE*)colorBits);
	    BITMAP_AND_BYTES ret = {bmp, colorBits};

	    return ret;
    }

    static void saveFileIconAsPng(int shilsize, const std::wstring& fname, const std::wstring& pngFile) {
	    HICON hIcon = getShellIcon(shilsize, fname);
	    BITMAP_AND_BYTES bbs = createAlphaChannelBitmapFromIcon(hIcon);

	    IStream* fstrm = NULL;
	    SHCreateStreamOnFile(pngFile.c_str(), STGM_WRITE|STGM_CREATE, &fstrm);
	    bbs.bmp->Save(fstrm, &g_pngClsid, NULL);
	    fstrm->Release();

	    delete bbs.bmp;
	    delete[] bbs.bytes;
	    DestroyIcon(hIcon);
    }


static PBytes getBitmapPngBytes(Gdiplus::Bitmap* bmp) {
	PBytes ret;

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

	return ret;
}

static PBytes createPngIcon(const std::wstring& fname) {

	PBytes ret;
	HICON hIcon = getShellIcon(SHIL_LARGE, fname);

	if (hIcon) {

		BITMAP_AND_BYTES bbs = createAlphaChannelBitmapFromIcon(hIcon);
		ret = getBitmapPngBytes(bbs.bmp);
	
		delete bbs.bmp;
		delete[] bbs.bytes;
		DestroyIcon(hIcon);
	}

	wstring pngFile = L"d:\\icons\\";
	size_t p = fname.find_last_of(L'\\');
	pngFile += p != wstring::npos ? fname.substr(p+1) : fname;
	pngFile += L".png";
	saveFileIconAsPng(SHIL_JUMBO, fname, pngFile);
	
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