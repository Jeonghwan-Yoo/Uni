//문자열 "1234567890"이 저장되어 있는 버퍼의 '5' 위치에 '3' 위치로부터의 값을 이동하여
//"12345670"처럼 메모리 구조가 변경되는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

char s1[20] = "1234567890";
char s2[20] = "1234567890";

void main(void) {
	puts(s1);
	memcpy(s1 + 4, s1 + 2, 5);
	puts(s1);

	puts(s2);
	memmove(s2 + 4, s2 + 2, 5);
	puts(s2);
}
//void* memmove(void* buf1, const void* buf2, unsigned int count);
//buf1은 buf2가 옮겨질 버퍼이며, buf2는 옮겨질 데이터가 저장된 버퍼입니다.
//count는 비교할 버퍼의 크기입니다.
//데이터가 겹치는 경우 memcpy는 s+4를 s+6에 복사하려고 할 때 문제가 발생한다.
//하지만, 비쥬얼스튜디오에서는 문제가 발생하면 memmove()처럼 동작하게 한다.
//memmove()는 내부적으로 뒤에서부터 복사하기 때문에 올바르게 메모리에 복사됩니다.