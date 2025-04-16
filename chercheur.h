#ifndef CHERCHEUR_H
#define CHERCHEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QList>
#include <QStringList>
#include <QLabel>
#include <QString>
#include <QSqlQuery>
#include <QTableWidget>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QString>
#include <QMap>
#include <QStringList>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QPrinter>
#include <QTextTableCell>
#include <QTextDocument>
#include <QTextCursor>
#include <QFileDialog>
#include <QPushButton>
#include <QSqlError>
#include <QDebug>
#include <QDesktopServices>  // Add this include at the top
#include <QUrl>
#include <QPrinter>
#include <QTextDocument>
#include <QTextTable>
#include <QTextCursor>
#include <QTextTableCell>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QFont>
#include <QColor>
#include <QDate>
#include <QInputDialog>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QComboBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
class QLineEdit;
class QLabel;

class Chercheur {
private:
    int id;
    QString nom;
    QString prenom;
    QString email;
    int num_tlp;
    QString domaine_recherche;
    QString projet_en_cours;
    static QHash<int, QList<QPair<QString, QDateTime>>> projectHistory;
    void initProjectJson();



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


    // Database Methods
    bool ajouter(); // To add a new chercheur
    static QList<Chercheur> afficher();  // Static method to display all chercheurs
    bool supprimer(int id); // To remove a chercheur by ID
    bool modify(int id, const QString &nom, const QString &prenom,
                const QString &email, int num_tlp,
                const QString &domaine_recherche, const QString &newProject);
    static void generatePDF(const QString &filePath, QWidget *parent);
    static void afficherStatistiques(QStackedWidget *stackedWidget);
    bool fetchDataById(int id);
    static QList<Chercheur> searchChercheur(const QString &searchTerm, const QString &filter);
    static QList<Chercheur> getChercheursSorted(const QString& sortBy, bool ascending);
 QString getCurrentProject() const;
    QString getFullProjectJson() const { return projet_en_cours; }
    QString getFormattedHistory() const;
    QString cleanProjectName(const QString &project) const;

    void updateProjectHistory(const QString &newProject);
     void cleanCurrentProject();
    static void generatePDF(const QString& filePath, const QList<Chercheur>& chercheurs);

    private:

          QString getReport() const;
        // ...

    // Function to display search results in a QTableWidget








};

#endif // CHER
