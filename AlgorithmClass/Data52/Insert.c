//Insertion sort
//Ư¡���� ��ġ�� ��� �ٲ�.
//�ε����� �ϳ��� Ŀ���� �װ��� �ڱ� ��ġ�� ã���� ������ ��(�����).
//�ε����� 1���� �����ؾ� ����.

#include <stdio.h>

void printAll(int *toBeDisplayed, int size) {
	int i;
	for (i = 0;i < size;i++) {
		printf("%d ", toBeDisplayed[i]);
	}
	printf("\n");
}

void swap(int *arr, int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void performInsertionSort(int *toBeSorted, int sz) {
	int i;
	for (i = 1;i < sz;i++) {
		int j = i;
		while ((j - 1 >= 0) && (toBeSorted[j - 1] > toBeSorted[j])) {
			swap(toBeSorted, j - 1, j);
			j--;
		}printAll(toBeSorted, sz);
	}
}

void main() {

	int data[10] = { 31,24,56,1,4,10,6,76,87,30 };

	printf("---------------------------------\n");
	printf("Before being sorted\n");
	printAll(data, 10);
	printf("---------------------------------\n");
	performInsertionSort(data, 10);
}