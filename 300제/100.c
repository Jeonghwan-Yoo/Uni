//구조체를 아래의 4~9번째 줄과 같이 선언하고, 구조체 변수 x1, x2를 정의하세요.
//그리고, x1 구조체에 값을 대입한 후, x1 구조체를 x2 구조체로 복사하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

struct tagM1 {
	int x;
	int y;
	char buffer[30];
};

void main(void) {
	struct tagM1 x1, x2;

	x1.x = 5;
	x1.y = 10;

	strcpy_s(x1.buffer, sizeof("memory copy"), "memory copy");

	memcpy(&x2, &x1, sizeof(x1));

	puts(x2.buffer);
}
//void* memcpy(void* dest, const void* src, unsigned int count);
//dest는 복사될 버퍼, src는 복사할 버퍼, count는 복사할 src의 메모리의 크기.
//strcpy()는 문자열을 복사, memcpy()는 메모리를 복사.
//memcpy()는 버퍼에 널이 있는 경우에도 지정된 길이만큼 모두 복사합니다.