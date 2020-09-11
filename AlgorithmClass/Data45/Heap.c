#include <stdio.h>
//Max Heap
int data[20] = { 0,6,3,5,7,10,1,2 }; //index0=0;
//data[i]<-->data[j]
void swap(int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
void findLocation(int cur_idx, int lastIdx) {
	//���� �ڽİ� ������ �ڽ��� index�� ���
	int leftIdx = cur_idx * 2;
	int rightIdx = leftIdx + 1;
	int biggest = cur_idx; //cur_idx, leftIdx, rightIdx �߿��� ���� ū ���� ���� ����� �ε���
	//���ʰ� ������ �߿��� ��� ���� cur_idx�� ���� ��庸�� �� ū ���� ������ �Ǵ�
	if (leftIdx <= lastIdx && data[leftIdx] > data[cur_idx]) { //�迭������ �̳����� �Ѵ�.
		biggest = leftIdx;
	}
	if (rightIdx <= lastIdx && data[rightIdx] > data[biggest]) { //biggest���� Ŀ�� �ȴ�.
		biggest = rightIdx;
	}
	if (biggest == cur_idx) { //��ġ��� �� �ִ�.
		return;
	}
	else {
		//cur_idx�� �ڱ� �ڸ��� ������ ��ġ�� biggest�� �ڸ��� �ٲ��ش�.
		swap(cur_idx, biggest); //���� �ٲ� �ε����� ����.
		findLocation(biggest, lastIdx); //�ٲ۰� �������鼭 �ٽ�Ȯ��.
	}
}

void heapify(int lastIdx) {
	int cur_idx = lastIdx / 2; //�ؾ��� ������ ����� �θ� �� �� �ִ�.
	while (cur_idx >= 1) {
		//cur_idx�� ����Ű�� ��尡 maxheap���� ���ڸ��� ã���� ��迭
		findLocation(cur_idx, lastIdx);
		cur_idx--; //���� ��ĭ�� �ű�
	}
}

int main(void) {
	printf("Before heapify:%d\n", data[1]);

	heapify(7);

	printf("After heapify:%d\n", data[1]);
	return 0;
}