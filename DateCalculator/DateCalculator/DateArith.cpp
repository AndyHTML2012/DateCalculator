// DateArith.cpp : implementation file
//

#include "pch.h"
#include "DateCalculator.hpp"
#include "afxdialogex.h"
#include "DateArith.h"
#include "resource.h"
#include <vector>

// DateArith dialog

IMPLEMENT_DYNAMIC(DateArith, CDialogEx)

DateArith::DateArith(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB2, pParent)
{
	this->currentOperation_ = NONE;
	this->days_ = 0;
	this->months_ = 0;
	this->years_ = 0;
	this->output_ = L"ADD OR SUBTRACT FROM INPUTED DATE";
}

DateArith::~DateArith()
{
}

void DateArith::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

#pragma warning( push )
#pragma warning( disable : 26454 )

BEGIN_MESSAGE_MAP(DateArith, CDialogEx)
	ON_BN_CLICKED(IDC_ADD_OPERATION, &DateArith::OnBnClickedAddOperation)
	ON_BN_CLICKED(IDC_SUBTRACT_OPERATION, &DateArith::OnBnClickedSubtractOperation)
	ON_EN_CHANGE(IDC_YEARSFROM, &DateArith::OnEnChangeYearsfrom)
	ON_EN_CHANGE(IDC_MONTHSFROM, &DateArith::OnEnChangeMonthsfrom)
	ON_EN_CHANGE(IDC_DAYSFROM, &DateArith::OnEnChangeDaysfrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE_INPUT, &DateArith::OnDtnDatetimechangeDateInput)
	ON_BN_CLICKED(IDC_ARITHCALC_BUTTON, &DateArith::OnBnClickedArithcalcButton)
END_MESSAGE_MAP()

#pragma warning( pop )

// DateArith message handlers

void DateArith::OnBnClickedAddOperation()
{
	currentOperation_ = ADD;
}


void DateArith::OnBnClickedSubtractOperation()
{
	currentOperation_ = SUBTRACT;
}


void DateArith::OnEnChangeYearsfrom()
{
	// get inputed year text
	CEdit* yearArithCtrl = (CEdit*)GetDlgItem(IDC_YEARSFROM);
	CString yearsCtrltxt;
	yearArithCtrl->GetWindowTextW(yearsCtrltxt);

	// convert text to unsigned int
	this->years_ = _tstoi(yearsCtrltxt.GetString());
}


void DateArith::OnEnChangeMonthsfrom()
{
	// get inputed month text
	CEdit* monthArithCtrl = (CEdit*)GetDlgItem(IDC_MONTHSFROM);
	CString monthsCtrltxt;
	monthArithCtrl->GetWindowTextW(monthsCtrltxt);

	// convert text to unsigned int
	this->months_ = _tstoi(monthsCtrltxt.GetString());
}


void DateArith::OnEnChangeDaysfrom()
{
	// get inputed day text
	CEdit* dayArithCtrl = (CEdit*)GetDlgItem(IDC_DAYSFROM);
	CString daysCtrltxt;
	dayArithCtrl->GetWindowTextW(daysCtrltxt);

	// convert text to unsigned int
	this->days_ = _tstoi(daysCtrltxt.GetString());
}


BOOL DateArith::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void DateArith::OnDtnDatetimechangeDateInput(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);

	using namespace DateCalculator;

	CDateTimeCtrl* dateCtrlInput = (CDateTimeCtrl*)GetDlgItem(IDC_DATE_INPUT);
	COleDateTime dateCtrlInfo;

	if (dateCtrlInput->GetTime(dateCtrlInfo) && dateCtrlInfo.GetStatus() == COleDateTime::valid)
	{
		Date tempDate(static_cast<DateCalculator::MONTH>(dateCtrlInfo.GetMonth()),
														 dateCtrlInfo.GetDay(),
														 dateCtrlInfo.GetYear());
		inputDate = tempDate;
	}

	*pResult = 0;
}


void DateArith::OnBnClickedArithcalcButton()
{
	using namespace DateCalculator;

	std::vector<std::wstring> month = { L"N/A", L"January", L"February", L"March", L"April", L"May", L"June", L"July", L"August", L"September", L"October", L"November", L"December" };
	Date outputDate;

	CStatic* ArithOutputCtrl = (CStatic*)GetDlgItem(IDC_DATEARITH_OUTPUT);
	ArithOutputCtrl->SetWindowTextW(L"");
	output_.clear();

	////////// GET DATE ///////////

	CDateTimeCtrl* dateCtrlInput = (CDateTimeCtrl*)GetDlgItem(IDC_DATE_INPUT);
	COleDateTime dateCtrlInfo;

	if (dateCtrlInput->GetTime(dateCtrlInfo) && dateCtrlInfo.GetStatus() == COleDateTime::valid)
	{
		Date tempDate(static_cast<DateCalculator::MONTH>(dateCtrlInfo.GetMonth()),
			dateCtrlInfo.GetDay(),
			dateCtrlInfo.GetYear());
		inputDate = tempDate;
	}

	///// CALCULATE NEW DATE /////

	outputDate = inputDate;

	// Calculate new date

	if (currentOperation_ == ADD)
	{
		outputDate.AddYears(years_);
		outputDate.AddMonths(months_);
		outputDate.AddDays(days_);
	}

	if (currentOperation_ == SUBTRACT)
	{
		outputDate.SubYears(years_);
		outputDate.SubMonths(months_);
		outputDate.SubDays(days_);
	}

	if (outputDate.GetYear() == 0)
	{
		output_ += L"Cannot go past year 0";
	}
	else 
	{
		output_ += month[outputDate.GetMonth()] + L" " + std::to_wstring(outputDate.GetDay()) + L", " + std::to_wstring(outputDate.GetYear());
	}
	
	// Print new date
	ArithOutputCtrl->SetWindowTextW(output_.c_str());
}


void DateArith::OnOK()
{
	//CDialogEx::OnOK();
	return;
}
