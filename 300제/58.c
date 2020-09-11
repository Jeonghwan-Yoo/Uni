//"대한민국"이라는 문자열을 복사하는 함수 My_strcpy를 작성하세요.
#include <stdio.h>

#define KOREA "대한민국"

char* My_strcpy(char* dest, const char* src);
char* My_strncpy(char* dest, const char* src, int count);

void main(void) {
	char string[100];

	My_strcpy(string, KOREA);
	My_strncpy(string, KOREA,6);

	puts(string); //대한민국을 출력
}

char* My_strcpy(char* dest, const char* src) {
	char* ret = dest;
	//모든 문자열의 길이가 0이면 dest를 NULL로 설정.
	if (dest == (int)NULL || src == (int)NULL) {
		if (*dest != (int)NULL) *dest = (int)NULL;
		return NULL;
	}
	do {
		*dest++ = *src;
		
	} while (*src++ != (int)NULL);
	return ret;
}
//*dest++=*src++;를 하게되면 마지막에 dest에 null을 넣을 수가 없다.
//c에서는 문자열을 처리하는 방법 때문에 문자열을 직접 복사할 수 없습니다.
//메모리에서 원본 문자열을 목적 문자열의 메모리 영역으로 복사해야 합니다.
//복사함수:strcpy(), strncpy(), strdup()
//strcpy():전체 문자열을 다른 메모리 영역으로 복사합니다.
//strncpy():전체 문자열을 다른 메모리 영역에 복사하고, 복사할 문자의 개수를 지정할 수 있습니다.
//strdup():malloc()함수를 호출하여 목적 문자열을 저장하기 위한 메모리 영역을 할당한다.

char* My_strncpy(char* dest, const char* src, int count) {
	if (dest == (int)NULL || src == (int)NULL) {
		if (*dest != (int)NULL) {
			*dest = (int)NULL;
		}
		return NULL;
	}
	while (~(*src != NULL)&&(count--!=0)) {
		*dest++ = *src++;
	}
	*dest = NULL;
}
