//������ ���� i�� -5�� �ʱ�ȭ�� ��, ��Ʈ ������ ����Ͽ� i�� ���� 0���� ����� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	int i = -5;

	printf("i = %d\n", i);

	i = i ^ i;

	printf("i = %d\n", i);
}