//문자열을 입력받고, 입력 받은 문자열 중에 "sky"가 있는지 검색하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

#define SKY "sky"

void main(void) {
	char string[100];
	char* ret;

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("문자열 중에 sky가 포함되어 있으면, 프로그램은 종료됩니다.");

	do {
		gets(string);

		ret = strstr(string, SKY);

		if (ret == NULL) {
			puts("문자열 중에 sky가 없습니다.");
		}
		else {
			printf("%d 위치에서 sky 문자열을 찾았습니다.", ret - string);
			break;
		}
	} while (1);
}
//char* strstr(const char* string, const char* strCharSet);
//strCharSet은 검색할 문자 또는 문자열. 검색 성공 서ㅣ 위치의 포인터 값(번지)를 반환하며 실패시 NULL 반환.
//찾은 위치에 대한 메몰미 번지를 반환하는데, 반환값은 항상 문자 배열 변수 string이 가리키는 번지보다 크거나 같습니다.
//그래서 ret-string을 이용.
//단일 문자 할 때도 더블쿼테이션 이용.