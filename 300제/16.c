//문자형 상수 HUNDRED를 정의하고 HUNDRED의 값을 100 대신에 사용하는 프로그램을 작성하세요.
#include <stdio.h>

#define HUNDRED 100

const char j = 100;

main() {
	//HUNDRED = 200; //에러
	//j = 200; //에러

	printf("문자형 상수 HUNDRED의 값은 %d\n", HUNDRED);
	printf("문자형 상수 j의 값은 %d\n", j);
}
//문자형 상수는 문자형 변수를 대신하여 사용되는 값이고, 실행 시간동안 바뀌어서는 안되는 값
//#define과 const char형을 이용, 차이는 #define은 형을 구분하지 않는다.