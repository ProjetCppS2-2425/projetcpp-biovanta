#include "connection.h"

Connexion::Connexion(){

}
Connexion::~Connexion(){

}
bool Connexion::openConnexion() {

    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("RAWEN");
    db.setPassword("system");
    if (db.open()) {
        qDebug() << "Nouvelle connexion établie!";
        return true;
    } else {
        qDebug() << "Erreur de connexion: " << db.lastError().text();
        return false;
    }
}

void Connexion::closeConnexion() {
    // Check if the connection is open, and close it.
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database connection closed.";
    }
}
