//Quick sort
//맨 앞의 pivot을 중심으로 작은값은 앞으로 큰 값은 뒤로.
//pivot의 위치를 찾는 것을 반복.
//left는 pivot다음 인덱스, right는 맨끝의 인덱스.
//left는 pivot이랑 비교, 작으면 ++left, 크면 대기
//right도 pivot이랑 비교, 크면 --right, 작으면 left와 비교해서
//right>left이면 swap 아니면, right이랑 pivot이랑 swap.
//pivot보다 작은 덩어리와 큰 덩어리 각각 quick sort 반복.

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
		while ((toBeSorted[pivot_idx] > toBeSorted[left]) && left <= right_idx) { //오른쪽끝 넘어가면안됨.
			left = left + 1;
		}
		while ((toBeSorted[pivot_idx] < toBeSorted[right]) && right >= left_idx) { //왼쪽끝 넘어가면 안됨.
			right = right - 1;
		}
		if (right < left) {
			swap(toBeSorted, pivot_idx, right);
			performQuickSort(toBeSorted, pivot_idx, pivot_idx + 1, right - 1); //right이랑 pivot이랑 바꿨으므로.
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