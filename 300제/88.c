//������ ���Ե� �Ǽ��� 3.14e10�� ���ڿ��� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void main(void) {
	double value;
	char buffer[100];

	value = 3.14e10;
	gcvt(value, 3, buffer);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", buffer);

	value = -3.14e10;
	gcvt(value, 3, buffer);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", buffer);
}
//char* gcvt(double value, int digits, char* buffer);
//value�� ������ ���Ե� �Ǽ��̸�, digits�� ������ ���ڿ��� ��ȯ �� �� ����Ʈ�� �ǹ� �ִ� ���ڷ� ��ȯ�� �������� ����.
//value�� ��ȯ�Ǿ� buffer�� ����.
//fcvt()�� �޸� �Ҽ��� �� ��ȣ�� �����Ѵ�.
//sprintf�� �̿��� ���� �ִ�. buffer�� %f, %e, %g�̿��ؼ�.