//���� ǥ�ؽÿ� ���� ǥ�ؽ��� �ð����� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now, n1, n2;
	struct tm t1, t2;

	time(&now);
	t1 = *localtime(&now);
	t2 = *gmtime(&now);

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	printf("���� ǥ�ؽÿ� ���ѹα��� �ð����� : %g�ð�\n", difftime(n1, n2) / 3600.);
}
//struct tm *localtime(time_t *ptr);
//tm����ü�� ����̳� �ż⿡ ���� ������ �������� �ڷḦ ����.
//tm���� ���� �����͸� �����ؾ��ϰ�, localtime()�� ȣ��� ������ �ٽ� ���ǰ� ������ ��ü�˴ϴ�.
//���� ���͵Ǵ� ���� �����ϱ� ���Ѵٸ� ���α׷������� ������ tm�� ����ü�� �����ϰ� ���� ����ü�� ���� �����ؾ� �մϴ�.
//time_t mktime(struct tm *ntime);
//tm����ü���� time_t������ ���� ��ȯ�ϴ� �Լ���.
//localtime()�� TZ��� ȯ�溯���� �����ϸ�, TZ�� _timezone, _daylight �׸��� _tzname�� ȯ�� ������ �����ϴ�.
//�� �������� �����ϱ� ���ؼ��� _tzset() �Լ��� ����մϴ�.