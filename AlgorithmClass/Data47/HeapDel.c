//�켱���� ť:�����͵��� �켱������ ������ �ְ� �켱������ ����
//�����Ͱ� ���� ������ �ȴ�. ���� ���� �켱����x ���� �� o.
//����:���߿� ������ �� �켱������ ����.
//ť:���� ������ �� �켱������ ����.
//�켱����ť�� �ùķ��̼� �ý��ۿ� ���� ���. ��� ����� �ð�.
//��Ʈ��ũ Ʈ���� ����, �ü�� �۾������층 � ���.
//�迭 SLL�� ����������, ���� ȿ�� ���� ������ ���̴�.
//�迭�̸� ��� ������ ��������� �Ѵ�.
//������ �ȵ� �迭, ���� O(1), ���� O(n)
//���ĵ� �迭, ���� O(n), ���� O(1)
//������ �ȵ� SLL, ���� O(1), ���� O(n)
//���ĵ� SLL, ���� O(n), ���� O(1)

//Heap�� Tree�� ������ level���� ���ʿ������� �� ���־���ϰ�,
//Max heap�̸� �θ�>�ڽ�, Min heap�̸� �θ�<�ڽ�.
//��Ʈ��忡�� �׻� �켱������ ���� ���.
//heap��ü�� ����ü�� �ƴ� �迭�� ���ؼ� ������ �� �ִ�.
//�ε���0�� ��� ���·� ���������� ������� �迭�� �ִ´�.
//���� �ڽ��� �θ��ε���*2, ������ �ڽ��� �θ��ε���*2+1.
//�ݴ�� ����ε���/2=�θ����� �ε���
//Ȯ���� ���� �Ųٷ� �ڽ��ִ� �θ� ��Ʈ���� ������ �Ʒ������� 
//Ȯ���ϸ鼭 �ö󰣴�. �׸��� ��ȯ���� �ٽ� �ڽ��� Ȯ���Ѵ�.

//findLocation
//���� ���� ��, lastIdx>=leftIdx,rightIdx ���� �迭�� �ִ� ��.

//addToHeap
//lastIdx++���ְ�, v���̶� parent�� ���� ��� ���Ѵ�.

//removeRoot
//

//�������� �׻� ��Ʈ��常 ���������ϴ�.
//�Ǹ���������� ���� ��Ʈ�� ����.
//��Ʈ�������� Ȯ���ϸ鼭 �����´�.
//�� �ڽ� �� ū���̶� �ٲ۴�.


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
	int cur_idx = lastIdx + 1;
	int parent_idx = cur_idx / 2;

	data[cur_idx] = value;
	while (1) {
		if (data[parent_idx] > data[cur_idx]) {
			return;
		}
		else {
			swap(parent_idx, cur_idx);
			cur_idx = parent_idx;
			parent_idx = cur_idx / 2;
			if (parent_idx < 1) {
				return;
			}
		}
	}
}

//��Ʈ�� �����ϴ� �Լ�.
int removeRoot(int lastIdx) {
	int retValue = data[1]; //��Ʈ�� ����(�� ���������� ��ȯ�ϱ� ���ؼ�)
	data[1] = data[lastIdx]; //��Ʈ���� ������ ������ ����.
	findLocation(1, lastIdx - 1); //�ϳ� ���� �����Ƿ�
	return retValue;
}

int main(void) {
	int k;
	printf("Before heapify:%d\n", data[1]);

	heapify(7);

	printf("After heapify:%d\n", data[1]);

	addToHeap(30, 7);

	printf("After adding:%d\n", data[1]);

	addToHeap(40, 8);

	printf("After adding:%d\n", data[1]);

	addToHeap(20, 9);

	printf("After adding:%d\n", data[1]);

	k = removeRoot(10);

	printf("After removing:%d, current root is %d\n", k, data[1]);

	return 0;
}