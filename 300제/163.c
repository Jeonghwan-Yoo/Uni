//���� �۾����� ���͸��� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

void main(void) {
	char pathname[_MAX_PATH];

	_getcwd(pathname, _MAX_PATH);

	puts(pathname);
}
//_MAX_PATH�� �ü���� ���� �ִ� ����� ���� ���� ������ �ֽ��ϴ�.
//char* _getcwd(char* buffer, int maxlen);
//buffer�� �۾� ���͸��� ����� �����̸�, maxlen�� buffer�� �����Դϴ�.
