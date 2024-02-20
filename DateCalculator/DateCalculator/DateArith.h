#pragma once
#include "afxdialogex.h"
#include "DateCalculator.hpp"

// DateArith dialog

enum operations
{
	NONE = -1,
	ADD = 0,
	SUBTRACT = 1
};

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
public:
	afx_msg void OnBnClickedAddOperation();
	afx_msg void OnBnClickedSubtractOperation();
	afx_msg void OnEnChangeYearsfrom();
	afx_msg void OnEnChangeMonthsfrom();
	afx_msg void OnEnChangeDaysfrom();
	virtual BOOL OnInitDialog();
	afx_msg void OnDtnDatetimechangeDateInput(NMHDR* pNMHDR, LRESULT* pResult);
private:
	DateCalculator::Date inputDate;
	operations currentOperation_ = NONE;
	unsigned int days_ = 0;
	unsigned int months_ = 0;
	unsigned int years_ = 0;
};
