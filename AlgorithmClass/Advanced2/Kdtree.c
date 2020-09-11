/*
K-Dimensional tree
1. sorting array based on x and finding median which would be root.
2. left side of root is left subtree and right side of root is right subtree.
3. sorting subtrees based on y and finding median which would be parent nodes.
4. repeating 2. and alternately 1. and 3.
*/
#include <stdio.h> //printf
#include <stdlib.h> //malloc
//���������ʹ� �׻� �״�� ���ΰ� �ּҷ� �غ���.
//Linked list
struct node { //SSL root struct
	int x; //value for x.
	int y; //value for y.
	struct node *next; //point next node.
};

struct node *head = 0; //nothing to point(null)

//kd-tree�� root�� ����Ű�� root pointer
struct kdtree_node *kd_root = 0; //nothing to point(null)

//kd-tree�� ��� ����ü�� ����
struct kdtree_node { //SSL kdtree struct
	struct node *data; //SSL point
	struct kdtree_node *left; //point next left of kdtree
	struct kdtree_node *right; //point next right of kdtree
};

//linked list�� ��尡 �� �� �ִ����� ���� �Լ�
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

//array�� ��� �ּҵ��� xȤ��y���� ���� ������������ ����
//_byX�� 1�̸� x�� ���ؼ� 0�̸� y�� ���ؼ� ����
//_size:array�� ����
void doBubbleSort(struct node **_array, int _byX, int _size) { //array, x or y, array size.
	int i = 0;
	int j = 0;

	for (j = 0;j < _size;j++) { //bubble sort sorting one at once.
		for (i = 0;i < _size - 1 - j;i++) { //(0,1) (1,2), ..... it should check it out if swap or not. -1 is for first two number and -j for fixed number.
			if (_byX == 1) { //x�� ���ؼ� �� for x
				if (_array[i]->x > _array[i + 1]->x) { //if former foor x is bigger than latter for x,
					//swap
					struct node *temp = _array[i]; //making new temp.
					_array[i] = _array[i + 1]; //swap each other.
					_array[i + 1] = temp;
				}
			}
			else { //y�� ���ؼ� �� for y
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
	//Ż�� ����
	if (from > to) { //if putting index wrong,
		return 0; //return it.
	}
	struct node *cur = _array[from]; //intialization.
	cur->next = 0; //��������� ����ؼ� �ٿ��ֱ� ����
	struct node *temp = cur; //putting cur into temp for not changing original data.
	for (int i = from + 1;i <= to;i++) { //for loop for making new sorted points.
		temp->next = _array[i]; //next of temp should be next of array.
		temp->next->next = 0; //initialize next temp point.
		temp = temp->next; //next temp.
	}
	return cur; //returning new sorted points.
}

//kd-tree�� �����س��� �Լ�
//��ȯ:������ kdtree node�� ��ȯ�Ѵ�.
//�Է�:kdtree�� �� linked list
//		depth����:x�� Ȥ�� y�࿡ ���ؼ� ���� ����
//		dimension:�������� ����, 2���� ���� ��� 2
struct kdtree_node *build_kdtree(struct node *sll, int _depth, int _dimension) {
	//Ż�� ����
	if (sll == 0) { //if no SLL,
		return 0; //return 0.
	}
	//1. SLL ������ �ּҸ� array�� �����Ѵ�.
	//SLL�� ��� ����� ������ �����´�.
	int numSLLNodes = howManyNodes(sll); //checking how many nodes have.

	//��� �ּҵ��� ���� array�� �Ҵ��Ѵ�.
	struct node **nodeAddrArray = (struct node**)malloc(sizeof(struct node *)*numSLLNodes); //making array spaces which have SLL addresses.

	//array���ٰ� ��� �ּҵ��� �ϳ��� �ִ´�.
	int i;
	struct node *temp = sll; //head�� �����Ǿ�� �Ѵ�. root should not change.
	for (i = 0;i < numSLLNodes;i++) {
		nodeAddrArray[i] = temp; //putting node address to array.
		temp = temp->next; //pointing next node.
	}

	//����
	//nodeAddrArray�� �̿��ؼ� SLL ������ ���� ��� ���
	//for (i = 0;i < numSLLNodes;i++) {
	//	int _x = nodeAddrArray[i]->x;
	//	int _y = nodeAddrArray[i]->y;
	//	printf("%d,%d\n", _x, _y);
	//}

	// x�� Ȥ�� y�࿡ ���ؼ� �����ϴ��� ����
	int axis = _depth % _dimension; //axis is repeatitive.

	doBubbleSort(nodeAddrArray, !axis, numSLLNodes); //2���� ��(2!=0) sorting the array by bubblesort

	int _median = numSLLNodes / 2; //picking median out of the array.

	//�������� kdtree������
	struct kdtree_node *cur = (struct kdtree_node *)malloc(sizeof(struct kdtree_node)); //cur�� kdtree�� root
	cur->data = nodeAddrArray[_median]; //root should be median by sort.
	cur->left = build_kdtree(rebuildSLL(nodeAddrArray, 0, _median - 1), _depth + 1, 2); //rebuild left side of median by sorting to y, then build again recursively.
	cur->right = build_kdtree(rebuildSLL(nodeAddrArray, _median + 1, numSLLNodes - 1), _depth + 1, 2); //rebuild right side of median by sorting to y, then build again recursively.
	free(nodeAddrArray); //�ٽ����ϱ� free. Memory free.
	return cur; //returning well built points.
}

void addToSLL(int _x, int _y) { //Adding node.
	//�����͸� ������ ��带 �����Ѵ�.
	struct node *new_one = (struct node *)malloc(sizeof(struct node)); //Allocating space for new_one.
	new_one->x = _x; //x value of new_one is argument _x.
	new_one->y = _y; //y value of new_one is argument _y.
	new_one->next = 0; //Nothing to point next.

	//SLL�� new_one�� �߰��Ѵ�.
	if (head == 0) { //if root was Null,
		head = new_one; //root would be this new_one.
		return;
	}
	else //SLL�� ���� ã�Ƽ� �ٿ� �ִ´�. if something is in root
	{
		struct node *temp = head; //making temp node to put root point.
		while (1) { //infinite loop for looking for end of kdtree
			if (temp->next == 0) //�� ���� ã�� ��� if it is the end,
			{
				temp->next = new_one; //���� �ٿ� �ִ´�. put the new_one.
				return;
			}
			else //���� �� �� ��尡 �ƴ� ���
			{
				//�� ���� ���� �̵��Ѵ�.
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
		//���� ������ ��
		if (temp == 0) { //(_x,_y)�� ã�� ���� if there is nothing,
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

//(_x,_y)�� �־����� ��, axis�� ����Ͽ� _root�� left Ȥ�� right�� ���������� ��ȯ
struct kdtree_node *whichWayToGo(struct kdtree_node *_root, int _x, int _y, int axis) {
	if (axis == 0) { //x�� ��
		if (_root->data->x > _x) { //if data x is bigger than x which we wanna know,
			return _root->left; //go to left.
		}
		else //if not,
			return _root->right; //go to right.
	}
	else {  //y�� ��
		if (_root->data->y > _y) { //if data y is bigger than y which we wanna know,
			return _root->left; //go to left.
		}
		else //if not,
			return _root->right; //go to right.
	}
};

struct kdtree_node *whichWayNotToGo(struct kdtree_node *_root, int _x, int _y, int axis) {
	if (axis == 0) { //x�� ��
		if (_root->data->x > _x) { //if data x is bigger than x which we wanna know,
			return _root->right; //go to right.
		}
		else //if data x is bigger than x which we wanna know,
			return _root->left; //go to left.
	}
	else {  //y�� ��
		if (_root->data->y > _y) { //if data y is bigger than y which we wanna know,
			return _root->right; //go to right.
		}
		else //if not,
			return _root->left; //go to left.
	}
};

struct kdtree_node *RealNearestNeighbor(struct kdtree_node *_root, int _x, int _y, int _minDiff, struct kdtree_node *_minDiffNode, int _axis, int _dim) {
	//Ż������
	if (_root == 0) { //if there is nothing any more,
		return _minDiffNode; //return node which have minimum.
	}

	//���� ����Ʈ�� ��Ī�� ���
	if (_root->data->x == _x && _root->data->y == _y) { //if it is matched,
		return _root; //return that node.
	}
	//���� _root�� �Ÿ��� ����Ѵ�.
	int dist = (_root->data->x - _x)*(_root->data->x - _x) + (_root->data->y - _y)*(_root->data->y - _y); //formula of distance in coordinate.
	if (dist < _minDiff) { //if distance is smaller than previous minNode,
		_minDiff = dist; //change the distance
		_minDiffNode = _root; //change the node which have minimum.
	}
	//���� root�� ����, �����̵�, �������̵� ��������.
	struct kdtree_node *wayTo = whichWayToGo(_root, _x, _y, _axis%_dim); //find next node and move there.

	struct kdtree_node *NN = RealNearestNeighbor(wayTo, _x, _y, _minDiff, _minDiffNode, _axis + 1, _dim); //dimension�� ���� _axis�� ��� ��ȭ keeping doing it until temp=0.
	//������ nearest neighbor������ �Ÿ��� ���Ѵ�.
	int dist_to_NN = (NN->data->x - _x)*(NN->data->x - _x) + (NN->data->y - _y)*(NN->data->y - _y); //distance formula in coordinates.
	//nearest neighobr������ �Ÿ��� ��輱�� �Ѵ��� ����.
	if (_axis == 0) { //x�࿡ ���ؼ� �˻�
		if (dist_to_NN > (_x - _root->data->x)*(_x - _root->data->x)) { //if distance of NN is bigger than distance of root.
			//��輱 ������ ���� ���� �ȴ�.
			return RealNearestNeighbor(whichWayNotToGo(_root, _x, _y, _axis%_dim), _x, _y, _minDiff, _minDiffNode, _axis + 1, _dim); //return to different way to find minimum at other side
		}
		else { //if smaller,
			return NN; //nevermind. 
		}
	}
	else { //y�࿡ ���ؼ� �˻�
		if (dist_to_NN > (_y - _root->data->y)*(_y - _root->data->y)) {
			//��輱 ������ ���� ���� �ȴ�.
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

	struct kdtree_node *temp = _root; //_root�� �����̸� �ȵǹǷ�, temp�� ���
	int axis = 0; //x����� ����

	while (1) {
		if (temp == 0) { //Ż�� ����
			return minDiffNode; //return minimum node.
		}
		//(_x,_y)�� temp���� �Ÿ��� ���Ѵ�.
		int dist = (temp->data->x - _x)*(temp->data->x - _x) + (temp->data->y - _y)*(temp->data->y - _y); //distance formula

		//���ο� nearest neighbor�� �߰�
		if (dist < minDiff) { //if distance is smaller than previous distance,
			minDiff = dist; //change to this distance.
			minDiffNode = temp; //change to this node.
		}

		temp = whichWayToGo(temp, _x, _y, axis); //move to the way along this whcihWayToGo

		//���� �񱳸� ���ؼ� axis�� ����
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

	kd_root = build_kdtree(head, 0, 2); //head�� ���� �� ��� ������ ������ �ִ�. ���� root node�� �ּҸ� ��ȯ�Ѵ�.

	printf("(%d,%d)\n", kd_root->data->x, kd_root->data->y);
	printf("(%d,%d)\n", kd_root->left->data->x, kd_root->left->data->y);
	printf("(%d,%d)\n", kd_root->right->data->x, kd_root->right->data->y);
	printf("(%d,%d)\n", kd_root->left->left->data->x, kd_root->left->left->data->y);

	//returns 1 if (1,4) is in kd-tree
	//        0 if not
	//int result = searchKdTree(kd_root, 1, 4);

	//(2,5)�� ����� ���� ã�����ؼ� ������ ������� kd tree�� Ÿ�� �������鼭, ���� ����� ���� ã�Ƽ� �� �����͸� ��ȯ�Ѵ�.
	struct kdtree_node *p = naiveNearestNeighbor(kd_root, 2, 5); //������� �Ƹ��� (4,7)

	printf("Nearest neighbor is %d, %d\n", p->data->x, p->data->y);

	struct kdtree_node *realP = RealNearestNeighbor(kd_root, 2, 5, INT_MAX, 0, 0, 2);

	printf("Real Nearest Neighbor is %d, %d\n", realP->data->x, realP->data->y); //it should print out (2,3)

	return 0;
}