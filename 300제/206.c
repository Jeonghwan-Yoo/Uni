//21~50까지의 난수를 발생시키는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void) {
	int i, rand_num;

	srand(time(NULL));

	for (i = 0;i < 10;i++) {
		rand_num = rand() % 30 + 21;
		printf("[%d] ", rand_num);
	}
}