//������ �׸���ġ�� �������� �ϴ� ���� ǥ�ؽø� ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;

	time(&now);

	t = *gmtime(&now);

	printf("���� ǥ�� �� : %4d.%d.%d %d:%d:%d\n", t.tm_year + 1900, t.tm_mon+1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
}
//struct tm* gmtime(const time_t* timer);