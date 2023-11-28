#pragma once
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <windows.h>
#include "Res.h"

void DrawBonobono(HWND hwnd, HDC hdc, int blink);
void DrawRyan(HWND hwnd, HDC hdc, int left, int top, int right, int bottom);