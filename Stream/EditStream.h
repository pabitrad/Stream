#pragma once


// CEditStream dialog

class CEditStream : public CDialogEx
{
	DECLARE_DYNAMIC(CEditStream)

public:
	CEditStream(CListCtrl * pStreamList, CWnd* pParent = NULL);   // standard constructor
	virtual ~CEditStream();

// Dialog Data
	enum { IDD = IDD_EDIT_STREAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString streamURL;
	CString streamDescription;
	afx_msg void OnBnClickedSave();

private:
	CListCtrl * p2StreamList;
};
