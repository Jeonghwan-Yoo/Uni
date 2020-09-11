//널(NULL) 값이 포함된 버퍼를 비교하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char s1[100] = "123";
	char s2[100] = "123";

	strcpy_s(&s1[4], sizeof("abc"), "abc"); //1 2 3 \0 a b c \0
	strcpy_s(&s2[4], sizeof("efg"), "efg"); //1 2 3 \0 e f g \0
	
	if (strcmp(s1, s2) == 0) {
		puts("strcmp : 버퍼의 값이 일치합니다.");
	}

	if (memcmp(s1, s2, 7) == 0) {
		puts("memcmp : 버퍼의 값이 일치합니다.");
	}
	else {
		puts("memcmp : 버퍼의 값이 일치하지 않습니다.");
	}
}
//int memcmp(const void* buf1, const void* buf2, unsigned int count);
//buf1, buf2는 비교할 버퍼이며, count는 비교할 버퍼의 크기입니다.
//strcmp()는 3에 위치에서 널이 존재하기 때문에 3바이트만 비교되고, 두 문자열은 같다고 나옵니다.
//memcmp()함수에 의해 7바이트를 비교하면 결과가 다르다는 것을 알 수 있습니다.
//strcmp는 문자열(널까지)을 비교하고 memcmp는 버퍼에 지정된 길이만큼 비교.