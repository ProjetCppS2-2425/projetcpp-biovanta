#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;
public:
    //QSqlDatabase db;
    Connection();
    bool createconnect();
    bool check_data_base();
    void closeConnection();
};
#endif // CONNECTION_H
