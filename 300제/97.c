//100개의 정수형 값을 저장할 수 있는 메모리를 할당하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main(void) {
	char* pmem;

	printf("sizeof(int)의 길이는 %d입니다.\n", sizeof(int));

	pmem = calloc(100, sizeof(int));

	if (pmem == NULL) {
		puts("메모리를 할당할 수 없습니다.");
	}
	else {
		puts("정수형 변수 100개를 저장할 버퍼가 할당되었습니다.");

		free(pmem);
	}
}
//void* calloc(size_t num, size_t size);
//num는 동적으로 할당할 블록의 수이며, size는 블록의 크기입니다.
//num*size만큼 메모리를 할당할 수 있습니다.
//malloc과 다르게 할당된 버퍼를 모두 0으로 초기화한다.
//malloc(sizeof(int)*num)) = calloc(sizeof(int),num)