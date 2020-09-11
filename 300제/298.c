//���� Ŭ���̾�Ʈ ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib");
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	WSADATA wsaData;
	SOCKET s; //���� ��ũ����
	struct sockaddr_in sin; //���� ����ü
	char data[100];
	char ID[100], PWD[100];

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

	sin.sin_family = AF_INET; //�ּ� ü�� ����
	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //���� �ּ� ����
	sin.sin_port = htons(12345); //��Ʈ ��ȣ ����

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("�α��� ID�� ��ȣ�� 8�� �̳��� �Է��ϼ���.");
	printf("�α��� ID : ");
	gets(ID);
	printf("�α��� ��ȣ : ");
	gets(PWD);

	sprintf(data, "%-8.8s%-8.8s", ID, PWD); //����� ID�� ��ȣ�� ���� �����Ͽ� 8�ڱ����� �����մϴ�.

	if (send(s, data, strlen(data), 0) < strlen(data)) { //���� ������ �����մϴ�.
		printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (recv(s, data, 1, 0) < 1) { //��������� �����κ��� ���۹޽��ϴ�.
		printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (data[0] == '1') {
		puts("�α����� ���������� �Ͽ����ϴ�.");
	}
	else if(data[0]=='2') {
		puts("��ȣ�� Ʋ���ϴ�.");
	}
	else {
		puts("��ϵ��� ���� ����� ID�Դϴ�.");
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