#ifndef CHERCHEUR_H
#define CHERCHEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QList>

class Chercheur {
private:
    int id;
    QString nom;
    QString prenom;
    QString email;
    int num_tlp;
    QString domaine_recherche;
    QString projet_en_cours;

public:
    // Constructors
    Chercheur();
    Chercheur(int id, QString nom, QString prenom, QString email, int num_tlp, QString domaine_recherche, QString projet_en_cours);

    // Getter Methods
    int getId() const { return id; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getEmail() const { return email; }
    int getNumTlp() const { return num_tlp; }
    QString getDomaineRecherche() const { return domaine_recherche; }
    QString getProjetEnCours() const { return projet_en_cours; }

    // Setter Methods
    void setId(int newId) { id = newId; }
    void setNom(const QString& newNom) { nom = newNom; }
    void setPrenom(const QString& newPrenom) { prenom = newPrenom; }
    void setEmail(const QString& newEmail) { email = newEmail; }
    void setNumTlp(int newNumTlp) { num_tlp = newNumTlp; }
    void setDomaineRecherche(const QString& newDomaineRecherche) { domaine_recherche = newDomaineRecherche; }
    void setProjetEnCours(const QString& newProjetEnCours) { projet_en_cours = newProjetEnCours; }

    // Database Methods
    bool ajouter(); // To add a new chercheur
    static QList<Chercheur> afficher(); // Static method to display all chercheurs
    bool supprimer(int id); // To remove a chercheur by ID
    bool modify(int id, const QString &nom, const QString &prenom, const QString &email, int num_tlp, const QString &domaine_recherche, const QString &projet_en_cours);

    // Additional method to fetch data by ID (for deletion purposes)
    bool fetchDataById(int id); // To fetch the chercheur data from the database by ID
};

#endif // CHERCHEUR_H
