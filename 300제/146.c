//145를 rewind() 함수를 사용하여 파일의 처음으로 이동하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file4.txt", "w+");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		printf("파일의 포인터의 위치 : %d\n", ftell(fp)); //0
		fputs("abcde", fp);
		printf("파일의 포인터의 위치 : %d\n", ftell(fp)); //5
		rewind(fp);
		printf("파일의 포인터의 위치 : %d\n", ftell(fp)); //0
		fclose(fp);
	}
}
//void rewind(FILE* stream);
//파일 포인터의 위치를 처음으로 이동합니다.