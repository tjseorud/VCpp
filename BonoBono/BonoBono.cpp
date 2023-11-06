#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "resource.h"

bool isBox = false;			//상자
bool isCircle = false;		//타원
bool isBonobono = false;	//보노보노
bool isRyan = false;		//라이온
bool isCube = false;		//큐브

POINT startPoint = { 0 };
POINT endPoint = { 0 };
int isMouseLButtonPressed = 0;

HDC hdc;
PAINTSTRUCT ps;
HBITMAP myBitmap, oldBitmap;
HINSTANCE gInst;
LPCWSTR bmpName;
bool isClose;

void DrawBox(HWND hwnd, HDC hdc) {
	RECT rect;
	//GetClientRect(hwnd, &rect);
	if (isBox) {
		// 박스 그리기		
		hdc = GetDC(hwnd);			// 디바이스 컨텍스트 얻기
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // 브러시 생성
		//생성한 브러시를 DC에 연결하고 기존 브러시는 oldBrush에 저장
		HGDIOBJ oldBrush = SelectObject(hdc, hBrush);
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
		Rectangle(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
		SelectObject(hdc, oldBrush);	//기존에 사용하던 브러시로 복구
		DeleteObject(hBrush);			//생성한 브러시를 제거
		ReleaseDC(hwnd, hdc);			// 디바이스 컨텍스트 해제
	}
	else if (isCircle) {
		// 타원 그리기
		hdc = GetDC(hwnd);			// 디바이스 컨텍스트 얻기
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // 브러시 생성
		//생성한 브러시를 DC에 연결하고 기존 브러시는 oldBrush에 저장
		HGDIOBJ oldBrush = SelectObject(hdc, hBrush);
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
		Ellipse(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
		SelectObject(hdc, oldBrush);	//기존에 사용하던 브러시로 복구
		DeleteObject(hBrush);			//생성한 브러시를 제거
		ReleaseDC(hwnd, hdc);			// 디바이스 컨텍스트 해제
	}
	else if (isBonobono) {
		if (isClose) {
			bmpName = MAKEINTRESOURCE(IDB_BITMAP2);	//눈 감은
		}
		else {
			bmpName = MAKEINTRESOURCE(IDB_BITMAP1); //눈 뜬
		}
		//보노보노 그리기
		HDC Memdc;
		hdc = GetDC(hwnd);				// 디바이스 컨텍스트 얻기
		Memdc = CreateCompatibleDC(hdc);		//메모리dc 생성
		myBitmap = LoadBitmap(gInst, bmpName); //1 로딩
		oldBitmap = (HBITMAP)SelectObject(Memdc, myBitmap); //비트맵 선택
		// 800, 480
		BitBlt(hdc, 268, 112, 263, 257, Memdc, 0, 0, SRCCOPY); //복사 및 출력
		SelectObject(Memdc, oldBitmap);
		DeleteObject(myBitmap);	
		ReleaseDC(hwnd, hdc);			// 디바이스 컨텍스트 해제
	}
	else if (isRyan) {
		// 라이온 그리기
		hdc = GetDC(hwnd);				// 디바이스 컨텍스트 얻기			
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 200, 15)); // 브러시 생성
		//생성한 브러시를 DC에 연결하고 기존 브러시는 oldBrush에 저장
		HGDIOBJ oldBrush = SelectObject(hdc, hBrush);
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
		Ellipse(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
		SelectObject(hdc, oldBrush);	//기존에 사용하던 브러시로 복구
		DeleteObject(hBrush);			//생성한 브러시를 제거
		ReleaseDC(hwnd, hdc);			// 디바이스 컨텍스트 해제
	}
	else if (isCube) {
		// 큐브 그리기
		HDC hdc = GetDC(hwnd);			// 디바이스 컨텍스트 얻기	
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0)); // 브러시 생성
		//생성한 브러시를 DC에 연결하고 기존 브러시는 oldBrush에 저장
		HGDIOBJ oldBrush = SelectObject(hdc, hBrush);
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
		Rectangle(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
		SelectObject(hdc, oldBrush);	//기존에 사용하던 브러시로 복구
		DeleteObject(hBrush);			//생성한 브러시를 제거
		ReleaseDC(hwnd, hdc);			// 디바이스 컨텍스트 해제
	}
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_COMMAND: {	//버튼
			if (LOWORD(wParam) == 1) {
				isBox = true;
				isCircle = false;
				isBonobono = false;
				isRyan = false;
				isCube = false;
				InvalidateRect(hwnd, NULL, TRUE);
			}
			else if (LOWORD(wParam) == 2) {
				isBox = false;
				isCircle = true;
				isBonobono = false;
				isRyan = false;
				isCube = false;
				InvalidateRect(hwnd, NULL, TRUE);
			}
			else if (LOWORD(wParam) == 3) {
				isBox = false;
				isCircle = false;
				isBonobono = true;
				isRyan = false;
				isCube = false;
				InvalidateRect(hwnd, NULL, TRUE);
			}
			else if (LOWORD(wParam) == 4) {
				isBox = false;
				isCircle = false;
				isBonobono = false;
				isRyan = true;
				isCube = false;
				InvalidateRect(hwnd, NULL, TRUE);
			}
			else if (LOWORD(wParam) == 5) {
				isBox = false;
				isCircle = false;
				isBonobono = false;
				isRyan = false;
				isCube = true;
				InvalidateRect(hwnd, NULL, TRUE);
			}			
			break;
		}
		case WM_LBUTTONDOWN: {
			startPoint.x = LOWORD(lParam);	//시작점 x
			startPoint.y = HIWORD(lParam);	//시작점 y
			isMouseLButtonPressed = 1;
		}
		break;
		case WM_MOUSEMOVE: {
			// 마우스 이동 중
			if (isMouseLButtonPressed) {
				endPoint.x = LOWORD(lParam);
				endPoint.y = HIWORD(lParam);
				// WM_PAINT 메시지를 유발하여 네모를 화면에 그립니다.
				InvalidateRect(hwnd, NULL, TRUE);
			}
		}
		break;
		case WM_LBUTTONUP: {
			endPoint.x = LOWORD(lParam);
			endPoint.y = HIWORD(lParam);
			isMouseLButtonPressed = 0;		
			InvalidateRect(hwnd, NULL, TRUE);
		}
		break;
		case WM_KEYDOWN: {		
			if (wParam == VK_SPACE) {
				SetFocus(hwnd);
				isClose = !isClose;
				InvalidateRect(hwnd, NULL, TRUE);
			}
		}
		break;
		case WM_PAINT: {
			PAINTSTRUCT ps;			
			//메인 화면인데 처음만 나온다..
			HDC hdc = BeginPaint(hwnd, &ps);
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 240, 200));
			FillRect(hdc, &ps.rcPaint, hBrush);
			EndPaint(hwnd, &ps);
			DrawBox(hwnd, hdc);
		}
		break;
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		default: {
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
			break;
		}
	}
	//return DefWindowProc(hwnd, uMsg, wParam, lParam);
	return S_OK;
}

#ifdef UNICODE
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
#endif
{
	HWND hwnd;
	HWND hbutton1, hbutton2, hbutton3, hbutton4, hbutton5;

	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));
	//wc.cbSize = sizeof(WNDCLASS);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"Test";
	//wc.hIconSm = LoadIcon(wc.hInstance, IDI_APPLICATION);
	gInst = hInstance;

	if(!RegisterClass(&wc)) { return 1; }

	RECT rect = { 0, 0, 800, 480 };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	hwnd = CreateWindow(wc.lpszClassName, TEXT("보노보노"), WS_OVERLAPPEDWINDOW,
		0, 0, width, height, NULL, NULL, hInstance, NULL);

	if(!hwnd) { return FALSE; }

	hbutton1 = CreateWindow(L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		20, 16, 140, 64, hwnd, (HMENU)1, hInstance, NULL);

	hbutton2 = CreateWindow(L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		175, 16, 140, 64, hwnd, (HMENU)2, hInstance, NULL);

	hbutton3 = CreateWindow(L"BUTTON", L"Bonobono", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		330, 16, 140, 64, hwnd, (HMENU)3, hInstance, NULL);

	hbutton4 = CreateWindow(L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		485, 16, 140, 64, hwnd, (HMENU)4, hInstance, NULL);

	hbutton5 = CreateWindow(L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		640, 16, 140, 64, hwnd, (HMENU)5, hInstance, NULL);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}