//Quick sort
//�� ���� pivot�� �߽����� �������� ������ ū ���� �ڷ�.
//pivot�� ��ġ�� ã�� ���� �ݺ�.
//left�� pivot���� �ε���, right�� �ǳ��� �ε���.
//left�� pivot�̶� ��, ������ ++left, ũ�� ���
//right�� pivot�̶� ��, ũ�� --right, ������ left�� ���ؼ�
//right>left�̸� swap �ƴϸ�, right�̶� pivot�̶� swap.
//pivot���� ���� ����� ū ��� ���� quick sort �ݺ�.

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

void performQuickSort(int *toBeSorted, int pivot_idx, int left_idx, int right_idx) {
	int left = left_idx;
	int right = right_idx;

	printf("pivot:%d left:%d right:%d\n", pivot_idx, left_idx, right_idx);
	printAll(toBeSorted, 10);

	while (left < right) {
		while ((toBeSorted[pivot_idx] > toBeSorted[left]) && left <= right_idx) { //�����ʳ� �Ѿ��ȵ�.
			left = left + 1;
		}
		while ((toBeSorted[pivot_idx] < toBeSorted[right]) && right >= left_idx) { //���ʳ� �Ѿ�� �ȵ�.
			right = right - 1;
		}
		if (right < left) {
			swap(toBeSorted, pivot_idx, right);
			performQuickSort(toBeSorted, pivot_idx, pivot_idx + 1, right - 1); //right�̶� pivot�̶� �ٲ����Ƿ�.
			performQuickSort(toBeSorted, right + 1, right + 2, right_idx);
		}
		else {
			swap(toBeSorted, left, right);
			printf("----->");
			printAll(toBeSorted, 10);
		}
	}
}

void main() {

	int data[10] = { 31,24,56,1,4,10,6,76,87,30 };

	printf("---------------------------------\n");
	printf("Before being sorted\n");
	printAll(data, 10);
	printf("---------------------------------\n");
	//performQuickSort(data,pivot,left,right)
	performQuickSort(data, 0, 1, 9);
}