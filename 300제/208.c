//������ 10�� 16���� ���ڿ��� ��ȯ�ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void main(void) {
	char buff[100];
	int radix = 16;

	itoa(10, buff, radix);
	puts(buff); //"a"

	itoa(255, buff, radix);
	puts(buff); //"ff"
}