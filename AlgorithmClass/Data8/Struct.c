#include <stdio.h>

struct A {
	int a;
	char c;
	//�ڱ����� ����ü
	struct A *b; //this is for pointing next node.
};

//����ü���������� �񱳸� �Ϸ���, ������� ���� �ؾ��Ѵ�.
int main(void) {
	struct A m, n;
	m.a = 10;
	m.c = 'k';
	n = m; //copied. value.

	printf("%d %c\n", n.a, n.c);

	if (n.a == m.a&&n.c == m.c) {
		printf("They are same\n");
	}


	return 0;
}