//"2는 1보다 큽니다"처럼 숫자 및 문자로 구성된 문자열을 숫자로 변환하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string1 = "2는 1보다 큽니다.";
	char* string2 = "1004는 천사입니다.";
	char* string3 = "2005년도 입니다.";
	char* string4 = "오늘은 6월 9일입니다.";
	long t1, t2, t3, t4;

	puts(string1);
	puts(string2);
	puts(string3);
	puts(string4);

	t1 = atol(string1);
	t2 = atol(string2);
	t3 = atol(string3);
	t4 = atol(string4);
	
	printf("문자열을 숫자로 변환한 값 : %ld, %ld, %ld, %ld\n", t1, t2, t3, t4);
	printf("총 합은 %d입니다.\n", t1 + t2 + t3 + t4);
}
//long atol(const char* string);
//string은 숫자로 변환될 문자열 버퍼입니다.
//변환 가능한 문자열은 공백, 탭, 기호 그리고 숫자뿐이다.
//변환되는 값이 없는 경우 atol()함수는 0을 반환합니다.
//MS에는 _int64가 존재하는데, 8바이트 메모리를 사용하며, _atoi64()함수를 사용하여 변환을 한다.