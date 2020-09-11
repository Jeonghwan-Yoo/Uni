//122의 배열 변수 ad를 대신하는 포인터를 사용하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct tagAddress {
	char name[30]; //이름
	char phone[20]; //전화
	char address[100]; //주소
};

void main(void) {
	struct tagAddress ad[3];
	struct tagAddress *pad;
	int i;

	pad = ad; //배열 변수이므로 번지지정연산자를 사용하지 않습니다.

	for (i = 0;i < 3;i++) {
		sprintf(pad[i].name, "홍길동 %d", i);
		strcpy(pad[i].phone, "02-1234-5678");
		strcpy(pad[i].address, "서울시 양천구 목동아파트 13단지");
	}

	for (i = 0;i < 3;i++) {
		printf("이름 : %s\n", pad[i].name);
		printf("전화 : %s\n", pad[i].phone);
		printf("주소 : %s\n", pad[i].address);
	}
}

//구조체에 포인터는 함수의 인수로 구조체를 전달할 때 가끔사용됩니다.
//또한, 링크드 리스트라고 알려져 있는 매우 강력한 데이터 저장방법입니다.