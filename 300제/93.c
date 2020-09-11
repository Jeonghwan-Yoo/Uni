//문자열 "This is Korea!"에서 소문자만 추출하는 프로그램을 작성하세요.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "This is Korea!";
	char buffer[100] = { 0 };
	int cnt = 0;

	while (*string) {
		if (islower(*string)) {
			buffer[cnt++] = *string;
		}
		string++;
	}
	puts(buffer);
}
//int islower(int c);
//c는 비교할 문자값입니다.
//대소문자를 구분시 isupper(65); 또는 islower(97)처럼 숫자값으로 비교할 수도 있습니다.
//if(*string>='a'&&*string<='z') ...