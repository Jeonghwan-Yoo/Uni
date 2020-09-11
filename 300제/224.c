//"    123    "에서 좌우 공백을 제거하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(void) {
	char* string = "    123    ";
	char buff[20] = { 0, };
	int i = 0;

	printf("string의 길이 : %d\n", strlen(string));

	while (*string) {
		if (!isspace(*string)) {
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
	printf("string의 길이 : %d\n", strlen(buff));
}