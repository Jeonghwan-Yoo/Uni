//memcpy() 함수를 직접 구현하는 My_memcpy() 함수를 만들어 보세요.
#include <stdio.h>
#include <string.h>

struct tagM1 {
	int x;
	int y;
	char buffer[30];
};

void* My_memcpy(void* dst, const void* src, unsigned int count);

void main(void) {
	struct tagM1 x1, x2;

	x1.x = 5;
	x1.y = 10;
	strcpy_s(x1.buffer, sizeof("memory copy"), "memory copy");

	My_memcpy(&x2, &x1, sizeof(x1));

	puts(x2.buffer);
}

void* My_memcpy(void* dst, const void* src, unsigned int count) {
	void* ret = dst;

	while (count--) {
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;
}
//void*는 크기가 정해지지 않은 상태이기 때문에 증가할 번지를 의미하는 데이터형으로 형변환해야 합니다.