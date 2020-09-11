//"대한민국 Korea"에서 한글만 추출하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	unsigned char* string = "대한민국 Korea";
	unsigned char buff[20] = { 0, };
	int i = 0;

	while (*string) {
		if (*string > 127) {
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
}
//한글은 영문자와 달리, 아스키 값이 127보다 큰 2바이트를 사용합니다. 사실 그래픽문자가 있을 수도 있습니다.