#pragma once


// HotKeyDlg 对话框

class HotKeyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HotKeyDlg)

public:
	HotKeyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HotKeyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_HOT_KEY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
														// 生成的消息映射函数
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedHotKeyConfirmBtn();
	afx_msg void OnBnClickedHotKeyCancelBtn();
};
