//���� 150, 27, 33, 1, 5, 100, 99, 75, 81, 10�� ������������ ������ �Ŀ� 5�� �˻��ϴ� ���α׷��� �ۼ��ϼ���.
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
		puts("5�� ã�ҽ��ϴ�.");
	}
}

int intcmp(const void* v1, const void* v2) {
	return (*(int*)v1 - *(int*)v2);
}

//void* bsearch(const void* key, const void* base, size_t num, size_t width, 
//int(__cdecl* compare)(const void* elem1, const void* elem2));
//key:�˻��� Ű ��
//base:�˻��� �迭�� ����
//num:�� �迭 ����� ����
//width:�迭 ��Ұ� �����ϴ� ũ��, int���� 4����Ʈ, double���� 8����Ʈ
//compare:�� �Լ�, ������ �� ���ڿ��� ��� ���ϴ� �Լ��� ��� �����մϴ�.
//�˻� ���� �� NULL�� ��ȯ
//���̳ʸ� �˻� �˰����� �ſ� ȿ�����Դϴ�. ����� ũ���� �迭�� ������ �˻��� �� �ֽ��ϴ�.
//ȿ���� ������������ ���ĵ� �迭�� ���ؼ� �����˴ϴ�.
//1. �˻� Ű�� �迭�� �߾ӿ� �ִ� ��ҿ� ���մϴ�. 2���� ���� ��ġ�Ѵٸ� �˻��� ����ǰ�, �׷��� �ʴٸ�
//�˻� Ű�� �迭�� ��Һ��� �۰ų� ū ����Դϴ�.
//2. �˻� Ű�� �迭�� ��Һ��� �۴ٸ� �迭�� �պκ� ũ�� �޺κп� ��ġ
//3. �˻��� �迭�� ������ ������ �ϰ� �ǰ�, �ܰ� 1�� ���ư��ϴ�.
//bsearch�� �ϱ����� ������������ ���ĵǾ� �־�� �մϴ�.
//������ �ȵ��ִٸ� NULL�� ��ȯ.