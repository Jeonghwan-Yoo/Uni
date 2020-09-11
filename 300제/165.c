//현재 작업중인 드라이브를 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <direct.h>

void main(void) {
	int drive;

	drive = _getdrive();

	printf("현재 드라이브 : %c\n", 'A' + drive - 1);
}
//int _getdrive(void);
//A=1, B=2,...