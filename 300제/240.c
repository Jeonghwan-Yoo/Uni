//237���� ������ file.bin������ file_copy.bin���Ϸ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fpR, *fpW;
	char buff;
	int len;

	fopen_s(&fpR, "file8.bin", "rb");

	if (fpR == NULL) {
		perror("���� �б� ���� ����");
		return;
	}
	
	fopen_s(&fpW, "file_copy.bin", "w+b");

	if (fpW == NULL) {
		perror("���� ���� ���� ����");
		fclose(fpR); //�̹� ����� fpR�� ����
		return;
	}

	while (!feof(fpR)) {
		len = fread(&buff, 1, 1, fpR);
		if (ferror(fpR)) {
			perror("���� �б� ����");
			_fcloseall();
			return;
		}
		if (len > 0) { //if(!feof(fpR)) 
			fwrite(&buff, 1, 1, fpW);
			if (ferror(fpW)) {
				perror("���� ���� ����");
				_fcloseall();
				return;
			}

		}
	}
	_fcloseall();

	puts("������ ���������� �����Ͽ����ϴ�.");
}
//len>0�� �ƴ϶�� ������ ���� ������ ���Դϴ�.
//������ char buff[4096]; fread(buff,1,4096,fpR); �̳� 1024