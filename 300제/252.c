//�ð��� 5�ʰ� �����ϴ� sleep()�Լ��� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>

void sleep(int sec);

void main(void) {
	time_t n1, n2;

	time(&n1);
	sleep(5);
	time(&n2);

	printf("%g�ʰ� �����Ǿ����ϴ�.\n", difftime(n2, n1));
}

void sleep(int sec) {
	clock_t ct;
	ct = clock();
	while (ct + CLK_TCK * sec > clock());
}
//CLK_TCK�� CLOCKS_PER_SEC���� �����ϸ�, 1000�Դϴ�. clock()�Լ��� ���� �������� �Լ����� �Һ��� �ð���
//1/1000�� ������ ��ȯ�ϱ� ������.