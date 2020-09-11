//문자열을 입력받고, 입력받은 문자열 중에 "h"가 있는지 검색하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

#define FINE_CHAR 'h'

void main(void) {
	char string[100];
	char* ret;

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("문자열 중에 'h'가 포함되어 있으면, 프로그램은 종료됩니다.");
	
	do {
		gets(string);

		ret = strchr(string, FINE_CHAR);
		if (ret == NULL) {
			puts("문자열 중에 'h'가 없습니다.");
		}
		else {
			printf("%d 위치에서 'h'문자를 찾았습니다.", ret - string);
			break;
		}
	} while (1);
}
//입력된 문자열 중에 'h'가 있는지 검색합니다. 'h' 문자를 찾았으면, 그 찾은 위치에 대한 메모리 번지 갑ㅈㅅ을 반환하며,
//찾지 못했으면 NULL 포인터를 반환합니다.
//문자열의 뒤에서부터 검색하려면, strrchr()을 사용하세요.
//char* strrchr(const char* string,int c);