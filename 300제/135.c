//���α׷� ���� �� main() �Լ����� �μ��� �Ѿ�� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

int main(int argc, int *argv[]) {
	int i;

	printf("�μ��� ��:%d\n", argc);

	for (i = 0;i < argc;i++) {
		printf("argv[%d]:%s\n", i, argv[i]);
	}
}
//main�Լ��� ��ȯ���� ������ �� ������ ����࿡�� ���ڿ��� �����Ͽ� ���α׷��� ������ �� �ֽ��ϴ�.
//135.exe abc 123�ϸ� �μ��� main�Լ��� ���޵˴ϴ�. �������� �и��ؾ� �մϴ�.
//argc�� �� ���޵� �μ��� ���Դϴ�.
//MFC(Microsoft Foundation Class Library)�� Windows API �Լ����� C++Ŭ������ ����Ͽ�, ������ ���α׷����� �� �� �ְ�.