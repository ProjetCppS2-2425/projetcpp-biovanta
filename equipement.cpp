#include "equipement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QFile>
#include <QProcess>
// Constructeurs
Equipement::Equipement() {}

Equipement::Equipement(QString id, QString nom, QString etat, QByteArray image, QString type, QString dispo, int nombre, QDate debut, QDate fin) {
    this->id_equipement = id;
    this->nom_eq = nom;
    this->etat = etat;
    this->imageData = image;
    this->type = type;
    this->disponibilite = dispo;
    this->nbre_eq = nombre;
    this->dateDebutDispo = debut;
    this->dateFinDispo = fin;
}


bool Equipement::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO Equipement (id_equipement, nom_eq, etat, image, type, disponibilite, nbre_eq, date_debut, date_fin) "
                  "VALUES (:id, :nom, :etat, :img, :type, :dispo, :nbre, :debut, :fin)");
    query.bindValue(":id", id_equipement);
    query.bindValue(":nom", nom_eq);
    query.bindValue(":etat", etat);
    query.bindValue(":img", imageData);
    query.bindValue(":type", type);
    query.bindValue(":dispo", disponibilite);
    query.bindValue(":nbre", nbre_eq);
    query.bindValue(":debut", dateDebutDispo);
    query.bindValue(":fin", dateFinDispo);

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
        Equipement e(
            query.value("id_equipement").toString(),
            query.value("nom_eq").toString(),
            query.value("etat").toString(),
            query.value("image").toByteArray(),
            query.value("type").toString(),
            query.value("disponibilite").toString(),
            query.value("nbre_eq").toInt()
            );
        e.setDateDebutDispo(query.value("date_debut").toDate());
        e.setDateFinDispo(query.value("date_fin").toDate());
        liste.append(e);
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
                  "nbre_eq = :nbre, "
                  "date_debut = :debut, "
                  "date_fin = :fin "
                  "WHERE id_equipement = :id");

    query.bindValue(":id", id_equipement);
    query.bindValue(":nom", nom_eq);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);
    query.bindValue(":dispo", disponibilite);
    query.bindValue(":img", imageData);
    query.bindValue(":nbre", nbre_eq);
    query.bindValue(":debut", dateDebutDispo);
    query.bindValue(":fin", dateFinDispo);

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
        return query.value(0).toInt() > 0;
    }

    return false;
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
    else if (critere == "disponibilite") {
        queryStr += "disponibilité = :valeur";
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

QList<Equipement> Equipement::getEquipementsNonFonctionnels()
{
    QList<Equipement> liste;
    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPEMENT WHERE "
                  "(LOWER(etat) LIKE '%pas fonctionnel%' OR "
                  "LOWER(etat) LIKE '%non fonctionnel%' OR "
                  "LOWER(etat) LIKE '%maintenance%')");

    if (query.exec()) {
        while (query.next()) {
            liste.append(Equipement(
                query.value("id_equipement").toString(),
                query.value("nom_eq").toString(),
                query.value("etat").toString(),
                query.value("image").toByteArray(),
                query.value("type").toString(),
                query.value("disponibilite").toString(),
                query.value("nbre_eq").toInt()
                ));
        }
    } else {
        qDebug() << "Erreur lors de la récupération des équipements non fonctionnels:"
                 << query.lastError().text();
    }
    return liste;
}

int Equipement::countEquipementsNonFonctionnels() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EQUIPEMENT WHERE LOWER(etat) LIKE '%pas fonctionnel%' OR LOWER(etat) LIKE '%maintenance%'");
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Erreur lors du comptage:" << query.lastError().text();
    }
    return 0;
}
int Equipement::countEquipementsParEtat(const QString &etatRecherche) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EQUIPEMENT WHERE LOWER(TRIM(etat)) LIKE LOWER(TRIM(?))");
    query.addBindValue("%" + etatRecherche + "%"); // Recherche partielle

    if (!query.exec()) {
        qDebug() << "Erreur SQL (countEquipementsParEtat):" << query.lastError().text();
        return 0;
    }

    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

