#include <stdio.h>

void print_array(int *parray, int len) {
	int i;
	for (i = 0;i < len;i++) {
		printf("%d ", parray[i]);
	}
	printf("\n");
}

void insert_sort(int *array, int n) {
	int i, j, temp_value;
	print_array(array, 10);

	//array[1]~array[n-1]
	for (i = 1;i < n;i++) {
		temp_value = array[i];

		for (j = i;j > 0;j--) {
			if (array[j - 1] <= temp_value) break;
			array[j] = array[j - 1];
		}
		array[j] = temp_value;
	}
	print_array(array, 10);
}

void select_sort(int *array, int n) {
	int i, j, index, temp_value;

	print_array(array, 10);

	//array[0]~array[n-2]
	for (i = 0;i < n - 1;i++) {
		index = i;
		temp_value = array[i];

		for (j = i + 1;j < n;j++) {
			if (temp_value > array[j]) {
				temp_value = array[j];
				index = j;
			}
		}

		array[index] = array[i];
	}
	print_array(array, 10);
}

void main(void) {
	int array[10] = { 6,4,32,3,2,451,24,5,12,64 };
	print_array(array,10);

	printf("insert\n");
	insert_sort(array, 10);
	printf("select\n");
	select_sort(array, 10);
}