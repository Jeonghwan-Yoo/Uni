//"21", "1004.5" 등 소수점이 포함된 문자열을 실수로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string1 = "2.1은 1.0보다 큽니다.";
	char* string2 = "1004.5는 천사.오 입니다.";
	char* string3 = "2005년도 입니다.";
	char* string4 = "오늘은 6월 9일입니다.";
	double t1, t2, t3, t4;

	puts(string1);
	puts(string2);
	puts(string3);
	puts(string4);

	t1 = atof(string1);
	t2 = atof(string2);
	t3 = atof(string3);
	t4 = atof(string4);

	printf("문자열을 숫자로 변환한 값 : %.1f, %.1f, %.1f, %.1f\n", t1, t2, t3, t4);
	printf("총 합은 %.2f입니다.\n", t1 + t2 + t3 + t4);
}
//double atof(const char* string);
//string은 소수점을 포함하고 있는 문자열입니다.
//변환 가능한 문자열은 공백, 탭, 기호, 숫자, 소수점 그리고 지수(d,D,e,E)입니다.
//변환되는 값이 없는 경우 0.0을 반환합니다.
//atof()는 최대 100자리의 문자열을 숫자로 변환할 수 있습니다.