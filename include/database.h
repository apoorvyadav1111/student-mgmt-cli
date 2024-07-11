#ifndef DATABASE_H
#define DATABASE_H

#include <mysql/mysql.h>
#include <string> 
using namespace std;

class Database{
private:
    MYSQL *conn;

public:
    Database();
    ~Database();
    bool connect(const string &host, const string &user, const string &passwd, const string &db);
    bool executeQuery(const string &query);
    MYSQL_RES *getQueryResult(const string &query);
};

#endif
