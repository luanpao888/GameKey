// HotKeyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KeyClick.h"
#include "HotKeyDlg.h"
#include "afxdialogex.h"


// HotKeyDlg �Ի���

IMPLEMENT_DYNAMIC(HotKeyDlg, CDialogEx)

HotKeyDlg::HotKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ID_HOT_KEY_DIALOG, pParent)
{
}

HotKeyDlg::~HotKeyDlg()
{
}

//�ȼ��ؼ�
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

// HotKeyDlg ��Ϣ�������


void HotKeyDlg::OnBnClickedHotKeyConfirmBtn()
{
	HotKeyDlg::OnOK();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
