//1부터 10까지 더하는 프로그램을 do~while문을 사용하여 작성하세요.
#include <stdio.h>

main() {
	int i = 1;
	int hap = 0;

	do {
		hap = hap + i;
		i++; //i가 1부터 11까지 증가.
	} while (i <= 10); //i가 10보다 작거나 같은 동안 반복. 11이 되면 순환 탈출.

	printf("hap = %d", hap); //hap=55
}
//do는 일단 한번은 문장을 실행 후 조건식을 평가한다.
//break와 continue를 사용할 수 있다.