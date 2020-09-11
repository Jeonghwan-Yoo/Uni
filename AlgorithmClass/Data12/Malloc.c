//Dangling pointer:A pointer to a freed space
/*
pointer *p, *q;
p=malloc(size); p->�� p�� �޸𸮸� �Ҵ�ް� �װ��� ����Ų��.
q=p; q�� p�� ����Ű�� ���� ����Ų��. p,q->��
free(q); q�� ����Ű�� ���� �޸𸮸� �����Ѵ�. p�� ����.
p now becomes a dangling pointer
����� �� ���� ������ ����Ŵ.
*/

//Unreferenced space:a space with no pointer
/*
pointer *p,*q;
p=malloc(size); p->��
q=malloc(size); q->��
p=q; �� p,q->�� ������ ���� �ִ�.
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
	p = (struct node *)malloc(sizeof(struct node)); //p->��
	free(p);
	return;
}
