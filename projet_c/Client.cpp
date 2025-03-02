#include "Client.h"

Client::Client(int id_client, QString nom_association, QString adresse, QString type_association,
               QString nom_rep, QString email, int id_contrat, int ID_emp)
{
    this->id_client=id_client;
    this->nom_association=nom_association;
    this->adresse=adresse;
    this->type_association=type_association;
    this->nom_rep=nom_rep;
    this->email=email;
    this->id_contrat=id_contrat,
    this->ID_emp=ID_emp;
}

int Client::getIdClient()  {
    return id_client;
}
QString Client::getNomA()  {
    return nom_association;
}
QString Client::getAdresse()  {
    return adresse;
}
QString Client::getTypeA()  {
    return type_association;
}
QString Client::getNomR()  {
    return nom_rep;
}
QString Client::getEmail()  {
    return email;
}
int Client::getIdContrat()  {
    return id_contrat;
}
int Client::getIdEmp()  {
    return ID_emp;
}


void Client::setIdClient(int id_client) {
    this->id_client = id_client;
}
void Client::setNomA( QString &nom_association) {
    this->nom_association = nom_association;
}
void Client::setAdresse( QString &adresse) {
    this->adresse = adresse;
}
void Client::setTypeA( QString &type_association) {
    this->type_association = type_association;
}
void Client::setNomR( QString &nom_rep) {
    this->nom_rep = nom_rep;
}
void Client::setEmail( QString &email) {
    this->email = email;
}
void Client::setIdContrat(int id_contrat) {
    this->id_contrat = id_contrat;
}
void Client::setIdEmp(int ID_emp) {
    this->ID_emp = ID_emp;
}
