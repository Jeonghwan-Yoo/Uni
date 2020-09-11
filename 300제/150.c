//파일 포인터의 위치를 구하는 프로그램을 fgetpos() 함수를 사용하여 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	fpos_t pos;

	fopen_s(&fp, "file4.txt", "w+");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fputs("abcde", fp);
		fgetpos(fp, &pos);
		printf("파일 포인터의 위치 : %d\n", pos); //5
		fclose(fp);
	}
}
//int fgetpos(FILE* stream, fpos_t* pos);
//pos에 파일 포인터의 위치가 저장됩니다.