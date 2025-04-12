#ifndef VACCIN_H
#define VACCIN_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class vaccin
{

private:
    QString id_vaccin,nom_vaccin,type_vaccin,nombres_doses;
    float temperature_conservation;
    QDate date_expiration;

public:
    vaccin();
    vaccin(QString,QString,QString,float,QString,QDate);

    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprime(QString);
    bool modifier();

    // Getters
    QString getIdVaccin() const { return id_vaccin; }
    QString getNomVaccin() const { return nom_vaccin; }
    QString getTypeVaccin() const { return type_vaccin; }
    QString getNombresDoses() const { return nombres_doses; }
    float getTemperatureConservation() const { return temperature_conservation; }
    QDate getDateExpiration() const { return date_expiration; }

    // Setters
    void setIdVaccin(const QString& id) { id_vaccin = id; }
    void setNomVaccin(const QString& nom) { nom_vaccin = nom; }
    void setTypeVaccin(const QString& type) { type_vaccin = type; }
    void setNombresDoses(const QString& doses) { nombres_doses = doses; }
    void setTemperatureConservation(float temp) { temperature_conservation = temp; }
    void setDateExpiration(const QDate& date) { date_expiration = date; }

    vaccin * readvaccin (QString val);//pdf

    QSqlQueryModel * afficher_choix_ASC(QString choix);//tri
    QSqlQueryModel * afficher_choix_DSC(QString choix);
    QSqlQueryModel *afficher_temperature_conservation(QString ch);//recherche
    QSqlQueryModel *afficher_nom_vaccin(QString ch);
    QSqlQueryModel *afficher_type_vaccin(QString ch);

    int statistique1();//stat
    int statistique2();


    // metiers avancées //
    void sendSMS(const QString& phoneNumber , const QString& message );
    QString constructSMS(const QString& nomSponsor);

};

#endif // VACCIN_H
