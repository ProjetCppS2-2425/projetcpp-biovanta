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
    query.prepare("INSERT INTO Equipement (id_equipement, nom_eq, etat, image, type, disponibilite, nbre_eq) "
                  "VALUES (:id, :nom, :etat, :img, :type, :dispo, :nbre)");

    query.bindValue(":id", id_equipement);
    query.bindValue(":nom", nom_eq);
    query.bindValue(":etat", etat);
    query.bindValue(":img", image);
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
    checkQuery.prepare("SELECT COUNT(*) FROM \"RAWEN\".\"EQUIPEMENT\" WHERE \"ID_EQUIPEMENT\" = :id");
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
    query.prepare("DELETE FROM \"RAWEN\".\"EQUIPEMENT\" WHERE \"ID_EQUIPEMENT\" = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'équipement : " << query.lastError().text();
        return false;
    }

    qDebug() << "Suppression réussie pour l'équipement avec ID : " << id;
    return true;
}

bool Equipement::modifier() {
    QSqlQuery query;

    // Vérifier si l'équipement existe avant modification
    query.prepare("SELECT COUNT(*) FROM Equipement WHERE id_equipement = :id");
    query.bindValue(":id", id_equipement);

    if (!query.exec() || !query.next() || query.value(0).toInt() == 0) {
        qDebug() << "Erreur : Aucun équipement trouvé avec l'ID :" << id_equipement;
        return false;
    }

    // Préparer la requête de mise à jour
    query.prepare("UPDATE Equipement SET nom_eq = :nom, type = :type, etat = :etat, "
                  "disponibilite = :dispo, image = :img, nbre_eq = :nbre "
                  "WHERE id_equipement = :id");

    query.bindValue(":id", id_equipement);
    query.bindValue(":nom", nom_eq);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);
    query.bindValue(":dispo", disponibilite);
    query.bindValue(":img", image);
    query.bindValue(":nbre", nbre_eq);

    // Exécuter la requête et vérifier le succès
    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification :" << query.lastError().text();
        return false;
    }

    qDebug() << "Modification réussie pour l'équipement ID :" << id_equipement;
    return true;
}
Equipement Equipement::getEquipementById(const QString &id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM Equipement WHERE id_equipement = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString id = query.value("id_equipement").toString();
        QString nom = query.value("nom_eq").toString();
        QString etat = query.value("etat").toString();
        QString image = query.value("image").toString(); // Récupérer le nom du fichier image
        QString type = query.value("type").toString();
        QString dispo = query.value("disponibilite").toString();
        int nombre = query.value("nbre_eq").toInt();

        return Equipement(id, nom, etat, image, type, dispo, nombre);
    }

    return Equipement(); // Retourne un équipement vide si non trouvé
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
