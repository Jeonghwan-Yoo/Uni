//문자열 "abcde"의 길이를 구하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>

int length(char* pstr);

main() {
	int len = length("abcde");

	printf("길이 = %d", len); //길이 = 5
}

int length(char* pstr) {
	int len = 0;

	while (*pstr != NULL) {
		pstr++; //pstr의 번지를 1만큼 증가.
		len++; //문자열의 길이를 1만큼 증가.
	}
	return len;
}
//*은 간접 지정 연산자. 가리키는 번지에 저장되어 있는 값.
//더블 쿼테이션으로 둘러 쌓인 모든 문자열의 끝은 항상 널로 종료된다.
//포인터 변수에 대한 증감연산자는 포인터가 가리키는 데이터형의 크기만큼 증가된다. char*:1, int*:4, 구조체는 구조체 크기만큼.
//문자열 또는 문자형 배열은 증감 연산자 사용 시 무조건 1씩 증감된다.