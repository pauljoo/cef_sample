
// SampleCefMfcDlg.h : ͷ�ļ�
//

#pragma once


// CSampleCefMfcDlg �Ի���
class CSampleCefMfcDlg : public CDialogEx
{
// ����
public:
	CSampleCefMfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAMPLECEFMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void OnClose();
	afx_msg void OnDestroy();
};
