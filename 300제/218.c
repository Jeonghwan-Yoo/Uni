//"(02) 1111-2222"에서 숫자만 추출하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char* string = "(02) 1111-2222";
	char buff[20] = { 0, };
	int i = 0;

	while (*string) {
		if (isdigit(*string)) {
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
}