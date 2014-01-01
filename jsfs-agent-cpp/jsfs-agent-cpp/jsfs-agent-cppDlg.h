/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 

// jsfs-agent-cppDlg.h : header file
//

#pragma once

#include "JSFS-api.h"
#include "Bypshttp.h"
#include "FileSystemServiceImpl.h"


using namespace com::wilutions::jsfs;
using namespace byps;
using namespace byps::http;

// CjsfsagentcppDlg dialog
class CjsfsagentcppDlg : public CDialogEx
{
	// URL to JSFS Dispatcher
	std::wstring jsfsDispatcherUrl;

	// URL to application that uses the JSFS.
	// This application requests a session ID at this URL.
	std::wstring tokenServiceUrl;
	std::wstring userName;
	std::wstring userPwd;

	PClient_JSFS jsfsClient;
	void connectToJSFS();
	void reconnectToJSFS();

	void keepAlive();

	void showTrayInfo(const std::wstring& msg, bool isError);

// Construction
public:
	CjsfsagentcppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_JSFSAGENTCPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};
