// RtOptDllTest.h : main header file for the RTOPTDLLTEST application
//

#if !defined(AFX_RTOPTDLLTEST_H__BF9D1339_48FE_4D4A_B606_9733B0CCD6C9__INCLUDED_)
#define AFX_RTOPTDLLTEST_H__BF9D1339_48FE_4D4A_B606_9733B0CCD6C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRtOptDllTestApp:
// See RtOptDllTest.cpp for the implementation of this class
//

class CRtOptDllTestApp : public CWinApp
{
public:
	CRtOptDllTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRtOptDllTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRtOptDllTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RTOPTDLLTEST_H__BF9D1339_48FE_4D4A_B606_9733B0CCD6C9__INCLUDED_)
