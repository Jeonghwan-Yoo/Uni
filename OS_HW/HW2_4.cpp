#include <stdio.h>

int main() {
	//n is for process number
	//bt is for burst time
	//wt is for waiting time
	//tat is for turnaround time
	//avwt is for average of waiting time
	//avtat is for average of turnaround time
	//i, j is for loop.
	int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
	printf("Enter total number of processes(maximum 20):");
	scanf_s("%d", &n); //storing process number

	printf("\nEnter Process Burst Time\n");
	for (i = 0;i < n;i++) {
		printf("P[%d]:", i + 1);
		scanf_s("%d", &bt[i]); //storing each burst time
	}
	//There is no arrival time for all processes.
	wt[0] = 0; //first process has no waiting time.
	//And this algorithm is FCFS.
	for (i = 1;i < n;i++) {
		wt[i] = 0; //initialization.
		for (j = 0;j < i;j++) {
			wt[i] += bt[j]; //add all previous burst time on waiting time, which is the current waiting time.
		}
	}
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

	//calculating turnaround time
	for (i = 0;i < n;i++) {
		tat[i] = bt[i] + wt[i]; //burst time + waiting time.
		avwt += wt[i];
		avtat += tat[i];
		printf("\nP[%d]\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
	}
	avwt /= i; //average
	avtat /= i; //average
	printf("\nAverage Waiting Time:%d", avwt);
	printf("\nAverage Turnaround Time:%d", avtat);

	getchar(); //waiting for any key to close the console window.
	return 0;
}