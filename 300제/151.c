//파일 포인터를 저장한 후 다시 설정하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	fpos_t pos;

	fopen_s(&fp, "file4.txt", "w+");

	fgetpos(fp, &pos); //0
	fputs("abcde", fp); //5
	fsetpos(fp, &pos); //0
	printf("파일 포인터의 위치 : %d\n", ftell(fp)); //0
	fclose(fp);
}
//int fsetpos(FILE* stream, const fpos_t* pos);
//pos는 fgetpos()함수에서 읽은 값을 사용합니다.
//파일 포인터를 원래의 값으로 재설정한다.