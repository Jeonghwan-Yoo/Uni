//������ ���Ե� �Ǽ��� 3.14e10�� ���ڿ��� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void main(void) {
	double value;
	char* pstr;
	int dec, sign;

	value = 3.14e10;
	pstr = ecvt(value, 3, &dec, &sign);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", pstr);
	printf("�Ҽ����� ��ġ�� %d, ��ȣ�� %d�Դϴ�.\n", dec, sign);

	value = -3.14e10;
	pstr = ecvt(value, 3, &dec, &sign);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", pstr);
	printf("�Ҽ����� ��ġ�� %d, ��ȣ�� %d�Դϴ�.\n", dec, sign);
}
//char* ecvt(double value, int count, int* dec, int* sign);
//value�� ������ ���Ե� �Ǽ����̸�, count�� �� �� �ڸ���ŭ�� ���ڿ��� ������ ���ΰ��� ����.
//dec�� ��ȯ�� ���ڿ��� �� ��°�� �Ҽ����� ��ġ�ΰ��� ǥ��, sign�� 0�̸� ��� 1�̸� ����.
//�Ǽ��� ���ڿ��� ��ȯ�� �� �Ҽ��� �� ��ȣ�� �������� �ʽ��ϴ�. ��, �Ҽ����� ��ġ�� ��ȣ�� ����.
//�������� �������� ������ ����ϸ�, �� �޸𸮿� ���� �����͸� ��ȯ.