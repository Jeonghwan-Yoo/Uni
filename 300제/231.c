//메모리를 100MB 할당하고 해제하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)

#define MEGA_BYTE 1048576

void main(void) {
	char* pbuf;

	pbuf = malloc(100 * MEGA_BYTE);

	if (pbuf) {
		memset(pbuf, 0, 100 * MEGA_BYTE);

		strcpy(&pbuf[0], "서울시 양천구 목동");
		puts(&pbuf[0]);

		strcpy(&pbuf[104857500], "부산시 강서구 미음동");
		puts(&pbuf[104857500]);

		free(pbuf);
	}
}
//malloc은 초기에 쓰레기 값들로 채워져 있습니다.
//그리고, 메모리 블록의 첫 번째 바이트의 주소 값을 반환.
//1024바이트 이하의 메모리를 할당하고 사용하는 것이 보통.