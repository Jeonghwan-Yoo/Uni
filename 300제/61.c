//���ܾ �Է¹ް�, �Էµ� �ܾ sky�� �����ϴ��� �˻��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

#define SKY "sky"

void main(void) {
	char string[100];
	int ret;

	printf("���ܾ �Է��� �� EnterŰ�� ġ����!\n");
	printf("sky�� ���۵Ǵ� �ܾ �Է��ϸ� ���α׷��� ����˴ϴ�.\n");

	do {
		gets(string);

		ret = strncmp(string, SKY, 3);

		if (ret == 0) {
			printf("%3.3s==%s, ret=%d\n", string, SKY, ret); //���ڿ��� �Ҽ����� ������ �ǹ�.
			break;
		}
		else if (ret < 0) printf("%3.3s<%s, ret=%d\n", string, SKY, ret);
		else printf("%3.3s>%s, ret=%d\n", string, SKY, ret);
	} while (1);
}
//int strncmp(const char* src1, const char* src2, unsigned int count);
//��ҹ��� ���о��ϰ� �κ������� ���Ϸ��� int _strnicmp(const char* string1, const char* string2, unsigned int count);