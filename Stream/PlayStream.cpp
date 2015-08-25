// PlayStream.cpp : implementation file
//

#include "stdafx.h"
#include "Stream.h"
#include "PlayStream.h"
#include "afxdialogex.h"

// CPlayStream dialog

IMPLEMENT_DYNAMIC(CPlayStream, CDialogEx)

CPlayStream::CPlayStream(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayStream::IDD, pParent)
{

}

CPlayStream::~CPlayStream()
{
}

void CPlayStream::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_VOLUME, volumeSlider);
}


BEGIN_MESSAGE_MAP(CPlayStream, CDialogEx)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER_VOLUME, &CPlayStream::OnTRBNThumbPosChangingSliderVolume)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_VOLUME, &CPlayStream::OnNMReleasedcaptureSliderVolume)
END_MESSAGE_MAP()


// CPlayStream message handlers


void CPlayStream::OnTRBNThumbPosChangingSliderVolume(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CPlayStream::OnNMReleasedcaptureSliderVolume(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	int pos = volumeSlider.GetPos();
}

BOOL CPlayStream::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	volumeSlider.SetRange(1, 100);
	return TRUE;
}