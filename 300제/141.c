//정수의 값을 file.txt 파일에 저장하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int i = 12345;

	fopen_s(&fp, "file2.txt", "w+");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fprintf(fp, "%d", i);
		fclose(fp);
	}
}
//int fprintf(FILE* stream, const char* format[,argument]...);
//format은 printf함수와 같은 구조를 가진 형식 문자열.