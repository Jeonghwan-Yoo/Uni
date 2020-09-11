//난수를 발생시키는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void) {
	int i;

	srand((unsigned)time(NULL)); //난수 발생기를 초기화
	
	for (i = 0;i < 5;i++) {
		printf("난수 %d : %d\n", i, rand());
	}
}
//void srand(unsigned int seed); int rand(void);
//seed는 난수의 초기값이며, time(NULL)을 사용합니다.
//rand()난수는0~32767사이의 값
