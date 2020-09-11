//현재 작업중인 드라이브를 변경하는 프로그램을 작성하세요.
#include <stdio.h>
#include <direct.h>

void main(void) {
	int drive = 4;

	if (_chdrive(drive) == 0) { //error:-1
		drive = _getdrive();
		printf("변경된 드라이브 : %c\n", 'A' + drive - 1);
	}
}
//int _chdrive(int drive);
//drive는 변경할 드라이브를 숫자로 표현한 값
