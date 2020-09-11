//puts() 함수를 대신해서 사용할 수 있는 함수 포인터 myfunc을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	int(*myfunc)(const char*);

	myfunc = puts;

	puts("울챙이가 쭉 ~.~");
	myfunc("뒷다리가 쭉 ~.~");

	myfunc = strlen;

	printf("문자열의 길이 : %d\n", strlen("aa"));
	printf("문자열의 길이 : %d\n", myfunc("aa"));
}
//함수 포인터는 함수의 분신을 만들 수 있는 포인터를 말합니다.
//myfunc은 변수이기 때문에 사용 가능한 다른 변수의 이름으로 바꿀 수 있습니다.
//unsigned int도 그냥 int로 사용할 수 있음.
//strcpy()같은 경우 char* (*cpy)(char*, const char*)로 사용할 수 있다.