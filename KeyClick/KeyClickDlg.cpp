
// KeyClickDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KeyClick.h"
#include "KeyClickDlg.h"
#include "HotKeyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKeyClickDlg �Ի���

CKeyClickDlg::CKeyClickDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_KEYCLICK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

long l_timestamp_edit = 100;//����� �󶨱���

void CKeyClickDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//���ݰ�
	DDX_Text(pDX, ID_TIMESTAMP_EDIT, l_timestamp_edit);
	DDX_Control(pDX, IDC_LIST, Domain.cListBox);
}

BEGIN_MESSAGE_MAP(CKeyClickDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_COLLECT_KEY_BTN, &CKeyClickDlg::OnBnClickedCollectKeyBtn)
END_MESSAGE_MAP()


// CKeyClickDlg ��Ϣ�������
HotKeyDlg* dialog;

BOOL CKeyClickDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//CEdit* pTimeStampEdit = (CEdit*)GetDlgItem(ID_TIMESTAMP_EDIT);
	//pTimeStampEdit->SetWindowTextW(L"1");
	UpdateData(FALSE);

	//ʵ���ȼ��Ի���
	dialog = new HotKeyDlg(this);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CKeyClickDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CKeyClickDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CKeyClickDlg::OnBnClickedCollectKeyBtn()
{
	UpdateData(TRUE);
	//CString text;
	//text.Format(_T("%ld"),l_timestamp_edit);

	//AfxMessageBox(L"ʱ������"+text);
	//AfxMessageBox(L"����һ����...");
	//dialog->Create(ID_HOT_KEY_DIALOG, this);
	//dialog->ShowWindow(SW_MAX);
	dialog->DoModal();
}
