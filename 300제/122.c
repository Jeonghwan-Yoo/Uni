//구조체 배열을 사용하여 119에서 사용된 주소록을 3개 정의하는 프로그램을 작성하세요.
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
	int i;

	for (i = 0;i < 3;i++) {
		sprintf(ad[i].name, "홍길동 %d", i);
		strcpy(ad[i].phone, "02-1234-5678");
		strcpy(ad[i].address, "서울시 양천구 목동아파트 13단지");
	}

	for (i = 0;i < 3;i++) {
		printf("이름 : %s\n", ad[i].name);
		printf("전화 : %s\n", ad[i].phone);
		printf("주소 : %s\n", ad[i].address);
	}
}
//구조체 배열은 일반 배열과 같은 방법.