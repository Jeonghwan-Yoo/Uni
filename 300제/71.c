//문자열을 입력받아, 입력받은 문자 중 다섯 번째 문자까지만 별표(*)를 채우는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strnset_s(string, sizeof(string),'*', 5);
		puts(string);
	} while (1);
}
//char* strnset(char* string, int c, unsigned int count);
//string은 채울 버퍼이며, c는 채울 문자이고, count는 채울 문자의 수입니다.
//strset()은 string에서 널 문자를 제외한 모든 문자를 c로 변경합니다.
//strnset()은 string의 처음부터 count의 수만큼 c로 변경합니다.
//memset을 이용할 수도 있다.