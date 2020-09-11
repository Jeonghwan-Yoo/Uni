//한 개의 문자를 입력받아 아스키 코드 값을 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <conio.h>

#define ENTER 13

void main(void) {
	int ch;

	printf("아스키 코드로 변환할 키를 누르세요...\n");
	printf("Enter키를 누르면 프로그램은 종료됩니다.\n");

	do {
		ch = _getch();
		//if (ch == 0) continue;
		printf("문자 : (%c), 아스키 코드 = (%d)\n", ch, ch);
	} while (ch != ENTER);
}