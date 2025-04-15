#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

class Connexion {
public:  
    Connexion();
    ~Connexion();
    bool openConnexion();
    void closeConnexion();
private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
