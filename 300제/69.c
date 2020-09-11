//영어 문장을 입력 받아 공백을 기준으로 잘라내는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

#define TOKEN " "

void main(void) {
	char string[100];
	char* pos;

	puts("문자열을 입력한 후 Enter키를 치세요!");

	gets(string);

	pos = strpbrk(string, TOKEN);

	while (pos != NULL) {
		puts(pos++);

		pos = strpbrk(pos, TOKEN);
	}
}
//char* strpbrk(const char* string, const char* strCharSet);
//string은 검색될 문자열, strCharSet은 구분 문자 또는 문자세트.
//공백을 찾은 경우, 공백이 있는 자리에 대한 번지를 반환합니다.
//없는 경우, 문자 배열 변수 string의 선두 번지를 반환합니다.