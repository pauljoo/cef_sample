#include "stdafx.h"
#include "KeyBoardProc.h"

#ifndef KEYBOARDPROC_H_
#define KEYBOARDPROC_H_

HHOOK g_hKeyBoard = NULL;

LRESULT CALLBACK KeyBoardProc(int code, WPARAM wParam, LPARAM lParam)
{
	if (code == HC_ACTION)
	{
		PKBDLLHOOKSTRUCT p;

		switch (wParam)
		{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
			p = (PKBDLLHOOKSTRUCT)lParam;

			if ((p->vkCode == VK_TAB) && ((p->flags & LLKHF_ALTDOWN) != 0) //ALT+TAB
				|| (p->vkCode == VK_LWIN) || (p->vkCode == VK_RWIN))  //left win or right win)  
			{
				return 1;
			}

			break;
		}

	}

	return ::CallNextHookEx(g_hKeyBoard, code, wParam, lParam);
}

//注册全局hook  
void SetHook()
{
	g_hKeyBoard = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardProc, GetModuleHandle(L"Hook"), 0);

}

//注销全局hook  
void UnSetHook()
{
	if (g_hKeyBoard)
		UnhookWindowsHookEx(g_hKeyBoard);
	g_hKeyBoard = NULL;
}

#endif