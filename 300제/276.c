//���� ����Ʈ�� 20�̻��� �ڷ� �߿� (����+�󿩱�)�� �� ���� ū ���� ����ϵ�,
//���� ���� �� �߻��ô� �ѹ��� ����Ͻÿ�(Ans2.txt)
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
		puts("�μ��� �Է��Ͻʽÿ�.");
		return;
	}

	nStartLine = atoi(argv[1]);
	nEndLine = atoi(argv[2]);

	fp = fopen(DATAFILE, "r");

	if (!fp) {
		perror("���� ���� ����");
		return;
	}

	while (!feof(fp)) {
		fgets(buff, 200, fp);

		if (ferror(fp)) {
			perror("���� �б� ����");
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

	for (i = nStartLine - 1;i < nEndLine;i++) { //����� 20�� �͸� ã�Ƽ� S�� ����
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
//�����̶�, Ű�� �̿��Ͽ� ������ ������ ���� ��迭�ϴ� ��.
//Ű�� ���ڵ� ���� Ư�� �ʵ带 ����� �� �ִ�.
//���� ������ ���������� �� ���ڵ徿 �����ͼ� ���� ���� ��, ũ�⿡ ���� ������� �����ϴ� ���
//�����ϰ��� �ϴ� �����Ͱ� ��� ���� ������ �Ǿ� ���� ��쿡 �ſ� ȿ����.
//������ ����(Interchange sort)�󵵰� �ϸ�, ó�� �ڷ��� ���� Rn���� ���ʴ�� ���Ͽ� �ڷ��� ũ�⿡ ���� �����ذ���.