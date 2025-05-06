#include "connection.h"

connection::connection() {}

bool connection::createconnect()
{
    bool test = false;

    // Supprime toute connexion existante pour éviter les conflits
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    }

    // Configuration de la connexion ODBC
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("RAWEN");
    db.setPassword("system");

    if (db.open()) {
        test = true;
        qDebug() << "[INFO] Connexion à la base de données réussie.";
    } else {
        qDebug() << "[ERREUR] Échec de la connexion à la base de données !";
        qDebug() << "[ERREUR] Détails : " << db.lastError().text();
    }

    return test;
}

void connection::closeconnect()
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        qDebug() << "[INFO] Connexion à la base de données fermée.";
    }
}

