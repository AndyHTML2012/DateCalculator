// DateArith.cpp : implementation file
//

#include "pch.h"
#include "DateCalculator.hpp"
#include "afxdialogex.h"
#include "DateArith.h"
#include "resource.h"


// DateArith dialog

IMPLEMENT_DYNAMIC(DateArith, CDialogEx)

DateArith::DateArith(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB2, pParent)
{

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
END_MESSAGE_MAP()

#pragma warning( pop )

// DateArith message handlers

static void UpdateArithOutputLabel(CStatic* arithOutputCtrl)
{
	//UNREFERENCED_PARAMETER(arithOutputCtrl);
	arithOutputCtrl->SetWindowTextW(L"04/20/6969");
}


void DateArith::OnBnClickedAddOperation()
{
	// TODO: Add your control notification handler code here
}


void DateArith::OnBnClickedSubtractOperation()
{
	// TODO: Add your control notification handler code here
}


void DateArith::OnEnChangeYearsfrom()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void DateArith::OnEnChangeMonthsfrom()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void DateArith::OnEnChangeDaysfrom()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
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

	CStatic* ArithOutputCtrl = (CStatic*)GetDlgItem(IDC_DATEARITH_OUTPUT);
	UpdateArithOutputLabel(ArithOutputCtrl);

	*pResult = 0;
}
