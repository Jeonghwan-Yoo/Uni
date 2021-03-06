// Fun Homework #2 regarding multithreaded programming
// Operating System by Prof. Kwangtaek Kim, Fall 2018
// Department of Information and Telecommunication Engineering
// Incheon National University

#include <windows.h>
#include <stdio.h>
#define NUMTHREADS 10 //number of threads

struct suminterval {
	int index; //index of subtask
	int start; //start of summation
	int end; //end of summation
};

int result[NUMTHREADS];

DWORD WINAPI summation(LPVOID Param) { //this function is for thread. DWORD=Double Word=unsigned int 32bit LPVOID=Long Pointer Void=void* WINAPI=_stdcall
	//Create structure and assign data from param to it.
	struct suminterval interval = *(struct suminterval*)Param;
	int start = interval.start;
	int end = interval.end;
	//Perform summation
	int total = 0;
	for (int i = start;i <= end;i++) {
		total += i;
	}
	result[interval.index] = total; //store the result into global array.
	printf("This is thread #%d, the sub-sum from %d to %d is %d.\n", interval.index + 1, start, end, total);
	return 0;
}

int main(int argc, char *argv[]) {
	DWORD ThreadId[NUMTHREADS];
	HANDLE ThreadHandle[NUMTHREADS]; //Handle is the unique number for telling other objects
	int i, j, input;
	printf("Please input a number:");
	scanf_s("%d", &input);
	while (input < NUMTHREADS) { //size should be greater than 1.
		printf("\nPlease input a number greater than %d\n", NUMTHREADS);
		scanf_s("%d", &input);
	}
	int size = input / NUMTHREADS; //calculate the size of each subtast.
	int start = 1; //initialization.
	struct suminterval mval[NUMTHREADS];
	for (i = 0;i < NUMTHREADS;i++) {
		//specify the start and end points for a subtask.
		mval[i].start = start; 
		start += size; 
		mval[i].end = start - 1;
		mval[i].index = i;
		if (i == NUMTHREADS - 1) { //for remained works
			mval[i].end = input;
		}
		//Create Thread to calculate summation from start to end.
		//lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId.
		ThreadHandle[i] = CreateThread(NULL, 0, summation, &mval[i], 0, &ThreadId[i]);

	}
	for (i = 0;i < NUMTHREADS;i++) {
		if (ThreadHandle[i] != NULL) { //if thread created,
			WaitForSingleObject(ThreadHandle[i], INFINITE); //until summation function finished.
			CloseHandle(ThreadHandle[i]); //close the thread.
		}
	}
	//Merge results generated by each thread
	long total = 0;
	for (i = 0;i < NUMTHREADS;i++) {
		total += result[i];
	}
	//Display results of summation
	printf("\nRsult for Summation is %d\n\n", total); //Print total value.
	system("PAUSE"); //Press any key to continue . . . and waiting for any key.
	return 0;
}