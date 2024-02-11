// DateDiff.cpp : implementation file
//

#include "pch.h"
#include "DateCalculator.hpp"
#include "afxdialogex.h"
#include "DateDiff.h"
#include "resource.h"
#include <string>


// DateDiff dialog

IMPLEMENT_DYNAMIC(DateDiff, CDialogEx)

DateDiff::DateDiff(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB1, pParent)
{

}

DateDiff::~DateDiff()
{
}

void DateDiff::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

#pragma warning( push )
#pragma warning( disable : 26454 )

BEGIN_MESSAGE_MAP(DateDiff, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_FROMDATE_PICKER, &DateDiff::OnDtnDatetimechangeFromdatePicker)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TODATE_PICKER, &DateDiff::OnDtnDatetimechangeTodatePicker)
END_MESSAGE_MAP()

#pragma warning( pop )

// DateDiff message handlers


void DateDiff::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
}

static std::wstring GetDateDifference(CDateTimeCtrl* fromDateCtrl, CDateTimeCtrl* toDateCtrl)
{
	std::string dateDiff = "Homies Be Balling";

	CTime dateInfo;

	fromDateCtrl->GetTime(dateInfo);

	// FIXME: CTime GetYear will break if you go past 1970

	int year = dateInfo.GetYear();
	DateCalculator::MONTH month = static_cast<DateCalculator::MONTH>(dateInfo.GetMonth());
	int day = dateInfo.GetDay();
	DateCalculator::Date from_Date(month, day, year);

	toDateCtrl->GetTime(dateInfo);
	year = dateInfo.GetYear();
	month = static_cast<DateCalculator::MONTH>(dateInfo.GetMonth());
	day = dateInfo.GetDay();
	DateCalculator::Date to_Date(month, day, year);

	dateDiff = from_Date - to_Date;

	std::wstring dateDiffOutput(dateDiff.begin(), dateDiff.end());
	return dateDiffOutput;
}

void DateDiff::OnDtnDatetimechangeFromdatePicker(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);

	// calc & change date difference output
	CDateTimeCtrl* fromDateCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_FROMDATE_PICKER);
	CDateTimeCtrl* toDateCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_TODATE_PICKER);
	CStatic* DiffDateOutput = (CStatic*)GetDlgItem(IDC_DATEDIFF_OUTPUT);

	std::wstring diffOutputString = GetDateDifference(fromDateCtrl, toDateCtrl);
	LPCTSTR OUTPUT_DIFFERENCE = diffOutputString.c_str();

	DiffDateOutput->SetWindowTextW(OUTPUT_DIFFERENCE);

	*pResult = 0;
}


void DateDiff::OnDtnDatetimechangeTodatePicker(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);

	// calc & change date difference output
	CDateTimeCtrl* fromDateCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_FROMDATE_PICKER);
	CDateTimeCtrl* toDateCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_TODATE_PICKER);
	CStatic* DiffDateOutput = (CStatic*)GetDlgItem(IDC_DATEDIFF_OUTPUT);

	std::wstring diffOutputString = GetDateDifference(fromDateCtrl, toDateCtrl);
	LPCTSTR OUTPUT_DIFFERENCE = diffOutputString.c_str();

	DiffDateOutput->SetWindowTextW(OUTPUT_DIFFERENCE);

	*pResult = 0;
}
