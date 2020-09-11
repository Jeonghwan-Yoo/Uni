//memset() �Լ��� �����ϼ���.
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

	My_memset(&pt, 0, sizeof(pt)); //�ƽ�Ű0, ��

	printf("x,y :%d,%d\n", pt.x, pt.y);

	My_memset(array, 48, sizeof(array)); //�ƽ�Ű48, ����0

	printf("array[0] ~ array[9]:%c ~ %c\n", array[0], array[9]);
}

void My_memset(void* dest, int c, unsigned count) {
	while (count--) { //�ϳ��� �о���� count�� 0�̵Ǹ� Ż��.
		*(char*)dest = c; //��ġ�� ���� ���� c�� �ٲٰ�
		dest = (char*)dest + 1; //��ġ�� ���� ��ĭ �̵�.
	}
}