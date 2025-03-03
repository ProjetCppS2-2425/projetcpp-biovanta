#include "equipement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
// Constructeurs
Equipement::Equipement() {}

Equipement::Equipement(QString id, QString nom, QString etat, QString image, QString type, QString dispo, int nombre) {
    this->id_equipement = id;
    this->nom_eq = nom;
    this->etat = etat;
    this->image = image;
    this->type = type;
    this->disponibilite = dispo;
    this->nbre_eq = nombre;
}


bool Equipement::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO Equipement (ID_EQUIPEMENT, NOM_EQ, ETAT, IMAGE, TYPE, DISPONIBILITÉ, NBRE_EQ) "
                  "VALUES (:id, :nom, :etat, :image, :type, :disponibilite, :nbre)");
    query.bindValue(":id", id_equipement);
    query.bindValue(":nom", nom_eq);
    query.bindValue(":etat", etat);
    query.bindValue(":image", image);
    query.bindValue(":type", type);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":nbre", nbre_eq);

    return query.exec();
}

QList<Equipement> Equipement::afficher() {
    QList<Equipement> liste;
    QSqlQuery query("SELECT * FROM EQUIPEMENT");

    while (query.next()) {
        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString etat = query.value(2).toString();
        QString image = query.value(3).toString();
        QString type = query.value(4).toString();
        QString dispo = query.value(5).toString();
        int nombre = query.value(6).toInt();

        liste.append(Equipement(id, nom, etat, image, type, dispo, nombre));
    }
    return liste;
}

bool Equipement::supprimer(const QString &id) {
    // Vérification de la connexion à la base de données
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "La connexion à la base de données a échoué.";
        return false;
    }

    // Vérification de l'existence de l'équipement dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM \"MANEL\".\"EQUIPEMENT\" WHERE \"ID_EQUIPEMENT\" = :id");
    checkQuery.bindValue(":id", id);
    if (!checkQuery.exec()) {
        qDebug() << "Erreur lors de la vérification de l'ID : " << checkQuery.lastError().text();
        return false;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count == 0) {
        qDebug() << "Aucun équipement trouvé avec l'ID : " << id;
        return false;
    }

    // Requête de suppression
    QSqlQuery query;
    query.prepare("DELETE FROM \"MANEL\".\"EQUIPEMENT\" WHERE \"ID_EQUIPEMENT\" = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'équipement : " << query.lastError().text();
        return false;
    }

    qDebug() << "Suppression réussie pour l'équipement avec ID : " << id;
    return true;
}
