#include "stdafx.h"
#include "CSimpleClient.h"

CSimpleClient::CSimpleClient() {}
CSimpleClient::~CSimpleClient() {}
void CSimpleClient::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
	m_cefBrowser = browser;
}