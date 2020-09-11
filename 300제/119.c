//주소록에 사용되는 이름, 전화번호, 주소를 구조체를 사용하여 정의하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct tagAddress {
	char name[30]; //이름
	char phone[20]; //전화
	char address[100]; //주소ㅓ
}; //중괄호 뒤에 세미콜론을 절대로 빠뜨리지 마세요

void main(void) {
	struct tagAddress ad;

	strcpy(ad.name, "홍길동");
	strcpy(ad.phone, "02-1234-5678");
	strcpy(ad.address, "서울시 양천구 목동아파트 13단지");

	printf("이름 : %s\n", ad.name);
	printf("전화 : %s\n", ad.phone);
	printf("주소 : %s\n", ad.address);
}