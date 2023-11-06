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
    int cid = socket(AF_INET, SOCK_STREAM, 0);
    if (cid == -1)
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
    

    //connect function
	int conn = connect(cid, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(conn < 0)
	{
		printf(" Connect fail " );
		return 0;
	}
	cout<<" Connection with server done "<<endl;
	
	

return 0;
}	
