//파일 포인터의 현재 읽고 쓸 위치를 구하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file4.txt", "w+");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		printf("파일 포인터의 위치 : %d\n", ftell(fp)); //0
		fputs("abcde", fp);
		printf("파일 포인터의 위치 : %d\n", ftell(fp)); //5
		fclose(fp);
	}
}
//long ftell(FILE* stream);
//파일 포인터는 현재 읽거나 쓸 위치 값을 가리키는 것입니다.
//파일을 새로 생성하거나 읽기모드로 개방한 경우, 파일 포인터는 처음의 위치를 가리키는 0값을 갖습니다.
//즉, 파일 포인터의 길이를 구합니다.