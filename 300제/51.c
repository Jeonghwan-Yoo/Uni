//�� ���� ���ڸ� �Է¹޾� �ƽ�Ű �ڵ� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <conio.h>

#define ENTER 13

void main(void) {
	int ch;

	printf("�ƽ�Ű �ڵ�� ��ȯ�� Ű�� ��������...\n");
	printf("EnterŰ�� ������ ���α׷��� ����˴ϴ�.\n");

	do {
		ch = _getch();
		//if (ch == 0) continue;
		printf("���� : (%c), �ƽ�Ű �ڵ� = (%d)\n", ch, ch);
	} while (ch != ENTER);
}