//���ڰ� 12345�� ���� ���ڿ� "11000000111001"�� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int value;
	char string[100];
	int radix;

	radix = 2; //������

	value = 12345;
	_ltoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", string);

	value = -12345;
	_ltoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", string);
}
//char* ltoa(long value, char* string, int radix);
//value�� ��ȯ�� ���ڰ��̸�, string�� ��ȯ�� ���ڰ� ����� �����Դϴ�.
//radix�� value���� �� ���� ���ڿ��� ���·� ������ ���� �����մϴ�.
//ultoa()�� �����ϴ�.