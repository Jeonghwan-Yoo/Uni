//���ڿ��� �Է¹޾�, �Է¹��� ���� �� �ټ� ��° ���ڱ����� ��ǥ(*)�� ä��� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strnset_s(string, sizeof(string),'*', 5);
		puts(string);
	} while (1);
}
//char* strnset(char* string, int c, unsigned int count);
//string�� ä�� �����̸�, c�� ä�� �����̰�, count�� ä�� ������ ���Դϴ�.
//strset()�� string���� �� ���ڸ� ������ ��� ���ڸ� c�� �����մϴ�.
//strnset()�� string�� ó������ count�� ����ŭ c�� �����մϴ�.
//memset�� �̿��� ���� �ִ�.