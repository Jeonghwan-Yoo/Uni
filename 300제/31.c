//문자형, 정수형, 실수형이 차지하는 메모리의 크기를 출력하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	char i;
	int j;
	double k;

	printf("%d\n", sizeof(i)); //1
	printf("%d\n", sizeof(j)); //4
	printf("%d\n", sizeof(k)); //8
}
//short는 2, long은 4.