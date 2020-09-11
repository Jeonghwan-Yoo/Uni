#include <stdio.h>
#include <stdlib.h>

struct node { //this is SLL with one data
	int i;
	struct node *next;
};

int main(void) {
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node)); //메모리할당
	p->i = 10; //i in node is 10.
	printf("%d\n", p->i);
	free(p); //메모리해제

	return 0;
}