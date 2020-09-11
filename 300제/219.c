//"temperature:200"에서 알파벳만 추출하는 프로그램을 작성하세요.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "temperature:200";
	char buff[20] = { 0, };
	int i = 0;

	while (*string) {
		if (isalpha(*string)) {
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
}