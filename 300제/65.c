//���ڿ��� �Է¹ް�, �Է¹��� ���ڿ� �߿� "h"�� �ִ��� �˻��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

#define FINE_CHAR 'h'

void main(void) {
	char string[100];
	char* ret;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("���ڿ� �߿� 'h'�� ���ԵǾ� ������, ���α׷��� ����˴ϴ�.");
	
	do {
		gets(string);

		ret = strchr(string, FINE_CHAR);
		if (ret == NULL) {
			puts("���ڿ� �߿� 'h'�� �����ϴ�.");
		}
		else {
			printf("%d ��ġ���� 'h'���ڸ� ã�ҽ��ϴ�.", ret - string);
			break;
		}
	} while (1);
}
//�Էµ� ���ڿ� �߿� 'h'�� �ִ��� �˻��մϴ�. 'h' ���ڸ� ã������, �� ã�� ��ġ�� ���� �޸� ���� �������� ��ȯ�ϸ�,
//ã�� �������� NULL �����͸� ��ȯ�մϴ�.
//���ڿ��� �ڿ������� �˻��Ϸ���, strrchr()�� ����ϼ���.
//char* strrchr(const char* string,int c);