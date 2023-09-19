// 0919.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>				//포준 입출력
#include <conio.h>				//콘솔 입출력
#include <Windows.h>			//Sleep함수가 포함

int main()
{
	char input;
	char combo;
	while (1) {
		if (kbhit()) {
			input = _getch();
			//Sleep(300);				//0.3초 지연
			if (input != 27) {		//esc
				return(0);
			}
			if (input == 224||input==0) {	//224반환후 ?반환
				input = _getch();
				switch (input) {
				case 65:
					printf("A");
					continue;
				case 66:
					printf("B");
					continue;
				case 72:
					printf("↑");
					continue;
				case 75:
					printf("←");
					continue;
				case 77:
					printf("→");
					continue;
				case 80:
					printf("↓");
					continue;
				case 0:
					printf("88224646BA... 어라?");
					continue;
				default:				//다른키 입력시
					continue;
				}
			}		
		}
	}	//num4=75, num6=77, num8=72, num2=80, A=65, B=66
	return(0);
}