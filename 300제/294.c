//TCP/IP 패킷을 전송하는 에코 클라이언트 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	SOCKET s; //소켓 디스크립터
	WSADATA wsaData;
	struct sockaddr_in sin; //소켓 구조체
	char data[100];

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

	sin.sin_family = AF_INET; //주소 체계 설정
	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //접속 주소 설정
	sin.sin_port = htons(10000); //포트 번호 설정

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("접속 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("에코 클라이언트를 시작합니다.");
	puts("전송할 데이터를 입력하고 엔터키를 치세요.");
	puts("정료를 하려면 END를 입력하세요.");

	while (1) {
		printf("전송할 데이터 입력 : ");
		gets(data);

		if (send(s, data, strlen(data), 0) < strlen(data)) { //입력 받은 데이터를 에코 서버에 전송합니다.
			printf("데이터 전송 실패, 에러 코드 = %u\n", WSAGetLastError()); 
			closesocket(s);
			WSACleanup();
			return;
		}

		if (recv(s, data, 100, 0) == SOCKET_ERROR) { //에코 서버가 돌려 주는 에코 문자열을 수신합니다.
			printf("데이터 전송 실패, 에러 코드 = %u\n", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return;
		}

		printf("\n%s가 에코되어 왔습니다.\n\n", data);

		if (strcmp(data, "END") == 0) break;
	}
	
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