//�� ��ǻ�Ϳ��� ������� ��� TCP/IP ��Ʈ�� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET s; //���� ��ũ����
	struct sockaddr_in sin; //���� ����ü
	unsigned short i;

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

	for (i = 1;i <= 65535;i++) { //1~65535���� ��� ��Ʈ�� ���Ͽ� �˻��մϴ�.
		sin.sin_family = AF_INET; //�ּ� ü�� ����
		sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //���� �ּ� ����
		sin.sin_port = htons(i); //��Ʈ ��ȣ ����.

		if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) == 0) { //�˻��Ŀ��� ���� ��Ʈ�� ã�� ����,
			//������ ������ closesocket()���� �ݾ��ְ� ���ο� ������ �����Ͽ� ���� ��Ʈ ��ȣ�� ��� �˻��մϴ�.

			printf("\n%5d ��Ʈ�� ��� ���Դϴ�.\n", i);
			closesocket(s);

			s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

			if (s == INVALID_SOCKET) {
				printf("���� ���� ����, ���� �ڵ� : %d\n", WSAGetLastError());
				WSACleanup();
				return;
			}
		}
		else { //��������� ���� ��,
			printf("."); 
		}
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
//well-known��Ʈ�� 21�� FTP, 25�� SMTP, 80�� ������,.
//CMD������ netstat /a�� ���� �� �� �ִ�.