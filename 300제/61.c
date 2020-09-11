//영단어를 입력받고, 입력된 단어가 sky로 시작하는지 검사하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

#define SKY "sky"

void main(void) {
	char string[100];
	int ret;

	printf("영단어를 입력한 후 Enter키를 치세요!\n");
	printf("sky로 시작되는 단어를 입력하면 프로그램이 종료됩니다.\n");

	do {
		gets(string);

		ret = strncmp(string, SKY, 3);

		if (ret == 0) {
			printf("%3.3s==%s, ret=%d\n", string, SKY, ret); //문자에서 소수점은 개수를 의미.
			break;
		}
		else if (ret < 0) printf("%3.3s<%s, ret=%d\n", string, SKY, ret);
		else printf("%3.3s>%s, ret=%d\n", string, SKY, ret);
	} while (1);
}
//int strncmp(const char* src1, const char* src2, unsigned int count);
//대소문자 구분안하고 부분적으로 비교하려면 int _strnicmp(const char* string1, const char* string2, unsigned int count);