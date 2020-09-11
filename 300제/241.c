//������ �� ���� ������ ���Ͽ� �ϳ��� ���Ϸ� ��ġ�� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

#define FILEREAD 4096

void main(void) {
	FILE* fpR1, *fpR2, *fpW;
	char buff[FILEREAD];
	int len;

	fopen_s(&fpR1, "file8.bin", "rb");

	if (fpR1 == NULL) {
		perror("���� �б� ���� ����");
		return;
	}

	fopen_s(&fpR2, "file_copy.bin", "rb");

	if (fpR2 == NULL) {
		perror("���� �б� ���� ����");
		return;
	}

	fopen_s(&fpW, "file9.bin", "w+b");

	if (fpW == NULL) {
		perror("���� ���� ���� ����");
		_fcloseall();
		return;
	}

	while (!feof(fpR1)) {
		len = fread(buff, 1, FILEREAD, fpR1);
		if (ferror(fpR1)) {
			perror("���� �б� ���� 1");
			_fcloseall();
			return;
		}

		if (len > 0) {
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW)) {
				perror("���� ���� ���� 1");
				_fcloseall();
				return;
			}
		}
	}
	while (!feof(fpR2)) {
		len = fread(buff, 1, FILEREAD, fpR2);
		if (ferror(fpR2)) {
			perror("���� �б� ���� 2");
			_fcloseall();
			return;
		}
		if (len > 0) {
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW)) {
				perror("���� ���� ���� 2");
				_fcloseall();
				return;
			}
		}
	}
	_fcloseall();

	puts("������ ���������� ���������ϴ�.");
}