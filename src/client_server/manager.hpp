
#ifndef MANAGER_HPP
#define MANAGER_HPP

namespace mic
{
	namespace client_server
	{
		class manager;
	}

	class client;
	class server;
}

class mic::client_server::manager
{
	private:
		static manager* m_instance;

	private:
		client* m_client;
		server* m_server;

	private:
		static void init_manager();

		// this class is not default constructable
	private:
		manager(){}

		// this class is not copy constructable
	private:
		manager(const manager&);

		// this class is not assignable
	private:
		manager& operator=(const manager&);

	public:
		static manager* get_instance();

	public:
		int create_server();
		int create_client();
		void run_server();
		void stop_server();
		void run_client();
		void stop_client();
};

#endif // MANAGER_HPP
