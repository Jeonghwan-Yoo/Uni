//Bubble sort
//숫자가 크면 위로 뜨듯이 뒤로간다.
//앞에서부터 앞뒤 비교해가며 스왑한다.
//가장 큰 숫자가 뒤에서부터 정렬된다.

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

void performBubbleSort(int *toBeSorted, int sz) {
	int i, j;
	for (i = 0;i < sz;i++) {
		for (j = 0;j < sz - 1 - i;j++) { //맨 끝에서부터 완성되기 때문에
			if (toBeSorted[j] > toBeSorted[j + 1]) {
				//j<-->j+1
				swap(toBeSorted, j, j + 1);
			}
		}
		printAll(toBeSorted, 10);
	}
}

void main() {

	int data[10] = { 31,24,56,1,4,10,6,76,87,30 };

	printf("---------------------------------\n");
	printf("Before being sorted\n");
	printAll(data, 10);
	printf("---------------------------------\n");
	performBubbleSort(data, 10);
}