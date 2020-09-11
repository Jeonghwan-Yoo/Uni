//정수형 포인터와 실수형 포인터의 값을 모두 대입할 수 있는 포인터를 정의하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i;
	double d = 3.14;

	int *pi;
	double *pd;
	void *pv;

	pi = &i;
	printf("정수 값 i:%d\n", *(int*)pi);
	pd = &d;
	printf("실수 값 d:%f\n", *(double*)pd);
	pi = &d; //warning?
	printf("실수 값 d:%f\n", *(double*)pi);
	pv = &i;
	printf("정수 값 i:%d\n", *(int*)pv);
	pv = &d;
	printf("실수 값 d:%f\n", *(double*)pv);
}
//void 포인터는 모든 포인터형을 수용할 수 있는 최고로 막강한 포인터입니다.
//한 가지가 아닌 여러 가지 형의 포인터를 전달받고자 할 때 사용.
//반드시 어떤 데이터형으로 사용되든지 캐스트 연산자를 사용하여 지정해야 합니다.
