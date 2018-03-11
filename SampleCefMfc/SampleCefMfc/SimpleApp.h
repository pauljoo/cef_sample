#pragma once

#include "include/cef_app.h"

class SimpleApp : public CefApp,
	public CefBrowserProcessHandler {
public:
	SimpleApp();

	// CefApp methods:
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler()
		OVERRIDE {
		return this;
	}

	// CefBrowserProcessHandler methods:
	virtual void OnContextInitialized() OVERRIDE;

	virtual void OnBeforeCommandLineProcessing(
		const CefString& process_type, CefRefPtr<CefCommandLine> command_line) {
		command_line->AppendSwitch("disable-gpu");
	}
private:
	HWND m_pParentWindow;
	// Include the default reference counting implementation.
	IMPLEMENT_REFCOUNTING(SimpleApp);
};