#include <stdio.h>

void main() {
	int a = 10;
	int *b; //������ ����
	int **c; //double point.
	b = &a; //address of b is same as it of a.
	c = &b; //address of c is same as it of b.
	printf("%d %d %d\n", a, *b, **c); //�ּҿ� �ִ� �� ��ȯ
	//*�� ó������ ���� �״������� ���ּҰ��� ����ִ� ��.
}