#pragma once


// HotKeyDlg �Ի���

class HotKeyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HotKeyDlg)

public:
	HotKeyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HotKeyDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_HOT_KEY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
														// ���ɵ���Ϣӳ�亯��
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedHotKeyConfirmBtn();
	afx_msg void OnBnClickedHotKeyCancelBtn();
};
