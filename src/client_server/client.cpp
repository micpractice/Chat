#include <cassert>
#include "client.h"


mic::client_server::client::client(int port, char* ip,):m_socket(0), m_connect(0), m_ip(ip), m_port(port)
{
    //m_socket = socket(AF_INET, SOCK_STREAM, 0);
    bzero (&m_addr, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(m_port);
    m_addr.sin_addr.s_addr = inet_addr(m_ip);

}

bool mic::client_server::client::client::create_socket()

{
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == m_socket)
        return 0;
    return 1;
}


bool mic::client_server::client::connect_socket()
{
    m_connect = connect(m_socket,(struct sockaddr*) &m_addr, sizeof(m_addr));
    if(-1 == m_connect)
        return 0;
    return 1;
}

int mic::client_server::client::send_all(int m_socket, std::string *msg, int len, int flags)
{
    assert(msg != NULL);
    if (create_socket_status() && connect_socket_status())
    {
        int total = 0;
        int n;
        while(total < len)
                {
                    n = send(m_socket, msg+total, len-total, flags);
                    if(-1 == n) { break; }
                    total += n;
                }

                return (n == -1 ? -1 : total);
    }

}

int mic::client_server::client::recv_all(int m_socket, std::string *msg, int len, int flags)
{
    assert(msg != NULL);
    if (create_socket_status() && connect_socket_status())
    {
        int total = 0;
        int n;
        while(total < len)
                {
                    n = recv(m_socket, msg+total, len-total, flags);
                    if(-1 == n) { break; }
                    total += n;
                }

                return (n == -1 ? -1 : total);
    }
}

int mic::client_server::client::close_socket(m_socket)
{
  if (connect_socket)
	{	
		shutdown (m_socket, 2);
		close (m_socket);
	}

	close (m_socket);
}
