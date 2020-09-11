//실수형 변수 d를 정의하고 3.141592를 대입하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	float d;
	double d1;
	double d2;

	d = 3.141592;
	d1 = 1234567890;
	d2 = 'c';

	printf("실수형 변수 d의 값은 %E\n", d);
	printf("실수형 변수 d1의 값은 %E\n", d1);
	printf("실수형 변수 d2의 값은 %10.5E\n", d2);

	double m = 1.2233445566778899112233445566778899;
	printf("실수형 변수의 정밀도:%30.25E", m);

}

//정밀도:소수점 이하 몇 자리까지를 표시하는가.
//float:7
//double:14