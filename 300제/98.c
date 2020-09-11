//메모리를 1M바이트씩 10번 할당하고 해제하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MEGA 1024*1024

void main(void) {
	int i;
	char* pmem;

	for (i = 0;i < 10;i++) {
		pmem = malloc(MEGA);

		if (pmem == NULL) {
			puts("메모리를 할당할 수 없습니다.");
		}
		else {
			puts("메모리를 1MB 할당하였습니다.");

			free(pmem);

			puts("메모리를 해제하였습니다.");
		}
	}
}
//void* free(void* memblock);
//memblock은 malloc 이나 calloc에서 반환된 포인터의 값이며, 포인터의 값을 변경해서 free()함수를 호출할 수 없습니다.
//heap : malloc이나 calloc을 사용하여 메모리를 할당할 때 할당된 메모리는 프로그램에서 사용할 수 있는 전체 메모리의 양을 소모.
//이렇게 사용 가능한 전체 메모리 영역을 힙이라고 하는데 제한되어 있습니다.
//프로그램에서 동적으로 할당된 메모리의 특정 블록을 사용한 후에는 나중에 다른 프로그램이나 함수에서 다시 할당하여
//사용할 수 있도록 해제시켜야 합니다. free()