#include <stdio.h>

struct A {
	int a;
	char c;
	//자기참조 구조체
	struct A *b; //this is for pointing next node.
};

//구조체변수끼리의 비교를 하려면, 멤버변수 별로 해야한다.
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