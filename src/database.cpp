#include "database.h"
#include <iostream>
using namespace std;

Database::Database(){
    conn = mysql_init(nullptr);
    if(conn == nullptr){
        cerr<<"mysql_init() failed\n";
    }
}

Database::~Database(){
    if(conn){
        mysql_close(conn);
    }
}

bool Database::connect(const string &host, const string &user, const string &password, const string &dbname){
    if(mysql_real_connect(conn, host.c_str(), user.c_str(), password.c_str(), dbname.c_str(), 0, nullptr, 0) == nullptr){
        cerr<<"mysql_real_connect() failed\n";
        return false;
    }
    return true;
}

bool Database::executeQuery(const string &query){
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "QUERY FAILED: " << mysql_error(conn) << '\n';
        return false;
    }
    return true;
}

MYSQL_RES* Database::getQueryResult(const string &query){
    if (mysql_query(conn, query.c_str())) {
        std::cerr << "QUERY FAILED: " << mysql_error(conn) << '\n';
        return nullptr;
    }
    return mysql_store_result(conn);
}
