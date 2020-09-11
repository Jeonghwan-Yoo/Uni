//웹 서버의 default.html을 불러오는 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>
#include <conio.h>

#define WEBSERVER "211.218.150.200"
#define WEBPORT 80
#define WINSOCK_VERSION MAKEWORD(2,2)

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

SOCKET s; //소켓 디스크립터

int SendData(char *data) {
	char buff[1000] = { 0, };
	int ret;

	ret = send(s, data, strlen(data), 0);

	puts(data);

	return ret;
}

int RecvData(void) {
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

	puts("웹 서버에 접속 중입니다...");

	sin.sin_family = AF_INET; //주소 체계 설정
	sin.sin_addr.s_addr = inet_addr(WEBSERVER); //접속 주소 설정
	sin.sin_port = htons(WEBPORT);

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("접속 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("웹 서버에 접속되었습니다.");

	sprintf(data, "GET /defalut.html HTTP/1.0\r\n"); //전송 받고자 하는 문서의 이름.
	strcat(data, "Accept:*/*\r\n");
	strcat(data, "Accept-Language:ko\r\n");
	strcat(data, "Accept-Encoding:gzip,deflate\r\n");
	strcat(data, "Cache-Control:no-cache\r\n");
	strcat(data, "User-Agent:Mozilla/4.0(compatible;MSIE 6.0;Windows NT;)\r\n");
	strcat(data, "Host:www.frclub.com\r\n");
	strcat(data, "Connection:Keep-Alive\r\n");
	strcat(data, "\r\n");

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
