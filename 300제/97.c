//100���� ������ ���� ������ �� �ִ� �޸𸮸� �Ҵ��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main(void) {
	char* pmem;

	printf("sizeof(int)�� ���̴� %d�Դϴ�.\n", sizeof(int));

	pmem = calloc(100, sizeof(int));

	if (pmem == NULL) {
		puts("�޸𸮸� �Ҵ��� �� �����ϴ�.");
	}
	else {
		puts("������ ���� 100���� ������ ���۰� �Ҵ�Ǿ����ϴ�.");

		free(pmem);
	}
}
//void* calloc(size_t num, size_t size);
//num�� �������� �Ҵ��� ����� ���̸�, size�� ����� ũ���Դϴ�.
//num*size��ŭ �޸𸮸� �Ҵ��� �� �ֽ��ϴ�.
//malloc�� �ٸ��� �Ҵ�� ���۸� ��� 0���� �ʱ�ȭ�Ѵ�.
//malloc(sizeof(int)*num)) = calloc(sizeof(int),num)