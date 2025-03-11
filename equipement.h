#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Equipement {
private:
    QString id_equipement;
    QString nom_eq;
    QString etat;
    QString image;
    QString type;
    QString disponibilite;
    int nbre_eq;

public:
    Equipement();
    Equipement(QString id, QString nom, QString etat, QString image, QString type, QString dispo, int nombre);



    bool ajouter();
    static QList<Equipement> afficher();
    bool modifier();
    bool supprimer(const QString &id);
    bool existe(const QString &id);
    // Ajoutez cette déclaration
    static Equipement getEquipementById(const QString &id);
    QString getId() const { return id_equipement; }
    QString getNom() const { return nom_eq; }
    QString getEtat() const { return etat; }
    QString getImage() const { return image; }
    QString getType() const { return type; }
    QString getDispo() const { return disponibilite; }
    int getNombre() const { return nbre_eq; }


    void setId(const QString &id) { id_equipement = id; }
    void setNom(const QString &nom) { nom_eq = nom; }
    void setEtat(const QString &etat) { this->etat = etat; }
    void setImage(const QString &img) { image = img; }
    void setType(const QString &type) { this->type = type; }
    void setDispo(const QString &dispo) { disponibilite = dispo; }
    void setNombre(int nombre) { nbre_eq = nombre; }

};

#endif // EQUIPEMENT_H
