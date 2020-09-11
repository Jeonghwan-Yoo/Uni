#include <stdio.h>

int add(int a, int b) { //�����Լ�
	if (b == 0)  //b=0�̸� �׳� a�� ���
		return a;
	int sum = a ^ b; // a��b XOR����(carry���� ����)
	int carry = (a & b) << 1; //a��b AND�����ϰ� �������� �̵�(carry�߰�)
	return add(sum, carry); //sum�� carry�� ���� ����
}

int subtract(int a, int b) { //�����Լ�
	return add(a, add(~b, 1)); //b�� ���� �ٲ��ش��� 1�� ���� 2�� ������ �ٲ��ְ� a�� ���� ����
}

int main() {

	int a,b;
	
	printf("Enter number a:"); 
	scanf_s("%d", &a); //a�Է�
	printf("Enter number b:"); 
	scanf_s("%d", &b); //b�Է�

	int sum = add(a, b); //a�� b����
	printf("%d + %d = %d \n", a, b, sum);

	int difference = subtract(a, b); //a�� b����
	printf("%d - %d = %d \n", a, b, difference);

	return 0;
}