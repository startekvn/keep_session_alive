// Tdi_keep_session_aliveDlg.h : header file
//

#include "afxwin.h"
#if !defined(AFX_keep_session_aliveDLG_H__76F96A57_D2D7_44E2_9CCD_06EE2BB96C71__INCLUDED_)
#define AFX_keep_session_aliveDLG_H__76F96A57_D2D7_44E2_9CCD_06EE2BB96C71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// Ckeep_session_aliveDlg dialog

class Ckeep_session_aliveDlg : public CDialog
{
// Construction
public:
	Ckeep_session_aliveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(Ckeep_session_aliveDlg)
	enum { IDD = IDD_KEEP_SESSION_ALIVE_DIALOG };
	CString	m_strCaption;
	CString	m_strHandleWindow;
	CString	m_strTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ckeep_session_aliveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(Ckeep_session_aliveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSetTimer();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnMaxtextEditTime();
	CEdit m_ctrEditTime;
	afx_msg void OnBnClickedButtonStop();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_keep_session_aliveDLG_H__76F96A57_D2D7_44E2_9CCD_06EE2BB96C71__INCLUDED_)
