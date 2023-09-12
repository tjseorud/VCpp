// 0912.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <stdio.h>
#include <conio.h>

int main()
{
	char tmp = NULL;
	char command = NULL;

    printf("사용자의 행복한 VC++\n");
	while (1) {
		printf("command>");
		//scanf_s("%s", &tmp, sizeof(tmp));
		tmp = _getch();
		if (tmp == 27) {
			return(0);
		}
		if (tmp == 13) {
			break;
		}
		if (tmp == 113) {
			printf("q : CS 화이팅\n");
			break;
		}else if(tmp == 119) {
			printf("W : 과제 너무 싫다\n");	
			break;
		}else if (tmp == 101) {
			printf("e :e-class\n");
			break;
		}else if (tmp == 114) {
			printf("r : qwer\n");
			break;
		}else if (tmp == command) {
			printf("command를 입력하세요.");
			exit;
		}else {
			printf("입력오류 재입력\n");
			exit;
		}
	}
}

