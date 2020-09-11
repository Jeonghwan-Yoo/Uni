//"a.book"에서 "a."을 잘라내는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[] = "a.book";
	char* pstr = string, *pfind = string;
	int i = 0;

	while (pfind) {
		pfind = strchr(pstr, 'a');

		if (pfind == NULL) {
			pfind = strchr(pstr, '.');
			if (pfind) pstr = &string[++i];
		}
		else {
			pstr = &string[++i];
		}
	}
	puts(pstr); //book이 출력.
}
//pstr은 a와 .을 지난 b를 가리킨다. 첫번째 인덱스가 b가 된다.