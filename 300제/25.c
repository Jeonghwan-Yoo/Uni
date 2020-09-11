//정수형 변수 x, y, z을 각각 1, 2, 3으로 초기화하여 정의하고, 각각의 값을 비교하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int x = 1;
	int y = 2;
	int z = 3;

	if (x == y) printf("x는 y와 같습니다.\n");
	if (x != y) printf("x는 y와 같지 않습니다.\n");
	if (x > y) printf("x는 y보다 큽니다.\n");
	if (x < y) printf("x는 y보다 작습니다.\n");
	if (y >= z) printf("y는 z보다 크거나 같습니다.\n");
	if (y <= y) printf("y는 z보다 작거나 같습니다.\n");
}