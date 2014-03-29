/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 

// jsfs-agent-cpp.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CjsfsagentcppApp:
// See jsfs-agent-cpp.cpp for the implementation of this class
//

class CjsfsagentcppApp : public CWinApp
{
public:
	CjsfsagentcppApp();
	virtual ~CjsfsagentcppApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CjsfsagentcppApp theApp;