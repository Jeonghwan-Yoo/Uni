//���� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>
#include <conio.h>

#define MAILSERVER "211.218.200.140"
#define MAILPORT 25
#define SENDER "polarisgsi@freechal.com"
#define RECIPIENT "polarisgsi@freechal.com"
#define WINSOCK_VERSION MAKEWORD(2,2)

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

SOCKET s; //���� ��ũ���� ����Լ����� ����� �� �ִ�.

int SendData(char *data) { //���� ������ ��Ŷ�� ����
	char buff[1000] = { 0, };
	int ret;
	ret = send(s, data, strlen(data), 0);

	puts(data);

	return ret;
}

int RecvData(void) { //���� �����κ��� ���� �޽���.
	char buff[1000] = { 0, };
	int ret;

	ret = recv(s, buff, 1000, 0);

	puts(buff);

	if (!strstr(buff, "250")) return 0;

	return ret;
}

void main(void) {
	WSADATA wsaData;
	struct sockaddr_in sin; //���� ����ü
	char data[1000], buff[1000];
	int nTimeOut = 3000;
	int size = sizeof(int);

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0) {
		printf("WSAStartup ����, ���� �ڵ� = %d\n", WSAGetLastError());
		return;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET) {
		printf("���� ���� ����, ���� �ڵ� : %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size);

	puts("���� ������ ���� ���Դϴ�...");

	sin.sin_family = AF_INET; //�ּ� ü�� ����
	sin.sin_addr.s_addr = inet_addr(MAILSERVER); //���� �ּ� ����
	sin.sin_port = htons(MAILPORT); //��Ʈ ��ȣ ����

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("���� ������ ���ӵǾ����ϴ�.");

	if (RecvData() == SOCKET_ERROR) {
		printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	sprintf(data, "EHLO frclub.com\r\n");
	SendData(data);
	RecvData();

	sprintf(data, "AUTH LOGIN\n");
	SendData(data);
	RecvData();

	sprintf(data, "MAIL FROM:<%s>\r\n", SENDER);
	SendData(data);
	RecvData();

	sprintf(data, "RCPT TO:<%s>\r\n", RECIPIENT);
	SendData(data);
	RecvData();

	sprintf(data, "�����Դϴ�.\r\n");
	SendData(data);
	RecvData();

	sprintf(data, "\r\n.\r\n");
	SendData(data);
	RecvData();

	sprintf(data, "QUIT\r\n");
	SendData(data);
	RecvData();

	if (closesocket(s) != 0) {
		printf("���� ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup ����, ���� �ڵ� = %u\n", WSAGetLastError());
		return;
	}
}
//RFP:Request for comments�� ���� ���ͳ��� ǥ���� ������ ����.