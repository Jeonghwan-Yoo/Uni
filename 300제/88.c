//지수가 포함된 실수값 3.14e10을 문자열로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void main(void) {
	double value;
	char buffer[100];

	value = 3.14e10;
	gcvt(value, 3, buffer);

	printf("변환된 문자열은 %s입니다.\n", buffer);

	value = -3.14e10;
	gcvt(value, 3, buffer);

	printf("변환된 문자열은 %s입니다.\n", buffer);
}
//char* gcvt(double value, int digits, char* buffer);
//value는 지수가 포함된 실수이며, digits는 지수를 문자열로 변환 시 몇 바이트를 의미 있는 숫자로 변환할 것인지를 지정.
//value는 변환되어 buffer에 저장.
//fcvt()와 달리 소수점 및 부호를 생성한다.
//sprintf를 이용할 수도 있다. buffer와 %f, %e, %g이용해서.