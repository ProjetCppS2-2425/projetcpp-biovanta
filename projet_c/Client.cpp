#include  "Client.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMessageBox>

Client::Client(){}
Client::Client(int id_c, QString nomA, QString adresse, QString typeA,
               QString nomR, QString email, int id_contrat)
{
    this->id_c = id_c;
    this->nomA = nomA;
    this->adresse = adresse;
    this->typeA = typeA;
    this->nomR = nomR;
    this->email = email;
    this->id_contrat = id_contrat;

}
//****************************GETTERS**************************************

int Client::getIdClient() {
    return id_c;
}
QString Client::getNomA() {
    return nomA;
}
QString Client::getAdresse() {
    return adresse;
}
QString Client::getTypeA() {
    return typeA;
}
QString Client::getNomR() {
    return nomR;
}
QString Client::getEmail() {
    return email;
}
int Client::getIdContrat() {
    return id_contrat;
}
//****************************SETTERS**************************************
void Client::setIdClient(int id_c) {
    this->id_c = id_c;
}
void Client::setNomA(QString &nomA) {
    this->nomA = nomA;
}
void Client::setAdresse(QString &adresse) {
    this->adresse = adresse;
}
void Client::setTypeA(QString &typeA) {
    this->typeA = typeA;
}
void Client::setNomR(QString &nomR) {
    this->nomR = nomR;
}
void Client::setEmail(QString &email) {
    this->email = email;
}
void Client::setIdContrat(int id_contrat) {
    this->id_contrat = id_contrat;
}

//****************************CRUD**************************************


bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID_CLIENT, NOM_ASSOCIATION, ADRESSE, TYPE_ASSOCIATION, NOM_REP, EMAIL, ID_CONTRAT)"
                  " VALUES (:ID_CLIENT, :NOM_ASSOCIATION, :ADRESSE, :TYPE_ASSOCIATION, :NOM_REP, :EMAIL, :ID_CONTRAT)");

    query.bindValue(":ID_CLIENT", id_c);
    query.bindValue(":NOM_ASSOCIATION", nomA);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":TYPE_ASSOCIATION", typeA);
    query.bindValue(":NOM_REP", nomR);
    query.bindValue(":EMAIL", email);
    query.bindValue(":ID_CONTRAT", id_contrat);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Database Error: " << query.lastError().text();
        return false;
    }
}
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>
#include <QSqlError>

/*bool Client::ajouter()
{
    // Validate ID (must be positive)
    if (id_c <= 0) {
        QMessageBox::warning(nullptr, "Invalid Input", "ID must be a positive number!");
        return false;
    }

    // Validate Association Name (must not be empty and must contain only letters)
    if (nomA.isEmpty() || !nomA.at(0).isLetter()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Association name must start with a letter and cannot be empty!");
        return false;
    }

    // Validate Address (must not be empty)
    if (adresse.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Address cannot be empty!");
        return false;
    }

    // Validate Type of Association (must not be empty)
    if (typeA.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Type of association cannot be empty!");
        return false;
    }

    // Validate Representative Name (must contain only letters)
    if (nomR.isEmpty() || !nomR.at(0).isLetter()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Representative name must start with a letter and cannot be empty!");
        return false;
    }

    // Validate Email (must be in correct format)
    QRegularExpression regex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,6}$");
    if (!regex.match(email).hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid email address!");
        return false;
    }

    // Validate Contract ID (must be positive)
    if (id_contrat <= 0) {
        QMessageBox::warning(nullptr, "Invalid Input", "Contract ID must be a positive number!");
        return false;
    }

    // If all validations pass, insert into database
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID_CLIENT, NOM_ASSOCIATION, ADRESSE, TYPE_ASSOCIATION, NOM_REP, EMAIL, ID_CONTRAT) "
                  "VALUES (:ID_CLIENT, :NOM_ASSOCIATION, :ADRESSE, :TYPE_ASSOCIATION, :NOM_REP, :EMAIL, :ID_CONTRAT)");

    query.bindValue(":ID_CLIENT", id_c);
    query.bindValue(":NOM_ASSOCIATION", nomA);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":TYPE_ASSOCIATION", typeA);
    query.bindValue(":NOM_REP", nomR);
    query.bindValue(":EMAIL", email);
    query.bindValue(":ID_CONTRAT", id_contrat);

    if (query.exec()) {
        return true;
    } else {
        QMessageBox::critical(nullptr, "Database Error", "Failed to insert data: " + query.lastError().text());
        return false;
    }
}*/

bool Client::supprimer(int id){
     QSqlQuery query;
     query.prepare("Delete from Client where ID_CLIENT=:id");
    query.bindValue(":ID_CLIENT",id);
     return query.exec();
}


