//���� �����͸� ������ �� �ٽ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	fpos_t pos;

	fopen_s(&fp, "file4.txt", "w+");

	fgetpos(fp, &pos); //0
	fputs("abcde", fp); //5
	fsetpos(fp, &pos); //0
	printf("���� �������� ��ġ : %d\n", ftell(fp)); //0
	fclose(fp);
}
//int fsetpos(FILE* stream, const fpos_t* pos);
//pos�� fgetpos()�Լ����� ���� ���� ����մϴ�.
//���� �����͸� ������ ������ �缳���Ѵ�.