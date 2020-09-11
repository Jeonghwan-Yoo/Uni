//파일을 송신하는 TCP/IP 클라이언트 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>

#pragma warning(disable:4996)
#pragma comment(lib,"wsock32.lib")

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(int argc, char *argv[]) {
	SOCKET s; //소켓 디스크립터
	WSADATA wsaData;
	struct sockaddr_in sin; //소켓 구조체
	char data[1024];
	FILE *fp;
	int ret;
	int nRead;

	if (argc < 2) {
		printf("전송할 파일명을 입력하십시오.\n");
		printf("예)291.exe sample.txt\n");
	}

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
		printf("접속 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	fp = fopen(argv[1], "rb");

	if (fp == NULL) {
		perror("파일 개방 에러");
		closesocket(s);
		WSACleanup();
		return;
	}

	while (1) {
		nRead = fread(data, 1, 1024, fp); //개방된 파일로부터 데이터를 1024바이트 읽습니다.

		if (ferror(fp)) {
			perror("파일 읽기 에러");
			closesocket(s);
			WSACleanup();
			fclose(fp);
			return;
		}

		ret = send(s, data, nRead, 0);

		if (ret == SOCKET_ERROR || ret != nRead) { //만약 1024바이트 이하가 전송되었다면, 미전송된 나머지
			//데이터를 전송할 수 있게 프로그램을 수정해야 합니다.

			printf("데이터 송신 실패, 에러 코드 = %u\n", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return;
		}

		printf("%d 바이트를 송신하였습니다.\n", ret);
		if (feof(fp)) break;
	}
	fclose(fp);

	printf("%s 파일을 전송하였습니다.\n", argv[1]);

	shutdown(s, SD_BOTH);

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