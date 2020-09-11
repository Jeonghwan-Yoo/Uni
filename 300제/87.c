//지수가 포함된 실수값 3.14e10을 문자열로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void main(void) {
	double value;
	char* pstr;
	int dec, sign;

	value = 3.14e10;
	pstr = ecvt(value, 3, &dec, &sign);

	printf("변환된 문자열은 %s입니다.\n", pstr);
	printf("소수점의 위치는 %d, 부호는 %d입니다.\n", dec, sign);

	value = -3.14e10;
	pstr = ecvt(value, 3, &dec, &sign);

	printf("변환된 문자열은 %s입니다.\n", pstr);
	printf("소수점의 위치는 %d, 부호는 %d입니다.\n", dec, sign);
}
//char* ecvt(double value, int count, int* dec, int* sign);
//value는 지수가 포함된 실수값이며, count는 총 몇 자리만큼의 문자열로 생성할 것인가를 지정.
//dec는 변환된 문자열의 몇 번째가 소수점의 위치인가를 표시, sign은 0이면 양수 1이면 음수.
//실수를 문자열로 변환할 때 소수점 및 부호를 생성하지 않습니다. 단, 소수점의 위치와 부호를 전달.
//내부적인 기억공간을 별도로 사용하며, 그 메모리에 대한 포인터만 반환.