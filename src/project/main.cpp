
#include <cassert>

#include "../db/manager.hpp"

int main()
{
	mic::db::manager* m = mic::db::manager::get_instance("./Database.db");
	m->create_database_table();

	return 0;
}
