#include <Windows.h> //TCHAR, STARUPINFO, PROCESS_INFORMATION, CreateProcess, strrchr, GetProcessImageFileName, GetProcessMemoryInfo, CloseHandle
#include <stdio.h>
#include <Psapi.h> //PROCESS_MEMORY_COUNTERS, GetProcessImageFileName, GetProcessMemoryInfo
#include <string.h>
#define MAX_PATH 100

int main() {
	TCHAR szProcessName[15][MAX_PATH] = { TEXT("<unknown>") }; //TCHAR automatically changing proper code by telling unicode and multibyte. TEXT for unicode like attaching L.
	STARTUPINFO si[15]; //argument for specifing main window properties if a new window is created for the new process.
	PROCESS_INFORMATION pi[15]; //argument for receiving identification information about the new process.
	PROCESS_MEMORY_COUNTERS pmc[15]; //argument for memory statistics for a process.

	for (int i = 0;i < 15;i++) {
		ZeroMemory(&si[i], sizeof(si[i])); //initialize memory block
		ZeroMemory(&pi[i], sizeof(pi[i])); //initialize memory block
	}
	getchar();
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
	if (!CreateProcess("C://Windows//notepad.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[2], //Pointer to STARTUPINFO structure
		&pi[2])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//System32//cleanmgr.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[3], //Pointer to STARTUPINFO structure
		&pi[3])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//System32//calc.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[4], //Pointer to STARTUPINFO structure
		&pi[4])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//explorer.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[5], //Pointer to STARTUPINFO structure
		&pi[5])) { //Pointer to PROCESS_INFORMATION structure
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
		&si[6], //Pointer to STARTUPINFO structure
		&pi[6])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//notepad.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[7], //Pointer to STARTUPINFO structure
		&pi[7])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//System32//cleanmgr.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[8], //Pointer to STARTUPINFO structure
		&pi[8])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//System32//calc.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[9], //Pointer to STARTUPINFO structure
		&pi[9])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//explorer.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[10], //Pointer to STARTUPINFO structure
		&pi[10])) { //Pointer to PROCESS_INFORMATION structure
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
		&si[11], //Pointer to STARTUPINFO structure
		&pi[11])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//notepad.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[12], //Pointer to STARTUPINFO structure
		&pi[12])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//System32//cleanmgr.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[13], //Pointer to STARTUPINFO structure
		&pi[13])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	if (!CreateProcess("C://Windows//System32//calc.exe", //when creating process failed
		NULL, //command line
		NULL, //Process handle not inheritable
		NULL, //Thread handle not inheritable
		FALSE, //Set handle inheritance to FALSE
		0, //No creation flags
		NULL, //Use parent's environment block
		NULL, //User parent's starting directory
		&si[14], //Pointer to STARTUPINFO structure
		&pi[14])) { //Pointer to PROCESS_INFORMATION structure
		printf("CreatePstartupinforocess() failed!\n");
	}
	else {
		printf("A process has been successfully created\n");
	}
	for (int i = 0;i < 15;i++)
	{
		GetProcessImageFileName(pi[i].hProcess, szProcessName[i], MAX_PATH); //retrieving the name of the excutable file for the specified process. (hProcess, lpImageFileName, nSize)
		GetProcessMemoryInfo(pi[i].hProcess, &pmc[i], sizeof(pmc[i])); //retrieving information about the memory usage of the specified process. (Process, ppsmemCounters, cb)
	}
	printf("PROCESS MANAGER created by Jeonghwan\n");
	printf("====================================\n");
	printf("ID      NAME            MEMORY(KB)\n");

	for (int i = 0;i < 15;i++)
	{
		const char *cp;
		cp = strrchr(szProcessName[i], '\\'); //a pointer to the last occurrence of character(\\) in str.
		if (cp) {
			printf("%u\t%s\t%dKB\n", pi[i].dwProcessId, cp + 1, pmc[i].WorkingSetSize / 1024); //ID, NAME, MEMORY
		}
	}
	getchar(); //getting a character from stdin
	for (int i = 0;i < 15;i++)
	{
		CloseHandle(pi[i].hProcess); //return handle
	}
	return 0;
}