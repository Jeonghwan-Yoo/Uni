//����ü�� �Ʒ��� 4~9��° �ٰ� ���� �����ϰ�, ����ü ���� x1, x2�� �����ϼ���.
//�׸���, x1 ����ü�� ���� ������ ��, x1 ����ü�� x2 ����ü�� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

struct tagM1 {
	int x;
	int y;
	char buffer[30];
};

void main(void) {
	struct tagM1 x1, x2;

	x1.x = 5;
	x1.y = 10;

	strcpy_s(x1.buffer, sizeof("memory copy"), "memory copy");

	memcpy(&x2, &x1, sizeof(x1));

	puts(x2.buffer);
}
//void* memcpy(void* dest, const void* src, unsigned int count);
//dest�� ����� ����, src�� ������ ����, count�� ������ src�� �޸��� ũ��.
//strcpy()�� ���ڿ��� ����, memcpy()�� �޸𸮸� ����.
//memcpy()�� ���ۿ� ���� �ִ� ��쿡�� ������ ���̸�ŭ ��� �����մϴ�.