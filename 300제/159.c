//158에서 사용한 file_1.txt파일의 속성을 읽기 전용으로 설정하는 프로그램을 작성하세요.
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>

void main(void) {
	char* filename = "file_1.txt";

	if (_chmod(filename, _S_IREAD) != 0) {
		perror("파일 속성 설정 에러");
	}
	else {
		puts("파일의 속성을 성공적으로 설정하였습니다!");
	}
}
//int _chmod(const char* filename, int pmode);
//filename은 파일명이며, pmode는 읽기 또는 쓰기 설정 값
//_S_IREAD는 읽기 전용, _S_IWRITE는 일반 파일로 설정할 때 사용합니다.