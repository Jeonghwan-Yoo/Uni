/*
ten number is its own number should divide fully like 1234567890 is first unit divides fully and 12 is divides fully, etc.
the number of 0 to 9 should use only once.
Then, what is this number.
Backtracking is try first and if it is failed, go to back and then try the other way.
*/

#include <stdio.h>
#define SZ 9 //10이면 20억까지 밖에 안되서 제한이 있음 0은 확실하니까 없애버림 last must be 0.

int numbers[SZ]; //declared as array.

void initNumbers(void) { //initialization.
	for (int i = 0;i < SZ;i++) {
		numbers[i] = -1;
	}
}

int makeNumbers(int idx) {
	//numbers={1,2,3,-1,-1,..} ==> 123 숫자로 만들기
	int sum = numbers[0]; //first unit.
	for (int i = 1;i <= idx;i++) { //1's unit to idx's unit.
		sum = sum * 10 + numbers[i]; //first unit*10+second unit, first and second unit*10+third unit.
	}
	return sum; //return result.
}
//idx 위치에 v라는 숫자를 넣는다. 그리고 거기까지 만들어진 숫자가 조건에 맞는지를 검사한다.
void checkNumber(int v, int idx) { //check the number is whether divided or not.
	//0. 숫자를 집어 넣는다.
	numbers[idx] = v; //put the number in the index.
	//1. idx앞에 v와 겹치는 숫자가 있는지 검사한다.
	//실패하면 return.
	for (int i = 0;i < idx;i++) {
		if (numbers[i] == v) { //checking if there is same number or not.
			return; //back-tracking
		}
	}
	//2. numbers[0,..., idx]까지 숫자가 '조건'을 만족하는지 검사한다.
	//실패하면 return
	if (makeNumbers(idx) % (idx + 1) != 0) { //it should be divided by (idx+1) cuz makeNumbers returns idx+1
		return; //back-tracking
	}
	//탈출조건
	if (idx == 8) {
		//원하는 숫자를 찾았음.
		printf("The NUMBER is %d\n", makeNumbers(8));
		return; //back-tracking

	}
	//1차와 2차 관문을 무사히 통과했으면 다음 단계로 진입
	for (int i = 1;i <= 9;i++) {
		checkNumber(i, idx + 1); //if first number passed, then try next index.
	}
}

int main(void) {
	initNumbers();
	/*
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 5;
	printf("%d\n", makeNumbers(2));
	*/

	for (int i = 1;i <= 9;i++) {
		checkNumber(i, 0); //number 1 to 9.
	}
	return 0;
}