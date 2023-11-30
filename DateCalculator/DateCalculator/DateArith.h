#pragma once
#include "afxdialogex.h"


// DateArith dialog

class DateArith : public CDialogEx
{
	DECLARE_DYNAMIC(DateArith)

public:
	DateArith(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DateArith();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
