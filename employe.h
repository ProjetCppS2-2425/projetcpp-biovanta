#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe {
public:
    // Constructors
    Employe();
    Employe(int id, const QString &nom, const QString &prenom, const QString &email,
            int numTel, const QDate &dateEmbauche,
            const QString &poste, double salaire, const QString &mdp);

QString getLastError() const;
    // Getters
    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    int getNumTel() const;
    QDate getDateEmbauche() const;
    double getSalaire() const;
    QString getposte() const;
    QString getMdp() const;

    // Setters
    void setId(int id);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setEmail(const QString &email);
    void setNumTel(int numTel);
    void setDateEmbauche(const QDate &dateEmbauche);
    void setSalaire(double salaire);
    void setposte(const QString &poste);
    void setMdp(const QString &mdp);

    // CRUD Operations
    bool ajouter();
    bool supprimer(int id);
    QSqlQueryModel* afficher();
     bool modifier();

private:
    int m_id;
    QString m_nom;
    QString m_prenom;
    QString m_email;
    int m_numTel;
    QDate m_dateEmbauche;
    double m_salaire;
    QString m_poste;
    QString m_mdp;
    QString lastError;

};

#endif // EMPLOYE_H
