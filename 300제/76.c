//문자형, 정수형, 실수형, 문자열형 변수를 정의하고, 각 변수를 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char cValue = 'a';
	int iValue = 1234567;
	long lValue = 7890123;
	float fValue = 3.141592;
	double dValue = 3.141592;
	char* string = "korea";
	char buffer[100];

	sprintf_s(buffer, sizeof(buffer), "char 형은 %c", cValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "int 형은 %d", iValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "long 형은 %ld", lValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "float 형은 %f", fValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "double 형은 %e", dValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "char* 형은 %s", string);
	puts(buffer);
}
//int sprintf(char* buffer, const char* format [,argument]...);
//buffer는 형식화된 문자열이 저장될 버퍼, format은 printf()함수와 동일한 형식화 문자열.
//버퍼에 형식화된 문자열을 생성할 때 사용한다는 점이 다르다.