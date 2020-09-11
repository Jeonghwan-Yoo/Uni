//영어 문장을 입력받아, 입력받은 문자열을 모두 소문자로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strlwr_s(string, sizeof(string));
		puts(string);
	} while (1);
}
//char* strlwr(char* string);
//string은 소문자로 변환될 문자 버퍼입니다.