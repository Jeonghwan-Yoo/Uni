//2���� ���ڿ��� 16���� ���ڿ��� ��ȯ�ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int radix = 16; //��ȯ�� ����� 16����
	int base = 2; //��ȯ�� ���ڿ��� 2����
	char string[] = "10101011";
	char* stop;
	long value;
	char buff[100];

	value = strtol(string, &stop, base); //10������ ��ȯ
	itoa(value, buff, radix);
	puts(buff); //"ab"
}