//������ ���� i�� �����ϰ�, i�� ���ǵǾ� �ִ� ���� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	int i = 127;
	int j;

	printf("%d, %x\n", i, i);

	printf("%#x\n", &i);
	printf("%#x\n", &j);
}