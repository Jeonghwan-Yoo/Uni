//137���� ������ ���ڸ� �о ȭ�鿡 ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int ch;

	fopen_s(&fp, "file.txt", "r");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		ch = fgetc(fp);
		printf("���� ���� : %c\n", ch);
		fclose(fp);
	}
}
//int fgetc(FILE* stream);
//steam�� ����� ������ �������Դϴ�.
//���� ���ڸ� ���� ���ߴٸ�, ch�� ���� EOF(-1)�� ��ȯ�˴ϴ�.
//������ �ٸ� ���α׷��� ���� ����� �ִ� ��� ���������� ����� �� �����ϴ�.
//�׷� ��쿡�� _access()�Լ��� ����Ͽ� ������ ����� �� �ִ��� ���θ� Ȯ���ؾ� �մϴ�.
/*
#include <stdio.h>
#include <io.h>

void main(void){
	char* path="file.txt";
	if(_access(path,6)!=0){
		printf("������ �аų� �� �� �����ϴ�.");
	}
}
*/