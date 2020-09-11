//근무지 구분에 따른 할인 포인트 A는 10 B는 20 C는 30
//부서 코드가 C인 자료에 대해 (매출 포인트+할인포인트)의 합계를 출력하시오 (Ans4.txt)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATAFILE "abc0108.txt"
#define ANSWERFILE "Ans4.txt"

#pragma warning(disable:4996)

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
	char kunmujigubun;
	int hap;
}data;

data D[1000], S[1000], T;
int nStartLine, nEndLine;
FILE *fp;
char buff[200];
int i = 0;j, k, hap;

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

		D[i].kunmujigubun = buff[29];
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
		strncpy(D[i].no, &buff[0], 6);

		if (D[i].kunmujigubun == 'A') D[i].hap = D[i].mechulpoint + 10;
		if (D[i].kunmujigubun == 'B') D[i].hap = D[i].mechulpoint + 20;
		if (D[i].kunmujigubun == 'C') D[i].hap = D[i].mechulpoint + 30;

		i++;
	}
	fclose(fp);

	j = 0;

	for (i = nStartLine - 1;i < nEndLine;i++) {
		if (D[i].code == 'C') {
			hap += D[i].hap;
		}
	}

	fp = fopen(ANSWERFILE, "w+");
	fprintf(fp, "%d %d %d ", nStartLine, nEndLine, hap);
	fclose(fp);
}