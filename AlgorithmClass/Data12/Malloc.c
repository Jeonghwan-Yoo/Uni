//Dangling pointer:A pointer to a freed space
/*
pointer *p, *q;
p=malloc(size); p->ㅁ p는 메모리를 할당받고 그것을 가리킨다.
q=p; q는 p가 가리키는 곳을 가리킨다. p,q->ㅁ
free(q); q가 가리키는 곳의 메모리를 해제한다. p만 남음.
p now becomes a dangling pointer
사용할 수 없는 공간을 가리킴.
*/

//Unreferenced space:a space with no pointer
/*
pointer *p,*q;
p=malloc(size); p->ㅁ
q=malloc(size); q->ㅁ
p=q; ㅁ p,q->ㅁ 남겨진 ㅁ가 있다.
*/

#include <stdio.h>
#include <stdlib.h>
//C implementation of a singly linked list
struct node {
	int i;
	struct node *next; //this is for next node.
};
void main() {
	//Node creation and deletion
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node)); //p->ㅁ
	free(p);
	return;
}
