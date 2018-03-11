
// SampleCefMfcDlg.cpp : 实现文件
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

// CSampleCefMfcDlg 对话框


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



// CSampleCefMfcDlg 消息处理程序

BOOL CSampleCefMfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSampleCefMfcDlg::OnPaint()
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
HCURSOR CSampleCefMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSampleCefMfcDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnClose();
	
}


void CSampleCefMfcDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	UnSetHook();
}
