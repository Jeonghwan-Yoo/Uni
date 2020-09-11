//문자열 버퍼 변수 buff의 모든 값을 NULL로 채우는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void main(void) {
	char buff[] = "암호는 Korea입니다.";
	
	puts(buff);
	strset(buff, 0);
	printf("[%s]\n", buff);
}