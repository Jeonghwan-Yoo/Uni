//158���� ����� file_1.txt������ �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	char* filename = "file_1.txt";

	if (remove(filename)) {
		perror("���� ���� ����");
	}
	else {
		puts("������ ���������� �����Ͽ����ϴ�!");
	}
}
//int remove(const char* path);
//path�� ������ ������ ��� �� �̸�
//������ ���ų� ������� ��� �Ǵ� �б� ���� ������ ������ �� �����ϴ�.