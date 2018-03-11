#pragma once

LRESULT CALLBACK KeyBoardProc(int code, WPARAM wParam, LPARAM lParam);
void SetHook();
void UnSetHook();