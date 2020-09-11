//메모리를 100바이트 할당하고, 200바이트로 재할당하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main(void) {
	char* pmem;

	pmem = malloc(100);

	if (pmem == NULL) {
		puts("메모리를 할당할 수 없습니다.");
	}
	else {
		printf("할당된 메모리 길이는 %d바이트입니다.\n", _msize(pmem));

		pmem = realloc(pmem, 200);

		if (pmem == NULL) {
			puts("메모리를 재 할당할 수 없습니다.");
		}
		else {
			printf("재할당된 메모리 길이는 %d바이트입니다.\n", _msize(pmem));
		}
		free(pmem);
	}
}
//void* realloc(char* memblock, unsigned int size);
//memblock은 기존에 malloc함수에서 반환된 포인터이며, size는 재할당할 메모리의 크기입니다.
//메모리 사이즈를 확인할 떄는 _msize()을 이용.
//calloc을 재할당하려면 _expand()를 이용한다.