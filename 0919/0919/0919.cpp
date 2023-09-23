// 0919.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>				//포준 입출력
#include <conio.h>				//콘솔 입출력
#include <windows.h>			//Sleep 함수

using namespace std;

int main() {
    char input[3];
    char ch;
    int i = 0;

    while (1) {
        if (_kbhit()) {
            ch = _getch();
            Sleep(300);
            if (ch == 27) {                 // ESC key
                exit(1);
            }
            else {
                input[i++] = ch;
                if (i >= 3) {   			//←75 ↑72 →77 ↓80
                    if (input[i - 3] == 80 && input[i - 2] == 77 && input[i - 1] == 'a') {
                        cout << "아도겐! =o" << endl;
                    }
                    else if (input[i - 3] == 77 && input[i - 2] == 77 && input[i - 1] == 's') {
                        cout << "돌진!!" << endl;
                    }
                    else if (input[i - 3] == 75 && input[i - 2] == 72 && input[i - 1] == 'd') {
                        cout << "?" << endl;
                    }
                    else if (input[i - 3] == 77 && input[i - 2] == 72 && input[i - 1] == 'f') {
                        cout << "뻐큐! ( -_-)-ㅗ" << endl;
                    }
                    /*else if (input[i - 10] == 72 && input[i - 9] == 72 && input[i - 8] == 80 && input[i - 7] == 80 && input[i - 6] == 75 && input[i - 5] == 77 && input[i - 4] == 75 && input[i - 3] == 77 && input[i - 2] == 'b' && input[i - 1] == 'a') {
                        cout << "88224646BA... 어라?"\n << endl;
                    }*/
                }
            }
        }
    }
    return 0;
}
       