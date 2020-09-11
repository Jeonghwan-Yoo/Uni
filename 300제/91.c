//문자와 숫자가 혼합된 "Cat 1 Car 2 Cow 3"과 같은 문자열에서 문자와 숫자만 추출하는 프로그램을 작성하세요.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "Cat 1 Car 2 Cow 3,...";
	char buffer[100] = { 0 };
	int cnt = 0;

	while (*string) {
		if (isalnum(*string)) {
			buffer[cnt++] = *string;
		}
		string++;
	}
	puts(buffer);
}
//int isalnum(int c);
//c는 비교할 문자값입니다.
//문자가 숫자 및 기타 문자들이 포함되어 있는 문자열에서 문자와 숫자를 뽑아내는 경우에 isalnum()을 사용.