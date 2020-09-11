//두 개의 단어를 입력받아, 두 단어를 연결하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string1[100];
	char string2[100];

	printf("첫 번째 단어를 입력하세요!\n");
	gets(string1);

	printf("두 번째 단어를 입력하세요!\n");
	gets(string2);

	strcat_s(string1, sizeof(string1),string2);

	puts(string1);
}
//string1에 string2를 연결합니다.
//char* strcat(char* dest, const char* src);
//dest 버퍼는 src문자열을 추가할 만큼의 충분한 버퍼가 있어야 한다.
//strncat():문자열 결합ㅈ을 수행하지만, 원본 문자열에서 마지막 목적 문자열의 마지막에 추가되는 문자의 개수를 지정할 수 있다.
//char* strncat(char* dest,const char* src,unsigned int count);