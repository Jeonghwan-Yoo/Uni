//���ڿ��� �Է¹޾�, �Է¹��� ���ڿ��� ����� ���۸� �ϳ� �� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main(void) {
	char string[100];
	char* pstr;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		pstr = _strdup(string);

		strcpy_s(string, sizeof(string),"temporary string");

		printf("���ڿ� string : %s\n", string);
		printf("���ڿ� pstr : %s\n", pstr);

		free(pstr);
	} while (1);
}
//char* strdup(const char* string);
//string�� ������ ���ڿ��Դϴ�.
//strdup()�� ���������� �޸𸮸� �Ҵ��ϴ� malloc()�Լ��� ����մϴ�.
//string�� ���� ������ ������ ���������� �����ǰ�, �� ������ string�� �����մϴ�.
//pstr ������ ������ ������ �޸𸮰� �Ҵ�� ������ ����Ű��, ���н� NULL�� �˴ϴ�.
//�Ҵ�� �޸𸮴� �ݵ�� free()�� ���� �����Ǿ�� �մϴ�.