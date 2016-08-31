
// KeyClickDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyClick.h"
#include "KeyClickDlg.h"
#include "HotKeyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKeyClickDlg 对话框

CKeyClickDlg::CKeyClickDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_KEYCLICK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

long l_timestamp_edit = 100;//输入框 绑定变量

void CKeyClickDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//数据绑定
	DDX_Text(pDX, ID_TIMESTAMP_EDIT, l_timestamp_edit);
	DDX_Control(pDX, IDC_LIST, Domain.cListBox);
}

BEGIN_MESSAGE_MAP(CKeyClickDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_COLLECT_KEY_BTN, &CKeyClickDlg::OnBnClickedCollectKeyBtn)
END_MESSAGE_MAP()


// CKeyClickDlg 消息处理程序
HotKeyDlg* dialog;

BOOL CKeyClickDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//CEdit* pTimeStampEdit = (CEdit*)GetDlgItem(ID_TIMESTAMP_EDIT);
	//pTimeStampEdit->SetWindowTextW(L"1");
	UpdateData(FALSE);

	//实例热键对话框
	dialog = new HotKeyDlg(this);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CKeyClickDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CKeyClickDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CKeyClickDlg::OnBnClickedCollectKeyBtn()
{
	UpdateData(TRUE);
	//CString text;
	//text.Format(_T("%ld"),l_timestamp_edit);

	//AfxMessageBox(L"时间间隔："+text);
	//AfxMessageBox(L"输入一个键...");
	//dialog->Create(ID_HOT_KEY_DIALOG, this);
	//dialog->ShowWindow(SW_MAX);
	dialog->DoModal();
}
