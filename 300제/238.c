//237에서 사용한 파일을 이진 모드로 개방하여 한 바이트씩 읽고 출력하는 프로그램을 작성하세요.
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