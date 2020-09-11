//아래의 문제에 따른 답안 프로그램을 작성하세요.
//매출 포인트가 20이상인 자료 중에 (본봉+상여금)으로 오름차순 정렬햇을 때 5번째(본봉+상여금)을 출력하시오.
//동일값 발생시 사원번호로 오름차순 정렬하시오(결과값은 수검자 PC의 C:\C_it\data\Ans1.txt파일에 출력되도록 프로그램을 작성)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define DATAFILE "abc0108.txt"
#define ANSWERFILE "Ans1.txt"

typedef struct tagData {
	char no[7];
	char code;
	int hobong;
	char mail[5];
	int bonbong;
	int sangyuikum;
	int kongjeak;
	int mechulak;
	int mechulpoint;
	char insakokwa;
	char kunmjigubun;
	int hap;
}data;

data D[1000], S[1000], T;
int nStartLine, nEndLine;
FILE *fp;
char buff[200];
int i = 0, j, k;

void main(int argc, char *argv[]) {
	if (argc < 3) {
		puts("인수를 입력하십시오.");
		return;
	}
	nStartLine = atoi(argv[1]);
	nEndLine = atoi(argv[2]);

	fp = fopen(DATAFILE, "r");

	if (!fp) {
		perror("파일 개방 에러");
		return;
	}
	while (!feof(fp)) {
		fgets(buff, 200, fp);

		if (ferror(fp)) {
			perror("파일 읽기 에러");
			fclose(fp);
			return;
		}

		if (feof(fp)) break;

		D[i].kunmjigubun = buff[29];
		D[i].insakokwa = buff[28];
		buff[28] = 0;
		D[i].mechulpoint = atoi(&buff[25]);
		buff[25] = 0;
		D[i].mechulak = atoi(&buff[22]);
		buff[22] = 0;
		D[i].kongjeak = atoi(&buff[19]);
		buff[19] = 0;
		D[i].sangyuikum = atoi(&buff[16]);
		buff[16] = 0;
		D[i].bonbong = atoi(&buff[13]);
		buff[13] = 0;
		strncpy(D[i].mail, &buff[9], 4);
		buff[9] = 0;
		D[i].hobong = atoi(&buff[7]);
		D[i].code = buff[6];
		strcpy(D[i].no, &buff[0], 6);
		D[i].hap = D[i].bonbong + D[i].sangyuikum;

		i++;
	}
	fclose(fp);

	j = 0;

	for (i = nStartLine - 1;i < nEndLine;i++) {
		if (D[i].mechulpoint >= 20) {
			S[j++] = D[i];
		}
	}

	for (i = 0;i < j - 1;i++) { //버블 정렬
		for (k = i + 1;k < j;k++) {
			if (S[i].hap > S[k].hap) {
				T = S[i];
				S[i] = S[k];
				S[k] = T;
			}
			else if (S[i].hap == S[k].hap) {
				if (strcmp(S[i].no, S[k].no) > 0) {
					T = S[i];
					S[i] = S[k];
					S[k] = T;
				}
			}
		}
	}
	for (i = 0;i < 10;i++) {
		printf("%3d %6.6s\n", S[i].hap, S[i].no);
	}

	fp = fopen(ANSWERFILE, "w+");
	fprintf(fp,"%d %d %d ", nStartLine, nEndLine, S[4].hap);
	fclose(fp);
}
//버블정렬이란 서로 인접한 레코드 값들끼리 비교한 후, 자리 교환을 통해 정렬해 나가는 방법으로,
//"Sinking, Shifting Sort" 또는 "Transposition Sort"라고도 합니다.
//오름차순=작은 값에서 큰 값순으로 정렬하는 방법.