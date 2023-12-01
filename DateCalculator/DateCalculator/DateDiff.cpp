// DateDiff.cpp : implementation file
//

#include "pch.h"
#include "DateCalculator.hpp"
#include "afxdialogex.h"
#include "DateDiff.h"
#include "resource.h"


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


BEGIN_MESSAGE_MAP(DateDiff, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// DateDiff message handlers


void DateDiff::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}
