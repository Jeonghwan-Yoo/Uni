//인증 클라이언트 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib");
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	WSADATA wsaData;
	SOCKET s; //소켓 디스크립터
	struct sockaddr_in sin; //소켓 구조체
	char data[100];
	char ID[100], PWD[100];

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
	sin.sin_port = htons(12345); //포트 번호 설정

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("접속 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("로그인 ID와 암호를 8자 이내로 입력하세요.");
	printf("로그인 ID : ");
	gets(ID);
	printf("로그인 암호 : ");
	gets(PWD);

	sprintf(data, "%-8.8s%-8.8s", ID, PWD); //사용자 ID와 암호를 왼쪽 정렬하여 8자까지만 복사합니다.

	if (send(s, data, strlen(data), 0) < strlen(data)) { //인증 서버로 전송합니다.
		printf("전송 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (recv(s, data, 1, 0) < 1) { //인증결과를 서버로부터 전송받습니다.
		printf("수신 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (data[0] == '1') {
		puts("로그인을 성공적으로 하였습니다.");
	}
	else if(data[0]=='2') {
		puts("암호가 틀립니다.");
	}
	else {
		puts("등록되지 않은 사용자 ID입니다.");
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