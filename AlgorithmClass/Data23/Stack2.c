//Stack�� ������ �Ʒ��� ���� �ö���� ����, LIFO ���߿� ���°��� ���� ������.
//Stack�迭�� ������ ������ �� top�� ����� top=-1�� ����.
//isFull�� top�� �������迭�� MAX-1�� ��, isEmpty�� top�� -1�� ��.
//push�� top++�Ŀ� ���� stack�� ����, pop�� temp�� ���� ������ top--�Ŀ� stack�� ���� return.
//���⳪ �����Ϸ����� ���. �ǵ�����, ���������� ���.

//�޸� ������ �� 4����
//1.�����Ϳ���
//���, ��������, ��������
//2.����
//��������
//3.��
//�����Ҵ�(scanf)
//4.�ڵ�

//the stack grows and shrinks as functions push and pop local variables.
//there is no need to manage the memory yourself, variables are allocated and freed automatically.
//the tack has size limits.
//stack variables only exiest while the function that created them, is running.
//very fast access.
//don't have to explicitly de-allocate variables.
//local variables only
//limit on stack size(OS-dependnet)
//variables cannot be resized.

//�ݸ鿡 heap��
//variables can be accessed globally
//no limit on memory size
//(relatively)slower access
//no guaranteed efficient use of space, memory may become fragmented over time as blocks of memory are allocated, then freed.
//you mush manage memory(you're in charge of allocating and freeing variables)
//variables can be resized using realloc()

//class�� heap�����̶� ��������(����o)
//struct�� stack�����̶� ������(����x)

#define MAXIMUM_STACK_SIZE 10
#define INVALID_VALUE -999
#define true 1
#define false 0
#include <stdio.h>

typedef int boolean;

int stack[MAXIMUM_STACK_SIZE];
int top = -1; //push�� ��(top++) �迭 ù��° �ε����� 0�̱� ������.

boolean isFull(void) {
	if (top == (MAXIMUM_STACK_SIZE - 1)) {
		return true;
	}
	else return false;
}

boolean isEmpty(void) {
	if (top == -1) {
		return true;
	}
	else return false;
}

boolean push(int v) {
	if (isFull() == true) {
		//stack is full, so it cannot push v
		return false;
	}
	else {
		top++;
		stack[top] = v;
		return true;
	}
}

int pop(void) {
	if (isEmpty() == true) {
		return INVALID_VALUE;
	}
	else {
		int temp = stack[top];
		top--;
		return temp;
	}
}

int main(void) {
	int i;

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);

	for (i = 0;i < 5;i++) {
		printf("%d\n", pop());
	}
	//5, 4, 3, 2, 1
}