//����ð� ����
#include <stdio.h>
#include <time.h> //clock() <-- ȣ���� ���� clock count
				  //���� <-- clock(100),, �� <-- clock(2000)
				  //clock count --> 2000-100=1900

void main() {
	clock_t start_time, end_time; //int, char
	int i;
	double k = 0.0;

	start_time = clock(); //start clock.

	//duration --> clock count
	//duration/CLOCKS_PER_SEC --> �� ����

	//Work
	for (i = 1;i < 1000000;i++) {
		k = (k*k*k) / (double)i;
	}

	end_time = clock(); //end clock for this algorithm
	printf("%d\n", (end_time - start_time) / CLOCKS_PER_SEC); //this is for seconds.
	printf("%d\n", end_time - start_time); //this is for the clock count.
}