#include <stdio.h>

int main(void)
{
	int a[12] = { 0 };
	int *q;
	int i = 0;
	for (i = 0;i < 12;i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
	printf("\n");
	q = &a[2];
	for (i = 0;i < 12;i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
	printf("\n");
	*q = 5;
	for (i = 0;i < 12;i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
	printf("\n");
	q++;
	for (i = 0;i < 12;i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
	printf("\n");
	*q = 7;
	for (i = 0;i < 12;i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
	printf("\n");
	q--;
	for (i = 0;i < 12;i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
	printf("\n");
	*q = 3;
	for (i = 0;i < 12;i++)
	{
		printf("a[%d]=%d\t", i, a[i]);
	}
	printf("\n");
}