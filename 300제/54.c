//정수값 100, 1000, 12345를 오른쪽으로 정렬하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i = 100;
	int j = 1000;
	int k = 12345;

	//정렬을 사용하지 않는 경우
	printf("[%d]\n", i); //[100]
	printf("[%d]\n", j); //[1000]
	printf("[%d]\n", k); //[12345]

	//출력을 5자리 결정
	printf("[%5d]\n", i); //[  100]
	printf("[%5d]\n", j); //[ 1000]
	printf("[%5d]\n", k); //[12345]
	
	//출력을 10자리로 결정
	printf("[%10d]\n", i); //[       100]
	printf("[%10d]\n", j); //[      1000]
	printf("[%10d]\n", k); //[     12345]

	//출력을 10자리로 설정하고 왼쪽 정렬
	printf("[%-10d]\n", i); //[100       ]
	printf("[%-10d]\n", j); //[1000      ]
	printf("[%-10d]\n", k); //[12345     ]

}
//정수값을 10자리 범위로 출력 시 빈 공간을 0으로 채우려면 printf("%010d",i);
//마지막에 "..."이란 것이 있으면 변수의 수가 정해져 있지 않는 경우.
//문자열을 출력하기 위해서는 변환 문자 %s를 사용
//문자열의 경우, 인자는 출력하기 원하는 문자열에 대한 포인터가 되어야 합니다.
//널 문자가 나타날 때까지 문자열을 출력.