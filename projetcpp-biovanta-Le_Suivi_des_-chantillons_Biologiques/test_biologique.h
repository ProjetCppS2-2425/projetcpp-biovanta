#ifndef TEST_BIOLOGIQUE_H
#define TEST_BIOLOGIQUE_H
#include <QTableWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QList>
#include <QDate>
#include <QFile>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
class TestBiologique {
private:
    int id_test;
    QString nom;
    QString type;
    QString Chercheur_responsable;
    QDate date_pre;

public:
    // Constructors
    TestBiologique();
    TestBiologique(int id_test, QString nom, QString type,QString Chercheur_responsable, QDate date_pre);

    // Getter Methods
    int getIdTest() const { return id_test; }
    QString getNom() const { return nom; }
    QString getType() const { return type; }
    QString getChercheur_responsable() const { return Chercheur_responsable; }
    QDate getDatePre() const { return date_pre; }
    // Setter Methods
    void setIdTest(int newIdTest) { id_test = newIdTest; }
    void setNom(const QString& newNom) { nom = newNom; }
    void setType(const QString& newType) { type = newType; }
    void setChercheur_responsable(const QString& newChercheur_responsable) { Chercheur_responsable = newChercheur_responsable; }
    void setDatePre(const QDate &d) { date_pre = d; }
    // Database Methods
    bool ajouter(); // Add a new test
    static QList<TestBiologique> afficher(); // Display all tests
    bool modifier(int id_test, const QString &nom, const QString &type, const QString &Chercheur_responsable, QDate date_pre);    // Fetch data by ID
    bool fetchDataById(int id_test);

    // PDF operations
    bool extractFromPDF(const QString &filePath);
    bool generatePDFReport(const QString &filePath);
    static void generatePDF(const QString &filePath, QWidget *parent = nullptr);
    static void afficherStatistiques(QWidget *parent);

    //qr code

    static QList<TestBiologique> rechercherTests(const QString& terme, const QString& filtre);
    static void afficherResultats(const QList<TestBiologique>& resultats, QTableWidget* table);

    static QList<TestBiologique> searchByIdNameType(const QString &searchTerm, const QString &filterField);

};


#endif // TEST_BIOLOGIQUE_H
