//puts() �Լ��� strlen() �Լ��� ����ؼ� ����� �Լ� �����͸� �迭�� ����ؼ� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	int(*myfunc[3])(const char*);

	myfunc[0] = puts;
	myfunc[1] = strlen;
	myfunc[2] = myfunc[1];

	puts("��ì�̰� �� ~.~");
	myfunc[0]("�޴ٸ��� �� ~.~"); //puts()

	printf("���ڿ��� ���� : %d\n", strlen("aa"));
	printf("���ڿ��� ���� : %d\n", myfunc[1]("aa"));
	printf("���ڿ��� ���� : %d\n", myfunc[2]("aa"));
}
//�Լ��� �����͸� �Ű� ������ �Ѱ��ִ� �Լ���, �Լ��� �����͸� ��ȯ�ϴ� �Լ� ���� ����ϰ� �� ���̴�.
//�Լ��� ���� �����͸� ������ ������ ��ȣ�� ����ؾ� �Ѵٴ� ��ǿ� �����ϱ� �ٶ��ϴ�.