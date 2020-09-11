//배열 array[5]={5,3,1,2,4}일 때, array의 값을 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

int intcmp(const void* v1, const void* v2);

void main(void) {
	int i;
	int array[5] = { 5,3,1,2,4 };

	qsort(array, 5, sizeof(array[0]), intcmp);

	for (i = 0;i < 5;i++) {
		printf("%d ", array[i]);
	}
}

int intcmp(const void* v1, const void* v2) {
	int cmpvalue1, cmpvalue2;

	cmpvalue1 = *(int*)v1;
	cmpvalue2 = *(int*)v2;

	return cmpvalue1 - cmpvalue2;
}
//void qsort(void* base, size_t num, size_t width, int (__cdecl* compare)(const void* elem1, const void* elem2));
//base:정렬할 배열의 번지
//num:총 배열 요소의 갯수
//width:배열 요소가 차지하는 크기, int형은 4바이트, double형은 8바이트
//compare:비교함수, 정수값 및 문자열을 모두 비교하는 함수를 사용 가능합니다.\
//내림차순으로 정렬하려면 return cmpvalue2-cmpvalue1;
//다른 데이터형도 모두 정렬할 수 있습니다.