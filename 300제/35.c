//1부터 10까지 더하는 프로그램을 while문을 사용하여 작성하세요.
#include <stdio.h>

main() {
	int i = 1;
	int hap = 0;

	while (i <= 10) { //i가 10보다 작거나 같은 동안
		hap = hap + i;
		i++; //i의 값을 1증가
	}
	
	printf("hap=%d", hap); //hap=55
	
}
//무한 루프에 빠지지않게 조심한다. break와 continue를 사용할 수 있다.
//while(1){} 무한 루프.