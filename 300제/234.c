//233에서 저장한 "대한민국"을 모두 읽어서 출력하는 프로그램을 작성하세요.
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
//feof를 이용해 파일의 끝까지 읽습니다.
//파일의 끝인 경우 fgets는 아무것도 읽어오지 않습니다.