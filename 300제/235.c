//c:\file.txt ���Ͽ� fwrite() �Լ��� ����Ͽ� "�츮����"�� �� �� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char* string = "�츮����\n";

	fopen_s(&fp, "file7.txt", "w+");

	if (fp != NULL) {
		fwrite(string, 1, strlen(string), fp);
		fwrite(string, 1, strlen(string), fp);
		fwrite(string, 1, strlen(string), fp);
		fclose(fp);
	}
}
//fputs()�� �ٸ� ���� ���̳ʸ� ���� ������ ����� NULL���� �� �� �ִٴ� ���Դϴ�.
//size_t wrtie(const void* buffer, size_t size, size_t count, FILE* stream);
//buffer�� ������ ������, size�� ����� ũ��, count�� ����� ����, stream�� ����� ������ ������.
//�ѹ��� �� ����Ʈ ���� size*count.
//fwrite() �Լ��� �ַ� ���� ������ ó���� �� ���� ���˴ϴ�. ����, ��� ������ �����͸� ������ �� �� ������ �Լ��Դϴ�.
//fwrite()�Լ��� �׻� 3��° �Ű� ������ ���� ��ȯ�մϴ�.