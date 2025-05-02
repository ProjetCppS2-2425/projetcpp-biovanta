#ifndef 84_H
#define 84_H

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

#endif // 84_H
