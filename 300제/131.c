//문자형 포인터 배열을 3개 정의하고, 그 값을 함수를 통해 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void print(char** ppanimal);

void main(void) {
	char* animal[3];

	animal[0] = "호랑이";
	animal[1] = "사자";
	animal[2] = "토끼";

	print(animal);
}

void print(char** ppanimal) {
	puts(ppanimal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}
//경고 에러인 경우 프로그램은 실행할 수 있지만, 논리적 에러가 발생할 가능성이 아주 높습니다.
//포인터의 포인터는 주로 문자형 포인터 배열을 다룰 때 많이 사용합니다.
//API(Application Progamming Interface)는 현재 사용하고 있는 운영체제에서 응용 프로그램을 만들기 위한 라이브러리.