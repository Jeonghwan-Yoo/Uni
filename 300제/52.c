//���ڿ��� ����ϴ� print() �Լ��� putch() �Լ��� ����Ͽ� �ۼ��ϼ���.
#include <stdio.h>
#include <conio.h>

int print(char* string);

void main(void) {
	print("This is a putch function!");
}

int print(char* string) {
	int len = 0;

	while (*string != (char)NULL) {
		_putch(*string);
		string++;
		len++;
	}

	//���� ��µǰ� �ִ� ���� ���� ���� ù ��°�� �̵�
	_putch('\r'); //ĳ���� ����
	_putch('\n'); //���� �ǵ�

	return len;
}
//ĳ���� ����(CR):Ŀ���� �� ������
//�����ǵ�(LF):���� �ٷ� �̵�.
//�����쿡���� CR LF�� �Ѵ� ��� �ǰ� �������� LF�� �ᵵ�ȴ�. �׷���, ���������� ������ �������϶��� CR�� ���� �ۼ��ؼ� �׷���.