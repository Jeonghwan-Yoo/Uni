//문자와 숫자가 혼합된 "Cat 1 Car 2 Cow 3"과 같은 문자열에서 숫자만 추출하는 프로그램을 작성하세요.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "Cat 1 Car 2 Cow 3,...";
	char buffer[100] = { 0 };
	int cnt = 0;

	while (*string) {
		if (isdigit(*string)) {
			buffer[cnt] = *string;
			cnt++;
		}
		string++;
	}
	puts(buffer);
}
//int isdigit(int c);
//c는 비교할 문자값입니다.