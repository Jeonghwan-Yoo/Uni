//c:\file.txt 파일에 "대한민국"을 다섯 줄 저장하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file6.txt", "w+");
	
	if (fp != NULL) {
		fputs("대한민국\n", fp);
		fputs("대한민국\n", fp);
		fputs("대한민국\n", fp);
		fputs("대한민국\n", fp);
		fputs("대한민국\n", fp);
		fclose(fp);
	}
}
//fputs함수에서 \n는 자동으로 0x0D, 0x0A로 변환되어 저장됩니다.