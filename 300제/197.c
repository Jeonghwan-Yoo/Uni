//��ũ�� ����� COUNT�� ���� 100�� �ƴ϶��, ������ ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

#define COUNT 100

#if COUNT!=100
#error "COUNT!=100"
#endif

void main(void) {
	printf("COUNT : %d\n", COUNT);
}