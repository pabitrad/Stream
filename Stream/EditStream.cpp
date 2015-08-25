// EditStream.cpp : implementation file
//

#include "stdafx.h"
#include "Stream.h"
#include "EditStream.h"
#include "afxdialogex.h"

// CEditStream dialog

IMPLEMENT_DYNAMIC(CEditStream, CDialogEx)

CEditStream::CEditStream(CListCtrl * pStreamList, CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditStream::IDD, pParent)
	, streamURL(_T(""))
	, streamDescription(_T(""))
{
	p2StreamList = pStreamList;
	POSITION pos = pStreamList->GetFirstSelectedItemPosition();
	int nItem = pStreamList->GetNextSelectedItem(pos);

	streamURL = pStreamList->GetItemText(nItem, 0);
	streamDescription = pStreamList->GetItemText(nItem, 1);
}

CEditStream::~CEditStream()
{
}

void CEditStream::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STREAM_URL, streamURL);
	DDX_Text(pDX, IDC_EDIT_STREAM_DESCRIPTION, streamDescription);
}


BEGIN_MESSAGE_MAP(CEditStream, CDialogEx)
	ON_BN_CLICKED(IDC_SAVE, &CEditStream::OnBnClickedSave)
END_MESSAGE_MAP()

// CEditStream message handlers

void CEditStream::OnBnClickedSave()
{
	UpdateData(TRUE);
	POSITION pos = p2StreamList->GetFirstSelectedItemPosition();
	int nItem = p2StreamList->GetNextSelectedItem(pos);

	p2StreamList->SetItemText(nItem, 0, streamURL);
	p2StreamList->SetItemText(nItem, 1, streamDescription);

	EndDialog(1);
}
