#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;
int main(){

// SOCKET
    int sid = socket(AF_INET, SOCK_STREAM, 0);
    if (sid == -1)
    {
        printf(" CLient is not Ready  ");
        return 0;
    }
   	cout<<" Socket created" <<endl;
    
    
    //server details 
    struct sockaddr_in server_addr;
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("10.5.74.82");
    
    // Bind server 
    if(bind(sid, (struct sockaddr*)&server_addr, sizeof(server_addr))<0){
        printf("Couldn't bind to the port\n");
        return -1;
    }
    cout<<" Server binding done " <<endl;
    
    //listening (int , 1);
    if(listen(sid, 1) < 0){
        printf("Error while listening\n");
        return -1;
    }
    struct sockaddr_in client_addr;
    
    
    unsigned int client_size = sizeof(client_addr);
    int client_sock = accept(sid, (struct sockaddr*)&client_addr, &client_size);
	
	if (client_sock < 0){
        printf("Can't accept\n");
        return -1;
    }
    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	
	

return 0;
}	
