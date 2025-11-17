// keep_session_aliveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "keep_session_alive.h"
#include "keep_session_aliveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


HWND hWndWindow = NULL;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ckeep_session_aliveDlg dialog

Ckeep_session_aliveDlg::Ckeep_session_aliveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Ckeep_session_aliveDlg::IDD, pParent)
	, m_bIsChildWindow(FALSE)
{
	//{{AFX_DATA_INIT(Ckeep_session_aliveDlg)
	m_strCaption = _T("");
	m_strHandleWindow = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ckeep_session_aliveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ckeep_session_aliveDlg)
	DDX_Text(pDX, IDC_EDIT_CAPTION, m_strCaption);
	DDX_Text(pDX, IDC_EDIT_HANDLE, m_strHandleWindow);
	DDX_Text(pDX, IDC_EDIT_TIME, m_strTime);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDIT_TIME, m_ctrEditTime);
	DDV_MaxChars(pDX, m_strTime, 4);
	DDX_Control(pDX, IDC_CHECK_ISCHILD, m_cbIsChild);
	DDX_Check(pDX, IDC_CHECK_ISCHILD, m_bIsChildWindow);
}

BEGIN_MESSAGE_MAP(Ckeep_session_aliveDlg, CDialog)
	//{{AFX_MSG_MAP(Ckeep_session_aliveDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SET_TIMER, OnButtonSetTimer)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_EN_MAXTEXT(IDC_EDIT_TIME, &Ckeep_session_aliveDlg::OnEnMaxtextEditTime)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &Ckeep_session_aliveDlg::OnBnClickedButtonStop)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ckeep_session_aliveDlg message handlers

BOOL Ckeep_session_aliveDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	// TODO: Add extra initialization here

    
    m_strCaption = _T("");
	m_strTime = _T("10");
	
    UpdateData(FALSE);
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ckeep_session_aliveDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ckeep_session_aliveDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ckeep_session_aliveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define ID_TIMER_REFRESH_WINDOW 1
#define MAX_TIME 3600
void Ckeep_session_aliveDlg::OnButtonSetTimer()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	/*
	if (m_strCaption.IsEmpty())
	{
	MessageBox(_T("You need to specify the caption of the window"), _T("Timer"), MB_OK|MB_ICONERROR);
	return;
	}

	*/
	TCHAR szCaption[MAX_PATH];

	DWORD dwTime = atoi((LPCSTR)m_strTime);
	if (dwTime > MAX_TIME || dwTime < 1)
	{
		MessageBox(_T("Time value is between 1 and 3600. Please correct it!"), _T("Timer"), MB_OK|MB_ICONERROR);
		m_ctrEditTime.SetFocus();
		return;
	}

	dwTime *= 1000;

	hWndWindow = (HWND)strtol((LPCSTR)m_strHandleWindow, NULL, 16);
	m_strHandleWindow.Format(_T("0x%08x"), hWndWindow);
	if (TRUE == m_bIsChildWindow)
	{
		hWndWindow = ::GetParent(hWndWindow);
	}
	::GetWindowText(hWndWindow, szCaption, MAX_PATH);
	szCaption[MAX_PATH] = 0;
	m_strCaption = szCaption;

	UpdateData(FALSE);
    if (0 == hWndWindow)
    {
		MessageBox(_T("You need to specify the handle of the window."), _T("Timer"), MB_OK | MB_ICONERROR);
		return;

    }



    GetDlgItem(IDC_BUTTON_SET_TIMER)->EnableWindow(FALSE);

    SetTimer(ID_TIMER_REFRESH_WINDOW, dwTime, NULL);
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(TRUE);

}
BOOL CALLBACK EnumChildProc(HWND hwnd,
							LPARAM lParam
							)
{
	::PostMessage(hwnd,  WM_KEYDOWN, VK_F5, 0x003F0001);  //OK

	::PostMessage(hwnd,  WM_KEYUP, VK_F5, 0xC03F0001);    // OK

	//EnumChildWindows(hwnd, EnumChildProc, 0);
	return TRUE;
}
void Ckeep_session_aliveDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
#if 1
    if (nIDEvent == ID_TIMER_REFRESH_WINDOW)
    {
		::PostMessage(hWndWindow, WM_KEYDOWN, VK_F5, 0x003F0001);  //OK
		::PostMessage(hWndWindow, WM_KEYUP, VK_F5, 0xC03F0001);    // OK
		EnumChildWindows(hWndWindow, EnumChildProc, 0);
    }
#endif

	CDialog::OnTimer(nIDEvent);
}



void Ckeep_session_aliveDlg::OnOK() 
{
	// TODO: Add extra validation here
	KillTimer(ID_TIMER_REFRESH_WINDOW);
	CDialog::OnOK();
}

void Ckeep_session_aliveDlg::OnEnMaxtextEditTime()
{
	// TODO: Add your control notification handler code here
}



void Ckeep_session_aliveDlg::OnBnClickedButtonStop()
{
	// TODO: Add your control notification handler code here
	KillTimer(ID_TIMER_REFRESH_WINDOW);
	GetDlgItem(IDC_BUTTON_SET_TIMER)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(FALSE);
}
