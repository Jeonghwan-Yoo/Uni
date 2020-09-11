//0~9까지의 서로 같지 않은 난수 3개를 발생시켜 그 숫자를 순서대로 맞추는 야구 게임 프로그램을 작성하세요.
#include <stdio.h> //fflush, scanf, puts, printf,
#include <time.h> //time
#include <stdlib.h> //srand, rand
#include <memory.h> //memset

void main(void) {
	int com[3] = { 0, };
	int gamer[3] = { 0, };
	int guess[10] = { 0, };
	int count, i;
	int strike, ball;
	char yesno;

	srand(time(NULL));

	puts("야구 게임을 시작합니다.");

	while (1) {
		com[0] = rand() % 10;
		com[1] = rand() % 10;
		com[2] = rand() % 10;
		count = 1;

		if (com[0] == com[1] || com[0] == com[2] || com[1] == com[2]) continue;

		puts("숫자 0~9를 공백으로 분리하여 3개 입력하고 엔터키를 치세요!!");

		memset(guess, 0, sizeof(guess));

		while (1) {
			strike = 0; ball = 0;

			for (i = 0;i < 10;i++) {
				printf("%d ", guess[i]);
			}
			printf("\n3개의 숫자[0~9]를 입력하세요 : ");

			scanf_s("%d %d %d", &gamer[0], &gamer[1], &gamer[2]);

			if (com[0] == gamer[0]) strike++;
			else if (com[0] == gamer[1] || com[0] == gamer[2]) ball++;

			if (com[1] == gamer[1]) strike++;
			else if (com[1] == gamer[0] || com[1] == gamer[2]) ball++;

			if (com[2] == gamer[2]) strike++;
			else if (com[2] == gamer[0] || com[2] == gamer[1]) ball++;

			if (gamer[0] > 9 || gamer[1] > 9 || gamer[2] > 9) {
				puts("입력한 숫자가 너무 큽니다. 0~9를 입력하세요.");
				continue;
			}

			guess[gamer[0]] = 1;
			guess[gamer[1]] = 1;
			guess[gamer[2]] = 1;

			printf("\n[%2d회] %d 스트라이크 %d 볼 \n\n", count, strike, ball);

			if (strike == 3) break;
			count++;
		}

		fflush(stdin);

		printf("게임을 계속하시겠습니까(y/n)?");
		scanf_s("%c", &yesno);

		if (yesno == 'N' || yesno == 'n') break;
	}
}
//fflush로 비우지 않으면 scanf에 영향을 줍니다.