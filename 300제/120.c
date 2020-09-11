//119에서 사용된 ad 변수를 대신하는 포인터를 사용하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct tagAddress {
	char name[30]; //이름
	char phone[20]; //전화
	char address[100]; //주소
};

void main(void) {
	struct tagAddress ad;
	struct tagAddress *pad;

	pad = &ad;

	strcpy((*pad).name, "홍길동");
	strcpy((*pad).phone, "02-1234-5678");
	strcpy((*pad).address, "서울시 양천구 목동아파트 13단지");

	printf("이름 : %s\n", pad->name);
	printf("전화 : %s\n", pad->phone);
	printf("주소 : %s\n", pad->address);
}
//구조체는 일반 변수처럼 사용되기 때문에 번지 지정연산자를 반드시 사용해야 합니다.
//*가 .보다 우선순위가 낮기 때문에 괄호를 묶어주어야 합니다.
//(*pad).name보다는 pad->name이 더 많이 사용된다.