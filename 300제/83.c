//���ڰ� 5�� ���� ���ڿ� "5"�� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int value;
	char string[100];
	int radix;

	radix = 10; //������

	value = 5;
	_itoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", string);
	
	value = -12345;
	_itoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", string);
}
//char* itoa(int value, char* string, int radix);
//value�� ��ȯ�� ���ڰ��̸�, string�� ��ȯ�� ���ڰ� ����� �����Դϴ�.
//radix�� value ���� �� ���� ���ڿ��� ���·� ������ ���� �����մϴ�.