//비트 연산 XOR을 사용하여 파일을 암호화하는 프로그램을 작성하세요.
#include <stdio.h>

int encryption(char *filename) {
	char data[1024];
	char secret[16] = { "!@#$%^&*()-_><,." };
	FILE *fp;
	unsigned int read_size, i;
	long frpos, fwpos; //파일의 읽고 쓸 위치를 저장할 변수.

	fopen_s(&fp, filename, "r+b"); //("r+t")로 개방하면 암호화가 제대로 되지 않을 수 있다.

	if (fp == NULL) {
		perror("파일 개방 에러");
		return -1;
	}

	while (!feof(fp)) {
		fwpos = ftell(fp); //fread()로 읽으면, 파일 포인터는 자동으로 읽은 길이만큼 이동. fwpos에 위치를 저장하고 암호화한 후에 다시 저장.
		read_size = fread(data, 1, 1024, fp); //1024바이트 만큼 읽습니다.

		if (read_size == 0) break; //파일의 끝인 경우 0을 반환

		for (i = 0;i < read_size;i++) {
			data[i] ^= secret[i % 16]; //파일을 암호화합니다.
		}

		frpos = ftell(fp); //다시 읽을 위치를 frpos에 저장.

		fseek(fp, fwpos, SEEK_SET); //암호화된 데이터를 저장할 위치로 파일 포인터를 이동.
		fwrite(data, 1, read_size, fp); //암호화된 데이터를 씁니다.

		fseek(fp, frpos, SEEK_SET); //다음 데이터를 읽기 위해 파일 포인터를 이동합니다.
	}
	fclose(fp);

	return 1;
}

void main(int argc, char *argv[]) {
	encryption(argv[1]);
}
//1번 실행하면 암호화, 한번 더 하면 복호화.
//암호화 알고리즘으로 DES, 3DES, IDEA, MD5등이 있다.