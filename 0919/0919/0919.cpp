// 0919.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>				//포준 입출력
#include <conio.h>				//콘솔 입출력
#include <Windows.h>			//Sleep함수가 포함

int main()
{
	char input;
	char combo[9];
	int i = 0;
	while (1) {
		if (kbhit()) {
			input = _getch();
			Sleep(300);				//0.3초 지연
			if (input != 27) {		//esc
				return(0);
			}
			combo[i] = input;
			if (input == 224||input==0) {	//224반환후 ?반환
				input = _getch();

			}		
		}	//printf("88224646BA... 어라?");
	}	//num4=75, num6=77, num8=72, num2=80, A=65, B=66
	return(0);
}