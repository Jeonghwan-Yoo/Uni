//String search
//abcdefgijklmno:n efg:m (n-m+1)m=O(n*m-m^2+m)=O(n*m)
//Rabin-karp algorithm
//Hashing:글자에 대응하는 것을 숫자로. ex)a:1 b:2... g:7 h(x)=sun(x). 역은 성립안함.
//무조건 hashing값이 맞아야한다.
//a+b+c->b+c+d를 b+c는 냅두고 -a+d한다. 새로운 hashing값이 바로바로 나온다. (n-m+1)2=O(n*2-m^2+m)=O(n)
//hashing function에 따라 엄청 다를수 있다. -> 겹치지않는 hashing fucntion 이용해야 한다. 1*128^2+2*128+3.
//바로앞의 계산한 (hashing값에 -a*128^2)*128+d
//64를 안쓰는이유:뒤에 더해지면서 누적되다가 겹칠수도있음 256을 선호...
//1. hashing
//2. 빠른 hash 계산
//3. 겹치지 않는 해쉬값.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 7
#define PATTERN_LENGTH 3

char *str = (char*)"abcdefg";
char *pattern = (char*)"def";

int rabinKarpHash(char out, char in, int oldHash, int highestOrder) {
	//3글자에 대해 (oldHash-out*128^2)*128+in
	printf("oldHash is %d\n", oldHash);
	return ((oldHash - (out << (highestOrder * BASE))) << BASE) + in;
}

//_s[_start] ~ _s[_end]까지의 hash 함수를 계산한다.
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

