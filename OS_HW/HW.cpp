#include <Windows.h> //TCHAR, STARUPINFO, PROCESS_INFORMATION, CreateProcess, strrchr, GetProcessImageFileName, GetProcessMemoryInfo, CloseHandle
#include <stdio.h>
#include <Psapi.h> //PROCESS_MEMORY_COUNTERS, GetProcessImageFileName, GetProcessMemoryInfo
#include <string.h>
#define MAX_PATH 100

int main() {
	TCHAR szProcessName[2][MAX_PATH] = { TEXT("<unknown>"),TEXT("<unknown>") }; //TCHAR automatically changing proper code by telling unicode and multibyte. TEXT for unicode like attaching L.
	STARTUPINFO si[2]; //argument for specifing main window properties if a new window is created for the new process.
	PROCESS_INFORMATION pi[2]; //argument for receiving identification information about the new process.
	PROCESS_MEMORY_COUNTERS pmc[2]; //argument for memory statistics for a process.

	for (int i = 0;i < 2;i++) {
		ZeroMemory(&si[i], sizeof(si[i])); //initialize memory block
		ZeroMemory(&pi[i], sizeof(pi[i])); //initialize memory block
	}
	if (!CreateProcess("C://Windows//explorer.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[0], //Pointer to STARTUPINFO structure
		&pi[0])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreateProcess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//System32//mspaint.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[1], //Pointer to STARTUPINFO structure
		&pi[1])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	GetProcessImageFileName(pi[0].hProcess, szProcessName[0], MAX_PATH); //retrieving the name of the excutable file for the specified process. (hProcess, lpImageFileName, nSize)
	GetProcessMemoryInfo(pi[0].hProcess, &pmc[0], sizeof(pmc[0])); //retrieving information about the memory usage of the specified process. (Process, ppsmemCounters, cb)
	GetProcessImageFileName(pi[1].hProcess, szProcessName[1], MAX_PATH); //retrieving the name of the excutable file for the specified process. (hProcess, lpImageFileName, nSize)
	GetProcessMemoryInfo(pi[1].hProcess, &pmc[1], sizeof(pmc[1])); //retrieving information about the memory usage of the specified process. (Process, ppsmemCounters, cb)

	printf("PROCESS MANAGER created by Jeonghwan\n");
	printf("====================================\n");
	printf("ID      NAME            MEMORY(KB)\n");

	const char *cp;
	cp = strrchr(szProcessName[0], '\\'); //a pointer to the last occurrence of character(\\) in str.
	if (cp) { 
		printf("%u\t%s\t%dKB\n", pi[0].dwProcessId, cp + 1, pmc[0].WorkingSetSize / 1024); //ID, NAME, MEMORY
	}
	const char *cp1;
	cp1 = strrchr(szProcessName[1], '\\'); //a pointer to the last occurrence of character(\\) in str.
	if (cp1) {
		printf("%u\t%s\t%dKB\n", pi[1].dwProcessId, cp1 + 1, pmc[1].WorkingSetSize / 1024); //ID, NAME, MEMORY
	}
	getchar(); //getting a character from stdin
	CloseHandle(pi[0].hProcess); //return handle
	CloseHandle(pi[1].hProcess); //return handle

	return 0;
}