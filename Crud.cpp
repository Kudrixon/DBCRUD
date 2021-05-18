#include "Database.h"

using namespace std;
using namespace DB;

void PrintDatabaseOutput(vector<vector<string>> data) {
    for (int a = 0; a < data.size(); a++) {
        for (int c = 0; c < data[a].size(); c++) {
            cout << data[a][c] + " | ";
        } cout << " " << endl;
    }
}

int main(void) {
    vector<vector<string>> data;

    Database* database = new Database("localhost", "3306", "root", "root", "service");

    //Create
    database->Execute(" START TRANSACTION;");

    data = database->Get("SELECT * FROM employees", 5);
    //Printowanie po Select
    PrintDatabaseOutput(data);
    database->Insert("INSERT INTO employees(id, name, surname, role, email) VALUES (?,?,?,?,?)", { "I:5","S:Tomek","S:Gmyrek", "S:Monter", "S:mail@tomka.pl"});
    //Printowanie po Insert
    data = database->Get("SELECT * FROM employees", 5);
    PrintDatabaseOutput(data);
    database->Update("UPDATE employees SET email=? WHERE id=?", { "S:nowymail@tomka.pl" , "I:5" });
    //Printowanie po Update
    data = database->Get("SELECT * FROM employees", 5);
    PrintDatabaseOutput(data);
    database->Delete("DELETE FROM employees WHERE id=?", { "I:5" });
    //Printowanie po Delete
    data = database->Get("SELECT * FROM employees", 4);
    PrintDatabaseOutput(data);

    database->Execute(" COMMIT;");
}