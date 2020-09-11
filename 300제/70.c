//문자열을 입력받아, 입력받은 문자 중 첫 번째 문자로 입력받은 문자열을 채우는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strset_s(string, sizeof(string),string[0]);
		puts(string);
	} while (1);
}
//char* strset(char* string,int c);
//string은 채울 버퍼이며, c는 채울 문자입니다.