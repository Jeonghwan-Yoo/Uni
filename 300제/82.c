//문자열 "1.234E-10"과 같이 지수를 포함한 문자열을 숫자로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string = "1.234E-10";
	char* stop;
	double value;

	value = strtod(string, &stop);

	printf("%d개의 문자가 변환되었습니다.\n", stop - string);
	printf("문자열[%s]를 숫자로 변환하면 %E입니다.\n", string, value);
}
//double strtod(conset char* string, char**stop);
//string은 지수가 포함된 문자열이며, stop은 변환이 되다가 멈춰진 위치의 포인터 값입니다.