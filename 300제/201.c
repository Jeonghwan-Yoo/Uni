//scanf()�Լ��� ����Ͽ� ��� ���������� ���� �д� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#pragma warning(disable:4996)

#define scan(d,x,y) printf(#d "��(%"#x")�� �Է��ϼ���\n"); \
					scanf(#x, &y); \
					printf("scanf %"#x":"#x"\n\n", y); //������ �� %�� ���̴����� �ǹ�

void main(void) {
	char ch = 0;
	short int si = 0;
	int i = 0;
	int o8 = 0;
	int x16 = 0;
	unsigned ui = 0;
	long l = 0;
	float f = 0;
	char s[100] = { 0, };

	scan(char, %c, ch);
	scan(short, %hd, si);
	scan(int, %d, i);
	scan(unsigned, %u, ui);
	scan(long, %d, l);
	scan(8����, %o, o8);
	scan(16����, %x, x16);
	scan(�����Ҽ���, %f, f);
	scan(���ڿ�, %s, s);

	scanf("%4d %3d", &i, &o8);
	printf("%d, %d\n", i, o8);
}
//��ũ�� �Լ��� ���� �ٿ� ���� ���� ���� ���� ����(\)�� ����ؾ� �մϴ�.
//%[*][width][{h|l|I64|L}]type
//%*�� ����ϸ�, �Է°� �ϳ��� �����ϰ� �ǳ� �� �� �ֽ��ϴ�.
//Executables:�ü���� ���� ���۵Ǵ� ���α׷�
//Libraries:�ٸ� ���α׷��� ������� �� ����ǵ��� ���۵� �ڵ�
//Dynamic Linked Libraries(DLL):���α׷��� ����ǰ� ���� �� ����� �� �ֵ��� ���۵� �ڵ�
//Controls:�ٸ� ���α׷��� ������ ������ �� �ֵ��� ���۵� �ڵ�