//String search
//abcdefgijklmno:n efg:m (n-m+1)m=O(n*m-m^2+m)=O(n*m)
//Rabin-karp algorithm
//Hashing:���ڿ� �����ϴ� ���� ���ڷ�. ex)a:1 b:2... g:7 h(x)=sun(x). ���� ��������.
//������ hashing���� �¾ƾ��Ѵ�.
//a+b+c->b+c+d�� b+c�� ���ΰ� -a+d�Ѵ�. ���ο� hashing���� �ٷιٷ� ���´�. (n-m+1)2=O(n*2-m^2+m)=O(n)
//hashing function�� ���� ��û �ٸ��� �ִ�. -> ��ġ���ʴ� hashing fucntion �̿��ؾ� �Ѵ�. 1*128^2+2*128+3.
//�ٷξ��� ����� (hashing���� -a*128^2)*128+d
//64�� �Ⱦ�������:�ڿ� �������鼭 �����Ǵٰ� ��ĥ�������� 256�� ��ȣ...
//1. hashing
//2. ���� hash ���
//3. ��ġ�� �ʴ� �ؽ���.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 7
#define PATTERN_LENGTH 3

char *str = (char*)"abcdefg";
char *pattern = (char*)"def";

int rabinKarpHash(char out, char in, int oldHash, int highestOrder) {
	//3���ڿ� ���� (oldHash-out*128^2)*128+in
	printf("oldHash is %d\n", oldHash);
	return ((oldHash - (out << (highestOrder * BASE))) << BASE) + in;
}

//_s[_start] ~ _s[_end]������ hash �Լ��� ����Ѵ�.
int calcHash(char* _s, int _start, int _end) {
	int sum = 0;
	for (int i = _start;i <= _end;i++) {
		sum = (sum << BASE) + _s[i];
	}
	return sum;
}

int main() {
	//int res = calcHash(str, 0, (PATTERN_LENGTH-1));
	//printf("Hash value is %d\n", res);
	int patternHash = calcHash(pattern, 0, (PATTERN_LENGTH - 1));
	printf("Hash of pattern is %d\n", patternHash);
	int res = calcHash(str, 0, (PATTERN_LENGTH - 1));
	printf("Hash value is %d\n", res);

	int strLen = strlen(str);

	for (int i = 1;i <= strLen - PATTERN_LENGTH + 1;i++) {
		res = rabinKarpHash(str[i - 1],
			str[i + (PATTERN_LENGTH - 1)],
			res,
			(PATTERN_LENGTH - 1));
		if (res == patternHash)
		{
			printf("Found pattern at %d\n", i);
			break;
		}
		printf("Hash value is %d, naive hash: %d\n",
			res,
			calcHash(str, i, (i + PATTERN_LENGTH - 1)));
	}

	return 0;
}

