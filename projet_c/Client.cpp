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
#include  <QSqlTableModel>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
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
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_ASSOCIATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_ASSOCIATION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_REP"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_CONTRAT"));

    return model;
}
Client Client::fetch(int id){
   /* Client* C = new Client();
    QSqlQuery query;
    query.prepare("SELECT NOM_ASSOCIATION, ADRESSE, TYPE_ASSOCIATION, NOM_REP, EMAIL, ID_CONTRAT FROM CLIENT where ID_CLIENT=:ID_CLIENT");
    query.bindValue(":ID_CLIENT",id);
    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        delete C;
        return nullptr;
    }
    if (query.next()){
        C->setIdClient(id);
        QString nomA=query.value("NOM_ASSOCIATION").toString();
        C->setNomA(nomA);
        QString adr = query.value("ADRESSE").toString();
        C->setAdresse(adr);
        QString type = query.value("TYPE_ASSOCIATION").toString();
        C->setTypeA(type);
        QString Rep = query.value("NOM_REP").toString();
        C->setNomR(Rep);
        QString mail = query.value("EMAIL").toString() ;
        C->setEmail(mail);
        C->setIdContrat(query.value("ID_CONTRAT").toInt());
    }else {delete C; return nullptr;}
    return C;*/
}
/*bool Client::exists(int id) {
    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT FROM CLIENT WHERE ID_CLIENT = :ID_CLIENT");
    query.bindValue(":ID_CLIENT", id);
    if (query.exec() && query.next()) {
        return true;
    } else {
        return false;
    }
}*/


/*QSqlQueryModel * Client::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from CLIENT");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Association"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type Association"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nom Representant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID contrat"));
    return model;
}
QSqlQueryModel * Client::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT ID_CLIENT AS \"ID\", NOM_ASSOCIATION AS \"Association\", "
                    "ADRESSE AS \"Address\", TYPE_ASSOCIATION AS \"Type\", "
                    "NOM_REP AS \"Representative\", EMAIL AS \"Email\", "
                    "ID_CONTRAT AS \"Contract\" FROM CLIENTS");

    return model;
}
bool Client::modifier(){
    QSqlQuery query;
    query.prepare("UPDATE CLIENTS SET NOM_ASSOCIATION = :nom_association, ADRESSE = :adresse, TYPE_ASSOCIATION = :type_association, NOM_REP = :nom_rep, EMAIL = :email, ID_CONTRAT = :id_contrat  WHERE ID_CLIENT = :id_client");
    query.bindValue(":id_client", id_c);
    query.bindValue(":nom_association", nomA);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type_association", typeA);
    query.bindValue(":nom_rep", nomR);
    query.bindValue(":email", email);
    query.bindValue(":id_contrat", id_contrat);
    if (query.exec()) {
        return true;
    } else {
        return false;
    }
}
*/
bool Client::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET NOM_ASSOCIATION = :NOM_ASSOCIATION, ADRESSE = :ADRESSE, "
                  "TYPE_ASSOCIATION = :TYPE_ASSOCIATION, NOM_REP = :NOM_REP, "
                  "EMAIL = :EMAIL, ID_CONTRAT = :ID_CONTRAT WHERE ID_CLIENT = :ID_CLIENT");

    query.bindValue(":ID_CLIENT", id_c);
    query.bindValue(":NOM_ASSOCIATION", nomA);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":TYPE_ASSOCIATION", typeA);
    query.bindValue(":NOM_REP", nomR);
    query.bindValue(":EMAIL", email);
    query.bindValue(":ID_CONTRAT", id_contrat);

    return query.exec();
}

int Client::countClients()
{
    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT FROM CLIENT");
    int count = 0;
    if (query.exec()) {
        while (query.next()) {
            count++;
        }
    }
    return count;
}

int Client::CalculMinister(){
    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT, NOM_ASSOCIATION, ADRESSE, TYPE_ASSOCIATION, NOM_REP, EMAIL, ID_CONTRAT  FROM CLIENT");
    int countM=0;
    if (query.exec()) {
        while (query.next()) {
          //  int id = query.value(0).toInt();
            //QString NomA = query.value(1).toString();
           // QString Adresse = query.value(2).toString();
            QString typeA = query.value(3).toString();
           /* QString NomR = query.value(4).toString();
            QString Email = query.value(5).toString();
            int contrat = query.value(6).toInt();*/
            if (typeA=="Ministère de Santé"){
                countM++;
                qDebug()<<"fi wost loop minister";
            }
        }
    }
   /* qDebug()<<countM<<" error:"<<query.lastError().text();
    QMessageBox::information(nullptr, QObject::tr("Minister:%1").arg(countM),
                             QObject::tr("connection successful.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);*/
    return countM;
}
int Client::CalculCentre(){
    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT, NOM_ASSOCIATION, ADRESSE, TYPE_ASSOCIATION, NOM_REP, EMAIL, ID_CONTRAT  FROM CLIENT");
    int countC=0;
    if (query.exec()) {
        while (query.next()) {
             QString typeA = query.value(3).toString();
            if(typeA=="Centre pharmaceutique"){
                countC++;
            }
        }
    }
    qDebug()<<countC<<" error:"<<query.lastError().text();
    return countC;
}
int Client::CalculLabo(){
    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT, NOM_ASSOCIATION, ADRESSE, TYPE_ASSOCIATION, NOM_REP, EMAIL, ID_CONTRAT  FROM CLIENT");
    int countL=0;
    if (query.exec()) {
        while (query.next()) {
            QString typeA = query.value(3).toString();
            if(typeA=="Laboratoire d'analyse"){
                countL++;
            }
        }
    }

    return countL;
}

QString Client::AdresseSup(){
    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT, ADRESSE  FROM CLIENT");
    if (query.exec()) {
        while (query.next()) {
            QString Adr = query.value(1).toString();

        }
    }
   // qDebug()<<countC<<" error:"<<query.lastError().text();
   // return countC;
}
/*  int Client::SupAdress(){
        QSqlQuery query;
        query.prepare("SELECT ADRESSE FROM CLIENT");
        vector<string> tab;
        int total=0;
        if (query.exec()) {
            while (query.next()) {
                tab.push_back(query.value(0).toString().toStdString()); // Add addresses to vector
                total++;
            }
        }
        // 2. Count occurrences using a frequency map
        multimap<string, int> freqMap;
        int mapcount=0;
        for (int i = 0; i < total; i++) {
            freqMap[tab[i]]++;
        }

        //count sup adress
        for (int i = 0; i < freqMap.size() ; i++) {
            int max= freqMap[tab[i]];
            for (int j = 0; j < total; j++) {
                if (freqMap[tab[j]]>max){
                    max=freqMap[tab[j]];
                }
            }
        }

        return max ; // Or whatever return value makes sense
}
  string Client::SupAdressname(){
      QSqlQuery query;
      query.prepare("SELECT ADRESSE FROM CLIENT");
      vector<string> tab;
      int total=0;
      if (query.exec()) {
          while (query.next()) {
              tab.push_back(query.value(0).toString().toStdString()); // Add addresses to vector
              total++;
          }
      }
      // 2. Count occurrences using a frequency map
      multimap<string, int> freqMap;
      for (int i = 0; i < total; i++) {
          freqMap[tab[i]]++;
      }
      //count sup adress
      string maxAddr;
      int maxCount = 0;
      for (map<string, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
          if (it->second > maxCount) {
              maxCount = it->second;
              maxAddr = it->first;
          }
      }

      return maxAddr;
  }*/

