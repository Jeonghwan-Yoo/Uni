//c:\file.txt ���Ͽ� "���ѹα�"�� �ټ� �� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file6.txt", "w+");
	
	if (fp != NULL) {
		fputs("���ѹα�\n", fp);
		fputs("���ѹα�\n", fp);
		fputs("���ѹα�\n", fp);
		fputs("���ѹα�\n", fp);
		fputs("���ѹα�\n", fp);
		fclose(fp);
	}
}
//fputs�Լ����� \n�� �ڵ����� 0x0D, 0x0A�� ��ȯ�Ǿ� ����˴ϴ�.