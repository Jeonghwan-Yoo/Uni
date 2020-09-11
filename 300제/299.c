//메일 서버와 통신하는 프로그램을 작성하세요.
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

SOCKET s; //소켓 디스크립터 모든함수에서 사용할 수 있다.

int SendData(char *data) { //매일 서버에 패킷을 전송
	char buff[1000] = { 0, };
	int ret;
	ret = send(s, data, strlen(data), 0);

	puts(data);

	return ret;
}

int RecvData(void) { //매일 서버로부터 응답 메시지.
	char buff[1000] = { 0, };
	int ret;

	ret = recv(s, buff, 1000, 0);

	puts(buff);

	if (!strstr(buff, "250")) return 0;

	return ret;
}

void main(void) {
	WSADATA wsaData;
	struct sockaddr_in sin; //소켓 구조체
	char data[1000], buff[1000];
	int nTimeOut = 3000;
	int size = sizeof(int);

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0) {
		printf("WSAStartup 실패, 에러 코드 = %d\n", WSAGetLastError());
		return;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET) {
		printf("소켓 생성 실패, 에러 코드 : %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size);

	puts("메일 서버에 접속 중입니다...");

	sin.sin_family = AF_INET; //주소 체계 설정
	sin.sin_addr.s_addr = inet_addr(MAILSERVER); //접속 주소 설정
	sin.sin_port = htons(MAILPORT); //포트 번호 설정

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("접속 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("메일 서버에 접속되었습니다.");

	if (RecvData() == SOCKET_ERROR) {
		printf("수신 실패, 에러 코드 = %u\n", WSAGetLastError());
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

	sprintf(data, "본문입니다.\r\n");
	SendData(data);
	RecvData();

	sprintf(data, "\r\n.\r\n");
	SendData(data);
	RecvData();

	sprintf(data, "QUIT\r\n");
	SendData(data);
	RecvData();

	if (closesocket(s) != 0) {
		printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup 실패, 에러 코드 = %u\n", WSAGetLastError());
		return;
	}
}
//RFP:Request for comments의 약어로 인터넷의 표쥰을 정의한 문서.