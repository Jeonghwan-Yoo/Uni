//C����̺꿡 ��ġ�� file.txt������ file_1.txt�� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	char* oldname = "file.txt";
	char* newname = "file_1.txt";

	if (rename(oldname, newname) != 0) {
		perror("���ϸ� ���� ����");
	}
	else {
		puts("���ϸ��� ���������� �����Ͽ����ϴ�!");
	}
}
//int rename(const char* oldname, const char* newname);
//oldname�� ���� ���ϸ�, newname�� ���� ������ ���ϸ�.
//�����Ϸ��� ������ �������� �ʰų� ������� ���, ������ �̸��� ������ �� �����ϴ�.