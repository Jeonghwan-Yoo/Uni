//문자열로 초기화되는 버퍼를 정의하고, 그 버퍼를 동적 할당으로 복제하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)

void main(void) {
	char buff[] = "문자열 복제하기";
	char* dup;

	dup = strdup(buff);
	if (dup) {
		strcpy(buff, "다른 문자열");
		puts(buff);
		puts(dup);
		free(dup);
	}
}
//복제만한거지 주소를 복사한건 아니다.