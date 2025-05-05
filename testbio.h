#ifndef TESTBIO_H
#define TESTBIO_H
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QDate>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QNetworkAccessManager>


#include <QMainWindow>
#include <QSqlQuery>
#include <QDesktopServices>  // For opening URLs
#include <QUrl>
#include "test_biologique.h"
#include <QNetworkReply>  // Add this line
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui {
class TestBio;  // Changed from MainWindow
}
QT_END_NAMESPACE

class TestBio : public QMainWindow  // Changed from MainWindow
{
    Q_OBJECT

public:
    explicit TestBio(QWidget *parent = nullptr);  // Changed constructor
    ~TestBio();  // Changed destructor

    QString selectedId;
      // For adding emoji buttons to table


private slots:
    void pushButton_2_clicked(); // Gère l'ajout et la suppression
    void refreshTable();
    void pushButton_3_clicked();  // Make sure this matches your UI button
    void on_suppButton_clicked();
    void onPdfButtonClicked();  // Déclaration du slot
    void on_stat_clicked();

    void onSearchClicked();
    void onCellClicked(int row, int column);




private:
    QPixmap generateQRCode(const QString& data, int size = 200);
    void addQRButtonToRow(int row, int testId);
private:
    // Méthodes de validation
    bool validateTestInputs(bool checkId = true, bool forModification = false);
    bool validateId();
    bool validateName();
    bool validateResearcher();
    bool validateDate();
    bool validateType();

    bool isDataFetched;
    // Méthodes utilitaires
    void highlightError(QWidget *widget, bool error = true);
    void clearAllHighlights();
    void setupConnections();
 void refreshTableWithSortedData(const QList<TestBiologique>& tests);
    Ui::TestBio *ui;  // Changed from MainWindow
    QTableWidget *tableWidget;
    void clearFields();

private slots:

    void onSortOrderChanged();
    void displayTests(const QList<TestBiologique>& tests);
    void applySorting();
    void onTriChanged();


};

#endif // TESTBIO_H
