//송 수신 버퍼의 크기를 1MB로 설정하는 프로그램을 작성하세요.
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	SOCKET s; //소켓 디스크립터
	WSADATA wsaData;
	int nSize = 1048576; //송수신 버퍼 크기 1MB.
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
	
	getsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, (int*)&size); //버퍼크기 출력
	printf("현재 송신 버퍼의 크기가 %d로 설정되었습니다.\n", nSize);
	
	getsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, (int*)&size);
	printf("현재 수신 버퍼의 크기가 %d로 설정되었습니다.\n", nSize);

	setsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, (int)&size);
	setsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, (int)&size);
	
	getsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, (int*)&size);
	printf("송신 버퍼의 크기가 %d로 설정되었습니다.\n", nSize);

	getsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, (int*)&size);
	printf("수신 버퍼의 크기가 %d로 설정되었습니다.\n", nSize);

	if (closesocket(s) != 0) {
		printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSAClenaup 실패, 에러 코드 = %u\n", WSAGetLastError());
		return;
	}
}
//기본적으로 사용되는 송수신 버퍼의 크기는 8KB(8196)입니다. 데이터의 양이 많거나 일괄 처리해야하면 크기를 늘려줘야 합니다.
//closesocket()함수는 현재 연결되어 있는 소켓을 임의로 차단할 때 사용되어 집니다.
//SO_SNDTIMEO송신 타임아웃을 설정합니다. 전송하려는 데이터가 타임아웃 시간 내에 전송되지 않는다면, 에러가 발생됩니다.
//SO_RCVTIMEO수신 타임아웃을 설정합니다. 수신하려는 데이터가 타임아웃 시간 내에 전송되지 않는다면, 에러가 발생됩니다.
//SO_LINGER closesocket()함수를 호출하면, 그 즉시 모든 전송중인 데이터를 잃게 되는데, 일정 시간 동안 전송을
//대기하기 위해 이 옵션을 사용합니다.
//그 밖에도 UDP, 브로드캐스트 멀티개스트에서 사용되는 옵션으로 SO_MAX_MSG_SIZE, SO_BROADCAST, SO_REUSEADDR등이 있다.