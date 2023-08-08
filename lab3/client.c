#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet.h>

//int socket(AF_INET, SOCK_DGRAM, 0);

int main(){

	int cli = socket(AF_INET, SOCK_DGRAM, 0);
	if(cli == -1){
		printf(" CLient is Ready  ");
		return 0;
	}
	
	printf(" Khudos Client  is ready ");
	return 0;
}
