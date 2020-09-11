//컴퓨터와 가위 바위 보를 하는 게임 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void check_game(int saram, int computer);

enum{
	GAWI = 1, BAWI, BO 
};

enum {
	WIN=1, LOSE, TIE
};

int point = 15000;

void main(void) {
	int gamer, computer, cheat = 0;
	int COM_gawi_bawi_bo[3] = { 0, };
	int SRM_gawi_bawi_bo[3] = { 0, };

	srand(time(NULL));

	puts("가위 바위 보 게임을 시작합니다.");
	puts("숫자를 누르고 엔터키를 치세요!!");

	for (;;) {
		printf("컴퓨터는 가위:%d회 바위:%d회 보:%d회를 냈습니다.\n",
			COM_gawi_bawi_bo[0], COM_gawi_bawi_bo[1], COM_gawi_bawi_bo[2]);

		printf("게이머는 가위:%d회 바위:%d회 보:%d회를 냈습니다.\n",
			SRM_gawi_bawi_bo[0], SRM_gawi_bawi_bo[1], SRM_gawi_bawi_bo[2]);

		computer = rand() % 3 + 1;
		if (cheat) printf("컴퓨터는 %s를 냅니다.\n",computer==1?"가위":computer==2?"바위":"보");

		printf("현재재산 : %d원\n가위(1) 바위(2) 보(3) 종료(4) --> ", point);

		scanf_s("%d", &gamer);

		if (gamer == 4) {
			puts("가위 바위 보 게임을 종료합니다...");
			return;
		}
		if (gamer == 9) {
			puts("칫트키를 사용합니다.");
			cheat = 1;
		}
		if (gamer < 0 || gamer>4) {
			puts("숫자는 1~4 범위의 값을 입력하세요.");
			continue;
		}

		COM_gawi_bawi_bo[computer - 1]++;
		SRM_gawi_bawi_bo[gamer - 1]++;

		check_game(gamer, computer);
	}
}

void check_game(int gamer, int computer) {
	int flag;
	static int count_win = 0, count_lose = 0;

	switch (gamer) {
	case GAWI:
		flag = computer == BO ? WIN : computer == BAWI ? LOSE : TIE;
		break;
	case BAWI:
		flag = computer == GAWI ? WIN : computer == BO ? LOSE : TIE;
		break;
	case BO:
		flag = computer == BAWI ? WIN : computer == GAWI ? LOSE : TIE;
		break;
	}

	if (flag == WIN) {
		puts("\n^..^ 이겼습니다. 5000원 벌음 ^.^\n");
		point += 5000;
		if (++count_win == 3) {
			puts("3회 연속 이겼습니다. 보너스 10000원 지급\n");
			point += 10000;
		}
		else if (count_win >= 5) {
			puts("5회 연속 이겼습니다. 보너스 30000원 지급\n");
			point += 30000;
		}
		count_lose = 0;
	}
	else if (flag == LOSE) {
		puts("\nㅠ.ㅠ 졌습니다. 5000원 잃음... 우울모드.. \n");
		point -= 5000;

		if (--count_lose == -3) {
			puts("3회 연속 졌습니다. 10000원 잃음\n");
			point -= 10000;
		}
		else if (count_lose <= -5) {
			puts("5회 이상 연속 졌습니다. 30000원 잃음\n");
			point -= 30000;
		}
		count_win = 0;
	}
	else {
		puts("\n-,.- 비겼습니다. 다시 한 번 해봅시당... ^&^\n");
	}
}
//일반적인 지역 변수는 함수가 호출될 때마다 값이 초기화되지만, static에 의해 지정된 변수는 함수가 처음 호출될 때,
//단 한번만 초기화되고, 프로그램이 종료될 때까지 그 값이 계속 유지가 됩니다.
//전역 변수와 다른 점은 전역 변수는 모든 함수에서 사용할 수 있는 변수이지만, count_win과 같은 지역변수는
//check_game()함수 내에서만 전역 변수처럼 사용됩니다. static이 없다면 0으로 초기화됩니다.