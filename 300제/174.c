//for ���� �ߺ��Ͽ� 0~10000000���� ��ȯ��ų �� ����ð��� ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t s1, s2;
	double gop=0.0;
	int i;

	time(&s1);

	for (i = 0;i < 10000000;i++) {
		gop = gop * 100;
	}

	time(&s2);

	printf("����ð� : %g��\n", difftime(s2, s1));
}
//double difftime(time_t timer1, time_t timer0);
//timer1�� ����ð��̸�, timer0�� ���� �ð��Դϴ�.
//assert() ���α׷��� ���׸� �м��ϴµ� ���˴ϴ�. <assert.h> void assert(int expression);
//�μ� expression�� Ȯ���ϱ� ���ϴ� � ������ c�� ������ �� �� �ֽ��ϴ�.
//expression�� TRUE�� �򰡵Ǹ� assert�� �ƹ� �͵� �������� ������, expression�� FALSE�� �򰡵Ǹ�,
//assert()�� stderr�� ���� �޽����� ����ϰ� ���α׷��� ������ ��ġ�� �˴ϴ�.
//���״� ���α׷��� �����ϵ��� �ʰ� �ϰų� �Ǵ� ���α׷��� �����ϵǰ� �ϸ鼭�� ����Ȯ�� ����� ��Ÿ���ų�
//�������ϰ� ����ǰ� �ϴ� ���� ���մϴ�.
//difftime()��� �� �ٲٸ� ������ ���� ���ɴϴ�.