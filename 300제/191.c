//숫자 150, 27, 33, 1, 5, 100, 99, 75, 81, 10를 오름차순으로 정렬한 후에 5를 검색하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#include <search.h>

int intcmp(const void* v1, const void* v2);

void main(void) {
	int key = 5, *ptr;
	int array[10] = { 150,27,33,1,5,100,99,75,81,10 };

	qsort(array, 10, sizeof(array[0]), intcmp);
	ptr = bsearch(&key, array, 10, sizeof(array[0]), intcmp);

	if (ptr) {
		puts("5를 찾았습니다.");
	}
}

int intcmp(const void* v1, const void* v2) {
	return (*(int*)v1 - *(int*)v2);
}

//void* bsearch(const void* key, const void* base, size_t num, size_t width, 
//int(__cdecl* compare)(const void* elem1, const void* elem2));
//key:검색할 키 값
//base:검색할 배열의 번지
//num:총 배열 요소의 갯수
//width:배열 요소가 차지하는 크기, int형은 4바이트, double형은 8바이트
//compare:비교 함수, 정수값 및 문자열을 모두 비교하는 함수를 사용 가능합니다.
//검색 실패 시 NULL을 반환
//바이너리 검색 알고리즘은 매우 효율적입니다. 방대한 크기의 배열을 빠르게 검색할 수 있습니다.
//효율은 오름차순으로 정렬된 배열에 의해서 결정됩니다.
//1. 검색 키가 배열의 중앙에 있는 요소와 비교합니다. 2개의 값이 일치한다면 검색이 수행되고, 그렇지 않다면
//검색 키는 배열의 요소보다 작거나 큰 경우입니다.
//2. 검색 키가 배열의 요소보다 작다면 배열의 앞부분 크면 뒷부분에 위치
//3. 검색은 배열의 절반을 범위로 하게 되고, 단계 1로 돌아갑니다.
//bsearch를 하기전에 오름차순으로 정렬되어 있어야 합니다.
//정렬이 안되있다면 NULL을 반환.