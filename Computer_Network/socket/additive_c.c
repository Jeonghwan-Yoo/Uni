#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h> //close read write
#include <string.h> //memset
#include <arpa/inet.h> //inet

#define PORT 9000
#define IPADDR "127.0.0.1"

char buffer[BUFSIZ];

int key=5; //additive key(0~25).

int add_cipher(char* plain, int _key){
    for(int i=0;i<strlen(plain);i++){
        char temp=plain[i]-'a';
        temp+=_key;
        temp%=26;
        plain[i]=temp+'a';
    }
}

int add_decipher(char *cipher,int _key){
    for(int i=0;i<strlen(cipher);i++){
        int temp=(int)cipher[i]-'a';
        temp-=_key;
	if(temp<0){
		temp+=26;
	}
    temp=temp%26;
    cipher[i]=temp+'a';
    }
}


int main(){
	int c_socket;
	struct sockaddr_in c_addr;
	int len;
	int n;
	
	char rcvBuffer[BUFSIZ];

	c_socket=socket(PF_INET, SOCK_STREAM, 0);

	memset(&c_addr, 0, sizeof(c_addr));
	c_addr.sin_addr.s_addr=inet_addr(IPADDR);
	c_addr.sin_family=AF_INET;
	c_addr.sin_port=htons(PORT);

	if(connect(c_socket,(struct sockaddr *)&c_addr, sizeof(c_addr))==-1){
		printf("Can not connect\n");
		close(c_socket);
		return -1;
	}
	scanf("%s",buffer);
	buffer[strlen(buffer)]='\0';
	add_cipher(buffer,key); //cipher print.
	printf("sent message : %s\n",buffer);
	write(c_socket,buffer,strlen(buffer)+1);
	if((n=read(c_socket,rcvBuffer,sizeof(rcvBuffer)))<0){
		return -1;
	}
	rcvBuffer[n]='\0';
	printf("received Data : %s\n",rcvBuffer);
	add_decipher(rcvBuffer,key); //decipher data.
	printf("deciphered Data : %s\n", rcvBuffer);

	close(c_socket);
}
