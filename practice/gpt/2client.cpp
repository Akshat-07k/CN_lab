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
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    char data[100];

    while (true) {
        // Send a message to the server
        cout << "Enter a message to send to the server: ";
        fgets(data, sizeof(data), stdin);

        int sendInt = sendto(sockInt, data, strlen(data), 0, (struct sockaddr*)&server, sizeof(server));

        if (sendInt < 0) {
            perror("Error sending data");
            return 1;
        }

        // Receive a response from the server
        int recvInt = recvfrom(sockInt, data, sizeof(data), 0, nullptr, nullptr);

        if (recvInt < 0) {
            perror("Error receiving data");
            return 1;
        }

        cout << "Received response from server: " << data << endl;
    }

    close(sockInt);

    return 0;
}
