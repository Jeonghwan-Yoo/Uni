//233���� ������ file.txt�� c:\temp ���͸��� �̵��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	char* filename = "file6.txt";
	char* movefile = "c:\\temp\\file6.txt";

	if (rename(filename, movefile) != 0) {
		perror("���� �̵� ����");
	}
	else {
		puts("������ �̵��Ǿ����ϴ�.");
	}
}
//�̵���λӸ� �ƴ϶� �����ε� �ٲ� �� �ִ�.