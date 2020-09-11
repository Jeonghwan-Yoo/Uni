#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h> //close read write
#include <string.h> //memset
#include <arpa/inet.h> //inet
#include "aes_enc_2.c"
#include "aes_dec_2.c"

#define PORT 9000
#define IPADDR "127.0.0.1"

unsigned char buffer[BUFSIZ]; //not to overflow.

int main(){
	int c_socket;
	struct sockaddr_in c_addr;
	int len;
	int n;
	
	unsigned char rcvBuffer[BUFSIZ];

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
	// Recieve the length of key here.
	Nr=128;
    // Calculate Nk and Nr from the recieved value.
    Nk = Nr / 32;
    Nr = Nk + 6;

	//Recieve the key from the user
    printf("Enter the Key in hexadecimal:");
	for(int i=0;i<Nk*4;i++){
		scanf("%x",&Key[i]);
	}
	while(getchar()!='\n');
	printf("Enter the PlainText:");
	
	for(int i=0;i<Nb*4;i++){
		scanf("%c",&in[i]);
		if(in[i]=='\n'){
			break;
		}
    }
	
    // The KeyExpansion routine must be called before encryption.
    KeyExpansion();

    // The next function call encrypts the PlainText with the Key using AES$
    Cipher();
	// Output the encrypted text.
    printf("Text after encryption:");
    for(int i=0;i<Nb*4;i++)
    {
            printf("%02x ",out[i]);
	buffer[i]=out[i];
    }
    printf("\n");

	write(c_socket,buffer,strlen(buffer)+1);
	for(int i=0;i<Nb*4;i++){
		in[i]=buffer[i];
	}
	InvCipher();
	for(int i=0;i<Nb*4;i++){
		buffer[i]=out[i];
	}
	if((n=read(c_socket,rcvBuffer,sizeof(rcvBuffer)))<0){
		return -1;
	}
	printf("\nreceived Data:");
	for(int i=0;i<Nb*4;i++){
		printf("%02x ",rcvBuffer[i]);
		in[i]=rcvBuffer[i];
	}
	// The next function call encrypts the PlainText with the Key using AES$
    InvCipher();
	// Output the encrypted text.
    printf("\nText after Decryption:");
    for(int i=0;i<Nb*4;i++)
    {
		rcvBuffer[i]=out[i];
        printf("%c",rcvBuffer[i]);
    }
    printf("\n");

	close(c_socket);
}
