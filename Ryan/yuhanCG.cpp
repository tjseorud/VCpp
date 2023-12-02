#include "yuhanCG.h"

HDC hdc;
PAINTSTRUCT ps;
HBITMAP myBitmap, oldBitmap;
HINSTANCE gInst;
LPCWSTR bmpName;
//bool isClose;
//POINT startPoint = { 0 };
//POINT endPoint = { 0 };

void DrawBonobono(HWND hwnd, HDC hdc, int blink) {
	if (blink) {
		bmpName = MAKEINTRESOURCE(IDB_BITMAP2);	//눈 감은
	}
	else {
		bmpName = MAKEINTRESOURCE(IDB_BITMAP1); //눈 뜬
	}
	//보노보노 그리기
	HDC Memdc;
	hdc = GetDC(hwnd);				// 디바이스 컨텍스트 얻기
	Memdc = CreateCompatibleDC(hdc);		//메모리dc 생성
	myBitmap = LoadBitmap(gInst, bmpName); //1 2 로딩
	oldBitmap = (HBITMAP)SelectObject(Memdc, myBitmap); //비트맵 선택
	//800, 400
	BitBlt(hdc, 268, 157, 263, 258, Memdc, 0, 0, SRCCOPY); //복사 및 출력
	SelectObject(Memdc, oldBitmap);
	DeleteObject(myBitmap);
	ReleaseDC(hwnd, hdc);			// 디바이스 컨텍스트 해제
}

void DrawRyan(HWND hwnd, HDC hdc, int left, int top, int right, int bottom) {
	// 라이온 그리기
	HDC Memdc;
	hdc = GetDC(hwnd);				// 디바이스 컨텍스트 얻기
	Memdc = CreateCompatibleDC(hdc);		//메모리dc 생성
	myBitmap = LoadBitmap(gInst, MAKEINTRESOURCE(IDB_BITMAP3)); //3 로딩
	oldBitmap = (HBITMAP)SelectObject(Memdc, myBitmap); //비트맵 선택
	StretchBlt(hdc, left, right, top, bottom, Memdc, 0, 0, 263, 250, SRCCOPY); //복사 및 출력
	SelectObject(Memdc, oldBitmap);
	DeleteObject(myBitmap);
	ReleaseDC(hwnd, hdc);			// 디바이스 컨텍스트 해제
}