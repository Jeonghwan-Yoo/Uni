//�ִ밪�� �ּҰ��� ���ϴ� ��ũ�θ� �ۼ��ϼ���.
#include <stdio.h>

#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y

void main(void) {
	printf("�ִ� �� : %d\n", max(5, 3));
	printf("�ּ� �� : %d\n", min(5, 3));
	printf("�ִ� �� : %g\n", max(3.5, 4.4));
	printf("�ּ� �� : %g\n", min(3.5, 4.4));
}
