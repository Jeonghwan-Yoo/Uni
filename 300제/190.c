//�迭 array[5]={5,3,1,2,4}�� ��, array�� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
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
//base:������ �迭�� ����
//num:�� �迭 ����� ����
//width:�迭 ��Ұ� �����ϴ� ũ��, int���� 4����Ʈ, double���� 8����Ʈ
//compare:���Լ�, ������ �� ���ڿ��� ��� ���ϴ� �Լ��� ��� �����մϴ�.\
//������������ �����Ϸ��� return cmpvalue2-cmpvalue1;
//�ٸ� ���������� ��� ������ �� �ֽ��ϴ�.