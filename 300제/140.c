//139에서 저장한 "대한민국"을 읽는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char buffer[100];

	fopen_s(&fp, "file1.txt", "r");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fgets(buffer, 100, fp);
		puts(buffer);
		fclose(fp);
	}
}
//int fgets(char* buffer, int n, FILE* stream);
//buffer는 문자열이 읽혀질 버퍼, n은 읽을 문자열의 길이
//읽는중 개행문자를 만나면 99바이트를 읽지 않고, 그 지점까지만 버퍼에 읽습니다.
//버퍼의 끝은 문자열처럼 NULL이 자동으로 추가됩니다.