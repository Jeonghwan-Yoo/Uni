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
	int biggest = cur_idx; //cur_idx, leftIdx, rightIdx �ֿ��� ���� ū ���� ���� ����� �ε���
	//���ʰ� ������ �߿��� ��� ���� cur_idx�� ���� ��庸�� �� ū ���� ������ �Ǵ�
	if (leftIdx <= lastIdx && data[leftIdx] > data[cur_idx]) {
		biggest = leftIdx;
	}
	if (rightIdx <= lastIdx && data[rightIdx] > data[biggest]) {
		biggest = rightIdx;
	}
	if (biggest == cur_idx) {
		return;
	}
	else {
		//cur_idx�� �ڱ� �ڸ��� ������ ��ġ�� biggest�� �ڸ��� �ٲ��ش�.
		swap(cur_idx, biggest);
		findLocation(biggest, lastIdx);
	}
}

void heapify(int lastIdx) {
	int cur_idx = lastIdx / 2;
	while (cur_idx >= 1) {
		//cur_idx�� ����Ű�� ��尡 maxheap���� ���ڸ��� ã���� ��迭
		findLocation(cur_idx, lastIdx);
		cur_idx--; //���� ��ĭ�� �ű�
	}
}

void addToHeap(int value, int lastIdx) {
	int cur_idx = lastIdx + 1; //��� �ϳ� ����.
	int parent_idx = cur_idx / 2; //������ ����� �θ��� �ε��� Ȯ��.

	data[cur_idx] = value; //�ϴ� �������� �߰�
	while (1) { //���� �߰��� �͸� ��
		if (data[parent_idx] > data[cur_idx]) { //���� �����ϸ�
			return; //�״��
		}
		else { //�ƴϸ�
			swap(parent_idx, cur_idx); //���� ����.
			cur_idx = parent_idx; //���� Ư���� �̿��ؼ� ���� �ܰ� Ȯ��
			parent_idx = cur_idx / 2;
			if (parent_idx < 1) { //�� �ٽ������� ��, root���� ��.
				return;
			}
		}
	}
}

int main(void) {
	printf("Before heapify:%d\n", data[1]);

	heapify(7);

	printf("After heapify:%d\n", data[1]);

	addToHeap(30, 7);

	printf("After adding:%d\n", data[1]);

	addToHeap(40, 8);

	printf("After adding:%d\n", data[1]);

	addToHeap(20, 9);

	printf("After adding:%d\n", data[1]);

	return 0;
}