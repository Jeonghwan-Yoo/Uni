//영어 문장을 입력받아, 입력받은 문자열을 모두 대문자로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strupr_s(string,sizeof(string));
		puts(string);
	} while (1);
}
//char* strupr(char* string);
//string은 대문자로 변환될 문자 버퍼입니다. 단, 반드시 문자열 버퍼이거나 문자열 버퍼를 가리키는 포인터여야 한다.
//만약 문자열 상수 등을 string에 사용한다면 메모리 에러가 발생되면서 문제가 생긴다.