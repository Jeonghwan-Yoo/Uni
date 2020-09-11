#include <stdio.h>
#include <stdlib.h>

void main() {
	int *k; //k is pointer.
	k = (int*)malloc(100); //k has memory and the size of it is 100.
	char *m;
	m = (char*)malloc(sizeof(char));

	*k = 1; //pointing value of k is 1.
	*m = 1;
	printf("%d %d %d %d\n", k, *k, m, *m);
	free(k); //deallocating memory of k.
	free(m);
}