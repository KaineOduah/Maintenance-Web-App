#include <iostream>
#include <sqlite3.h>
#include <string>

void addRequest(int apartment_number, const std::string& area, const std::string& description, const std::string& date_time) {
    sqlite3* db;
    sqlite3_open("maintenance.db", &db);

    std::string sql = "INSERT INTO maintenance_requests (apartment_number, area, description, date_time) VALUES ('" +
                      std::to_string(apartment_number) + "', '" + area + "', '" + description + "', '" + date_time + "');";

    char* errorMessage;
    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errorMessage) != SQLITE_OK) {
        std::cerr << "SQL Error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    } else {
        std::cout << "Request added successfully." << std::endl;
    }

    sqlite3_close(db);
}

