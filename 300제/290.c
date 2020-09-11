//������ �����ϴ� TCP/IP���� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	SOCKET s, cs; //���� ��ũ����
	WSADATA wsaData;
	struct sockaddr_in sin; //���� ����ü
	struct sockaddr_in cli_addr;
	int size = sizeof(cli_addr);
	char data[1024] = { 0, };
	int ret;
	FILE *fp;
	int nTimeOut = 3000; //recv()�� �����Ͱ� ������ ������ ���� ��� ���¿� �ӹ��ϴ�.
	//���Ѵ����¸� �����ϱ� ���� 3�ʰ� �����Ͱ� ������ ������ Ÿ�Ӿƿ��� �߻��ϰ� �մϴ�.

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

	sin.sin_family = AF_INET; //AF_INET ü������ ���
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

	printf("Ŭ���̾�Ʈ�� ���� ������ ��ٸ��� �ֽ��ϴ�...\n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) {
		printf("���� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	fp = fopen("recv.bin", "w+b");

	if (fp == NULL) {
		perror("���� ���� ����");
		closesocket(cs);
		closesocket(s);
		WSACleanup();
		return;
	}

	setsockopt(cs, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size); //recv�Լ��� ���� Ÿ�Ӿƿ��� �����մϴ�.
	//���� ��, recv()�Լ��� 3�ʰ� �����Ͱ� ���ŵ��� ������ Ÿ�Ӿƿ��� �߻��ϰ� 0�� ��ȯ�˴ϴ�.

	while (1) {
		ret = recv(cs, data, 1024, 0); //�����͸� �����մϴ�. �ִ� 1024����Ʈ���� ���ŵǸ�,
		//�۽��ʿ��� 1024����Ʈ �̸��� �����͸� �����Ͽ��� ��� �� ũ�⸸ŭ ���ŵ˴ϴ�.

		if (ret == 0) break;

		if (ret == SOCKET_ERROR) {
			printf("���� ����, ���� �ڵ� = (%u)\n", WSAGetLastError());
			closesocket(cs);
			closesocket(s);
			WSACleanup();
			fclose(fp);
			return;
		}

		fwrite(data, 1, ret, fp);
		printf("%d ����Ʈ�� �����Ͽ����ϴ�.\n", ret);
	}
	fclose(fp);

	shutdown(s, SD_BOTH);

	if (closesocket(cs) != 0 || closesocket(s) != 0) {
		printf("���� ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup ����, ���� �ڵ� = %u\n", WSAGetLastError());
		return;
	}
}