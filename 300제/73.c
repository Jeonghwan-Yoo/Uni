//���� ������ �Է¹޾�, �Է¹��� ���ڿ��� ��� �ҹ��ڷ� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strlwr_s(string, sizeof(string));
		puts(string);
	} while (1);
}
//char* strlwr(char* string);
//string�� �ҹ��ڷ� ��ȯ�� ���� �����Դϴ�.