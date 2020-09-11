//"호랑이", "사자", "토끼"를 포인터 배열에 대입하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char* animal[3];
	char** ppanimal;

	animal[0] = "호랑이";
	animal[1] = "사자";
	animal[2] = "토끼";

	ppanimal = animal;

	puts(animal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}
//분신의 분신. 포인터 배열을 함수에 전달하기 위해서 필요하다.
