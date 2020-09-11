//120에서 사용된 구조체 포인터 pad를 사용하여 주소록을 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void print(struct tagAddress *pad);

struct tagAddress {
	char name[30]; //이름
	char phone[20]; //전화
	char address[100]; //주소
};

void main(void) {
	struct tagAddress ad;

	strcpy(ad.name, "홍길동");
	strcpy(ad.phone, "02-1234-5678");
	strcpy(ad.address, "서울시 양천구 목동아파트 13단지");

	print(&ad);
}

void print(struct tagAddress *pad) {
	printf("이름 : %s\n", pad->name);
	printf("전화 : %s\n", pad->phone);
	printf("주소 : %s\n", pad->address);
}
//포인터를 사용하여 나눗셈, 곱셈, 나머지 연산과 같은 산술 동작을 수행하지 않도록 합시다. 포인터에서는 증감이 허용됩니다.
//포인터의 값이 증가되거나 감소될 때에는 1이나 지정된 값만큼 변화하는 것이 아니라, 포인터가 가리키는 데이터의 크기만큼
//값이 증가되거나 감소된다는 것을 잊지 않도록 합시다.
//배열로 사용되는 변수 즉, 포인터 상수를 증가시키거나 감소시키지 않도록 합시다.
//포인터에 배열의 시작 주소를 할당하고 나서 포인터 변수를 사용합니다.