//���� �۾����� ���͸��� c:\temp�� �����ϴ� ���α׷��� �ۼ��ϼ���.
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
//buffer�� ����� ���͸��� �̸�