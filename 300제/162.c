//161에서 생성한 ccc라는 디렉터리를 삭제하는 프로그램을 작성하세요.
#include <stdio.h>
#include <direct.h>

void main(void) {
	char* pathname = "c:\\ccc";

	if (_rmdir(pathname) == -1) {
		perror("디렉터리 삭제 에러");
	}
	else {
		puts("디렉터리를 성공적으로 삭제하였습니다!");
	}
}
//int _rmdir(const char* dirname);
//dirname은 삭제할 디렉터리의 경로 및 이름.
//에러시 -1반환