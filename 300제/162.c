//161���� ������ ccc��� ���͸��� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <direct.h>

void main(void) {
	char* pathname = "c:\\ccc";

	if (_rmdir(pathname) == -1) {
		perror("���͸� ���� ����");
	}
	else {
		puts("���͸��� ���������� �����Ͽ����ϴ�!");
	}
}
//int _rmdir(const char* dirname);
//dirname�� ������ ���͸��� ��� �� �̸�.
//������ -1��ȯ