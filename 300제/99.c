//�޸𸮸� 100����Ʈ �Ҵ��ϰ�, 200����Ʈ�� ���Ҵ��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main(void) {
	char* pmem;

	pmem = malloc(100);

	if (pmem == NULL) {
		puts("�޸𸮸� �Ҵ��� �� �����ϴ�.");
	}
	else {
		printf("�Ҵ�� �޸� ���̴� %d����Ʈ�Դϴ�.\n", _msize(pmem));

		pmem = realloc(pmem, 200);

		if (pmem == NULL) {
			puts("�޸𸮸� �� �Ҵ��� �� �����ϴ�.");
		}
		else {
			printf("���Ҵ�� �޸� ���̴� %d����Ʈ�Դϴ�.\n", _msize(pmem));
		}
		free(pmem);
	}
}
//void* realloc(char* memblock, unsigned int size);
//memblock�� ������ malloc�Լ����� ��ȯ�� �������̸�, size�� ���Ҵ��� �޸��� ũ���Դϴ�.
//�޸� ����� Ȯ���� ���� _msize()�� �̿�.
//calloc�� ���Ҵ��Ϸ��� _expand()�� �̿��Ѵ�.