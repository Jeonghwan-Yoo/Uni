//124에서 사용된 구조체의 길이를 구하고, 구조체를 널로 초기화하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

struct tagAddress {
	char name[30]; //이름
	char phone[20]; //전화
	char address[100]; //주소
};

typedef struct tagAddress addr;

void main(void) {
	addr ad; //struct tagAddress ad
	int len;

	len = sizeof(addr); //sizeof(struct tagAddress)
	
	printf("구조체 addr의 크기 : %d\n", len);

	memset(&ad, 0, len); //memset(&ad,0,sizeof(addr));
}
//공백으로 초기화하려면 32(0x20)
//sizeof를 이용하면 문자열의 길이가 아닌 차지하고 있는 메모리상의 총 바이트 수
//sizeof는 함수가 아니라 단항 연산자이고, 변수의 이름이나 데이터형을 인수로 받아들이고, 인수로 사용된
//변수나 데이터형의 크기를 바이트 단위로 계산하여 돌려줍니다.