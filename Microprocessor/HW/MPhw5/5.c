#include<stdio.h>    
#include<string.h>  
#include <stdlib.h>

#define SIZE 8

int main() 
{
	int b,i,m; //변수 선언
	char a[SIZE]; //배열 선언
	unsigned n; 
	
	printf("Enter the number from -128 to 127 : ");
	scanf_s("%d", &n); //n값 입력
	if (n >= 0)
	{
		for (i = 0;i < SIZE;i++)
		{
			a[i] = n % 2; //2로 나눈 나머지를 배열로 저장(계산법 알고리즘에 따라)
			n = n / 2;
		}
	}
	else if (n < 0)
	{
		for (i = 0;i < SIZE;i++)
		{
			a[i] = (256 - n) % 2; //2로 나눈 나머지를 배열로 저장(계산법 알고리즘에 따라) 128=-128 이용
			n = n / 2;
		}
	}
	printf("Binary of Given Number is=");
	for (i = i - 1;i >= 0;i--) //역으로 해서 2진수 표현
	{
		printf("%d", a[i]); //2진수 표현
	}
	printf("\nWhich bit do you wanna know?");
	scanf_s("%d", &m); //몇 번째 비트?
	b = a[7] * 128 + a[6] * 64 + a[5] * 32 + a[4] * 16 + a[3] * 8 + a[2] * 4 + a[1] * 2 + a[0] * 1; //배열을 숫자로 만듦
	int c=(b& (1 << m - 1)) ? 1 : 0; //삼항연산자를 통해 마스크한 후 값을 c에 저장
	printf("%d\n", c);
	return 0;
}


