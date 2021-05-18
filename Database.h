#include <vector>

#include "jdbc/mysql_connection.h"

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include "jdbc/cppconn/prepared_statement.h"


namespace DB {
	class Database {
	protected:
		sql::Driver* driver;
		sql::Connection* con;
		sql::Statement* stmt;
		sql::ResultSet* res;
		sql::PreparedStatement* prep_stmt;

	private:
		void Execute_Query(std::string,
			std::vector<std::string>);

	public:
		Database();

		Database(std::string, std::string, std::string, std::string, std::string);

		void Execute(std::string);

		std::vector<std::vector<std::string>> Execute(std::string, int);

		void Connect(std::string, std::string, std::string, std::string);

		void Insert(std::string, std::vector<std::string>);

		std::vector<std::vector<std::string>> Get(std::string, std::vector<std::string>, int);

		std::vector<std::vector<std::string>> Get(std::string, int);

		void Update(std::string, std::vector<std::string>);

		void Delete(std::string, std::vector<std::string>);

	};
};

