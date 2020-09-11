//영어 문장을 입력받아 공백으로 구분하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdio.h>

#define TOKEN " "

void main(void) {
	char string[100];
	char* token;

	puts("문자열을 입력한 후 Enter키를 치세요!");

	gets(string);

	token = strtok(string, TOKEN);

	while (token != NULL) {
		puts(token);

		token = strtok(NULL, TOKEN);
	}
}
//char* strtok(char* strToken, const char* strDelimit);
//strToken은 원본 문자열 이며 strDelimit은 구분문자 또는 문자세트입니다.
//공백을 찾은 경우, 공백이 있는 자리에 NULL을 넣은 후 문자열의 선두 번지를 반환하고,
//없는 경우, 문자 배열 변수 string의 선두 번지를 반환합니다.
//strtok()함수는 내부적으로 이전에 검색한 위치를 저장하고 있습니다. 그러므로 string이 아닌 NULL을 넘겨주면,
//검색된 다음 위치부터 자동으로 검색합니다.