//158���� ����� file_1.txt������ �Ӽ��� �б� �������� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>

void main(void) {
	char* filename = "file_1.txt";

	if (_chmod(filename, _S_IREAD) != 0) {
		perror("���� �Ӽ� ���� ����");
	}
	else {
		puts("������ �Ӽ��� ���������� �����Ͽ����ϴ�!");
	}
}
//int _chmod(const char* filename, int pmode);
//filename�� ���ϸ��̸�, pmode�� �б� �Ǵ� ���� ���� ��
//_S_IREAD�� �б� ����, _S_IWRITE�� �Ϲ� ���Ϸ� ������ �� ����մϴ�.