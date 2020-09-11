//������ ���� ���� ����� ���α׷�.
//�츮�� ����ϴ� ���� ����ǥ���, ���⼭�� ����ǥ������� ���.
//ex)5,2,+ =>5+2

#include <stdio.h>
#define STACK_SIZE 10
int stack[STACK_SIZE]; //0, 1, 2, ..., 9

int top = -1;
//return 1:yes 0:no
int isEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull() {
	if (top == STACK_SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(int v) {
	if (isFull() != 1) {
		top++;
		stack[top] = v;
	}
}
//return -999:nothing to pop
int pop() {
	if (isEmpty() == 1) {
		return -999;
	}
	else {
		int v = stack[top];
		top--;
		return v;
	}
}

int main() {
	char c;
	while (1) {
		printf("Enter: ");
		scanf_s("%c", &c, sizeof(c));
		while (getchar() != '\n'); //���ۿ� \n�� �����ֱ⿡ ���� �ι�, ���� �ι��� �Է¹ް� �ȴ�. ���۸� ���� ����
		//fflush(stdin);
		switch (c) {
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
		{
			int v = c - '0';
			push(v); //���ڸ� �޾Ƽ� ���ؿ� ����.
		}
		break;
		case '+':
		case '-':
		case '*':
		case '/':
		{
			int v2 = pop(); //�����ڰ� ������ ���ؿ� �ִ� ���� pop�Ͽ� v2�� ����.
			int v1 = pop(); //pop�Ͽ� v1�� ����.

			switch (c) { //�����ڿ� v2, v1�� ����� ���� �ٽ� ���ؿ� ����.
			case '+':
				push(v1 + v2);
				break;
			case '-':
				push(v1 - v2);
				break;
			case '*':
				push(v1 * v2);
				break;
			case '/':
				push(v1 / v2);
				break;
			}
		}
		break;
		case 'e':
		case 'E':
			printf("This result is %d\n", pop());
			break;
		default:
			break;
		}
	}
	return 0;
}