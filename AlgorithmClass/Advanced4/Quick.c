/*
Quick sort
this is log2(n) time complexity, but it could be slower than other sort when it is worst case which is pivot is always the most front.
In the case, over n^2 time complexity by recursive form.
*/
#include <stdio.h>
#include <stdlib.h>

#define SZ 10

int numbers[SZ] = { 15,6,7,34,3,4,20,21,12,9 };

void swap(int *arr, int idx1, int idx2) { //swap function.
	int temp = arr[idx1]; //first value put the temp.
	arr[idx1] = arr[idx2]; //swap each other.
	arr[idx2] = temp; //put the temp.
	return;
}

void qsort(int _pivot, int _left, int _right) { //������ �ε���
	//Ż������(�߸��� �ε����� ���� ���)
	if (_pivot < 0 || _pivot >= SZ) { //pivot index is smaller than 0 or bigger than size of array.
		return;
	}
	if (_left < 0 || _left >= SZ) { //left index is smaller than 0 or bigger than size of array.
		return;
	}
	if (_right < 0 || _right >= SZ) { //right index is smaller than 0 or bigger than size of array.
		return;
	}
	if (_left > _right) { //left index is bigger than right index.
		return;
	}
	if (_pivot > _left) { //pivot index is bigger than left index.
		return;
	}
	//l�� r�� ������Ѿ� �ϱ� ������..
	int l = _left; //left index.
	int r = _right; //right index.

	//�ݺ�
	while (1) { //infinite loop.
		//l�� �̵�
		while (numbers[_pivot] > numbers[l]) { //while pivot number is bigger than left number.
			l += 1; //move l to next l(l+1).
		}
		//r�� �̵�
		while (numbers[_pivot] < numbers[r]) { //while pivot number is smallder than right number.
			r -= 1; //move r to next r(r-1);
		}
		//l<r������ swap
		if (l < r) { //if left index is smaller than right index,
			//int temp = numbers[l]; 
			//numbers[l] = numbers[r];
			//numbers[r] = temp; //�ٽ� �ݺ����� �̵�
			swap(numbers, l, r); //swap left number and right number.
		}
		else { //l>r������ recursive�ϰ� �� �Ŀ� ����
			//pivot�ϰ� �ٲٰ� recursive
			//int temp = numbers[r];
			//numbers[r] = numbers[_pivot];
			//numbers[_pivot] = temp;
			swap(numbers, r, _pivot); //swap right number and pivot number.
			//����
			qsort(_pivot, _pivot + 1, r - 1); //recursively quick sort with different pivot in left side of previous pivot.
			//������
			qsort(r + 1, r + 2, _right); //recursively quick sort with different pivot in right side of previous pivot.
			return;
		}

	}
}

void main() {
	qsort(0, 1, SZ - 1); //pivot index 0, left index 1 and right index SZ-1.
	for (int i = 0;i < SZ;i++) {
		printf("%d ", numbers[i]); //print quick sorted array.
	}
	return;
}