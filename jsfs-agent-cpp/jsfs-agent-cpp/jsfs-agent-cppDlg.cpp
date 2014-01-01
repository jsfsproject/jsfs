/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */ 

// jsfs-agent-cppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "jsfs-agent-cpp.h"
#include "jsfs-agent-cppDlg.h"
#include "afxdialogex.h"


#include "JsfsAuthentication.h"
#include "JsfsWireClient.h"

#define WM_TRAYICON_CALLBACK (WM_USER + 1)
#define ID_TRAYICON 100
#define ID_TIMER_RECONNECT 1
#define ID_TIMER_CHECK_CONNECTION 2

#define RECONNECT_AFTER_MILLIS  (30 * 1000)
#define CHECK_CONNECTION_AFTER_MILLIS (300 * 1000)


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CjsfsagentcppDlg dialog



CjsfsagentcppDlg::CjsfsagentcppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CjsfsagentcppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	jsfsDispatcherUrl = L"http://localhost:5080/jsfs-dispatcher/jsfs";
	tokenServiceUrl = L"http://localhost:5080/yourapp/fstokens";
	userName = L"user";
	userPwd = L"pwd";

}

void CjsfsagentcppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CjsfsagentcppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()


// CjsfsagentcppDlg message handlers

BOOL CjsfsagentcppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = GetSafeHwnd();
	nid.uID = ID_TRAYICON;
	nid.uVersion = NOTIFYICON_VERSION;
	nid.uCallbackMessage = WM_TRAYICON_CALLBACK;
	nid.hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	wcscpy_s(nid.szTip, L"JavaScript File System Agent");
	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
 
	Shell_NotifyIcon(NIM_ADD, &nid);

	SetTimer(ID_TIMER_RECONNECT, 100, NULL);
	SetTimer(ID_TIMER_CHECK_CONNECTION, CHECK_CONNECTION_AFTER_MILLIS, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CjsfsagentcppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CjsfsagentcppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CjsfsagentcppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CjsfsagentcppDlg::connectToJSFS() {

	PWire wire = JsfsWireClient::create(NULL, jsfsDispatcherUrl, 0, 60, PThreadPool());
	PTransportFactory transportFactory = PTransportFactory(new HTransportFactoryClient(BApiDescriptor_JSFS::instance(), wire, 1));

	jsfsClient = BClient_JSFS::createClient(transportFactory);

	jsfsClient->setAuthentication(PAuthentication(new JsfsAuthentication(tokenServiceUrl, userName, userPwd)));

	jsfsClient->setLostReverseConnectionHandler([this](BException ex) {
		showTrayInfo(ex.getMsg(), true);
		reconnectToJSFS();
	});

	jsfsClient->start([this](bool, BException ex) {
				
		if (ex) {
			showTrayInfo(ex.getMsg(), true);
			reconnectToJSFS();
		}
		else {
			showTrayInfo(L"Connected to server", false);
		}
	});


}

void CjsfsagentcppDlg::keepAlive() {

	if (!jsfsClient) return;
	
	PJsfsAuthentication auth = byps_ptr_cast<JsfsAuthentication>(jsfsClient->getAuthentication());
	if (!auth) return;

	wstring oldToken = auth->getToken();

	jsfsClient->dispatcherService->keepAlive(auth->getToken(), [this](bool, BException ex) {
		if (ex) {
			showTrayInfo(ex.getMsg(), true);
		}
	});
}

void CjsfsagentcppDlg::reconnectToJSFS() {
		// Release previous connections.
	if (jsfsClient) {
		jsfsClient->done();
	}
	SetTimer(ID_TIMER_RECONNECT, RECONNECT_AFTER_MILLIS, NULL);
}


void CjsfsagentcppDlg::showTrayInfo(const std::wstring& msg, bool isError) {
	NOTIFYICONDATA nid = {0};
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = m_hWnd;
	nid.uID = ID_TRAYICON;
	nid.uFlags = NIF_INFO;
	wcsncpy_s(nid.szInfo, msg.c_str(), ARRAYSIZE(nid.szInfo));
	wcsncpy_s(nid.szInfoTitle, isError ? L"Error" : L"Information", ARRAYSIZE(nid.szInfoTitle));
	nid.dwInfoFlags = isError ? NIIF_ERROR : NIIF_INFO;
	Shell_NotifyIcon(NIM_MODIFY, &nid);
}

void CjsfsagentcppDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialogEx::OnTimer(nIDEvent);

	if (nIDEvent == ID_TIMER_RECONNECT) {
		connectToJSFS();
		KillTimer(ID_TIMER_RECONNECT);
	}
	else if (nIDEvent == ID_TIMER_CHECK_CONNECTION) {
		// Keep Session alive
		keepAlive();
	}
}



void CjsfsagentcppDlg::OnDestroy()
{
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = m_hWnd;
	nid.uID = ID_TRAYICON;
	Shell_NotifyIcon(NIM_DELETE, &nid);

	CDialogEx::OnDestroy();

}


void CjsfsagentcppDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	lpwndpos->flags &= ~SWP_SHOWWINDOW; 
	CDialogEx::OnWindowPosChanging(lpwndpos);
}

