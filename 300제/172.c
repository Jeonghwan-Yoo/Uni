//time() �Լ��� ���� ��¥ �� �ð��� ���ڿ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;

	time(&now);

	printf("���� ��¥ �� �ð� : %s", ctime(&now));
}
//char* ctime(const time_t* timer);
//���� ��¥ �� �ð��� ���� now���� ���ڿ��� ����մϴ�.
//��, ctime() �Լ��� ���ڿ��� ���� ���๮��('\n')�� �ڵ����� �߰��ϹǷ� �����ϼ���.