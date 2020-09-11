//100바이트 버퍼 10000개를 할당하고 해제하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main(void) {
	char* pbuf;

	pbuf = malloc(100 * 10000);

	if (pbuf) {
		memset(pbuf, 0, 100 * 10000);
		strcpy_s(&pbuf[0], sizeof("서울시 양천구 목동"), "서울시 양천구 목동");
		puts(&pbuf[0]);
		free(pbuf);
	}
}