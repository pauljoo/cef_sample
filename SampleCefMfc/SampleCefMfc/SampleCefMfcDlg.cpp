
// SampleCefMfcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SampleCefMfc.h"
#include "SampleCefMfcDlg.h"
#include "afxdialogex.h"
#include "KeyBoardProc.h"
#include "include/cef_app.h"
#include "SimpleApp.h"
#include "SimpleHandler.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSampleCefMfcDlg �Ի���


CSampleCefMfcDlg::CSampleCefMfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SAMPLECEFMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSampleCefMfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSampleCefMfcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()



// CSampleCefMfcDlg ��Ϣ�������

BOOL CSampleCefMfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect m_FullScreenRect;
	int nFullWidth = GetSystemMetrics(SM_CXSCREEN);
	int nFullHeight = GetSystemMetrics(SM_CYSCREEN);

	m_FullScreenRect.left = 0;
	m_FullScreenRect.top = 0;
	m_FullScreenRect.right = m_FullScreenRect.left + nFullWidth;
	m_FullScreenRect.bottom = m_FullScreenRect.top + nFullHeight;
	
	//MoveWindow(0, 0, m_FullScreenRect.Width(), m_FullScreenRect.Height(), 1);

	//ModifyStyle(WS_CAPTION | WS_THICKFRAME, 0);
	SetHook();

	

	CRect rtBody;
	//GetDlgItem(IDC_STATIC_BROWSER)->MoveWindow(0, 0, m_FullScreenRect.Width(), m_FullScreenRect.Height(), 1);
	GetDlgItem(IDC_STATIC_BROWSER)->GetWindowRect(&rtBody);
	CefWindowInfo cefWindowInfo;
	cefWindowInfo.SetAsChild(GetSafeHwnd(), rtBody);

	CefBrowserSettings browserSetting;
	CefRefPtr<SimpleHandler> objEventHandler(new SimpleHandler());
	CefBrowserHost::CreateBrowser(cefWindowInfo, objEventHandler.get(), _T("http://www.baidu.com"), browserSetting, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSampleCefMfcDlg::OnPaint()
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
HCURSOR CSampleCefMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSampleCefMfcDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnClose();
	
}


void CSampleCefMfcDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	UnSetHook();
}
