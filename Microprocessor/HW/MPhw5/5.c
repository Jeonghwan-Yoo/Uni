#include<stdio.h>    
#include<string.h>  
#include <stdlib.h>

#define SIZE 8

int main() 
{
	int b,i,m; //���� ����
	char a[SIZE]; //�迭 ����
	unsigned n; 
	
	printf("Enter the number from -128 to 127 : ");
	scanf_s("%d", &n); //n�� �Է�
	if (n >= 0)
	{
		for (i = 0;i < SIZE;i++)
		{
			a[i] = n % 2; //2�� ���� �������� �迭�� ����(���� �˰��� ����)
			n = n / 2;
		}
	}
	else if (n < 0)
	{
		for (i = 0;i < SIZE;i++)
		{
			a[i] = (256 - n) % 2; //2�� ���� �������� �迭�� ����(���� �˰��� ����) 128=-128 �̿�
			n = n / 2;
		}
	}
	printf("Binary of Given Number is=");
	for (i = i - 1;i >= 0;i--) //������ �ؼ� 2���� ǥ��
	{
		printf("%d", a[i]); //2���� ǥ��
	}
	printf("\nWhich bit do you wanna know?");
	scanf_s("%d", &m); //�� ��° ��Ʈ?
	b = a[7] * 128 + a[6] * 64 + a[5] * 32 + a[4] * 16 + a[3] * 8 + a[2] * 4 + a[1] * 2 + a[0] * 1; //�迭�� ���ڷ� ����
	int c=(b& (1 << m - 1)) ? 1 : 0; //���׿����ڸ� ���� ����ũ�� �� ���� c�� ����
	printf("%d\n", c);
	return 0;
}


