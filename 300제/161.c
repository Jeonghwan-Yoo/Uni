//"c:"���͸��� ccc��� ���͸��� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <direct.h>

void main(void) {
	char* pathname = "c:\\ccc";

	if (_mkdir(pathname) == -1) {
		perror("���͸� ���� ����");
	}
	else {
		puts("���͸��� ���������� �����Ͽ����ϴ�.");
	}
}
//int _mkdir(const char* dirname);
//dirname�� ������ ���͸��� ��� �� �̸��Դϴ�.
//������ �Լ��� -1�� ��ȯ�մϴ�.
//���͸� ������ _rmdir()�Լ��� �̿�.