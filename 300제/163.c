//현재 작업중인 디렉터리를 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

void main(void) {
	char pathname[_MAX_PATH];

	_getcwd(pathname, _MAX_PATH);

	puts(pathname);
}
//_MAX_PATH는 운영체제에 따른 최대 경로의 길이 값을 가지고 있습니다.
//char* _getcwd(char* buffer, int maxlen);
//buffer는 작업 디렉터리가 저장될 버퍼이며, maxlen은 buffer의 길이입니다.
