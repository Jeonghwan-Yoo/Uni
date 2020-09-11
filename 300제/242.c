//제공된 파일을 개방하여 "대한민국"이 있는 행이 몇 번째 행인지 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	FILE* fp;
	char buff[200];
	int line = 1;

	fopen_s(&fp, "file10.txt", "r");

	if (fp == NULL) {
		perror("파일 읽기 개방 에러");
		return;
	}
	while (!feof(fp)) {
		fgets(buff, 200, fp);

		if (strstr(buff, "대한민국")) {
			printf("Line(%2d):%s", line, buff);
		}
		line++;
	}
	_fcloseall();
}
//fgets()함수는 텍스트를 한 줄 읽을 때 사용.