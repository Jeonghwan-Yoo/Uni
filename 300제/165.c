//���� �۾����� ����̺긦 ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <direct.h>

void main(void) {
	int drive;

	drive = _getdrive();

	printf("���� ����̺� : %c\n", 'A' + drive - 1);
}
//int _getdrive(void);
//A=1, B=2,...