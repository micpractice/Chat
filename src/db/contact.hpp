
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

namespace mic
{
	namespace db
	{
		class contact;
	}
}

// Active record pattern
class mic::db::contact
{
	private:
		std::string m_name;
		std::string m_ip;
		std::string m_port;
		unsigned m_id;

	public:
		contact();
		contact(std::string&, std::string&, std::string&);
		void set_name(std::string&);
		void set_ip(std::string&);
		void set_port(std::string&);
		unsigned get_id() const;
		std::string get_name() const;
		std::string get_ip() const;
		std::string get_port() const;

	public:
		contact(const contact&);
		contact& operator=(const contact&);
};

#endif // CONTACT_HPP
