//141에서 저장한 정수의 값을 읽는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int i;

	fopen_s(&fp, "file2.txt", "r");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fscanf_s(fp, "%d", &i);
		printf("i=%d\n", i);
		fclose(fp);
	}
}
//int fscanf(FILE* stream, const char* format[,argument]...);