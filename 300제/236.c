//235���� ������ "�츮����"�� �о ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char buff[100] = { 0, };
	int len;

	fopen_s(&fp, "file7.txt", "r");

	if (fp != NULL) {
		while (!feof(fp)) {
			len = fread(buff, 1, 9, fp);
			if (ferror(fp) || len < 9) break;
			printf("read : %d, %s", len, buff);
		}
		fclose(fp);
	}
}
//size_t fread(void* buffer, size_t size, size_t count, FILE* stream);
//buffer�� ������ �����͸� ������ ����, size�� ����� ũ��, count�� ����� ����, stream�� ����� ������ ������.
//�� ���� ���� ����Ʈ ���� size*count�Դϴ�.
//������ �д� �� ������ �߻��ϰų�, ���� ũ�Ⱑ 9���� ������ �ͱ⸦ ����ϴ�.
//"rt"�� ��쿡 fread()�� 0x0D, 0x0A�� �ڵ����� ���๮�ڷ� ��ȯ�ؼ� ������ fwrite() ���� �׷����ϴ�.
//"rb"�� ��쿡 fread()�� 0x0D, 0x0A�� ���๮�ڰ� �ƴ� �Ϲ� ���ڷ� �ν��մϴ�.
//"rb"�� ���̳ʸ� ���� ������ �����ϴ� ���̸�, ���๮�� ���� �ڵ� ��ȯ�� �Ͼ�� �ʽ��ϴ�.
//fread()�� �׻� 3��° �Ű� ������ ���� ��ȯ