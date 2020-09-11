//정수형 상수 HUNDRED_THOUSAND를 정의하고 HUNDRED_THOUSAND를 100,000 대신에 사용하는 프로그램을 작성하세요.
#include <stdio.h>

#define  HUNDRED_THOUSAND 100000

const int j = 200000;

main() {
	//HUDNRED_THOUSAND = 100000; //에러 발생
	//j = 200000; //에러 발생
	
	printf("정수형 상수 HUNDRED_THOUSAND의 값은 %d\n", HUNDRED_THOUSAND);
	printf("정수형 상수 j의 값은 %d\n", j);
}

//정수형 상수를 사용할 때는 일반적으로 정수임을 나타내는 L또는 UL을 사용하곤 한다.
//#define HUNDRED_THOUSAND 100000L
//const int j=200000UL;