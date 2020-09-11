#include <stdio.h>

int add(int a, int b) { //덧셈함수
	if (b == 0)  //b=0이면 그냥 a값 출력
		return a;
	int sum = a ^ b; // a와b XOR연산(carry없는 덧셈)
	int carry = (a & b) << 1; //a와b AND연산하고 왼쪽으로 이동(carry추가)
	return add(sum, carry); //sum과 carry로 덧셈 연산
}

int subtract(int a, int b) { //뺄셈함수
	return add(a, add(~b, 1)); //b의 값을 바꿔준다음 1을 더해 2의 보수로 바꿔주고 a와 덧셈 연산
}

int main() {

	int a,b;
	
	printf("Enter number a:"); 
	scanf_s("%d", &a); //a입력
	printf("Enter number b:"); 
	scanf_s("%d", &b); //b입력

	int sum = add(a, b); //a와 b덧셈
	printf("%d + %d = %d \n", a, b, sum);

	int difference = subtract(a, b); //a와 b뺄셈
	printf("%d - %d = %d \n", a, b, difference);

	return 0;
}