//memmove() 함수를 직접 구한하는 My_memmove() 함수를 만들어 보세요.
#include <stdio.h>
#include <stdlib.h>

char s[20] = "1234567890";

void* My_memmove(void* dst, const void* src, unsigned int count);

void main(void) {
	puts(s);
	My_memmove(s + 4, s + 2, 6);
	puts(s);
}

void* My_memmove(void* dst, const void* src, unsigned int count) {
	void* ret = dst;

	//안겹치는경우(카피될 곳의 위치가 앞이거나, 카피할 것보다 멀리있으면) 
	if (dst <= src||(char*)dst>=(char*)src+count) {
		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	//겹치는경우
	else {
		dst = (char*)dst + count-1; //index는 0번부터 시작이므로.
		src = (char*)src + count-1;

		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}

	return ret;
}
//dst와 src의 영역이 겹쳐지는지 확인하고 겹쳐지면 뒤에서부터 복사한다.