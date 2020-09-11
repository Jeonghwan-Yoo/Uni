#include <stdio.h>

int hanoiNum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return 1 + 2*hanoiNum(n - 1);
	}
}

/*n개의 접시를 from 막대에서 to 막대까지 옮긴다.
이때, tmp 막대를 임시로 사용해도 된다.*/
void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) { //나머지도 계속 분해하면 결국 한개를 옮겨야 된다.
		printf("Move dish from %c to %c\n", from, to);
		return;
	}
	else {
		hanoi(n - 1, from, to, tmp); //제일 밑빼고 나머지를 중간에 옮겨놓고
		hanoi(1, from, tmp, to); //제일 밑에 있는 것을 최종 목적지에 옮겨놓고
		hanoi(n - 1, tmp, from, to); //중간에 있는 것을 최종 목적지에 옮겨놓는다.
	}
}

int main(void) {
	char poleA = 'A';
	char poleB = 'B';
	char poleC = 'C';
	//막대 poleA에 접시 3개가 있는데,
	//이것을 poleC로 모두 옮겨라.
	//이 때, poleB를 임시로 사용할 수 있다.
	hanoi(3, poleA, poleB, poleC);

	return 0;
}