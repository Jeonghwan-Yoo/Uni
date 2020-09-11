#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h> //memset
#include <unistd.h> //close read write
#include "aes_enc_2.c"
#include "aes_dec_2.c"

#define PORT 9000

unsigned char buffer[BUFSIZ]="helloworld";
unsigned char rBuffer[BUFSIZ]; //initialization

int main(){
	
	int c_socket, s_socket;
	struct sockaddr_in s_addr, c_addr;
	int len;
	int n;
	char *temp; //initialization
	int length; //initialization

	s_socket=socket(PF_INET, SOCK_STREAM, 0);

	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	s_addr.sin_family=AF_INET;
	s_addr.sin_port=htons(PORT);

	if(bind(s_socket,(struct sockaddr *)&s_addr, sizeof(s_addr))==-1){
		printf("Can not Bind\n");
		return -1;
	}
	if(listen(s_socket, 5)==-1){
		printf("listen Fail\n");
		return -1;
	}
	while(1){
		len=sizeof(c_addr); 
		c_socket=accept(s_socket,(struct sockaddr *)&c_addr,&len);

		length=0;
		temp=rBuffer;
		while((n=read(c_socket,temp,1))>0){ //read temp as 1 byte in c_socket  
			if(length==BUFSIZ) break; 
			if(*temp=='\r') continue; //if \r, continue.
			if(*temp=='\n') break; //if \n, break.
			if(*temp=='\0') break; //if \0, break.

			temp++; //next character.
			length++; //next charater size.
		}
		// Recieve the length of key here.
		Nr=128;
		// Calculate Nk and Nr from the recieved value.
        Nk = Nr / 32;
        Nr = Nk + 6;
		//Recieve the key from the user
		printf("\nEnter the key in hexadecimal:");
        for(int i=0;i<Nk*4;i++){
			scanf("%x",&Key[i]);
		}
		printf("\nCipherText in hexadecimal:");
        for(int i=0;i<Nb*4;i++){
		printf("%02x ",rBuffer[i]);
            in[i]=rBuffer[i];
        }
		
		// The KeyExpansion routine must be called before encryption.
        KeyExpansion();

        // The next function call encrypts the PlainText with the Key using AES$
        InvCipher();

        // Output the encrypted text.
        printf("\nText after Decryption:");
        for(int i=0;i<Nb*4;i++){
			rBuffer[i]=out[i];
			printf("%c",rBuffer[i]);
        }
		if(!strcmp(rBuffer,"print\n")){ //if rBuffer is print,
			printf("\nsent Data:");
			for(int i=0;i<Nb*4;i++){
				in[i]=buffer[i];
				printf("%c",in[i]);
			}
			Cipher();
			printf("\nText after Cryption:");
			for(int i=0;i<Nb*4;i++){
				printf("%02x ",out[i]);
				buffer[i]=out[i];
			}
			n=strlen(out);
			write(c_socket,buffer,n); //write buffer.
			/*for(int i=0;i<Nb*4;i++){
				in[i]=buffer[i];
			}
			InvCipher();
			for(int i=0;i<Nb*4;i++){
				buffer[i]=out[i];
			}*/
			printf("\nreset\n");
		}
		close(c_socket);
	}
	close(s_socket);
}
