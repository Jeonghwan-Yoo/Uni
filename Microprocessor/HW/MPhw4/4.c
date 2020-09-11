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
			binary[i] = n % 2; //2로 나눈 나머지를 배열로 저장(계산법 알고리즘에 따라)
			n = n / 2;
		}
	}
	else if (n < 0)
	{
		for (i = 0;i < SIZE;i++)
		{
			binary[i] = (256 - n) % 2; //2로 나눈 나머지를 배열로 저장(계산법 알고리즘에 따라) 128=-128 이용
			n = n / 2;
		}
	}
	printf("Binary of Given Number is=");
	for (i = i - 1;i >= 0;i--) //역으로 해서 2진수 표현
	{
		printf("%d", binary[i]); //2진수 표현
	}
	for (i = 0; i<SIZE; i++) //1의 보수로서 각비트 전환
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
	onesComp[SIZE] = '\0'; //마지막 비트널
	
	for (i = 0; i <SIZE; i++) //1의보수와 1(carry)을 더하는 연산
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
	twosComp[SIZE] = '\0'; //마지막 비트널
	
	printf("\nOne's complement = ");
	for (i = SIZE-1;i >= 0;i--) //1의 보수 출력
	{
		printf("%d", onesComp[i]); //2진수 표현
	}
	printf("\nTwo's complement = ");
	for (i = SIZE-1;i >= 0;i--) //2의 보수 출력
	{
		printf("%d", twosComp[i]); //2진수 표현
	}
	getch();

	return 0;
}