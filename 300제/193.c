//최대값과 최소값을 구하는 매크로를 작성하세요.
#include <stdio.h>

#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y

void main(void) {
	printf("최대 값 : %d\n", max(5, 3));
	printf("최소 값 : %d\n", min(5, 3));
	printf("최대 값 : %g\n", max(3.5, 4.4));
	printf("최소 값 : %g\n", min(3.5, 4.4));
}
