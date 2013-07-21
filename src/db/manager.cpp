
#include <cassert>
#include <stdio.h>

#include "manager.hpp"

mic::db::manager* mic::db::manager::m_instance = 0;

mic::db::manager* mic::db::manager::get_instance(const std::string& s)
{
	if(m_instance == NULL)
	{
		m_instance = new manager(s);
	}
	return m_instance;
}

void mic::db::manager::create_database_table()
{
	const char* t = "CREATE TABLE Database("\
					  "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
					  "NAME TEXT NOT NULL," \
					  "IP TEXT NOT NULL," \
					  "PORT TEXT NOT NULL);";
	int rc = sqlite3_open(m_db_path.c_str(), &m_db);
	assert(m_db != 0);
	rc = sqlite3_exec(m_db, t, 0, 0, &m_zErrMsg);
	assert(rc == SQLITE_OK);
	sqlite3_close(m_db);
}

std::string mic::db::manager::get_db_path() const
{
	return m_db_path;
}

void mic::db::manager::read_contact(const contact& o)
{
	std::string s("");
	assert(!m_db_path.empty());
	int rc = sqlite3_open(m_db_path.c_str(), &m_db);
	assert(m_db != 0);
	std::string n(o.get_name());
	std::string i(o.get_ip());
	std::string p(o.get_port());
	std::string c("INSERT INTO Database(NAME, IP, PORT)");
	s = c + "VALUES('" + n + "', " + "'" + i + "', " + 
					"'" + p + "');";
	sqlite3_close(m_db);
}

void mic::db::manager::insert_contact(const contact& o)
{

}

void mic::db::manager::delete_contact(const contact& o)
{

}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i = 0; i < argc; ++i)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
