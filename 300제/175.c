//���� ��¥�� "Fri Sep 16 13:32:22 2005"�� ���·� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;

	now = time(NULL);
	t = *localtime(&now);

	printf("���� ��¥ �� �ð� : %s\n", asctime(&t));
}
//char* asctime(const struct tm* timeptr);
//��¥�� �ð��� �ƽ�Ű ���ڿ��� ����մϴ�.