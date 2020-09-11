//1차원 문자열 배열 one을 정의하고 "Korea"로 초기화하세요. 그리고, one을 대신해서 사용할
//수 있는 포인터(분신)을 사용하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char one[] = "Korea";
	char* pone;

	pone = one;

	puts(one); //"Korea"
	puts(pone); //"Korea"

	strcpy_s(pone, sizeof("Japan"), "Japan");
	puts(one); //"Japan"
	puts(pone); //"Japan"
}
//one이 문자형 배열을 대표하는 대표상수(분신)이기 때문에 번지지정연산자는 사용하지 않습니다.