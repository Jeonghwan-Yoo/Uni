//memset() 함수를 구현하세요.
#include <stdio.h>
#include <string.h>

typedef struct tagPoint {
	int x;
	int y;
} point;

void My_memset(void* dest, int c, unsigned count);

void main(void) {
	point pt = { 5,10 };
	char array[10];

	printf("x,y :%d,%d\n", pt.x, pt.y);

	My_memset(&pt, 0, sizeof(pt)); //아스키0, 널

	printf("x,y :%d,%d\n", pt.x, pt.y);

	My_memset(array, 48, sizeof(array)); //아스키48, 숫자0

	printf("array[0] ~ array[9]:%c ~ %c\n", array[0], array[9]);
}

void My_memset(void* dest, int c, unsigned count) {
	while (count--) { //하나씩 읽어나가며 count가 0이되면 탈출.
		*(char*)dest = c; //위치한 곳의 값을 c로 바꾸고
		dest = (char*)dest + 1; //위치한 곳을 한칸 이동.
	}
}