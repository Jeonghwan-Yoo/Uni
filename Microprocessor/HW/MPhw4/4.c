#include<stdio.h>    
#include<string.h>  
#include <stdlib.h>
#define SIZE 8

int main() {
	char binary[SIZE+1], onesComp[SIZE + 1], twosComp[SIZE + 1];
	int carry = 1;
	int i;
	unsigned n;

	printf("Enter the number from -128 to 127 : ");
	scanf_s("%d", &n);
	
	if (n >= 0)
	{
		for (i = 0;i < SIZE;i++)
		{
			binary[i] = n % 2; //2�� ���� �������� �迭�� ����(���� �˰��� ����)
			n = n / 2;
		}
	}
	else if (n < 0)
	{
		for (i = 0;i < SIZE;i++)
		{
			binary[i] = (256 - n) % 2; //2�� ���� �������� �迭�� ����(���� �˰��� ����) 128=-128 �̿�
			n = n / 2;
		}
	}
	printf("Binary of Given Number is=");
	for (i = i - 1;i >= 0;i--) //������ �ؼ� 2���� ǥ��
	{
		printf("%d", binary[i]); //2���� ǥ��
	}
	for (i = 0; i<SIZE; i++) //1�� �����μ� ����Ʈ ��ȯ
	{
		if (binary[i] == 1)
		{
			onesComp[i] = 0; 
		}
		else if (binary[i] == 0)
		{
			onesComp[i] = 1;
		}
	}
	onesComp[SIZE] = '\0'; //������ ��Ʈ��
	
	for (i = 0; i <SIZE; i++) //1�Ǻ����� 1(carry)�� ���ϴ� ����
	{
		if (onesComp[i] == 1 && carry == 1)
		{
			twosComp[i] = 0;
		}
		else if (onesComp[i] == 0 && carry == 1)
		{
			twosComp[i] = 1;
			carry = 0;
		}
		else
		{
			twosComp[i] = onesComp[i];
		}
	}
	twosComp[SIZE] = '\0'; //������ ��Ʈ��
	
	printf("\nOne's complement = ");
	for (i = SIZE-1;i >= 0;i--) //1�� ���� ���
	{
		printf("%d", onesComp[i]); //2���� ǥ��
	}
	printf("\nTwo's complement = ");
	for (i = SIZE-1;i >= 0;i--) //2�� ���� ���
	{
		printf("%d", twosComp[i]); //2���� ǥ��
	}
	getch();

	return 0;
}