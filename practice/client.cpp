#include<iostream>
#include<bits/stdc++.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

using namespace std;

int main(){
    int sockInt = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockInt < 0)return 0;

    struct sockaddr_in sock;
    sock.sin_family = AF_INET;
    sock.sin_port = 1091;
    sock.sin_addr.s_addr = inet_addr("127.0.0.1");

    int bindInt = bind(sockInt , (sockaddr *)&sock, sizeof(sock));
    
    if(bindInt < 0)return 0;

    cout<<" Client complete "<<endl;

    struct sockaddr_in toServer;

    toServer.sin_family = AF_INET;
    toServer.sin_port = 1090;
    toServer.sin_addr.s_addr = inet_addr("127.0.0.1");

    // string str;
    char str[100];
    // cin>> str;
    fgets(str, sizeof(str), stdin); 


    int sendInt = sendto(sockInt , str , sizeof(str),0, (struct sockaddr *)&toServer, sizeof(toServer));

    if(sendInt < 0){
        cout<<" OO NO ";
    } 

    cout<<" Send "<<endl;


      
    
    return 0;
}