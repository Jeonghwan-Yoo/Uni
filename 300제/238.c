//237���� ����� ������ ���� ���� �����Ͽ� �� ����Ʈ�� �а� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char buff;

	fopen_s(&fp, "file8.bin", "rb");

	if (fp != NULL) {
		while (!feof(fp)) {
			fread(&buff, 1, 1, fp);
			if (!feof(fp)) printf("%d(%#x) ", buff, buff);
		}
		fclose(fp);
	}
}