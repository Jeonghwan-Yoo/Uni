//���� 34567�� 16�� ���ڿ� "8707"�� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int value;
	char string[100];
	int radix;

	radix = 16; //16����

	value = 34567;
	_ultoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", string);

	value = 1234567890;
	_ultoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", string);
}
//char* ultoa(unsigned long value, char* string, int radix);
//fcvt()�� ����ϸ� �Ǽ��� ���ڿ��� ��ȯ�� �� �ֽ��ϴ�.