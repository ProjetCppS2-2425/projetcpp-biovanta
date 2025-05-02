#ifndef 87_H
#define 87_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class connection
{
public:
    connection();
    bool createconnect();
    void closeconnect();
};

#endif // 87_H
