/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 792
 *
 * Created on April 21, 2018, 2:30 PM
 */

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <string>


using namespace std;

/*
 * Given an HTTP URL (no need to support TLS or HTTPS), 
 * fetch the content using a GET request
 * Display the content on the console (a'la curl)
 * Exit
 * https://www.reddit.com/r/dailyprogrammer/comments/7jzy8k/20171215_challenge_344_hard_write_a_web_client/
 */

int sock;
struct sockaddr_in client;
int PORT = 80;
char c;
string url = "www.google.com";
string request;
bool headersOnly = true;

int main(int argc, char const *argv[])
{
    struct hostent * host = gethostbyname(url.c_str());
    

    if ( (host == NULL) || (host->h_addr == NULL) ) {
        cout << "Can't get DNS" << endl;
        exit(1);
    }

    bzero(&client, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons( PORT );
    memcpy(&client.sin_addr, host->h_addr, host->h_length);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        cout << "Can't create socket" << endl;
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&client, sizeof(client)) < 0) {
        close(sock);
        cout << "Can't connect" << endl;
        exit(1);
    }

    if (headersOnly){
        request = "HEAD / HTTP/1.1\r\nHost: "+ url +"\r\nConnection: close\r\n\r\n";
    } else {
        request = "GET / HTTP/1.1\r\nHost: "+ url +"\r\nConnection: close\r\n\r\n";
    }
    
    
    if (send(sock, request.c_str(), request.length(), 0) != (int)request.length()) {
        cout << "Can't send request" << endl;
        exit(1);
    }


    while (read(sock, &c, 1) > 0) {
        cout << c;
    }

    return 0;
}