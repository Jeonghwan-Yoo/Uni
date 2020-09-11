//TCP/IP�� ����Ͽ� ä�� ���� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>
#include <conio.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	WSADATA wsaData;
	SOCKET s, cs; //���� ��ũ����
	struct sockaddr_in sin; //���� ����ü
	struct sockaddr_in cli_addr;
	int size = sizeof(cli_addr);
	char buff[1000], data[1000];
	int nTimeOut = 200;
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

	sin.sin_family = AF_INET; //AF_INET ü������ ����
	sin.sin_port = htons(10000); //10000�� ��Ʈ�� ���
	sin.sin_addr.s_addr = htonl(ADDR_ANY); //��� Ŭ���̾�Ʈ�κ��� ���� ���

	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("���ε� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (listen(s, SOMAXCONN) != 0) {
		printf("���� ��� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("ä�� ������ �����մϴ�...");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) {
		printf("���� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("ä�ÿ� ����� ������ �Է��ϼ��� : ");
	gets(ID);
	printf("�޽����� �Է��ϰ� ����Ű�� ġ����.");

	size = sizeof(int);
	setsockopt(cs, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size); //recv() Ÿ�Ӿƿ� �ð��� 200ms�� �����մϴ�.

	while (1) {
		if (kbhit()) { //Ű���尡 ���������� �˻��մϴ�.
			gets(buff);
			if (strcmp(buff, "END") == 0) {
				send(s, "END", 3, 0);
				break;
			}
			sprintf(data, "%s:%s", ID, buff);

			if (send(cs, data, strlen(data), 0) < strlen(data)) {
				printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
				closesocket(cs);
				closesocket(s);
				WSACleanup();
				return;
			}

			memset(data, 0, sizeof(data)); //���۸� ���ϴ�.

			ret = recv(cs, data, 1000, 0); //ä�� �޽����� �����ϱ� ���� 0.2�ʰ� ����մϴ�.

			if (ret == 0 || WSAGetLastError() == WSAETIMEDOUT) continue; 
			//���Ź��� ���̰� 0�̰ų�, 0.2�ʰ� ���� Ÿ�Ӿƿ��̸� while��� ����.

			if (ret == SOCKET_ERROR) {
				printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
				closesocket(cs);
				closesocket(s);
				WSACleanup();
				return;
			}

			puts(data);
		}

		if (closesocket(cs) != 0 || closesocket(s) != 0) {
			printf("���� ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
			WSACleanup();
			return;
		}

		if (WSACleanup() != 0) {
			printf("WSACleanup ����, ���� �ڵ� = %n\n", WSAGetLastError());
			return;
		}
	}
}