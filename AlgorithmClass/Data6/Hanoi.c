#include <stdio.h>

int hanoiNum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return 1 + 2*hanoiNum(n - 1);
	}
}

/*n���� ���ø� from ���뿡�� to ������� �ű��.
�̶�, tmp ���븦 �ӽ÷� ����ص� �ȴ�.*/
void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) { //�������� ��� �����ϸ� �ᱹ �Ѱ��� �Űܾ� �ȴ�.
		printf("Move dish from %c to %c\n", from, to);
		return;
	}
	else {
		hanoi(n - 1, from, to, tmp); //���� �ػ��� �������� �߰��� �Űܳ���
		hanoi(1, from, tmp, to); //���� �ؿ� �ִ� ���� ���� �������� �Űܳ���
		hanoi(n - 1, tmp, from, to); //�߰��� �ִ� ���� ���� �������� �Űܳ��´�.
	}
}

int main(void) {
	char poleA = 'A';
	char poleB = 'B';
	char poleC = 'C';
	//���� poleA�� ���� 3���� �ִµ�,
	//�̰��� poleC�� ��� �Űܶ�.
	//�� ��, poleB�� �ӽ÷� ����� �� �ִ�.
	hanoi(3, poleA, poleB, poleC);

	return 0;
}