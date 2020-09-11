//문자열을 입력받아 길이를 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	printf("문장을 입력한 후, Enter키는 치세요!\n");
	printf("아무것도 입력하지 않으면 프로그램은 종료됩니다.\n");

	do {
		gets(string);

		if (strlen(string) == 0) {
			break;
		}

		printf("문자열의 길이는 %d입니다.\n", strlen(string));
	} while (1);
}
//unsigned int strlen(const char* string);