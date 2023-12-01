
// DateCalculatorDlg.h : header file
//

#pragma once
#include "DateDiff.h"
#include "DateArith.h"

// CDateCalculatorDlg dialog
class CDateCalculatorDlg : public CDialogEx
{
// Construction
public:
	CDateCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATECALCULATOR_DIALOG };
#endif

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
public:
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	// The main tab control for the application window
	CTabCtrl m_AppTabCtrl;
	DateDiff m_tab1;
	DateArith m_tab2;
	afx_msg void OnTcnSelchangeTabcontrol(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};