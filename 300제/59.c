//���ܾ �Է¹ް�, �Էµ� �ܾ� �� sky�� �˻��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

#define SKY "sky"

void main(void) {
	char string[100];
	int ret;

	printf("���ܾ �Է��� �� EnterŰ�� ġ����!\n");
	printf("sky�� �Է��ϸ� ���α׷��� ����˴ϴ�.\n");

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
//��ġ�ϸ� 0, string�� ũ�� 1 ������ -1.
//��ҹ��ڸ� �����Ͽ� ���Ѵ�. ���о��Ϸ��� int _stricmp(const char* string1, const char* string2);