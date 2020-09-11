//현재 작업중인 디렉터리를 c:\temp로 설정하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h> //_MAX_PATH
#include <direct.h> //_getcwd

void main(void) {
	char pathname[_MAX_PATH] = "c:\\temp";

	if (_chdir(pathname) == 0) { //error:-1
		_getcwd(pathname, _MAX_PATH);
		puts(pathname);
	}
}
//int _chdir(char* buffer);
//buffer는 변경될 디렉터리의 이름