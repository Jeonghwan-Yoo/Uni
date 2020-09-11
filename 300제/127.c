//126에서 사용된 공용체를 함수를 사용해서 출력하는 프로그램을 작성하세요.
#include <stdio.h>

typedef union tagVariable {
	int i;
	double d;
} VA;

void print(VA *pva);

void main(void) {
	VA va;

	print(&va);
}

void print(VA *pva) {
	pva->i = 5;

	printf("pva->i 공용체의 값 : %d\n", pva->i);

	pva->d = 3.14;

	printf("pva->d 공용체의 값 : %f\n", pva->d);
	printf("pva->i 공용체의 값 : %d\n", pva->i);
}
//공용체는 여러 가지 데이터형을 멤버로 선언하고, 상황에 맞는 데이터 값을 사용하고자 할 때 편리합니다.
//나중에 MFC를 배우면, COleVariant는 union을 사용하고 있는 클래스로써, 많은 데이터형을 사용하고 있습니다.