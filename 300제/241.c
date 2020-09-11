//임의의 두 개의 파일을 정하여 하나의 파일로 합치는 프로그램을 작성하세요.
#include <stdio.h>

#define FILEREAD 4096

void main(void) {
	FILE* fpR1, *fpR2, *fpW;
	char buff[FILEREAD];
	int len;

	fopen_s(&fpR1, "file8.bin", "rb");

	if (fpR1 == NULL) {
		perror("파일 읽기 개방 에러");
		return;
	}

	fopen_s(&fpR2, "file_copy.bin", "rb");

	if (fpR2 == NULL) {
		perror("파일 읽기 개방 에러");
		return;
	}

	fopen_s(&fpW, "file9.bin", "w+b");

	if (fpW == NULL) {
		perror("파일 쓰기 개방 에러");
		_fcloseall();
		return;
	}

	while (!feof(fpR1)) {
		len = fread(buff, 1, FILEREAD, fpR1);
		if (ferror(fpR1)) {
			perror("파일 읽기 에러 1");
			_fcloseall();
			return;
		}

		if (len > 0) {
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW)) {
				perror("파일 쓰기 에러 1");
				_fcloseall();
				return;
			}
		}
	}
	while (!feof(fpR2)) {
		len = fread(buff, 1, FILEREAD, fpR2);
		if (ferror(fpR2)) {
			perror("파일 읽기 에러 2");
			_fcloseall();
			return;
		}
		if (len > 0) {
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW)) {
				perror("파일 쓰기 에러 2");
				_fcloseall();
				return;
			}
		}
	}
	_fcloseall();

	puts("파일이 성공적으로 합쳐졌습니다.");
}