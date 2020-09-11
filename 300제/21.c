//정수형 변수 i를 정의하고, 1로 초기화하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int x = 1;
	int y = 2;
	int z;
	int zz;

	z = x + y;

	zz = printf("z의 값 : %d\n", z); //바로 먼저 출력된다.
	printf("zz의 값 : %d\n",zz); //문자의 개수이고 %d:1, \n:1 힌글:2이다.
}
//조건문에서 ==와 혼돈하지 않기 위해서 if(i==1)<==>if(1==i)를 사용한다.