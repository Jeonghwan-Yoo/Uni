//스텍을 통해 계산기 만드는 프로그램.
//우리가 사용하는 것은 중위표기식, 여기서는 후위표기식으로 계산.
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
		while (getchar() != '\n'); //버퍼에 \n이 남아있기에 문자 두번, 엔터 두번을 입력받게 된다. 버퍼를 비우기 위해
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
			push(v); //숫자를 받아서 스텍에 저장.
		}
		break;
		case '+':
		case '-':
		case '*':
		case '/':
		{
			int v2 = pop(); //연산자가 들어오면 스텍에 있던 값을 pop하여 v2로 저장.
			int v1 = pop(); //pop하여 v1로 저장.

			switch (c) { //연산자와 v2, v1과 계산한 값을 다시 스텍에 저장.
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