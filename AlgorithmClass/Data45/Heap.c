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
	int biggest = cur_idx; //cur_idx, leftIdx, rightIdx 중에서 가장 큰 값을 가진 노드의 인덱스
	//왼쪽과 오른쪽 중에서 어느 쪽이 cur_idx를 갖는 노드보다 더 큰 값을 갖는지 판단
	if (leftIdx <= lastIdx && data[leftIdx] > data[cur_idx]) { //배열사이즈 이내여야 한다.
		biggest = leftIdx;
	}
	if (rightIdx <= lastIdx && data[rightIdx] > data[biggest]) { //biggest보다 커야 된다.
		biggest = rightIdx;
	}
	if (biggest == cur_idx) { //위치대로 잘 있다.
		return;
	}
	else {
		//cur_idx가 자기 자리로 가도록 위치를 biggest와 자리를 바꿔준다.
		swap(cur_idx, biggest); //값만 바꿈 인덱스는 같음.
		findLocation(biggest, lastIdx); //바꾼거 내려가면서 다시확인.
	}
}

void heapify(int lastIdx) {
	int cur_idx = lastIdx / 2; //해야지 마지막 노드의 부모를 알 수 있다.
	while (cur_idx >= 1) {
		//cur_idx가 가리키는 노드가 maxheap에서 제자리를 찾도록 재배열
		findLocation(cur_idx, lastIdx);
		cur_idx--; //위로 한칸씩 옮김
	}
}

int main(void) {
	printf("Before heapify:%d\n", data[1]);

	heapify(7);

	printf("After heapify:%d\n", data[1]);
	return 0;
}