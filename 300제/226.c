//���ڿ� ���� ���� buff�� ��� ���� NULL�� ä��� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void main(void) {
	char buff[] = "��ȣ�� Korea�Դϴ�.";
	
	puts(buff);
	strset(buff, 0);
	printf("[%s]\n", buff);
}