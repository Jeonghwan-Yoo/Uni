//"12345678"을 비트 연산 XOR을 사용하여 암호화하고 복호화하는 프로그램을 작성하세요.
#include <stdio.h>

#define SECRETKEY "!@#$%^&*()_+=-"

void main(void) {
	int i;
	char string[] = "1234567890";

	puts(string);

	for (i = 0;i < strlen(string);i++) {
		string[i] ^= SECRETKEY[i];
	}

	puts(string);

	for (i = 0;i < strlen(string);i++) {
		string[i] ^= SECRETKEY[i];
	}
	puts(string);
}
//암호화:문서 및 메시지를 다른 사람이 구분할 수 없는 문자 코드로 변경하는 것
//복호화:암호화된 문서 및 메시지를 원래의 형태로 복원하는 것.
//비트연산자는 정수형 변수 값의 개별적인 비트를 다룰 수 있게 해줍니다.
//비트연산자는 정수형인 char, int ,long형에서만 사용 가능.
//C프로그램에서 시스템 하드웨어를 직접다루는 경우에 가장 많이 사용.