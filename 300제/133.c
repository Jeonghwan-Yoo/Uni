//puts() 함수와 strlen() 함수를 대신해서 사용할 함수 포인터를 배열을 사용해서 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	int(*myfunc[3])(const char*);

	myfunc[0] = puts;
	myfunc[1] = strlen;
	myfunc[2] = myfunc[1];

	puts("올챙이가 쑥 ~.~");
	myfunc[0]("뒷다리가 쭉 ~.~"); //puts()

	printf("문자열의 길이 : %d\n", strlen("aa"));
	printf("문자열의 길이 : %d\n", myfunc[1]("aa"));
	printf("문자열의 길이 : %d\n", myfunc[2]("aa"));
}
//함수의 포인터를 매개 변수로 넘겨주는 함수나, 함수의 포인터를 반환하는 함수 등을 사용하게 될 것이다.
//함수에 대한 포인터를 선언할 때에는 괄호를 사용해야 한다는 사실에 주의하기 바랍니다.