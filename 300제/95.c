//문자열이 "1a2b3c4d5e"처럼 구성되어 있을 때, 이 문자열을 "a1b2c3d4e5"처럼 교체하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char string1[] = "1a2b3c4d5e";
	char string2[] = "..........";

	puts(string1);
	puts(string2);

	_swab(string1, string2, sizeof(string1) - 1);
	puts(string1);
	puts(string2);
}
//void swab(char* src,char* dest, int count);
//src는 원본 문자열, dest는 바뀌어진 문자가 저장될 버퍼의 포인터.
//count는 바뀌어질 총 문자의 수
//문자열을 2바이트씩 잘라서 앞뒤로 교체합니다. sizeof(string1)은 NULL을 포함해 11이 됩니다.