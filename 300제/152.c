//file.txt�� �����ϰ� "fclose() �Լ�"�� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file5.txt", "w+");

	fputs("fclose() �Լ�",fp);
	fclose(fp);
}
//int fclose(FILE* stream);
//�ݵ�� �ݾƾ� �ǰ�, ���� �������� ���α׷��� ������ ���� ���� ������ �� ���� ��� �������� fcloseall() ���.