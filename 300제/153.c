//������ �дٰ� ������ ������, �ƴ��� �˻��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int ch;

	fopen_s(&fp, "file4.txt", "r");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		while (!feof(fp)) {
			ch = fgetc(fp);
			printf("���� ���� : %c\n", ch);
		}
		fclose(fp);
	}
}
//int feof(FILE* stream);
//*stream�� ������ �� �� fopen()�� �����ִ� FILE�������Դϴ�.
//feof()�� ���� stream�� �������� �������� �ʾҴٸ� 0�� �����ְ� �����ϸ� 0�� �ƴ� ���� �����ݴϴ�.
//������ ���� �����ߴٴ� ���� Ȯ���ϸ�, �� �̻� ���� �����Ͱ� �����Ƿ� �б⸦ ���߾�� �մϴ�.
//���� �����ʹ� fgetc, fputc, fgets, fputs, fprintf, fscanf�Լ��� ����� ������ �ڵ����� �����մϴ�.
//���������� ���� ���ڰ� ���µ�, �̰��� fgetc()�Լ��� ���� ���� ������ ������ �ƹ� ���ڵ� �������� �ʾұ� �����Դϴ�.
/*
while(!feof(fp)){
	ch=fgetc(fp);
	if(feof(fp)) break;
	printf("���� ���� : %c\n", ch);
}
*/