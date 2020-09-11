//문자열 "This is Korea!\t\n"에서 공백, 탭문자, 개행문자의 수를 세어서 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "This is Korea!\t\n";
	int cnt = 0;

	while (*string) {
		if (isspace(*string)) {
			cnt++;
		}
		string++;
	}
	printf("공백, 탭 그리고 개행문자의 수는 %d입니다", cnt);
}
//int isspace(int c);
//c는 비교할 문자값입니다.
//isacii():아스키 문자인지
//iscntrl():제어문자인지
//isgraph():공백을 제외하고 인쇄 가능한 문자인지
//isprint():공백을 포함하고 인쇄 가능한 문자인지
//ispunct():구두점인지
//isxdigit():16진수 문자인지
//isspace()는 필요없는 문자를 제거하려 할 때 유용합니다.
//if(*string==' '||*string=='\t'||*string=='\n'||*string=='r') ...