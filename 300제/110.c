//���ڿ� "koxea"�� 1���� �迭�� �����ϰ�, �迭�� 3��° ���� 'r'�� �ٲپ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	char one[10] = "Koxea";

	puts(one);
	one[2] = 'r';
	puts(one);

	printf("one[0]=%3d, %c\n", one[0], one[0]);
	printf("one[1]=%3d, %c\n", one[1], one[1]);
	printf("one[2]=%3d, %c\n", one[2], one[2]);
	printf("one[3]=%3d, %c\n", one[3], one[3]);
	printf("one[4]=%3d, %c\n", one[4], one[4]);
	printf("one[5]=%3d, %c\n", one[5], one[5]);
}
//���ڿ��� ������ ��Ÿ���� ���ؼ� �ڵ����� ���� ����.
//char one[]="Koxea"; ó�� ���ڿ��� �ʱ�ȭ�� ���� �迭 ��Ҹ� �����ϴ� ��찡 �����ϴ�. �ڵ����� 6�̵˴ϴ�.(5+��)