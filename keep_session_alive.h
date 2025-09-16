// Tkeep_session_alive.h : main header file for the Tdi_keep_session_alive application
//

#if !defined(AFX_keep_session_alive_H__B4CA098E_DF86_47A5_ACB1_C3012CB07981__INCLUDED_)
#define AFX_keep_session_alive_H__B4CA098E_DF86_47A5_ACB1_C3012CB07981__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// Ckeep_session_aliveApp:
// See keep_session_alive.cpp for the implementation of this class
//

class Ckeep_session_aliveApp : public CWinApp
{
public:
	Ckeep_session_aliveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ckeep_session_aliveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(Ckeep_session_aliveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
    
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_keep_session_alive_H__B4CA098E_DF86_47A5_ACB1_C3012CB07981__INCLUDED_)
