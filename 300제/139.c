//"대한민국"을 파일에 저장하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file1.txt", "w+");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fputs("대한민국\n",fp);
		fclose(fp);
	}
}
//int fputs(const char* string, FILE* stream);
//string은 저장할 문자열, stream은 개방된 파일의 포인터.