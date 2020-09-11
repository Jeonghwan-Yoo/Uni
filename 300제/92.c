//문자열 "This is Korea!"에서 대문자만 추출하는 프로그램을 작성하세요.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string="This is Korea!";
	char buffer[100] = { 0 };
	int cnt = 0;

	while (*string) {
		if (isupper(*string)) {
			buffer[cnt++] = *string;
		}
		string++;
	}
	puts(buffer);
}
//int isupper(int c);
//c는 비교할 문자값입니다.
//한글 및 숫자는 대소문자를 구분할 수 없습니다. isupper()를 사용하지 않고 대문자인지 검사하려면
//if(*string>='A'&&*string<='Z') ...