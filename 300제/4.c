//변수 x에 10을 대입하고, x에서 5를 빼는 프로그램을 작성하세요.
#include<stdio.h>

main() {
	int x;
	int y; 

	x = 10;

	y = x - 5;
	
	if (x > y) {
		printf("x의 값이 y보다 큽니다.");
	}
	else {
		printf("x의 값이 y보다 작거나 같습니다.");
	}
}