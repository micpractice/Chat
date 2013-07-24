#include "server.h"

// constructor
mic::server_socket::server_socket()
{
    local.sin_family = AF_INET;
    local.sin_port   = htons(7500);
    local.sin_addr.s_addr = htonl(INADDR_ANY);
}

// calling socket
void mic::server_socket::mic_socket()
{
    socket_server_varible = socket( AF_INET, SOCK_STREAM, 0);

    if( socket_server_varible <0 )
    {
        perror("Error socket calling");
        exit(1);
    }
}
// binding function
void mic::server_socket::mic_bind()
{
    server_bind = bind(socket_server_varible, ( struct sockaddr* ) &local,sizeof(local));

    if( server_bind<0 )
    {
        perror("Error binding");
        exit(1);
    }
}
void mic::server_socket::mic_listen()
{
    server_listen = listen(socket_server_varible,10000);
    if( server_listen<0 )
    {
        perror("Error listen");
        exit(1);
    }
}
void mic::server_socket::mic_accept()
{
    server_accept = accept(socket_server_varible, NULL, NULL);
    if( server_accept<0 )
    {
        perror("Error accept");
        exit(1);
    }
}
void mic::server_socket::mic_recv()
{
    server_recv = recv(server_accept, server_buffer, 1,0 );
    if( server_recv<=0 )
    {
        perror("Error recv");
    }
}
void mic::server_socket::mic_send()
{
    cout << server_buffer << endl;
    server_send = send(server_accept, "2", 1,0);
    if( server_send<=0 )
    {
        perror("Send error");
        exit(1);
    }
}
void mic::server_socket::mic_close()
{
    close(socket_server_varible);
}


////////////////////////////////////////
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "server.h"

int main()
{

    mic::server_socket obj;

    obj.mic_socket();
    obj.mic_bind();
    obj.mic_listen();
    obj.mic_accept();
    obj.mic_recv();
    obj.mic_send();
    obj.mic_close();


    return 0;
}



































