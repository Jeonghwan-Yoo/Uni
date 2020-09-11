//정수값과 실수값을 모두 저장할 수 있는 변수 va를 사용하는 프로그램을 작성하세요.
#include <stdio.h>

typedef union tagVariable {
	int i;
	double d;
} VA;

void main(void) {
	VA va;

	va.i = 5;

	printf("va.i 공용체의 값 : %d\n", va.i);

	va.d = 3.14;

	printf("va.d 공용체의 값 : %f\n", va.d);
	printf("va.i 공용체의 값 : %d\n", va.i);
}
//공용체 멤버는 서로 같은 메모리 영역을 공유하고 있다. 그래서 네트워크 프로그램 등에서 자주 사용.
//i에 5를 대입할 때 d도 메모리를 공유하고 있기 때문에 d의 값도 의미가 없는 값으로 변화됨.
//d에 값을 입력하면 자동으로 i의 값은 의미가 없는 값으로 변경.
//공용체 변수는 메모리 영역을 char 4개는 int 1개처럼 공유합니다. 두개의 변수를 모두 사용할 수는 없으며,
//각각의 상황에 맞는 데이터형 값을 저장할 때 편리하게 사용할 수 있습니다.