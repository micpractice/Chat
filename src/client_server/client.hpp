#ifndef CLIENT_H
#define CLIENT_H
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

namespace mic
{
    namespace client_server
    {
        class client;

    }

}

class mic::client_server::client
{
private:
    struct sockaddr_in m_addr;
    int m_socket;
    int m_connect;
  //bool m_status;
    //bool m_connect;
    char* m_ip;
    int m_port;
    //std::string m_buffer;
public:
    client (int port, char* ip);
    bool create_socket();
    bool connect_socket();
    int send_all(int m_socket, std::string* msg,int len, int flags);
    int recv_all(int m_socket, std::string *msg, int len, int flags);
    int close_socket(int m_socket);
    //void run_all();
};

#endif // CLIENT_H
