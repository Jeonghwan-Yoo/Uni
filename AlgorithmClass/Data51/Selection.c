//Selection sort
//가장 작은 것을 찾아서 앞에서부터 채운다.
//키순서대로 앞에서부터.
//가장작은 값의 인덱스를 찾는 함수 + selection sort

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

int findSmallest(int *arr, int start_idx, int sz) {
	int smallest_idx = start_idx;
	int smallest = arr[start_idx]; //초기화
	int i;
	for (i = start_idx;i < sz;i++) {
		if (arr[i] < smallest) {
			smallest = arr[i];
			smallest_idx = i;
		}
	}
	return smallest_idx;
}
void performSelectionSort(int *toBeSorted, int sz) {
	int i, j;
	for (i = 0;i < sz;i++) {
		//가장 작은 것을 찾고, 그것을 앞쪽으로 이동.
		j = findSmallest(toBeSorted, i, sz);
		swap(toBeSorted, i, j);
		printAll(toBeSorted, sz);
	}
}

void main() {

	int data[10] = { 31,24,56,1,4,10,6,76,87,30 };

	printf("---------------------------------\n");
	printf("Before being sorted\n");
	printAll(data, 10);
	printf("---------------------------------\n");
	performSelectionSort(data, 10);
}