//���ڿ��� �Է¹޾� ���̸� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	printf("������ �Է��� ��, EnterŰ�� ġ����!\n");
	printf("�ƹ��͵� �Է����� ������ ���α׷��� ����˴ϴ�.\n");

	do {
		gets(string);

		if (strlen(string) == 0) {
			break;
		}

		printf("���ڿ��� ���̴� %d�Դϴ�.\n", strlen(string));
	} while (1);
}
//unsigned int strlen(const char* string);