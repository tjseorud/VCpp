#include "yuhanCG.h"

HBITMAP myBitmap, oldBitmap;
HINSTANCE gInst;
LPCWSTR bmpName;

void DrawBonobono(HWND hWnd, HDC hdc, int blink) {
	//HDC Memdc;
	//hdc = GetDC(hWnd);				// 디바이스 컨텍스트 얻기
	//Memdc = CreateCompatibleDC(hdc);		//메모리dc 생성
	//myBitmap = LoadBitmap(gInst, bmpName); //1 2 로딩
	//oldBitmap = (HBITMAP)SelectObject(Memdc, myBitmap); //비트맵 선택
	////800, 400
	//BitBlt(hdc, 268, 112, 263, 258, Memdc, 0, 0, SRCCOPY); //복사 및 출력
	//SelectObject(Memdc, oldBitmap);
	//DeleteObject(myBitmap);
	//ReleaseDC(hWnd, hdc);			// 디바이스 컨텍스트 해제
}

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom) {
	//// 라이온 그리기
	//HDC Memdc;
	//hdc = GetDC(hWnd);				// 디바이스 컨텍스트 얻기
	//Memdc = CreateCompatibleDC(hdc);		//메모리dc 생성
	//myBitmap = LoadBitmap(gInst, MAKEINTRESOURCE(IDB_BITMAP3)); //3 로딩
	//oldBitmap = (HBITMAP)SelectObject(Memdc, myBitmap); //비트맵 선택
	//BitBlt(hdc, startPoint.x, startPoint.y, 263, 258, Memdc, 0, 0, SRCCOPY); //복사 및 출력
	//SelectObject(Memdc, oldBitmap);
	//DeleteObject(myBitmap);
	//ReleaseDC(hWnd, hdc);			// 디바이스 컨텍스트 해제
}