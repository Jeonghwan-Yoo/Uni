//puts() �Լ��� ����ؼ� ����� �� �ִ� �Լ� ������ myfunc�� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	int(*myfunc)(const char*);

	myfunc = puts;

	puts("��ì�̰� �� ~.~");
	myfunc("�޴ٸ��� �� ~.~");

	myfunc = strlen;

	printf("���ڿ��� ���� : %d\n", strlen("aa"));
	printf("���ڿ��� ���� : %d\n", myfunc("aa"));
}
//�Լ� �����ʹ� �Լ��� �н��� ���� �� �ִ� �����͸� ���մϴ�.
//myfunc�� �����̱� ������ ��� ������ �ٸ� ������ �̸����� �ٲ� �� �ֽ��ϴ�.
//unsigned int�� �׳� int�� ����� �� ����.
//strcpy()���� ��� char* (*cpy)(char*, const char*)�� ����� �� �ִ�.