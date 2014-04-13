// RtOptDllTestDlg.h : header file
//

#if !defined(AFX_RTOPTDLLTESTDLG_H__538CFE4A_DB6A_44EA_BE26_F9B5F0A3D77F__INCLUDED_)
#define AFX_RTOPTDLLTESTDLG_H__538CFE4A_DB6A_44EA_BE26_F9B5F0A3D77F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRtOptDllTestDlg dialog

class CRtOptDllTestDlg : public CDialog
{
// Construction
public:
	CRtOptDllTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRtOptDllTestDlg)
	enum { IDD = IDD_RTOPTDLLTEST_DIALOG };
	CListBox	m_ExcelList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRtOptDllTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CString GetExcelDriver();

	// Generated message map functions
	//{{AFX_MSG(CRtOptDllTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBTNExcel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RTOPTDLLTESTDLG_H__538CFE4A_DB6A_44EA_BE26_F9B5F0A3D77F__INCLUDED_)
