#include "chercheur.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Chercheur::Chercheur() {}

Chercheur::Chercheur(int id, QString nom, QString prenom, QString email, int num_tlp, QString domaine_recherche, QString projet_en_cours) {
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
    this->num_tlp = num_tlp;
    this->domaine_recherche = domaine_recherche;
    this->projet_en_cours = projet_en_cours;
}

bool Chercheur::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO CHERCHEUR (ID_CHERCHEUR, NOM, PRENOM, EMAIL, NUM_TLP, DOMAINE_RECHERCHE, PROJET_EN_COURS) "
                  "VALUES (:id, :nom, :prenom, :email, :num_tlp, :domaine_recherche, :projet_en_cours)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":num_tlp", num_tlp);
    query.bindValue(":domaine_recherche", domaine_recherche);
    query.bindValue(":projet_en_cours", projet_en_cours);

    if (!query.exec()) {
        qDebug() << "SQL Error: " << query.lastError().text();
        return false;
    }
    return true;
}
QList<Chercheur> Chercheur::afficher() {
    QList<Chercheur> chercheursList;

    QSqlQuery query;
    query.prepare("SELECT * FROM CHERCHEUR");

    if (!query.exec()) {
        qDebug() << "SQL Error: " << query.lastError().text();
        return chercheursList;
    }

    // Loop through the result set and create Chercheur objects
    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        QString email = query.value(3).toString();
        int num_tlp = query.value(4).toInt();
        QString domaine_recherche = query.value(5).toString();
        QString projet_en_cours = query.value(6).toString();
        Chercheur chercheur(id, nom, prenom, email, num_tlp, domaine_recherche, projet_en_cours);
        chercheursList.append(chercheur);
    }

    return chercheursList;
}

bool Chercheur::supprimer(int id) {
    QSqlQuery query;

    // Prepare the SQL query to delete a record
    query.prepare("DELETE FROM CHERCHEUR WHERE ID_CHERCHEUR = :id");
    query.bindValue(":id", id);

    // Execute the query
    if (!query.exec()) {
        // If the query fails, log the error and return false
        qDebug() << "SQL Error: " << query.lastError().text();
        return false;
    }

    // If the query succeeds, return true
    return true;
}
bool Chercheur::fetchDataById(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM CHERCHEUR WHERE ID_CHERCHEUR = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Assuming you have getters for all fields:
        setNom(query.value("NOM").toString());
        setPrenom(query.value("PRENOM").toString());
        setEmail(query.value("EMAIL").toString());
        setNumTlp(query.value("NUM_TLP").toInt());
        setDomaineRecherche(query.value("DOMAINE_RECHERCHE").toString());
        setProjetEnCours(query.value("PROJET_EN_COURS").toString());
        return true;
    }
    return false;
}
bool Chercheur::modify(int id, const QString &nom, const QString &prenom, const QString &email, int num_tlp, const QString &domaine_recherche, const QString &projet_en_cours) {
    QSqlQuery query;
    query.prepare("UPDATE CHERCHEUR SET nom = :nom, prenom = :prenom, email = :email, num_tlp = :num_tlp, domaine_recherche = :domaine_recherche, projet_en_cours = :projet_en_cours WHERE ID_CHERCHEUR = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":num_tlp", num_tlp);
    query.bindValue(":domaine_recherche", domaine_recherche);
    query.bindValue(":projet_en_cours", projet_en_cours);

    // Debug: Print the query and values
    qDebug() << "Executing query:" << query.lastQuery();
    qDebug() << "Values:" << id << nom << prenom << email << num_tlp << domaine_recherche << projet_en_cours;

    if (query.exec()) {
        qDebug() << "Researcher updated successfully!";
        return true;
    } else {
        qDebug() << "Failed to update researcher:" << query.lastError().text();
        return false;
    }
}
