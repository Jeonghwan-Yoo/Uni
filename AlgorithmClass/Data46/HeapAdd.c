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
	//왼쪽 자식과 오른쪽 자식의 index를 계산
	int leftIdx = cur_idx * 2;
	int rightIdx = leftIdx + 1;
	int biggest = cur_idx; //cur_idx, leftIdx, rightIdx 주에서 가장 큰 값을 가진 노드의 인덱스
	//왼쪽과 오른쪽 중에서 어느 쪽이 cur_idx를 갖는 노드보다 더 큰 값을 갖는지 판단
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
		//cur_idx가 자기 자리로 가도록 위치를 biggest와 자리를 바꿔준다.
		swap(cur_idx, biggest);
		findLocation(biggest, lastIdx);
	}
}

void heapify(int lastIdx) {
	int cur_idx = lastIdx / 2;
	while (cur_idx >= 1) {
		//cur_idx가 가리키는 노드가 maxheap에서 제자리를 찾도록 재배열
		findLocation(cur_idx, lastIdx);
		cur_idx--; //위로 한칸씩 옮김
	}
}

void addToHeap(int value, int lastIdx) {
	int cur_idx = lastIdx + 1; //노드 하나 증가.
	int parent_idx = cur_idx / 2; //마지막 노드의 부모노드 인덱스 확인.

	data[cur_idx] = value; //일단 마지막에 추가
	while (1) { //새로 추가된 것만 비교
		if (data[parent_idx] > data[cur_idx]) { //힙을 유지하면
			return; //그대로
		}
		else { //아니면
			swap(parent_idx, cur_idx); //값만 스왑.
			cur_idx = parent_idx; //힙의 특성을 이용해서 위에 단계 확인
			parent_idx = cur_idx / 2;
			if (parent_idx < 1) { //또 다시위에랑 비교, root까지 비교.
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