#pragma once
#include "afxcmn.h"


// CStreamTable dialog

class CStreamTable : public CDialogEx
{
	DECLARE_DYNAMIC(CStreamTable)

public:
	CStreamTable(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStreamTable();

// Dialog Data
	enum { IDD = IDD_STREAM_TABLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_InputStreamListControl;

private:
	void readStreamData();
public:

	BOOL OnInitDialog();
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedMoveDown();
	afx_msg void OnBnClickedMoveUp();
	afx_msg void OnBnClickedDeleteStream();
};
