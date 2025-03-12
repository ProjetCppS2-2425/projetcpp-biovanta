#include  "Client.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"


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


bool Client::supprimer(int id){
     QSqlQuery query;
     query.prepare("Delete from Client where ID_CLIENT=:ID_CLIENT");
    query.bindValue(":ID_CLIENT",id);
     return query.exec();
}
bool Client::exists(int id) {
    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT FROM CLIENT WHERE ID_CLIENT = :ID_CLIENT");
    query.bindValue(":ID_CLIENT", id);
    if (query.exec() && query.next()) {
        return true;  // Check if count > 0
    } else {
        return false;
    }
}


QSqlQueryModel * Client::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from CLIENT");

    if( model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Client"))){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("set"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
    }
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Association"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type Association"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nom Representant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID contrat"));
    return model;
}
bool Client::modifier(){
    QSqlQuery query;
    query.prepare("UPDATE CLIENTS SET NOM_ASSOCIATION = :nom_association, ADRESSE = :adresse, TYPE_ASSOCIATION = :type_association, NOM_REP = :nom_rep, EMAIL = :email, ID_CONTRAT = :id_contrat  WHERE ID_CLIENT = :id_client");
    query.bindValue(":id_client", id_client);
    query.bindValue(":nom_association", nomA);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type_association", typeA);
    query.bindValue(":nom_rep", nomR);
    query.bindValue(":email", email);
    query.bindValue(":id_contrat", id_contrat);
    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Database Error: " << query.lastError().text();
        return false;
    }
}
