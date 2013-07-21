
#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <sqlite3.h>
#include <string>
#include <vector>

#include "contact.hpp"

namespace mic
{
	namespace db
	{
		class manager;
	}
}

class mic::db::manager
{
	private:
		static manager* m_instance;

	private:
		sqlite3* m_db;
		char* m_zErrMsg;
		std::string m_db_path;

	private:
		static int callback(void*, int, char**, char**);

	public:
		typedef std::vector<std::vector<std::string> > table;
		table m_table;

	public:
		static manager* get_instance(const std::string& s);
		void create_database_table();
		void read_contact(const contact&);
		void insert_contact(const contact&);
		void delete_contact(const contact&);
		std::string get_db_path() const; 

	private:
		manager(const std::string& s): m_db_path(s) {}

	private:
		// this class is not copy constructable
		manager(const manager&);

		//this class is not assignable
		manager& operator=(const manager&);
};

#endif // MANAGER_HPP
