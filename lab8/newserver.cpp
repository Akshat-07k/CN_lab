#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>




int main() {
    
    int servSock, cliSock;
    char data[1000];

    // Create a socket
    servSock = socket(AF_INET, SOCK_STREAM, 0);



    // Server address structure
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(12345);
    serv.sin_addr.s_addr = inet_addr("10.2.244.200");



    // Bind()
    bind(servSock, (struct sockaddr*)&serv, sizeof(serv));



    // Listen()
    listen(servSock, 5);
    printf("Server is listening \n");



    //accept( ) function
    cliSock = accept(servSock, NULL, NULL);
    printf("Connected to client.\n");

    while (true) {

        //scanf(" %s",data);
        recv(cliSock, &data, sizeof(data), 0);
        if(strcmp(data,"END\n")==0){
            // printf(" ___ BYE ___");
            // return 0;
            // exit(0);break;
            break;
        }
        // exit(0);

        printf("Received from client: %s", data);


        printf("Enter a data to send to the client: ");
        fgets(data, sizeof(data), stdin);
        if(strcmp(data,"END\n")==0){
            // printf(" ___ BYE ___");
            // return 0;
            // exit(0);break;
            break;
        }
        send(cliSock, data, sizeof(data), 0);
    }


    return 0;
}