//for loop�̶� �ξ� ���� recursive���� ������ �� ���� ����
/*
Merge sort
bottom up case. time complexity is usually log2(n) and space complexity is twice.
this is exact quick sort but bottom up.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memcpy

#define SZ 10

int data[SZ] = { 34,32,2,3,0,1,8,10,99,7 };

void showData(int *_data) {
	for (int i = 0;i < SZ;i++) {
		printf("%d\n", _data[i]); //print data array.
	}
}

int doMerge(int *copied_data, int f_s, int f_e, int s_s, int s_e, int dst_idx) {
	int f = f_s; //first_start
	int s = s_s; //second_start
	while (f <= f_e && s <= s_e) { //while first start and end and second start and end are same,
		if (data[f] <= data[s]) { //if first data is bigger than second data,
			copied_data[dst_idx] = data[f]; //put the first data to first index of the copied_data.
			dst_idx += 1; //increment dst_idx.
			f += 1; //increment first index.
		}
		else { //if second data is bigger than first data,
			copied_data[dst_idx] = data[s]; //put the second data to first index of the copied_data.
			dst_idx += 1; //increment dst_idx.
			s += 1; //increment second index.
		}
	}
	while (f <= f_e) { //���� ����� ������ ��� ���� ���� ��� �����ؼ� ������. if first block left,
		copied_data[dst_idx] = data[f]; //put the first data to copied_data.
		f += 1; //increment first index.
		dst_idx += 1; //increment dst_idx.
	}
	while (s <= s_e) { //���� ����� ������ ��� ���� ���� ��� �����ؼ� ������. if second block left,
		copied_data[dst_idx] = data[s]; //put the second data to copied_data.
		s += 1; //increment second index.
		dst_idx += 1; //increment dst_idx.
	}
	//������ ����, ���� ���� ��ġ�� ��ȯ�Ѵ�.
	return dst_idx; //return dst_idx for next.
}

int main() {

	printf("--------------before merge sorting--------------\n");
	showData(data); //print original data array.

	//data�� copy���� �ϳ� �����.
	int *copied_data = (int *)malloc(sizeof(int)*SZ); //allocating size to copied_data.
	memcpy(copied_data, data, sizeof(int)*SZ); //memory copy from data to copied_data.

	int step = 1; //���� 1�� ¥�� ������ ���� size is one as initialization.
	int dst_idx = 0; //���� ��ġ�� 0���� ���� index is zero as initialization.
	while (1) {
		if (step >= SZ) { //if step is bigger than total size,
			break; //escape from this.
		}
		for (int i = 0;i < SZ;i += 2 * step) { //step�� �ι踸ŭ Ŀ���� �Ѵ�. 
			int _f_s = i; //first start index.
			int _f_e = i + step - 1; //first end index.
			int _s_s = i + step; //second start index.
			int _s_e = i + 2 * step - 1; //second end index.

			if (_f_e >= SZ - 1) { //merge�� ���� 1��� �ۿ� ����. left last block
				break; //�̹� �������� ������ �ʿ䰡 ����.
			}
			if (_s_e > SZ - 1) { //if second end index should be bigger than SZ-1,
				_s_e = SZ - 1; //second end index set,SZ-1,this last index. ex)7/3 6/4 ..
			}
			dst_idx = doMerge(copied_data, _f_s, _f_e, _s_s, _s_e, dst_idx); //do merge sort until finishing this step. recursive���� ����
		}
		step *= 2; //set next step.
		dst_idx = 0; //set dst_idx to 0 for next step.
		memcpy(data, copied_data, SZ * sizeof(int)); //memory copy back from temp copied_data to original data.
	}
	printf("--------------after merge sorting--------------\n");
	showData(data);
	return 0;
}