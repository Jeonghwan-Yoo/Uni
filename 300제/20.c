//문자열형 상수 KOREA를 정의하고, "대한민국" 대신에 사용하는 프로그램을 작성하세요.
#include <stdio.h>

#define KOREA "대한민국"
#define BOOK "This is a book"

const char* SOCCOR = "나는 축구를 좋아합니다"; //const는 생략 가능. =>char*는 문자열 상수

main() {
	printf("문자열형 상수 KOREA의 값 : %s\n", KOREA);
	printf("문자열형 상수 BOOK의 값 : %s\n", BOOK);
	printf("문자열형 상수 SOCCOR의 값 : %s\n", SOCCOR);
}
//char : 1byte
//short : 2byte
//int : 운영체제마다 다르면 Windows에서는 4byte