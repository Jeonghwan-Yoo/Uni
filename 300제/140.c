//139���� ������ "���ѹα�"�� �д� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char buffer[100];

	fopen_s(&fp, "file1.txt", "r");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		fgets(buffer, 100, fp);
		puts(buffer);
		fclose(fp);
	}
}
//int fgets(char* buffer, int n, FILE* stream);
//buffer�� ���ڿ��� ������ ����, n�� ���� ���ڿ��� ����
//�д��� ���๮�ڸ� ������ 99����Ʈ�� ���� �ʰ�, �� ���������� ���ۿ� �н��ϴ�.
//������ ���� ���ڿ�ó�� NULL�� �ڵ����� �߰��˴ϴ�.