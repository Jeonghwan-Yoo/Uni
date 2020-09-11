//우선순위 큐:데이터들이 우선순위를 가지고 있고 우선순위가 높은
//데이터가 먼저 나가게 된다. 들어올 때는 우선순위x 나갈 때 o.
//스텍:나중에 들어오는 게 우선순위가 높다.
//큐:먼저 들어오는 게 우선순위가 높다.
//우선순위큐는 시뮬레이션 시스템에 많이 사용. 대게 사건의 시각.
//네트워크 트래픽 제어, 운영체제 작업스케쥴링 등에 사용.
//배열 SLL다 가능하지만, 가장 효율 적인 구조는 힙이다.
//배열이면 계속 앞으로 움직여줘야 한다.
//정렬이 안된 배열, 삽입 O(1), 삭제 O(n)
//정렬된 배열, 삽입 O(n), 삭제 O(1)
//정렬이 안된 SLL, 삽입 O(1), 삭제 O(n)
//정렬된 SLL, 삽입 O(n), 삭제 O(1)

//Heap은 Tree중 마지막 level에서 왼쪽에서부터 잘 차있어야하고,
//Max heap이면 부모>자식, Min heap이면 부모<자식.
//루트노드에는 항상 우선순위가 높은 노드.
//heap자체는 구조체가 아닌 배열을 통해서 구성할 수 있다.
//인덱스0은 비운 상태로 위에서부터 순서대로 배열에 넣는다.
//왼쪽 자식은 부모인덱스*2, 오른쪽 자식은 부모인덱스*2+1.
//반대로 노드인덱스/2=부모노드의 인덱스
//확인할 때는 거꾸로 자식있는 부모 노트부터 오른쪽 아래서부터 
//확인하면서 올라간다. 그리고 순환으로 다시 자식을 확인한다.

//findLocation
//값을 비교할 때, lastIdx>=leftIdx,rightIdx 여야 배열에 있는 값.

//addToHeap
//lastIdx++해주고, v값이랑 parent의 값을 계속 비교한다.

//removeRoot
//

//힙에서는 항상 루트노드만 삭제가능하다.
//맨마지막노드의 값을 루트에 복사.
//루트에서부터 확인하면서 내려온다.
//두 자식 중 큰값이랑 바꾼다.


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

//루트를 삭제하는 함수.
int removeRoot(int lastIdx) {
	int retValue = data[1]; //루트값 저장(뭘 삭제했을지 반환하기 위해서)
	data[1] = data[lastIdx]; //루트값을 마지막 값으로 대입.
	findLocation(1, lastIdx - 1); //하나 삭제 했으므로
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