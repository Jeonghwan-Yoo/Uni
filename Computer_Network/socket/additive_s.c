#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h> //memset
#include <unistd.h> //close read write

#define PORT 9000

char buffer[BUFSIZ]="helloworld";
char rBuffer[BUFSIZ]; //initialization

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
			if(*temp=='\r') continue; //if \r, continue.
			if(*temp=='\n') break; //if \n, break.
			if(*temp=='\0') break; //if \0, break.

			if(length==BUFSIZ)  break; //if length size is same as BUFSIZ, break.
			temp++; //next character.
			length++; //next charater size.
		}
		rBuffer[length]='\0'; //last character should be null.
		printf("received message : %s\n",rBuffer);
		add_decipher(rBuffer,key); //decipher message.
		if(!strcmp(rBuffer,"print")){ //if rBuffer is print,
			n=strlen(buffer); //n is for buffer size.
			add_cipher(buffer,key); //cipher data.
			write(c_socket,buffer,n); //write buffer.
			add_decipher(buffer,key); //reset.

		}
		close(c_socket);
	}
	close(s_socket);
}
