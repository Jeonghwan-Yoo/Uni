//메모리를 널값으로 채우는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[50] = "아름다운 우리나라 대한민국";

	puts(string);

	memset(string, (int)NULL, sizeof(string));

	puts(string);

	memset(string, '*', sizeof(string) - 1);

	puts(string);
}
//void* memset(void* dest, int fillChar, unsigned int count);
//dest는 초기화될 버퍼, fillChar는 초기화할 문자 count는 dest에 몇 바이트의 문자를 채우는지.
//memset()은 구조체에서도 다른 버퍼의 값을 0으로 초기화할 때 사용.
//struct tagPoint pt;
//memset(&pt,0,sizeof(pt));