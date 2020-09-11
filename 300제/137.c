//file.txt 파일을 생성하고, 문자 'A'를 저장하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE *fp;

	fopen_s(&fp, "file.txt", "w+");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fputc('A', fp);
		puts("문자 'A'를 파일에 저장하였습니다.");
		fclose(fp);
	}
}
//int fputc(int c, FILE* stream);
//c는 쓰여질 문자이며, stream은 개방된 파일의 포인터입니다.
//w+는 기존에 있던 파일을 삭제하고, 다시 생성합니다. 기존 파일이 지워질 수도 있다.
/*
struct _iobuf{
	char* _ptr;
	int _cnt;
	char* _base;
	int _flag;
	int _file;
	int _charbuf;
	int _bufsiz;
	char* _tmpfname;
};
typedef struct _iobuf FILE;
*/