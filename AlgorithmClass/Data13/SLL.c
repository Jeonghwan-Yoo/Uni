#include <stdio.h>
#include <stdlib.h>

struct node { //this is SLL with one data
	int i;
	struct node *next;
};

int main(void) {
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node)); //�޸��Ҵ�
	p->i = 10; //i in node is 10.
	printf("%d\n", p->i);
	free(p); //�޸�����

	return 0;
}