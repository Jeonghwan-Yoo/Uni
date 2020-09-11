//메모리를 100바이트 할당하고, 문자열 "MEMORY"를 복사하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MEMORY "MEMORY"

void main(void) {
	char* pmem;

	pmem = malloc(100);

	if (pmem == NULL) {
		puts("메모리를 할당할 수 없습니다.");
	}
	else {
		strcpy_s(pmem, sizeof(MEMORY), MEMORY);
		puts(pmem);

		free(pmem);
	}
}
//void* malloc(unsigned int size);
//size는 동적으로 할당하고자 하는 메모리의 크기.
//할당된 메모리를 가리킬 문자형 포인터 변수를 정의.
//malloc()은 할당된 버퍼를 초기화하지 않기 때문에 버퍼에는 쓰레기 값이 존재하며, memset()을 이용할 수 있다.
//free()를 해야 자원이 안모자를 수 있다.
//32비트 운영체제에서 최대 4GB 할당.
//포인터가 NULL인지 확인해야 한다.