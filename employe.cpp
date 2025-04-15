#include "employe.h"
#include <QSqlError>

Employe::Employe()
    : m_id(0), m_nom(""), m_prenom(""), m_email(""), m_numTel(0),
    m_dateEmbauche(QDate()), m_salaire(0.0), m_poste(""), m_mdp("")
{
}

Employe::Employe(int id, const QString &nom, const QString &prenom, const QString &email,
                 int numTel, const QDate &dateEmbauche,
                 const QString &poste,double salaire, const QString &mdp)
    : m_id(id), m_nom(nom), m_prenom(prenom), m_email(email), m_numTel(numTel),
    m_dateEmbauche(dateEmbauche), m_salaire(salaire), m_poste(poste), m_mdp(mdp)
{
}

// Getters
int Employe::getId() const { return m_id; }
QString Employe::getNom() const { return m_nom; }
QString Employe::getPrenom() const { return m_prenom; }
QString Employe::getEmail() const { return m_email; }
int Employe::getNumTel() const { return m_numTel; }
QDate Employe::getDateEmbauche() const { return m_dateEmbauche; }
double Employe::getSalaire() const { return m_salaire; }
QString Employe::getposte() const { return m_poste; }
QString Employe::getMdp() const { return m_mdp; }

// Setters
void Employe::setId(int id) { m_id = id; }
void Employe::setNom(const QString &nom) { m_nom = nom; }
void Employe::setPrenom(const QString &prenom) { m_prenom = prenom; }
void Employe::setEmail(const QString &email) { m_email = email; }
void Employe::setNumTel(int numTel) { m_numTel = numTel; }
void Employe::setDateEmbauche(const QDate &dateEmbauche) { m_dateEmbauche = dateEmbauche; }
void Employe::setSalaire(double salaire) { m_salaire = salaire; }
void Employe::setposte(const QString &poste) { m_poste = poste; }
void Employe::setMdp(const QString &mdp) { m_mdp = mdp; }

// CRUD Operations
bool Employe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, EMAIL, NUM_TLP, DATE_EMBAUCHE, POSTE, SALAIRE, MDP) "
                  "VALUES ( :nom, :prenom, :email, :numTel, TO_DATE(:dateEmbauche, 'DD-MM-YYYY'), :poste, :salaire, :mdp)");



    // Debugging Output
    qDebug() << "Trying to insert employee:";
    qDebug() << "Nom:" << m_nom;
    qDebug() << "Prénom:" << m_prenom;
    qDebug() << "Email:" << m_email;
    qDebug() << "Téléphone:" << QString::number(m_numTel);
    qDebug() << "Date Embauche:" << m_dateEmbauche.toString("dd-MM-yyyy");
    qDebug() << "Salaire:" << m_salaire;
    qDebug() << "Poste:" << m_poste;
    qDebug() << "Mot de passe:" << m_mdp;

    query.bindValue(":nom", m_nom);
    query.bindValue(":prenom", m_prenom);
    query.bindValue(":email", m_email);
    query.bindValue(":numTel", m_numTel);
    query.bindValue(":dateEmbauche", m_dateEmbauche.toString("dd-MM-yyyy"));
    query.bindValue(":poste", m_poste);
    query.bindValue(":salaire", m_salaire);

    query.bindValue(":mdp", m_mdp);

    // Execute Query
    bool success = query.exec();

    if (!success) {
        qDebug() << "Insertion failed:" << query.lastError().text();
    }

    return success;
}



bool Employe::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM employe WHERE ID = :id");
    query.bindValue(":id", id);
    return query.exec();
}
QString Employe::getLastError() const
{
    return lastError;  // Add 'lastError' member variable
}

QSqlQueryModel* Employe::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID, NOM, PRENOM, EMAIL, NUM_TLP, DATE_EMBAUCHE,  POSTE, SALAIRE, MDP FROM EMPLOYE");

    // Column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Embauche"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Mot de passe"));

    return model;
}
bool Employe::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET "
                  "NOM = :nom, PRENOM = :prenom, EMAIL = :email, "
                  "NUM_TLP = :tel, DATE_EMBAUCHE = :date, POSTE = :poste, "
                  "SALAIRE = :salaire, MDP = :mdp "
                  "WHERE ID = :id");

    // Bind all values properly
    query.bindValue(":nom", m_nom);
    query.bindValue(":prenom", m_prenom);
    query.bindValue(":email", m_email);
    query.bindValue(":tel", m_numTel);
    query.bindValue(":date", m_dateEmbauche);
    query.bindValue(":poste", m_poste);
    query.bindValue(":salaire", m_salaire);
    query.bindValue(":mdp", m_mdp);
    query.bindValue(":id", m_id);

    if(query.exec()) {
        return true;
    } else {
        lastError = query.lastError().text();  // Store error
        return false;
    }
}

