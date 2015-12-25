#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

int main(){

    // the client needs to know the servers port number

    int client,
        server,
        port = 1500,
        bufferSize = 1024;

    bool isExit = false;
    char buffer[bufferSize];
    char const *ip= "127.0.0.1";

    struct sockaddr_in {};
    sockaddr_in sockaddrIn;

    struct sin_addr{
        int s_addr;
    };

    struct server_addr {
        int sin_family;
        sin_addr sin_addr;
        int sin_port;
    } serverAddr;

    // init socket

    client = socket(AF_INET, SOCK_STREAM, 0);

    if(client < 0){
        cout << "Error creating socket..." << endl;
        exit(1);
    }

    cout << "Client socket created" << endl;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    // connection socket server

    if(connect(client, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == 0){
        cout << "Connecting to server..." << endl;
    }

    recv(client, buffer, bufferSize, 0);
    cout << "Connection confirmed" << endl;
    cout << "Enter # to end the connection." << endl;

    do {
        cout << "Client: ";
        do {
            cin >> buffer;
            send(client, buffer, bufferSize, 0);
            if(*buffer == "#"){
                send(client, buffer, bufferSize, 0);
                *buffer = "*";
                isExit = true;
            }
        }while(*buffer != "*");

        cout << "\nServer: ";
        do{
            recv(client, buffer, bufferSize, 0);
            cout << buffer << " ";
            if(*buffer == "#"){
                *buffer = "*";
                isExit = true;
            }
        }while(*buffer != "*");
        cout<<endl;
    }while(!isExit);

    cout << "Connected terminated..." << endl;

    close(client);
    return 0;

}