// HotKeyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyClick.h"
#include "HotKeyDlg.h"
#include "afxdialogex.h"


// HotKeyDlg 对话框

IMPLEMENT_DYNAMIC(HotKeyDlg, CDialogEx)

HotKeyDlg::HotKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ID_HOT_KEY_DIALOG, pParent)
{
}

HotKeyDlg::~HotKeyDlg()
{
}

//热键控件
CHotKeyCtrl m_hotKeyCtrl;
void HotKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//CWnd* cwnd = GetDlgItem(IDC_HOTKEY1);
	DDX_Control(pDX, IDC_HOTKEY1, m_hotKeyCtrl);

}


BEGIN_MESSAGE_MAP(HotKeyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_HOT_KEY_CONFIRM_BTN, &HotKeyDlg::OnBnClickedHotKeyConfirmBtn)
	ON_BN_CLICKED(IDC_HOT_KEY_CANCEL_BTN, &HotKeyDlg::OnBnClickedHotKeyCancelBtn)
END_MESSAGE_MAP()


void HotKeyDlg::OnPaint()
{
	CDialogEx::OnPaint();
}

// HotKeyDlg 消息处理程序


void HotKeyDlg::OnBnClickedHotKeyConfirmBtn()
{
	HotKeyDlg::OnOK();
	// TODO: 在此添加控件通知处理程序代码
	//WORD VirtualKeyCode = 0, fsModifiers = 0;
	m_hotKeyCtrl.GetHotKey(Domain.VirtualKeyCode, Domain.fsModifiers);

	//AfxMessageBox(L"1");

	CString text;
	text.Format(_T("%d"), Domain.VirtualKeyCode);

	Domain.cListBox.AddString(text);
}

void HotKeyDlg::OnBnClickedHotKeyCancelBtn()
{
	HotKeyDlg::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}
