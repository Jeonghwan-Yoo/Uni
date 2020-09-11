//두 개의 수를 입력받아 계산하여 저장하고, 그 결과를 모두 합하여 출력하는 계산기 프로그램을 작성하세요.
#include <stdio.h> //puts, gets, printf
#include <string.h> //strlen, memset, memcpy
#include <stdlib.h> //atoi

int push(int value);
int pop(int *value);

#define STACK_MAX 100

typedef struct tagStack {
	int array[STACK_MAX];
	int top;
	int bottom;
} STACK;

STACK s;

void main(void) {
	char buff[100], tmp[100];
	char *op = "+-*/%";
	int index;
	int value1 = 0, value2 = 0;

	s.top = STACK_MAX;

	puts("계산식을 1*2처럼 입력하고 엔터키를 치세요.");
	puts("아무것도 입력하지 않으면 계산이 종료됩니다.");

	for (;;) {
		printf("계산식 : ");
		gets(buff);

		if (strlen(buff) == 0) break;

		memset(tmp, 0, sizeof(tmp));

		index = strcspn(buff, op); //연산자 인덱스를 찾아서 저장.

		memcpy(tmp, buff, index);

		value1 = atoi(tmp);
		value2 = atoi(&buff[index + 1]); //연산자 다음이니까 그 다음 숫자.

		switch (buff[index]) {
		case '+':
			value1 += value2;
			break;
		case '-':
			value1 -= value2;
			break;
		case '*':
			value1 *= value2;
			break;
		case '/':
			value1 /= value2;
			break;
		case '%':
			value1 %= value2;
			break;
		defalue:
			puts("잘못된 연산자를 사용하였습니다.");
			continue;
		}

		if (push(value1) == -1) {
			puts("더 이상 저장할 수 없습니다.");
		}
		printf("%s=%d, s.top=%d\n\n", buff, value1, s.top);
	}
	
	value1 = 0;

	for (;;) {
		if (pop(&value2) == -1) break; //array의 값을 value2에 저장.
		value1 += value2;
	}
	printf("계산의 총합은 %d입니다.\n", value1);
}

int push(int value) {
	if (s.top == 0) return -1;
	s.array[--s.top] = value;
	return 0;
}

int pop(int *value) {
	if (s.top == STACK_MAX) return -1;
	*value = s.array[s.top++];
	return 0;
}
//스택은 Last in First out 큐는 First in First out.
//스택은 보통 계산기 프로그램이나 컴파일러, 구문 분석등에 쓰이고,
//큐는 운영체제의 잡스케쥴러 등에 많이 사용됩니다.
//모든 프로그램에서 사용되는 지역 변수는 내부적으로 스택 알고리즘을 사용하고 있습니다.
//데이터를 삽입하는 동작을 push, 꺼내오는 동작을 pop.
//tmp버퍼를 모두 NULL로 채우는 이유는 atoi() 함수에서 문자열의 끝을 알기 위해서이다.