/*
ten number is its own number should divide fully like 1234567890 is first unit divides fully and 12 is divides fully, etc.
the number of 0 to 9 should use only once.
Then, what is this number.
Backtracking is try first and if it is failed, go to back and then try the other way.
*/

#include <stdio.h>
#define SZ 9 //10�̸� 20����� �ۿ� �ȵǼ� ������ ���� 0�� Ȯ���ϴϱ� ���ֹ��� last must be 0.

int numbers[SZ]; //declared as array.

void initNumbers(void) { //initialization.
	for (int i = 0;i < SZ;i++) {
		numbers[i] = -1;
	}
}

int makeNumbers(int idx) {
	//numbers={1,2,3,-1,-1,..} ==> 123 ���ڷ� �����
	int sum = numbers[0]; //first unit.
	for (int i = 1;i <= idx;i++) { //1's unit to idx's unit.
		sum = sum * 10 + numbers[i]; //first unit*10+second unit, first and second unit*10+third unit.
	}
	return sum; //return result.
}
//idx ��ġ�� v��� ���ڸ� �ִ´�. �׸��� �ű���� ������� ���ڰ� ���ǿ� �´����� �˻��Ѵ�.
void checkNumber(int v, int idx) { //check the number is whether divided or not.
	//0. ���ڸ� ���� �ִ´�.
	numbers[idx] = v; //put the number in the index.
	//1. idx�տ� v�� ��ġ�� ���ڰ� �ִ��� �˻��Ѵ�.
	//�����ϸ� return.
	for (int i = 0;i < idx;i++) {
		if (numbers[i] == v) { //checking if there is same number or not.
			return; //back-tracking
		}
	}
	//2. numbers[0,..., idx]���� ���ڰ� '����'�� �����ϴ��� �˻��Ѵ�.
	//�����ϸ� return
	if (makeNumbers(idx) % (idx + 1) != 0) { //it should be divided by (idx+1) cuz makeNumbers returns idx+1
		return; //back-tracking
	}
	//Ż������
	if (idx == 8) {
		//���ϴ� ���ڸ� ã����.
		printf("The NUMBER is %d\n", makeNumbers(8));
		return; //back-tracking

	}
	//1���� 2�� ������ ������ ��������� ���� �ܰ�� ����
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