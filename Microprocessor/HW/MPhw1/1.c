#include <stdio.h>

int main(void) 
{
	int v = 10;
	int *p = &v;

	
	printf("v=%d, p=%p\n", v, p);
	v = *p++;
	printf("v=%d, p=%p\n", v, p);
	printf("v=%d, p=%p\n", v, p);
	v = (*p)++;
	printf("v=%d, p=%p\n", v, p);
	printf("v=%d, p=%p\n", v, p);
	v = *++p;
	printf("v=%d, p=%p\n", v, p);
	printf("v=%d, p=%p\n", v, p);
	v=++*p;
	printf("v=%d, p=%p\n", v, p);

	return 0;
}




