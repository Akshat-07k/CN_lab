#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>

 // int socket(AF_INET, SOCK_DGRAM, 0);

int main(){

	int ser = socket(AF_INET, SOCK_DGRAM, 0);
	if(ser == -1){
		printf(" Server not Created ");
		return 0;
	}
	
	printf(" Khudos server is running ");
	return 0;
}
