//파일 포인터를 파일의 처음으로 이동하는 프로그램을 작성하세요.
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
		fseek(fp, 0L, SEEK_SET); //처음으로부터 0만큼떨어진 곳
		printf("파일 포인터의 위치 : %d\n", ftell(fp)); //0
		fclose(fp);
	}
}
//int fseek(FILE* stream, long offset, int origin);
//offset은 파일의 이동할 거리이며, origin은 이동을 시작할 위치입니다.
//파일 포인터의 위치를 파일의 처음을 기준으로 해서 0L만큼 이동합니다.
//즉, 파일의 처음으로 이동하는 것입니다. 
//SEEK_SET은 처음이므로 offset은 양수
//SEEK_END는 마지막이므로 offset은 음수
//SEEK_CUR은 현재 장소에 대해서 움직일 수 있다.


