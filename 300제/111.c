//1���� ���ڿ� �迭 one�� �����ϰ� "Korea"�� �ʱ�ȭ�ϼ���. �׸���, one�� ����ؼ� �����
//�� �ִ� ������(�н�)�� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char one[] = "Korea";
	char* pone;

	pone = one;

	puts(one); //"Korea"
	puts(pone); //"Korea"

	strcpy_s(pone, sizeof("Japan"), "Japan");
	puts(one); //"Japan"
	puts(pone); //"Japan"
}
//one�� ������ �迭�� ��ǥ�ϴ� ��ǥ���(�н�)�̱� ������ �������������ڴ� ������� �ʽ��ϴ�.