// 0919.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>		//포준 입출력
#include <conio.h>		//콘솔 입출력
#include <chrono>       //시간 사용을 위한 헤더
#include <thread>       //스레드 사용을 위한 헤더

using namespace std;
using namespace chrono;
using namespace this_thread;

int main() {
    string input_s;
    char input;
    char ch;
    bool output = false;
    wchar_t A[] = L"아도겐! =o";
    wchar_t S[] = L"HP 10 % 회복";
    wchar_t D[] = L"돌진!!";
    wchar_t F[] = L"( -_-)--*";

    while (1) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {    // ESC key
                exit(1);
            }
            input_s += ch; //문자열에 저장
            input = ch;
            sleep_for(milliseconds(300));   //300 간 대기
            switch (input)  //←75 ↑72 ↓80 →77 
            {               //A65  S83  D68  F70
            case 72:
                if (input == 65) {      //a
                    cout << A << endl;  //아도겐! =o
                    input_s.clear();
                    output = true;
                    break;
                }
            case 80:
                if (input == 70) {      //f
                    cout << F << endl;  //( -_-)--*
                    input_s.clear();
                    output = true;
                    break;
                }
            case 75:
                if (input == 83) {       //s
                    cout << S << endl;   //HP 10 % 회복
                    input_s.clear();
                    output = true;
                    break;
                }
            case 77:
                if (input == 68) {      //d
                    cout << D << endl;  //돌진!!
                    input_s.clear();
                    output = true;
                    break;
                }
            default:
                /*cout << "88224646BA... 어라?"\n << endl; */
                input_s.clear();
                output = true;
                break;
            }
        }
        if (output) {
            sleep_for(seconds(1));  //1초간 대기
            output = false;
        }
    }
    return 0;
}   