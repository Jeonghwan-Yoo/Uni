//���ڿ��� �Է¹޾�, �Է¹��� ���� �� ù ��° ���ڷ� �Է¹��� ���ڿ��� ä��� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strset_s(string, sizeof(string),string[0]);
		puts(string);
	} while (1);
}
//char* strset(char* string,int c);
//string�� ä�� �����̸�, c�� ä�� �����Դϴ�.