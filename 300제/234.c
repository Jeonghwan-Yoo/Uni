//233���� ������ "���ѹα�"�� ��� �о ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char buff[100];

	fopen_s(&fp, "file6.txt", "r");

	if (fp != NULL) {
		while (!feof(fp)) {
			fgets(buff, 100, fp);
			printf(buff);
		}
		fclose(fp);
	}
}
//feof�� �̿��� ������ ������ �н��ϴ�.
//������ ���� ��� fgets�� �ƹ��͵� �о���� �ʽ��ϴ�.