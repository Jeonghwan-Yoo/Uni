//time complexity=>count
//ex)f(8)-1+2^1+2^2+2^3+... O(2^n)=>worst
//=>dynamic programming.(table)(memorizing previous value)=>O(n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h> //int64_t
#include <inttypes.h> //print int64

int64_t Fibonacci(int n) { //by recursion.
	if (n == 1 || n == 2) {
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int64_t doFibo(int n, int64_t* memory) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (memory[n] == 0) { //unknown value.
		memory[n] = doFibo(n - 1, memory) + doFibo(n - 2, memory); //storing value as sum of previous values.
	}
	return memory[n]; //known value.
}
int64_t doFiboByDynamicProgramming(int n) { //by DP.
	int64_t* memory = (int64_t*)malloc(sizeof(int64_t)*(n + 1));
	memset(memory, 0, sizeof(int64_t)*(n + 1));
	return doFibo(n, memory);
}

int64_t doFiboByNonRecursionDynamicProgramming(int n) {
	int64_t* memory = (int64_t*)malloc(sizeof(int64_t)*(n + 1));
	memset(memory, 0, sizeof(int64_t)*(n + 1));
	memory[1] = memory[2] = 1;

	for (int i = 3;i <= n;i++) {
		memory[i] = memory[i - 1] + memory[i - 2];
	}
	return memory[n];
}

int main() {
	clock_t time_start, time_end;
	int n = 43;
	time_start = clock();
	int64_t k = Fibonacci(n);


	printf("Fibonacci[%d]:", n);
	printf("%" PRId64 "\n", k);
	time_end = clock();
	printf("%d\n", (time_end - time_start) / CLOCKS_PER_SEC);

	time_start = clock();
	k = doFiboByDynamicProgramming(n);
	printf("Fibonacci[%d]:", n);
	printf("%" PRId64 "\n", k);
	time_end = clock();
	printf("%d\n", (time_end - time_start) / CLOCKS_PER_SEC);

	time_start = clock();
	k = doFiboByNonRecursionDynamicProgramming(n);
	printf("Fibonacci[%d]:", n);
	printf("%" PRId64 "\n", k);
	time_end = clock();
	printf("%d\n", (time_end - time_start) / CLOCKS_PER_SEC);

	return 0;
}