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

/*!**************************************************************************************
 * @brief				Get wString difference between two inputed dates from MFC GUI.
 * @param fromDateCtrl	COleDateTime ctrl of past date.
 * @param toDateCtrl	COleDateTime ctrl of future date.
 * @return				wstring of date difference.
****************************************************************************************/
static std::wstring GetDateDifference(COleDateTime fromDateCtrl, COleDateTime toDateCtrl)
{
	std::string dateDiff = "foo";

	unsigned int day = 0;
	unsigned int int_month = 0;
	unsigned int year = 0;

	// Get fromDate
	year = fromDateCtrl.GetYear();
	int_month = fromDateCtrl.GetMonth();
	day = fromDateCtrl.GetDay();

	DateCalculator::MONTH month = static_cast<DateCalculator::MONTH>(int_month);
	DateCalculator::Date from_Date(month, day, year);

	// Get toDate
	year = toDateCtrl.GetYear();
	int_month = toDateCtrl.GetMonth();
	day = toDateCtrl.GetDay();

	month = static_cast<DateCalculator::MONTH>(int_month);
	DateCalculator::Date to_Date(month, day, year);

	if (from_Date.GetYear() == 0 || to_Date.GetYear() == 0)
	{
		dateDiff = "Date does not exist.";
	}
	else
	{
		// Get Date Difference
		dateDiff = from_Date - to_Date;
	}

	std::wstring dateDiffOutput(dateDiff.begin(), dateDiff.end());
	return dateDiffOutput;
}

void DateDiff::OnDtnDatetimechangeFromdatePicker(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);

	CDateTimeCtrl* fromDateCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_FROMDATE_PICKER);
	CDateTimeCtrl* toDateCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_TODATE_PICKER);
	CStatic* DiffDateOutput = (CStatic*)GetDlgItem(IDC_DATEDIFF_OUTPUT);

	if (fromDateCtrl != NULL && toDateCtrl != NULL)
	{
		COleDateTime fromDateInfo;
		COleDateTime toDateInfo;

		if (fromDateCtrl->GetTime(fromDateInfo) && toDateCtrl->GetTime(toDateInfo))
		{
			if (fromDateInfo.GetStatus() == COleDateTime::valid &&
				toDateInfo.GetStatus() == COleDateTime::valid)
			{
				// calc & change date difference output
				std::wstring diffOutputString = GetDateDifference(fromDateInfo, toDateInfo);
				LPCTSTR OUTPUT_DIFFERENCE = diffOutputString.c_str();
				DiffDateOutput->SetWindowTextW(OUTPUT_DIFFERENCE);
			}
		}
	}

	*pResult = 0;
}


void DateDiff::OnDtnDatetimechangeTodatePicker(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);

	CDateTimeCtrl* fromDateCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_FROMDATE_PICKER);
	CDateTimeCtrl* toDateCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_TODATE_PICKER);
	CStatic* DiffDateOutput = (CStatic*)GetDlgItem(IDC_DATEDIFF_OUTPUT);

	if (fromDateCtrl != NULL && toDateCtrl != NULL)
	{
		COleDateTime fromDateInfo;
		COleDateTime toDateInfo;

		if (fromDateCtrl->GetTime(fromDateInfo) && toDateCtrl->GetTime(toDateInfo))
		{
			if (fromDateInfo.GetStatus() == COleDateTime::valid &&
				toDateInfo.GetStatus() == COleDateTime::valid)
			{
				// calc & change date difference output
				std::wstring diffOutputString = GetDateDifference(fromDateInfo, toDateInfo);
				LPCTSTR OUTPUT_DIFFERENCE = diffOutputString.c_str();
				DiffDateOutput->SetWindowTextW(OUTPUT_DIFFERENCE);
			}
		}
	}

	*pResult = 0;
}


BOOL DateDiff::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
