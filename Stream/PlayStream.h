#pragma once
#include "afxcmn.h"


// CPlayStream dialog

class CPlayStream : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayStream)

public:
	CPlayStream(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPlayStream();

	BOOL OnInitDialog();
// Dialog Data
	enum { IDD = IDD_PLAY_STREAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTRBNThumbPosChangingSliderVolume(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderVolume(NMHDR *pNMHDR, LRESULT *pResult);

	CSliderCtrl volumeSlider;
};
