//c++ 언어에서 사용되는 bool데이터형을 선언하고 사용하는 프로그램을 작성하세요.
#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

main() {
	bool bCondition;

	bCondition = true;

	if (bCondition == true) {
		printf("조건식은 true입니다.");
	}
}
//typedef는 새로운 데이터형을 만드는 경우에 사용.
/*
typedef struct{
	int kor;
	int eng;
	int math;
} SungJuk;

SungJuk SJ; //struct를 사용하지 않아도 된다.
*/
//API(Application Programming Interface):애플리케이션을 개발하기 위한 함수의 집합.
//Windows API:윈도우즈 프로그램을 만들기위해서 사용되는 것. 보통 typedef int INT; 같이 이용한다.