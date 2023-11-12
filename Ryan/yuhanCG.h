#pragma once //중복선언 방지
#include <windows.h>

class yuhanCG {
public:
	void DrawBonobono(HWND hWnd, HDC hdc, int blink);
	void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom);
};