//매출 포인트가 20이상인 자료 중에 (본봉+상여금)값 중 가장 큰 값을 출려하되,
//만약 동일 값 발생시는 한번만 출력하시오(Ans2.txt)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define DATAFILE "abc0108.txt"
#define ANSWERFILE "Ans2.txt"

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
		D[i].hap = D[i].bonbong + D[i].sangyuikum;
		
		i++;
	}
	fclose(fp);

	j = 0;

	for (i = nStartLine - 1;i < nEndLine;i++) { //매출액 20인 것만 찾아서 S에 저장
		if (D[i].mechulpoint >= 20) {
			S[j++] = D[i];
		}
	}

	for (i = 0;i < j - 1;i++) {
		for (k = i + 1;k < j;k++) {
			if (S[i].hap < S[k].hap) {
				T = S[i];
				S[i] = S[k];
				S[k] = T;
			}
		}
	}
	fp = fopen(ANSWERFILE, "w+");
	fprintf(fp, "%d %d %d", nStartLine, nEndLine, S[0].hap);
	fclose(fp);
}
//정렬이란, 키를 이용하여 정해진 순서에 따라 재배열하는 것.
//키는 레코드 내의 특정 필드를 사용할 수 있다.
//삽입 정렬은 순차적으로 한 레코드씩 가져와서 서로 비교한 후, 크기에 따라 순서대로 정렬하는 방법
//정렬하고자 하는 데이터가 어느 정도 정렬이 되어 있을 경우에 매우 효과적.
//셀렉션 정렬(Interchange sort)라도고 하며, 처음 자료의 값과 Rn까지 차례대로 비교하여 자료의 크기에 따라 정렬해간다.