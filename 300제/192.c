//void main(void)대신 program으로 시작하는 프로그램을 작성하세요.
#include <stdio.h>

#define program void main(void)
#define println printf

#define MAX 1000
#define MIN 0

program{
	println("MAX:%d, MIN:%d\n",MAX,MIN);
}
//#define을 이용하여 모든 데이터형에 대한 상수값을 선언할 수 있습니다.