//������ ������ �����Ͽ� "���ѹα�"�� �ִ� ���� �� ��° ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	FILE* fp;
	char buff[200];
	int line = 1;

	fopen_s(&fp, "file10.txt", "r");

	if (fp == NULL) {
		perror("���� �б� ���� ����");
		return;
	}
	while (!feof(fp)) {
		fgets(buff, 200, fp);

		if (strstr(buff, "���ѹα�")) {
			printf("Line(%2d):%s", line, buff);
		}
		line++;
	}
	_fcloseall();
}
//fgets()�Լ��� �ؽ�Ʈ�� �� �� ���� �� ���.