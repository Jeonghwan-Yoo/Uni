//�޸𸮸� 100����Ʈ �Ҵ��ϰ�, ���ڿ� "MEMORY"�� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MEMORY "MEMORY"

void main(void) {
	char* pmem;

	pmem = malloc(100);

	if (pmem == NULL) {
		puts("�޸𸮸� �Ҵ��� �� �����ϴ�.");
	}
	else {
		strcpy_s(pmem, sizeof(MEMORY), MEMORY);
		puts(pmem);

		free(pmem);
	}
}
//void* malloc(unsigned int size);
//size�� �������� �Ҵ��ϰ��� �ϴ� �޸��� ũ��.
//�Ҵ�� �޸𸮸� ����ų ������ ������ ������ ����.
//malloc()�� �Ҵ�� ���۸� �ʱ�ȭ���� �ʱ� ������ ���ۿ��� ������ ���� �����ϸ�, memset()�� �̿��� �� �ִ�.
//free()�� �ؾ� �ڿ��� �ȸ��ڸ� �� �ִ�.
//32��Ʈ �ü������ �ִ� 4GB �Ҵ�.
//�����Ͱ� NULL���� Ȯ���ؾ� �Ѵ�.