//Stack은 ㅁ에서 아래서 위로 올라오는 느낌, LIFO 나중에 들어온것이 먼저 나간다.
//Stack배열과 포인터 역할을 할 top을 만들고 top=-1로 정의.
//isFull은 top이 마지막배열인 MAX-1일 때, isEmpty는 top이 -1일 때.
//push는 top++후에 값을 stack에 대입, pop은 temp에 값을 저장후 top--후에 stack의 값을 return.
//계산기나 컴파일러에서 사용. 되돌리기, 이전페이지 등등.

//메모리 공간은 총 4가지
//1.데이터영역
//상수, 전역변수, 정적변수
//2.스택
//지역변수
//3.힙
//동적할당(scanf)
//4.코드

//the stack grows and shrinks as functions push and pop local variables.
//there is no need to manage the memory yourself, variables are allocated and freed automatically.
//the tack has size limits.
//stack variables only exiest while the function that created them, is running.
//very fast access.
//don't have to explicitly de-allocate variables.
//local variables only
//limit on stack size(OS-dependnet)
//variables cannot be resized.

//반면에 heap은
//variables can be accessed globally
//no limit on memory size
//(relatively)slower access
//no guaranteed efficient use of space, memory may become fragmented over time as blocks of memory are allocated, then freed.
//you mush manage memory(you're in charge of allocating and freeing variables)
//variables can be resized using realloc()

//class는 heap영역이라 참조복사(유지o)
//struct는 stack영역이라 값복사(유지x)

#define MAXIMUM_STACK_SIZE 10
#define INVALID_VALUE -999
#define true 1
#define false 0
#include <stdio.h>

typedef int boolean;

int stack[MAXIMUM_STACK_SIZE];
int top = -1; //push할 때(top++) 배열 첫번째 인덱스는 0이기 때문에.

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