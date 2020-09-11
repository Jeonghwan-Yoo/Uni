//"it's good"에서 알파벳이 아닌 첫 문자의 위치를 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char* string = "it's good";
//                  0123456789
	char* find = "abcdefghijklmnopqrstuvwxyz";
	int nIndex;

	nIndex = strspn(string, find);
	printf("%d 위치에서 알파벳이 아닌 첫 문자를 찾았습니다.\n", nIndex);
}