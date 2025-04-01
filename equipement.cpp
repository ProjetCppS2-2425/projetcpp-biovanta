#include "equipement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
// Constructeurs
Equipement::Equipement() {}

Equipement::Equipement(QString id, QString nom, QString etat, QByteArray image, QString type, QString dispo, int nombre) {
    this->id_equipement = id;
    this->nom_eq = nom;
    this->etat = etat;
    this->imageData = image;
    this->type = type;
    this->disponibilite = dispo;
    this->nbre_eq = nombre;
}


bool Equipement::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO Equipement (id_equipement, nom_eq, etat, image, type, disponibilite, nbre_eq) "
                  "VALUES (:id, :nom, :etat, :img, :type, :dispo, :nbre)");

    query.bindValue(":id", id_equipement);
    query.bindValue(":nom", nom_eq);
    query.bindValue(":etat", etat);
   query.bindValue(":img", imageData);
    query.bindValue(":type", type);
    query.bindValue(":dispo", disponibilite);
    query.bindValue(":nbre", nbre_eq);

    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        return false;
    }

    return true;
}


QList<Equipement> Equipement::afficher() {
    QList<Equipement> liste;
    QSqlQuery query("SELECT * FROM EQUIPEMENT");

    while (query.next()) {
        // Changement : Récupération des données binaires au lieu du chemin
        QByteArray imageData = query.value("image").toByteArray();
        liste.append(Equipement(
            query.value("id_equipement").toString(),
            query.value("nom_eq").toString(),
            query.value("etat").toString(),
            imageData,  // Changement : Passage des données binaires
            query.value("type").toString(),
            query.value("disponibilite").toString(),
            query.value("nbre_eq").toInt()
            ));
    }
    return liste;
}

bool Equipement::supprimer(const QString &id) {
    QSqlQuery query;
    query.prepare("DELETE FROM Equipement WHERE id_equipement = :id");
    query.bindValue(":id", id);
    return query.exec();
}


bool Equipement::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE Equipement SET "
                  "nom_eq = :nom, "
                  "type = :type, "
                  "etat = :etat, "
                  "disponibilite = :dispo, "
                  "image = :img, "
                  "nbre_eq = :nbre "
                  "WHERE id_equipement = :id");

    query.bindValue(":id", id_equipement);
    query.bindValue(":nom", nom_eq);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);
    query.bindValue(":dispo", disponibilite);
    query.bindValue(":img", imageData);
    query.bindValue(":nbre", nbre_eq);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification :" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}


Equipement Equipement::getEquipementById(const QString &id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM Equipement WHERE id_equipement = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Changement : Récupération des données binaires
        QByteArray imageData = query.value("image").toByteArray();
        return Equipement(
            query.value("id_equipement").toString(),
            query.value("nom_eq").toString(),
            query.value("etat").toString(),
            imageData,
            query.value("type").toString(),
            query.value("disponibilite").toString(),
            query.value("nbre_eq").toInt()
            );
    }
    return Equipement();
}

bool Equipement::existe(const QString &id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Equipement WHERE id_equipement = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0; // Retourne true si l'équipement existe
    }

    return false; // Retourne false en cas d'erreur ou si l'équipement n'existe pas
}

QSqlQueryModel* Equipement::rechercher(const QString& critere, const QString& valeur) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM EQUIPEMENT WHERE ";

    if (critere == "type") {
        queryStr += "type LIKE :valeur";
    }
    else if (critere == "id équipement") {
        queryStr += "id_equipement = :valeur";
    }
    else if (critere == "disponibilité") {
        queryStr += "disponibilite = :valeur";
    }

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":valeur", (critere == "type") ? "%" + valeur + "%" : valeur);

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur de recherche:" << query.lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}
