#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

using namespace std;

int main() {
    int sockInt = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockInt < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(1090);
    server.sin_addr.s_addr = INADDR_ANY;

    int bindInt = bind(sockInt, (struct sockaddr*)&server, sizeof(server));

    if (bindInt < 0) {
        perror("Error binding socket");
        return 1;
    }

    cout << "Server listening on port 1090..." << endl;

    struct sockaddr_in fromClient;
    socklen_t fromClientLen = sizeof(fromClient);

    char data[100];

    while (true) {
        // Receive from client
        int recvInt = recvfrom(sockInt, data, sizeof(data), 0, (struct sockaddr*)&fromClient, &fromClientLen);

        if (recvInt < 0) {
            perror("Error receiving data");
            return 1;
        }

        cout << "Received data from client: " << data << endl;

        // Send a response to the client
        cout << "Enter a response to send back: ";
        fgets(data, sizeof(data), stdin);

        int sendInt = sendto(sockInt, data, strlen(data), 0, (struct sockaddr*)&fromClient, sizeof(fromClient));

        if (sendInt < 0) {
            perror("Error sending data");
            return 1;
        }
    }

    close(sockInt);

    return 0;
}
