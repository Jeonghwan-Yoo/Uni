//��ũ�� ��� COUNT�� ����Ǿ� ���� �ʴٸ�, ������ ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

#if !defined COUNT
#error "COUNT MACRO is not defiend!"
#endif

void main(void) {
	printf("COUNT : %d\n", COUNT);
}
//�������� ���� �ʰ� �����޼��� ���
//#error���� ���Ǻ� �������� �� �� �ַ� ���.