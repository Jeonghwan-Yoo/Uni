//문자열을 입력받아, 입력받은 문자열이 저장된 버퍼를 하나 더 생성하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main(void) {
	char string[100];
	char* pstr;

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		pstr = _strdup(string);

		strcpy_s(string, sizeof(string),"temporary string");

		printf("문자열 string : %s\n", string);
		printf("문자열 pstr : %s\n", pstr);

		free(pstr);
	} while (1);
}
//char* strdup(const char* string);
//string은 복제될 문자열입니다.
//strdup()은 내부적으로 메모리를 할당하는 malloc()함수를 사용합니다.
//string과 같은 길이의 공간이 내부적으로 생성되고, 그 공간에 string을 복제합니다.
//pstr 포인터 변수는 실제로 메모리가 할당된 공간을 가리키며, 실패시 NULL이 됩니다.
//할당된 메모리는 반드시 free()에 의해 해제되어야 합니다.