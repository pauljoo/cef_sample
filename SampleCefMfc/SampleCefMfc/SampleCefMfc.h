
// SampleCefMfc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSampleCefMfcApp: 
// �йش����ʵ�֣������ SampleCefMfc.cpp
//

class CSampleCefMfcApp : public CWinApp
{
public:
	CSampleCefMfcApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSampleCefMfcApp theApp;