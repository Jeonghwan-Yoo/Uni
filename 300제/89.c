//숫자와 문자가 혼합된 "Cat 1 Car 2 Cow 3"과 같은 문자열에서 알파벳 문자만 추출하는 프로그램을 작성하세요.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "Cat 1 Car 2 Cow 3,...";
	char buffer[100] = { 0, }; //모든 버퍼의 값을 널로 초기화
	int cnt = 0;

	while (*string) {
		if (isalpha(*string)) {
			buffer[cnt++] = *string;
		}
		string++;
	}
	puts(buffer);
}
//int isalpha(int c);
//c는 비교할 문자값입니다.
//string은 문자열 상수를 가리키도록 초기화되지때문에, string이 카리키는 번지에 다른 값을 대입할 수 없습니다.
//대문자와 소문자 범위에 있는 경우 1을 반환하고 아니면 0을 반환.