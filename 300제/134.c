//puts() 함수를 함수에 전달해서 문자열을 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void print1(int(*X)(const char*));
void print2(int(*X[2])(const char*));

void main(void) {
	int(*myfunc[2])(const char*);

	myfunc[0] = puts;
	myfunc[1] = strlen;

	print1(myfunc[0]);
	print2(myfunc);
}

void print1(int(*X)(const char*)) {
	X("올챙이가 쑥 ~.~");
}

void print2(int(*X[2])(const char*)) {
	X[0]("뒷다리가 쭉 ~.~");
	printf("문자열의 길이 : %d\n", X[1]("aa"));
}
//함수에 대한 포인터를 사용하려면 포인터를 선언해야 할 뿐만 아니라, 어떤 것을 가리키도록 초기화해야 합니다.
//포인터가 가리켜야 하는 함수에는 아무런 제한이 없습니다.
//하지만, 함수의 복귀형과 인수 목록이 포인터를 선언할 때 지정된 반환형이나 인수 목록과 일치해야 한다는 점입니다.