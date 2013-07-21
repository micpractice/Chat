
#include <cassert>

#include "manager.hpp"

mic::client_server::manager* mic::client_server::manager::m_instance = 0;

void mic::client_server::manager mic::client_server::manager::init_manager()
{
	m_client = new client();
	m_server = new server();
	assert(m_client != 0);
	assert(m_serve != 0);
}

void mic::client_server::manager* mic::client_server::manager::get_instance()
{
	if(m_instance == 0)
	{
		m_instance = new mic::client_server::manager();
		assert(m_instance != 0);
		return m_instance;
	}
}
		
int mic::client_server::manager::create_server()
{

}

int mic::client_server::manager::create_client()
{

}

void mic::client_server::manager::run_server()
{

}

void mic::client_server::manager::stop_server()
{

}

void mic::client_server::manager::run_client()
{
}

void mic::client_server::manager::stop_client()
{

}

