//실수형 상수 PI를 정의하고 3.141592대신에 사용하는 프로그램을 작성하세요.
#include <stdio.h>

#define PI 3.141592

const double j = 1.23456789;
main() {
	//PI = 3.141592; //에러발생
	//j = 1.23456789; //에러발생

	printf("실수형 상수 PI의 값은 %f\n", PI);
	printf("실수형 상수 j의 값은 %j\n", j);
}
//프로그램 내에서 변경되지 않는 값을 선언하거나, 사용된 값이 바뀔 경우가 있을 경우.
//문자형<정수형<실수형.