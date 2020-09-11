/*
selection problem
what is the k-th number of n number sorted by up?
use Quick sort.
concept is using pivot index. If pivot index is euqal to the index which we wanna know, that index number is the number.
Unless, only do left or right in pivot index. We don't have to sort all.
time complexity: n+n/2+n/4+n/8+...+=2n. But the worst case would be n+n-1+n-2+..+=n^2.
good division is 1/2 bad is 1/2 same.
*/

//나같으면 정렬을 하고, k번째 값을 호출?
#include <stdio.h>
#define SZ 15

int numbers[SZ] = { 15,20,34,54,32,57,45,87,43,21,5,7,2,1,3 };

void doSelection(int _pivot, int _left, int _right, int _which) { //pivot index, left index, right index, index which we wanna know
	//escape conditioning
	if (_pivot < 0 || _pivot >= SZ || _left < 0 || _left >= SZ || _right < 0 || _right >= SZ || (_left >= _right)) {
		printf("found location %d, which is %d\n", _which, numbers[_which]);
		return;
	}
	//quick sort
	int left = _left;
	int right = _right;
	while (1) {
		while (numbers[_pivot] > numbers[left]) { //if pivot index is smaller than left index,
			left += 1; //move left index. Finally, pointing big number.
		}
		while (numbers[_pivot] < numbers[right]) { //if pivot index is bigger than right index,
			right -= 1; //move right index. Finally, pointing small number.
		}
		if (left < right) { //if left index is smaller than right index,
			int temp = numbers[left]; //swap right and left index.
			numbers[left] = numbers[right];
			numbers[right] = temp;
		}
		else { //if left index is bigger than right index,
			if (right == _which) { //if right is the index which we know,
				printf("found %d number is %d\n", right, numbers[_pivot]);
				return;
			}
			else {
				//first of all, change pivot and right.
				int temp = numbers[_pivot];
				numbers[_pivot] = numbers[right];
				numbers[right] = temp;
				//Judge the index is left or right
				if (_which < right) { //if left side, only search left.
					doSelection(_pivot, _pivot + 1, right - 1, _which); //only search left.
				}
				else { //if right side, only search right.
					doSelection(_right + 1, _right + 2, _right, _which); //only search right.
				}
				return;
			}
		}
	}
}
int main() {
	doSelection(0, 1, SZ - 1, 5);
	return 0;
}