#pragma once
#include "afxdialogex.h"


// DateDiff dialog

class DateDiff : public CDialogEx
{
	DECLARE_DYNAMIC(DateDiff)

public:
	DateDiff(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DateDiff();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
