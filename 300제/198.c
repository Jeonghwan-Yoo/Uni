//��ũ�� ��� COUNT�� �����ϰ�, ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

#define COUNT 100

#if defined COUNT //defined �������� 
#undef COUNT //COUNT�� �ٽ� undefined �ϰ�
#define COUNT 99 //99�� �ٽ� define
#else //�ƴϸ�, 
#define COUNT 88
#endif

void main(void) {
	printf("COUNT : %d\n", COUNT);
}
