// 0912.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(){
	char tmp = NULL;
    printf("SDK의 행복한 VC++\n");
	while (1) {
		printf("command> ");
		tmp = _getch();
		if (tmp == 27) {	//esc
			break;
		}
		switch (tmp)
		{case 113:	//q
			printf("q : qwer 화이팅\n");
			continue;
		case 119:	//w
			printf("W : 과제 너무 좋다\n");
			continue;
		case 101:	//e
			printf("e : 담주부턴 과제량 3배다\n");
			continue;
		case 114:	//r
			printf("r : 행복합니다.\n");
			continue;
		default:
			printf("입력오류\n");
			continue;
		}
	}
	return(0);
}

