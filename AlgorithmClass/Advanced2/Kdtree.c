/*
K-Dimensional tree
1. sorting array based on x and finding median which would be root.
2. left side of root is left subtree and right side of root is right subtree.
3. sorting subtrees based on y and finding median which would be parent nodes.
4. repeating 2. and alternately 1. and 3.
*/
#include <stdio.h> //printf
#include <stdlib.h> //malloc
//원본데이터는 항상 그대로 냅두고 주소로 해보자.
//Linked list
struct node { //SSL root struct
	int x; //value for x.
	int y; //value for y.
	struct node *next; //point next node.
};

struct node *head = 0; //nothing to point(null)

//kd-tree의 root를 가리키는 root pointer
struct kdtree_node *kd_root = 0; //nothing to point(null)

//kd-tree의 노드 구조체를 정의
struct kdtree_node { //SSL kdtree struct
	struct node *data; //SSL point
	struct kdtree_node *left; //point next left of kdtree
	struct kdtree_node *right; //point next right of kdtree
};

//linked list에 노드가 몇 개 있는지를 세는 함수
int howManyNodes(struct node *_head) { //letting to know how many nodes have.
	int cnt = 0; //initialization.
	struct node *temp = _head; //putting the root node to temp.
	while (1) {
		if (temp == 0) //if there is no nodes,
			return cnt; //return cnt,0.
		else { //if there is node,
			cnt++; //add count
			temp = temp->next; //and go to next point.
		}
	}
}

//array에 담긴 주소들을 x혹은y값에 따라 오름차순으로 정렬
//_byX가 1이면 x에 대해서 0이면 y에 대해서 정렬
//_size:array의 길이
void doBubbleSort(struct node **_array, int _byX, int _size) { //array, x or y, array size.
	int i = 0;
	int j = 0;

	for (j = 0;j < _size;j++) { //bubble sort sorting one at once.
		for (i = 0;i < _size - 1 - j;i++) { //(0,1) (1,2), ..... it should check it out if swap or not. -1 is for first two number and -j for fixed number.
			if (_byX == 1) { //x에 대해서 비교 for x
				if (_array[i]->x > _array[i + 1]->x) { //if former foor x is bigger than latter for x,
					//swap
					struct node *temp = _array[i]; //making new temp.
					_array[i] = _array[i + 1]; //swap each other.
					_array[i + 1] = temp;
				}
			}
			else { //y에 대해서 비교 for y
				if (_array[i]->y > _array[i + 1]->y) {
					//swap
					struct node *temp = _array[i];
					_array[i] = _array[i + 1];
					_array[i + 1] = temp;
				}
			}
		}
	}
}

struct node *rebuildSLL(struct node **_array, int from, int to) { //rebuild for putting in the tree.
	//탈출 조건
	if (from > to) { //if putting index wrong,
		return 0; //return it.
	}
	struct node *cur = _array[from]; //intialization.
	cur->next = 0; //끊어버리고 계속해서 붙여넣기 시작
	struct node *temp = cur; //putting cur into temp for not changing original data.
	for (int i = from + 1;i <= to;i++) { //for loop for making new sorted points.
		temp->next = _array[i]; //next of temp should be next of array.
		temp->next->next = 0; //initialize next temp point.
		temp = temp->next; //next temp.
	}
	return cur; //returning new sorted points.
}

//kd-tree를 생성해내는 함수
//반환:생성된 kdtree node를 반환한다.
//입력:kdtree에 들어갈 linked list
//		depth정보:x축 혹은 y축에 대해서 비교할 정보
//		dimension:데이터의 차원, 2차원 점의 경우 2
struct kdtree_node *build_kdtree(struct node *sll, int _depth, int _dimension) {
	//탈출 조건
	if (sll == 0) { //if no SLL,
		return 0; //return 0.
	}
	//1. SLL 노드들의 주소를 array에 저장한다.
	//SLL에 담긴 노드의 개수를 가져온다.
	int numSLLNodes = howManyNodes(sll); //checking how many nodes have.

	//노드 주소들을 담을 array를 할당한다.
	struct node **nodeAddrArray = (struct node**)malloc(sizeof(struct node *)*numSLLNodes); //making array spaces which have SLL addresses.

	//array에다가 노드 주소들을 하나씩 넣는다.
	int i;
	struct node *temp = sll; //head는 고정되어야 한다. root should not change.
	for (i = 0;i < numSLLNodes;i++) {
		nodeAddrArray[i] = temp; //putting node address to array.
		temp = temp->next; //pointing next node.
	}

	//검증
	//nodeAddrArray를 이용해서 SLL 노드들의 값을 모두 출력
	//for (i = 0;i < numSLLNodes;i++) {
	//	int _x = nodeAddrArray[i]->x;
	//	int _y = nodeAddrArray[i]->y;
	//	printf("%d,%d\n", _x, _y);
	//}

	// x축 혹은 y축에 대해서 소팅하는지 결정
	int axis = _depth % _dimension; //axis is repeatitive.

	doBubbleSort(nodeAddrArray, !axis, numSLLNodes); //2차원 용(2!=0) sorting the array by bubblesort

	int _median = numSLLNodes / 2; //picking median out of the array.

	//이제부터 kdtree만들자
	struct kdtree_node *cur = (struct kdtree_node *)malloc(sizeof(struct kdtree_node)); //cur은 kdtree의 root
	cur->data = nodeAddrArray[_median]; //root should be median by sort.
	cur->left = build_kdtree(rebuildSLL(nodeAddrArray, 0, _median - 1), _depth + 1, 2); //rebuild left side of median by sorting to y, then build again recursively.
	cur->right = build_kdtree(rebuildSLL(nodeAddrArray, _median + 1, numSLLNodes - 1), _depth + 1, 2); //rebuild right side of median by sorting to y, then build again recursively.
	free(nodeAddrArray); //다썼으니까 free. Memory free.
	return cur; //returning well built points.
}

void addToSLL(int _x, int _y) { //Adding node.
	//데이터를 저장할 노드를 생성한다.
	struct node *new_one = (struct node *)malloc(sizeof(struct node)); //Allocating space for new_one.
	new_one->x = _x; //x value of new_one is argument _x.
	new_one->y = _y; //y value of new_one is argument _y.
	new_one->next = 0; //Nothing to point next.

	//SLL에 new_one을 추가한다.
	if (head == 0) { //if root was Null,
		head = new_one; //root would be this new_one.
		return;
	}
	else //SLL의 끝을 찾아서 붙여 넣는다. if something is in root
	{
		struct node *temp = head; //making temp node to put root point.
		while (1) { //infinite loop for looking for end of kdtree
			if (temp->next == 0) //맨 끝을 찾은 경우 if it is the end,
			{
				temp->next = new_one; //끝에 붙여 넣는다. put the new_one.
				return;
			}
			else //아직 맨 끝 노드가 아닌 경우
			{
				//그 다음 노드로 이동한다.
				temp = temp->next; //if not, it is going next point.
			}
		}
	}
}
//returns 1 if (_x,_y) is in the kd_tree
//        0 if not
int searchKdTree(struct kdtree_node *_root, int _x, int _y) { //search what we wanna know a node.
	struct kdtree_node *temp = _root; //coping root into temp.
	int axis = 0;

	while (1) {
		//같은 값인지 비교
		if (temp == 0) { //(_x,_y)를 찾지 못함 if there is nothing,
			return 0; //return 0.
		}
		if (temp->data->x == _x && temp->data->y == _y) { //if finding the node,
			return 1; //return 1.
		}
		if (axis == 0) { //compare x coordinates
			if (temp->data->x > _x) { //if value x which we wanna know is smaller than x in the tree, 
				temp = temp->left; //move left.
			}
			else { //if bigger,
				temp = temp->right; //move right.
			}
		}
		else { //axis==1 compare y coordinates
			if (temp->data->y > _y) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		axis = (axis + 1) % 2; //axis should keep changing.
	}//end of while
}

//(_x,_y)가 주어졌을 때, axis를 고려하여 _root의 left 혹은 right로 내려갈지를 반환
struct kdtree_node *whichWayToGo(struct kdtree_node *_root, int _x, int _y, int axis) {
	if (axis == 0) { //x축 비교
		if (_root->data->x > _x) { //if data x is bigger than x which we wanna know,
			return _root->left; //go to left.
		}
		else //if not,
			return _root->right; //go to right.
	}
	else {  //y축 비교
		if (_root->data->y > _y) { //if data y is bigger than y which we wanna know,
			return _root->left; //go to left.
		}
		else //if not,
			return _root->right; //go to right.
	}
};

struct kdtree_node *whichWayNotToGo(struct kdtree_node *_root, int _x, int _y, int axis) {
	if (axis == 0) { //x축 비교
		if (_root->data->x > _x) { //if data x is bigger than x which we wanna know,
			return _root->right; //go to right.
		}
		else //if data x is bigger than x which we wanna know,
			return _root->left; //go to left.
	}
	else {  //y축 비교
		if (_root->data->y > _y) { //if data y is bigger than y which we wanna know,
			return _root->right; //go to right.
		}
		else //if not,
			return _root->left; //go to left.
	}
};

struct kdtree_node *RealNearestNeighbor(struct kdtree_node *_root, int _x, int _y, int _minDiff, struct kdtree_node *_minDiffNode, int _axis, int _dim) {
	//탈출조건
	if (_root == 0) { //if there is nothing any more,
		return _minDiffNode; //return node which have minimum.
	}

	//제일 퍼펙트한 매칭의 경우
	if (_root->data->x == _x && _root->data->y == _y) { //if it is matched,
		return _root; //return that node.
	}
	//지금 _root와 거리를 계산한다.
	int dist = (_root->data->x - _x)*(_root->data->x - _x) + (_root->data->y - _y)*(_root->data->y - _y); //formula of distance in coordinate.
	if (dist < _minDiff) { //if distance is smaller than previous minNode,
		_minDiff = dist; //change the distance
		_minDiffNode = _root; //change the node which have minimum.
	}
	//이제 root를 떠나, 왼쪽이든, 오른쪽이든 내려간다.
	struct kdtree_node *wayTo = whichWayToGo(_root, _x, _y, _axis%_dim); //find next node and move there.

	struct kdtree_node *NN = RealNearestNeighbor(wayTo, _x, _y, _minDiff, _minDiffNode, _axis + 1, _dim); //dimension은 일정 _axis는 계속 변화 keeping doing it until temp=0.
	//결정된 nearest neighbor까지의 거리를 구한다.
	int dist_to_NN = (NN->data->x - _x)*(NN->data->x - _x) + (NN->data->y - _y)*(NN->data->y - _y); //distance formula in coordinates.
	//nearest neighobr까지의 거리가 경계선을 넘는지 본다.
	if (_axis == 0) { //x축에 대해서 검사
		if (dist_to_NN > (_x - _root->data->x)*(_x - _root->data->x)) { //if distance of NN is bigger than distance of root.
			//경계선 저쪽을 뒤져 봐야 된다.
			return RealNearestNeighbor(whichWayNotToGo(_root, _x, _y, _axis%_dim), _x, _y, _minDiff, _minDiffNode, _axis + 1, _dim); //return to different way to find minimum at other side
		}
		else { //if smaller,
			return NN; //nevermind. 
		}
	}
	else { //y축에 대해서 검사
		if (dist_to_NN > (_y - _root->data->y)*(_y - _root->data->y)) {
			//경계선 저쪽을 뒤져 봐야 된다.
			return RealNearestNeighbor(whichWayNotToGo(_root, _x, _y, _axis%_dim), _x, _y, _minDiff, _minDiffNode, _axis + 1, _dim);
		}
		else {
			return NN;
		}
	}
}

struct kdtree_node *naiveNearestNeighbor(struct kdtree_node *_root, int _x, int _y) {
	int minDiff = INT_MAX; //initialization to int max.
	struct kdtree_node *minDiffNode = 0; //initialization.

	struct kdtree_node *temp = _root; //_root를 움직이면 안되므로, temp를 사용
	int axis = 0; //x축부터 시작

	while (1) {
		if (temp == 0) { //탈출 조건
			return minDiffNode; //return minimum node.
		}
		//(_x,_y)와 temp간의 거리를 구한다.
		int dist = (temp->data->x - _x)*(temp->data->x - _x) + (temp->data->y - _y)*(temp->data->y - _y); //distance formula

		//새로운 nearest neighbor를 발견
		if (dist < minDiff) { //if distance is smaller than previous distance,
			minDiff = dist; //change to this distance.
			minDiffNode = temp; //change to this node.
		}

		temp = whichWayToGo(temp, _x, _y, axis); //move to the way along this whcihWayToGo

		//다음 비교를 위해서 axis를 증가
		axis = (axis + 1) % 2; //next axis.
	}
}

int main(void) {
	addToSLL(2, 3);
	addToSLL(5, 4);
	addToSLL(9, 6);
	addToSLL(4, 7);
	addToSLL(8, 1);
	addToSLL(7, 2);

	int num = howManyNodes(head);
	printf("num of SLL nodes:%d\n", num);

	kd_root = build_kdtree(head, 0, 2); //head가 들어가야 할 모든 정보를 가지고 있다. 다음 root node의 주소를 반환한다.

	printf("(%d,%d)\n", kd_root->data->x, kd_root->data->y);
	printf("(%d,%d)\n", kd_root->left->data->x, kd_root->left->data->y);
	printf("(%d,%d)\n", kd_root->right->data->x, kd_root->right->data->y);
	printf("(%d,%d)\n", kd_root->left->left->data->x, kd_root->left->left->data->y);

	//returns 1 if (1,4) is in kd-tree
	//        0 if not
	//int result = searchKdTree(kd_root, 1, 4);

	//(2,5)와 가까운 점을 찾기위해서 순진한 방법으로 kd tree를 타고 내려가면서, 가장 가까운 점을 찾아서 그 포인터를 반환한다.
	struct kdtree_node *p = naiveNearestNeighbor(kd_root, 2, 5); //결과값은 아마도 (4,7)

	printf("Nearest neighbor is %d, %d\n", p->data->x, p->data->y);

	struct kdtree_node *realP = RealNearestNeighbor(kd_root, 2, 5, INT_MAX, 0, 0, 2);

	printf("Real Nearest Neighbor is %d, %d\n", realP->data->x, realP->data->y); //it should print out (2,3)

	return 0;
}