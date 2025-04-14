#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QByteArray>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Equipement {
private:
    QString id_equipement;
    QString nom_eq;
    QString etat;
    QByteArray imageData;
    QString type;
    QString disponibilite;
    int nbre_eq;

public:
    Equipement();
    Equipement(QString id, QString nom, QString etat, QByteArray image, QString type, QString dispo, int nombre);
    bool ajouter();
    static QList<Equipement> afficher();
    bool modifier();
    bool supprimer(const QString &id);
    static void sendEmail(const QString &to, const QString &subject, const QString &body);


    bool existe(const QString &id);
    static Equipement getEquipementById(const QString &id);
    static QSqlQueryModel* rechercher(const QString& critere, const QString& valeur);
    static QList<Equipement> getEquipementsNonFonctionnels();
    static int countEquipementsNonFonctionnels();
    static int countEquipementsParEtat(const QString &etat);

    QString getId() const { return id_equipement; }
    QString getNom() const { return nom_eq; }
    QString getEtat() const { return etat; }
    QByteArray getImageData() const { return imageData; }
    QString getType() const { return type; }
    QString getDispo() const { return disponibilite; }
    int getNombre() const { return nbre_eq; }


    void setId(const QString &id) { id_equipement = id; }
    void setNom(const QString &nom) { nom_eq = nom; }
    void setEtat(const QString &etat) { this->etat = etat; }
    void setImageData(const QByteArray &data) { imageData = data; }
    void setType(const QString &type) { this->type = type; }
    void setDispo(const QString &dispo) { disponibilite = dispo; }
    void setNombre(int nombre) { nbre_eq = nombre; }
};

#endif // EQUIPEMENT_H
