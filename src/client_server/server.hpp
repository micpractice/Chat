#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

namespace mic
{
    class server_socket
    {
        private:
            struct sockaddr_in local;
            int socket_server_varible; //socket
            int server_bind; //
            int server_listen;  //rc
            int server_accept;  //s1;
            int server_recv;
            int server_send;
            char server_buffer[1];
            //char buf[1];
        public:
            server_socket();
            void mic_socket();
            void mic_bind();
            void mic_listen();
            void mic_accept();
            void mic_recv();
            void mic_send();
            void mic_close();
    };

}
#endif // SERVER_H
