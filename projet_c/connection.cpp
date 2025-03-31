#include "connection.h"
#include <QDebug>
Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
     db = QSqlDatabase::addDatabase("QODBC");
    //db.setHostName("localhost");
    db.setDatabaseName("Source_projet2A");//inserer le nom de la source de données
    db.setUserName("Rawen");//inserer nom de l'utilisateur
    db.setPassword("system");//inserer mot de passe de cet utilisateur
    if (db.open()){
        test=true;
        qDebug()<<"db opened";
    }
    return  test;
}
bool Connection::check_data_base(){
    if (db.isValid() && db.isOpen()) {
        return true;
    } else {
        return false;
    }
}
 void Connection::closeConnection()
{
    db.close();
}
