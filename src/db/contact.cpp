
#include <cassert>

#include "contact.hpp"

mic::db::contact::contact():
			  m_name("")
			, m_ip("")
			, m_port("")  
			, m_id(0)
{
}

mic::db::contact::contact(std::string& n, std::string& ip, std::string& p):
				  m_name(n)
				, m_ip(ip)
				, m_port(p) 
{
}

mic::db::contact::contact(const contact& o)
{
	this->m_id = o.m_id;
	this->m_name = o.m_name;
	this->m_ip = o.m_ip;
	this->m_port = o.m_port;
}

mic::db::contact& mic::db::contact::operator=(const contact& o)
{
	if(&o == this)
	{
		return *this;
	}
	this->m_id = o.m_id;
	this->m_name = o.m_name;
	this->m_ip = o.m_ip;
	this->m_port = o.m_port;
	return *this;
}

void mic::db::contact::set_name(std::string& s)
{
	assert(!s.empty());
	m_name = s;
}

void mic::db::contact::set_ip(std::string& ip)
{
	assert(!ip.empty());
	m_ip = ip;
}

void mic::db::contact::set_port(std::string& p)
{
	assert(!p.empty());
	m_port = p;
}

unsigned mic::db::contact::get_id() const
{
	return m_id;
}

std::string mic::db::contact::get_name() const
{
	return m_name;
}

std::string mic::db::contact::get_ip() const
{
	return m_ip;
}

std::string mic::db::contact::get_port() const
{
	return m_port;
}

