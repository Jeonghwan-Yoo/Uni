//영단어를 입력받고, 입력된 단어 중 sky를 검색하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

#define SKY "sky"

void main(void) {
	char string[100];
	int ret;

	printf("영단어를 입력한 후 Enter키를 치세요!\n");
	printf("sky를 입력하면 프로그램이 종료됩니다.\n");

	do {
		gets(string);

		ret = strcmp(string, SKY);

		if (ret == 0) {
			printf("%s==%s, ret=%d\n", string, SKY, ret);
			break;
		}
		else if (ret < 0) printf("%s<%s, ret=%d\n", string, SKY, ret);
		else printf("%s>%s, ret=%d\n", string, SKY, ret);
	} while (1);
}
//int strcmp(const char* src1, const char* src2);
//일치하면 0, string이 크면 1 작으면 -1.
//대소문자를 구분하여 비교한다. 구분안하려면 int _stricmp(const char* string1, const char* string2);