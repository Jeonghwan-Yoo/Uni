//��ǻ�Ϳ� ���� ���� ���� �ϴ� ���� ���α׷��� �ۼ��ϼ���.
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

	puts("���� ���� �� ������ �����մϴ�.");
	puts("���ڸ� ������ ����Ű�� ġ����!!");

	for (;;) {
		printf("��ǻ�ʹ� ����:%dȸ ����:%dȸ ��:%dȸ�� �½��ϴ�.\n",
			COM_gawi_bawi_bo[0], COM_gawi_bawi_bo[1], COM_gawi_bawi_bo[2]);

		printf("���̸Ӵ� ����:%dȸ ����:%dȸ ��:%dȸ�� �½��ϴ�.\n",
			SRM_gawi_bawi_bo[0], SRM_gawi_bawi_bo[1], SRM_gawi_bawi_bo[2]);

		computer = rand() % 3 + 1;
		if (cheat) printf("��ǻ�ʹ� %s�� ���ϴ�.\n",computer==1?"����":computer==2?"����":"��");

		printf("������� : %d��\n����(1) ����(2) ��(3) ����(4) --> ", point);

		scanf_s("%d", &gamer);

		if (gamer == 4) {
			puts("���� ���� �� ������ �����մϴ�...");
			return;
		}
		if (gamer == 9) {
			puts("ĩƮŰ�� ����մϴ�.");
			cheat = 1;
		}
		if (gamer < 0 || gamer>4) {
			puts("���ڴ� 1~4 ������ ���� �Է��ϼ���.");
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
		puts("\n^..^ �̰���ϴ�. 5000�� ���� ^.^\n");
		point += 5000;
		if (++count_win == 3) {
			puts("3ȸ ���� �̰���ϴ�. ���ʽ� 10000�� ����\n");
			point += 10000;
		}
		else if (count_win >= 5) {
			puts("5ȸ ���� �̰���ϴ�. ���ʽ� 30000�� ����\n");
			point += 30000;
		}
		count_lose = 0;
	}
	else if (flag == LOSE) {
		puts("\n��.�� �����ϴ�. 5000�� ����... �����.. \n");
		point -= 5000;

		if (--count_lose == -3) {
			puts("3ȸ ���� �����ϴ�. 10000�� ����\n");
			point -= 10000;
		}
		else if (count_lose <= -5) {
			puts("5ȸ �̻� ���� �����ϴ�. 30000�� ����\n");
			point -= 30000;
		}
		count_win = 0;
	}
	else {
		puts("\n-,.- �����ϴ�. �ٽ� �� �� �غ��ô�... ^&^\n");
	}
}
//�Ϲ����� ���� ������ �Լ��� ȣ��� ������ ���� �ʱ�ȭ������, static�� ���� ������ ������ �Լ��� ó�� ȣ��� ��,
//�� �ѹ��� �ʱ�ȭ�ǰ�, ���α׷��� ����� ������ �� ���� ��� ������ �˴ϴ�.
//���� ������ �ٸ� ���� ���� ������ ��� �Լ����� ����� �� �ִ� ����������, count_win�� ���� ����������
//check_game()�Լ� �������� ���� ����ó�� ���˴ϴ�. static�� ���ٸ� 0���� �ʱ�ȭ�˴ϴ�.