//"대한민국"이라는 문자열을 복사하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

#define KOREA "대한민국"

void main(void) {
	char *string1;
	char string2[100];

	strcpy_s(string1, sizeof(KOREA),KOREA); //실행 시 에러 발생
	strcpy_s(string2, sizeof(KOREA),KOREA);
	strcpy_s(string2, sizeof("봄"),"봄");
}

//반환형은 문자형 포인터이다.
//src는 const가 있고 dest는 const가 없다.
//dest에 넘겨주는 인자는 문자열 상수가 될 수 없습니다. dest에 넘겨주는 문자형 포인터 값은 strcpy()내부에서 변경되기 때문.
//그래서, 문자열 상수를 가리키는 문자형 포인터 값 사용할 수 없다.
//dest에 넘겨줄 수 있는 것은 문자 배열 등입니다.
//만약에, 문자형 포인터 변수를 정의하고, 그 포인터 변수가 문자 배열 변수를 가리키면 dest에 가능하다.
//dest에 넘겨주는 번지를 strcpy() 함수 내부에서 접근할 수 있는지, 없는지가 관건.
//src는 모두 넘겨줄 수 있지만, 초기화되지 않는 포인터 변수는 사용할 수 없다. 무조건 초기화 해야한다.
//부분적으로 복사하려면 int strncpy(char *string1, const char *string2, unsigned int count);