//������ �۽��ϴ� TCP/IP Ŭ���̾�Ʈ ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>

#pragma warning(disable:4996)
#pragma comment(lib,"wsock32.lib")

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(int argc, char *argv[]) {
	SOCKET s; //���� ��ũ����
	WSADATA wsaData;
	struct sockaddr_in sin; //���� ����ü
	char data[1024];
	FILE *fp;
	int ret;
	int nRead;

	if (argc < 2) {
		printf("������ ���ϸ��� �Է��Ͻʽÿ�.\n");
		printf("��)291.exe sample.txt\n");
	}

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
	sin.sin_port = htons(10000); //��Ʈ ��ȣ ����

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	fp = fopen(argv[1], "rb");

	if (fp == NULL) {
		perror("���� ���� ����");
		closesocket(s);
		WSACleanup();
		return;
	}

	while (1) {
		nRead = fread(data, 1, 1024, fp); //����� ���Ϸκ��� �����͸� 1024����Ʈ �н��ϴ�.

		if (ferror(fp)) {
			perror("���� �б� ����");
			closesocket(s);
			WSACleanup();
			fclose(fp);
			return;
		}

		ret = send(s, data, nRead, 0);

		if (ret == SOCKET_ERROR || ret != nRead) { //���� 1024����Ʈ ���ϰ� ���۵Ǿ��ٸ�, �����۵� ������
			//�����͸� ������ �� �ְ� ���α׷��� �����ؾ� �մϴ�.

			printf("������ �۽� ����, ���� �ڵ� = %u\n", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return;
		}

		printf("%d ����Ʈ�� �۽��Ͽ����ϴ�.\n", ret);
		if (feof(fp)) break;
	}
	fclose(fp);

	printf("%s ������ �����Ͽ����ϴ�.\n", argv[1]);

	shutdown(s, SD_BOTH);

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