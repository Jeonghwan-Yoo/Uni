//영어 단어를 입력받아, 그 입력된 단어를 거꾸로 뒤집는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strrev(string);
		puts(string);
	} while (1);
}
//char* strrev(char* string):
//string은 거꾸로 뒤집혀질 문자열 버퍼입니다.