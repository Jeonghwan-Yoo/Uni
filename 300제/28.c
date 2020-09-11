//정수형 변수 x, y를 한 줄에 정의하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int x = 1, y = 2, max;

	max = (x > y ? x : y);
	
	printf("max=%d, x=%d, y=%d", max, x, y);
}
//쉼표 연산자는 for에서도 사용되며, 여러 개의 값을 초기화할 수 있다.
//for(i=0,j=5;i<j;i++,j--)