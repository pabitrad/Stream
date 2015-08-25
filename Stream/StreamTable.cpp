// StreamTable.cpp : implementation file
//

#include "stdafx.h"
#include "Stream.h"
#include "StreamTable.h"
#include "afxdialogex.h"
#include "EditStream.h"

// CStreamTable dialog

IMPLEMENT_DYNAMIC(CStreamTable, CDialogEx)

CStreamTable::CStreamTable(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStreamTable::IDD, pParent)
{
}

CStreamTable::~CStreamTable()
{
}

void CStreamTable::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STREAM, m_InputStreamListControl);
}

BEGIN_MESSAGE_MAP(CStreamTable, CDialogEx)
	ON_WM_ACTIVATE()
	ON_BN_CLICKED(ID_EDIT, &CStreamTable::OnBnClickedEdit)
	ON_BN_CLICKED(ID_MOVE_DOWN, &CStreamTable::OnBnClickedMoveDown)
	ON_BN_CLICKED(ID_MOVE_UP, &CStreamTable::OnBnClickedMoveUp)
	ON_BN_CLICKED(ID_DELETE_STREAM, &CStreamTable::OnBnClickedDeleteStream)
END_MESSAGE_MAP()

// CStreamTable message handlers
void CStreamTable::readStreamData()
{
	m_InputStreamListControl.InsertColumn(0, _T("Url"), LVCFMT_LEFT, 200);
	m_InputStreamListControl.InsertColumn(1, _T("Description"), LVCFMT_LEFT, 220);

	int nIndex = m_InputStreamListControl.InsertItem(0, _T("www.yahoo.com"));
	m_InputStreamListControl.SetItemText(nIndex, 1, _T("AVI Audio Stream 1"));

	nIndex = m_InputStreamListControl.InsertItem(0, _T("www.hotmail.com"));
	m_InputStreamListControl.SetItemText(nIndex, 1, _T("AVI Audio Stream 2"));
}

BOOL CStreamTable::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_InputStreamListControl.SetExtendedStyle(m_InputStreamListControl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	readStreamData();

	return TRUE;
}

void CStreamTable::OnBnClickedEdit()
{
	POSITION pos = m_InputStreamListControl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("Select a steam to edit."));
		return;
	}

	CEditStream * pEditStream = new CEditStream(&m_InputStreamListControl);
	pEditStream->DoModal();
}


void CStreamTable::OnBnClickedMoveDown()
{
	int item = m_InputStreamListControl.GetNextItem(-1, LVNI_SELECTED);
	if (item == -1)
		return;

	if (item < m_InputStreamListControl.GetItemCount() - 1)
	{
		CString name, befehl;
		name = m_InputStreamListControl.GetItemText(item, 0);
		befehl = m_InputStreamListControl.GetItemText(item, 1);
		m_InputStreamListControl.DeleteItem(item);
		m_InputStreamListControl.InsertItem(item + 1, name);
		m_InputStreamListControl.SetItemText(item + 1, 1, befehl);
		m_InputStreamListControl.SetItemState(item + 1, LVNI_SELECTED, LVIS_SELECTED);
	}
}

void CStreamTable::OnBnClickedMoveUp()
{
	int item = m_InputStreamListControl.GetNextItem(-1, LVNI_SELECTED);
	if (item == -1)
		return;

	if (item > 0)
	{
		CString name, befehl;
		name = m_InputStreamListControl.GetItemText(item, 0);
		befehl = m_InputStreamListControl.GetItemText(item, 1);
		m_InputStreamListControl.DeleteItem(item);
		m_InputStreamListControl.InsertItem(item - 1, name);
		m_InputStreamListControl.SetItemText(item - 1, 1, befehl);
		m_InputStreamListControl.SetItemState(item - 1, LVNI_SELECTED, LVIS_SELECTED);
	}
}


void CStreamTable::OnBnClickedDeleteStream()
{
	POSITION pos =  m_InputStreamListControl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("Select a steam to delete."));
		return;
	}

	int nItem = m_InputStreamListControl.GetNextSelectedItem(pos);
	m_InputStreamListControl.DeleteItem(nItem);
}
