//237에서 생성된 file.bin파일을 file_copy.bin파일로 복사하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fpR, *fpW;
	char buff;
	int len;

	fopen_s(&fpR, "file8.bin", "rb");

	if (fpR == NULL) {
		perror("파일 읽기 개방 에러");
		return;
	}
	
	fopen_s(&fpW, "file_copy.bin", "w+b");

	if (fpW == NULL) {
		perror("파일 쓰기 개방 에러");
		fclose(fpR); //이미 개방된 fpR을 닫음
		return;
	}

	while (!feof(fpR)) {
		len = fread(&buff, 1, 1, fpR);
		if (ferror(fpR)) {
			perror("파일 읽기 에러");
			_fcloseall();
			return;
		}
		if (len > 0) { //if(!feof(fpR)) 
			fwrite(&buff, 1, 1, fpW);
			if (ferror(fpW)) {
				perror("파일 쓰기 에러");
				_fcloseall();
				return;
			}

		}
	}
	_fcloseall();

	puts("파일을 성공적으로 복사하였습니다.");
}
//len>0이 아니라면 파일의 끝에 도달한 것입니다.
//보통은 char buff[4096]; fread(buff,1,4096,fpR); 이나 1024