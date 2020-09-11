//TCP/IP�� ����Ͽ� ä�� Ŭ���̾�Ʈ ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>
#include <conio.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	WSADATA wsaData;
	SOCKET s; //���� ��ũ����
	struct sockaddr_in sin; //���� ����ü
	int size;
	int nTimeOut = 200;
	char buff[1000], data[1000];
	char ID[100];
	int ret;

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

	puts("ä�� Ŭ���̾�Ʈ�� �����մϴ�...");

	sin.sin_family = AF_INET; //�ּ� ü�� ����
	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //���� �ּ� ����
	sin.sin_port = htons(10000); //��Ʈ ��ȣ ����

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	size = sizeof(int);
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size);

	printf("ä�ÿ� ����� ������ �Է��ϼ��� : ");
	gets(ID);
	puts("�޽����� �Է��ϰ� ����Ű�� ġ����.");

	while (1) {
		if (kbhit()) {
			gets(buff);
			if (strcmp(buff, "END") == 0) {
				send(s, "END", 3, 0);
				break;
			}

			sprintf(data, "%s:%s", ID, buff);

			if (send(s, data, strlen(data), 0) < strlen(data)) {
				printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
				closesocket(s);
				WSACleanup();
				return;
			}

			memset(data, 0, sizeof(data));
			ret = recv(s, data, 1000, 0);

			if (ret == 0 || WSAGetLastError() == WSAETIMEDOUT) continue;

			if (ret == SOCKET_ERROR) {
				printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
				closesocket(s);
				WSACleanup();
				return;
			}

			puts(data);

			if (strcmp(data, "END") == 0) break;
		}
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
}