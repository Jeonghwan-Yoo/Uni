//실수값 3.1415926535를 문자열로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void main(void) {
	double value;
	char* pstr;
	int dec, sign;

	value = 3.1415926535;
	pstr = _fcvt(value, 6, &dec, &sign);

	printf("변환된 문자열은 %s입니다.\n", pstr);
	printf("소수점의 위치를 %d, 부호는 %d입니다.\n", dec, sign);

	value = -3.1415926535;
	pstr = _fcvt(value, 8, &dec, &sign);

	printf("변환된 문자열은 %s입니다.\n", pstr);
	printf("소수점의 위치를 %d, 부호는 %d입니다.\n", dec, sign);
}
//char* fcvt(double value, int count, int* dec, int* sign);
//value는 변환될 실수이며, count는 소수점 이하 몇 자리까지 문자열로 변환할지
//dec은 변환된 문자열의 몇 번째가 소수점의 위치인가를 표시, sign은 0이면 양수 1이면 음수.
//fcvt()는 실수값을 문자열로 변환하여 내부적인 기억 공간에 별도로 저장하며, 그 별도로 저장된 공간의 메모리 주소를 반환합니다.
//반환을 문자형 포인터 값을 하기 때문에 문자형 포인터를 정의한다.
//실수를 문자열로 변환할 때 소수점 및 부호를 생성하지 않습니다. 단, 소수점의 위치와 부호를 정수형 포인터에 전달.
//내부적인 기억공간을 별도로 사용하기 때문에, 이전의 결과가 사라진다.
//ecvt()를 사용하면 지수가 포함된 실수값을 문자열로 변환할 수 있습니다.
//소수점이 포함된 문자열을 만드려면, sprintf()를 사용하세요.