//��Ʈ ���� XOR�� ����Ͽ� ������ ��ȣȭ�ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

int encryption(char *filename) {
	char data[1024];
	char secret[16] = { "!@#$%^&*()-_><,." };
	FILE *fp;
	unsigned int read_size, i;
	long frpos, fwpos; //������ �а� �� ��ġ�� ������ ����.

	fopen_s(&fp, filename, "r+b"); //("r+t")�� �����ϸ� ��ȣȭ�� ����� ���� ���� �� �ִ�.

	if (fp == NULL) {
		perror("���� ���� ����");
		return -1;
	}

	while (!feof(fp)) {
		fwpos = ftell(fp); //fread()�� ������, ���� �����ʹ� �ڵ����� ���� ���̸�ŭ �̵�. fwpos�� ��ġ�� �����ϰ� ��ȣȭ�� �Ŀ� �ٽ� ����.
		read_size = fread(data, 1, 1024, fp); //1024����Ʈ ��ŭ �н��ϴ�.

		if (read_size == 0) break; //������ ���� ��� 0�� ��ȯ

		for (i = 0;i < read_size;i++) {
			data[i] ^= secret[i % 16]; //������ ��ȣȭ�մϴ�.
		}

		frpos = ftell(fp); //�ٽ� ���� ��ġ�� frpos�� ����.

		fseek(fp, fwpos, SEEK_SET); //��ȣȭ�� �����͸� ������ ��ġ�� ���� �����͸� �̵�.
		fwrite(data, 1, read_size, fp); //��ȣȭ�� �����͸� ���ϴ�.

		fseek(fp, frpos, SEEK_SET); //���� �����͸� �б� ���� ���� �����͸� �̵��մϴ�.
	}
	fclose(fp);

	return 1;
}

void main(int argc, char *argv[]) {
	encryption(argv[1]);
}
//1�� �����ϸ� ��ȣȭ, �ѹ� �� �ϸ� ��ȣȭ.
//��ȣȭ �˰������� DES, 3DES, IDEA, MD5���� �ִ�.