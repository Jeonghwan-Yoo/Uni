//123에서 사용된 구조체 포인터 pad를 사용하여 주소록을 출력하는 함수를 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct tagAddress {
	char name[30]; //이름
	char phone[20]; //전화
	char address[100]; //주소
};

void print(struct tagAddress *pad);

void main(void) {
	struct tagAddress ad[3];
	int i;

	for (i = 0;i < 3;i++) {
		sprintf(ad[i].name, "홍길동 %d", i);
		strcpy(ad[i].phone, "02-1234-5678");
		strcpy(ad[i].address, "서울시 양천구 목동아파트 13단지");
	}

	print(ad);
}

void print(struct tagAddress *pad) {
	int i;

	for (i = 0;i < 3;i++) {
		printf("이름 : %s\n", pad[i].name);
		printf("전화 : %s\n", pad[i].phone);
		printf("주소 : %s\n", pad[i].address);
	}
}
//구조체 포인터를 사용하지 않고 구조체 변수를 통해 전달한다면, 포인터의 전달에 비해 좀 더 시간이 걸릴것이며,
//배열을 전달한다면 그 시간은 더 많이 늘어날 것입니다.