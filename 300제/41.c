//정수형 변수 saram_A를 정의하고, 그 변수를 대신해서 사용할 수 있는 pointer를 정의하세요.
//그리고 pointer를 saram_A를 가리키도록 설정하고, saram_A를 사용할 곳에 pointer를 사용하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int saram_A = 0;
	int saram_B = 0;
	int *pointer; 
	int *psaram;

	pointer = &saram_A; 
	*pointer = 1;
	printf("%d, %d\n", saram_A, *pointer); //1, 1
	
	psaram = &saram_A;
	*psaram = 2;
	printf("%d, %d, %d\n", saram_A, *pointer, *psaram); //2, 2, 2

	pointer = &saram_B;
	*pointer = 3;
	printf("%d, %d, %d\n", saram_A, saram_B, *pointer); //2, 3, 3

	psaram = &saram_B;
	*psaram = 4;
	printf("%d, %d, %d, %d\n",saram_A,saram_B,*pointer,*psaram); //2, 4, 4, 4
}

//첫 번째 *는 분신이 될거라는 것을 알리고, &로 분신을 만든다. 두 번째 *은 주소의 있는 값을 의미한다.
//c언어는 어셈블리어와 더불어 저수준언어이다. 하드웨어적인 부분과 밀접하게 관련되어 프로그래밍을 하기 때문이다.
//특징이 메모리를 직접 접근하여 사용하는 것이며, 포인터를 사용한다.
//중요한 것은 단 하나의 변수에 대해서만 분신처럼 사용될 수 있다.
//문자열 포인터(char *)에서는 &을 사용하지 않습니다. 문자열 자체가 이미 분신이기 때문입니다.
//문자열을 정의하면 문자열의 본체는 메모리의 어딘가에 저장되고, 분신이 자동적으로 만들어집니다.
//배열 포인터(char [])에서는 초기화만 되고 분신은 아니다. 값만 넘겨받는 것입니다. string이 배열을 대표하는 분신이다.
//&는 번지 지정 연산자라고 한다.
//일반적인 문자형, 정수형, 실수형 등은 모두 번지 연산자 사용, 문자열형, 배열형 등은 사용 안한다.
/*
char str[100]="Korea";
char *pstr;

pstr=str; //&str안된다.
pstr=&str[0]; //str[0] 불가능
pstr=&str[1]; //str[1] 불가능
*/