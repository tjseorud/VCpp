// 0912.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>	//표준 입출력
#include <conio.h>	//콘솔 입출력

int main(){
	char input;
	char enter;
    printf("SDK의 행복한 VC++\n");
	while (1) {
		printf("command> ");
		input = _getch();
		if (input == 27) {		//esc 입력시
			exit(0);
		}
		enter = _getch();
		if (enter == 13); {		//enter 입력시
			switch (input)
			{
			case 113:	//q 입력시
				printf("q : qwer 화이팅\n");
				continue;
			case 119:	//w 입력시
				printf("W : 과제 너무 좋다\n");
				continue;
			case 101:	//e 입력시
				printf("e : 담주부턴 과제량 3배다\n");
				continue;
			case 114:	//r 입력시
				printf("r : 행복합니다.\n");
				continue;
			default:	//다른키 입력시
				printf("입력오류\n");
				continue;
			}
		}
	}
	return(0);
}

