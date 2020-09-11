//"c:"디렉터리에 ccc라는 디렉터리를 생성하는 프로그램을 작성하세요.
#include <stdio.h>
#include <direct.h>

void main(void) {
	char* pathname = "c:\\ccc";

	if (_mkdir(pathname) == -1) {
		perror("디렉터리 생성 에러");
	}
	else {
		puts("디렉터리를 성공적으로 생성하였습니다.");
	}
}
//int _mkdir(const char* dirname);
//dirname은 생성할 디렉터리의 경로 및 이름입니다.
//에러시 함수는 -1을 반환합니다.
//디렉터리 삭제는 _rmdir()함수를 이용.