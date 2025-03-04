#include "Client.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>


Client::Client(int id_c, QString nomA, QString adresse, QString typeA,
               QString nomR, QString email, int id_contrat, int id_emp)
{
    this->id_c = id_c;
    this->nomA = nomA;
    this->adresse = adresse;
    this->typeA = typeA;
    this->nomR = nomR;
    this->email = email;
    this->id_contrat = id_contrat;
    this->id_emp = id_emp;
}

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
int Client::getIdEmp() {
    return id_emp;
}


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
void Client::setIdEmp(int id_emp) {
    this->id_emp = id_emp;
}


bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID_CLIENT, NOM_ASSOCIATION, ADRESSE, TYPE_ASSOCIATION, NOM_REP, EMAIL, ID_CONTRAT, ID_EMP)"
                  " VALUES (:ID_CLIENT, :NOM_ASSOCIATION, :ADRESSE, :TYPE_ASSOCIATION, :NOM_REP, :EMAIL, :ID_CONTRAT, :ID_EMP)");

    query.bindValue(":ID_CLIENT", id_c);
    query.bindValue(":NOM_ASSOCIATION", nomA);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":TYPE_ASSOCIATION", typeA);
    query.bindValue(":NOM_REP", nomR);
    query.bindValue(":EMAIL", email);
    query.bindValue(":ID_CONTRAT", id_contrat);
    query.bindValue(":ID_EMP", id_emp);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Database Error: " << query.lastError().text();
        return false;
    }
}
