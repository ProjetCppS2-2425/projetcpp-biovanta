#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
#include <QSqlError>  // Add this

#include "test_biologique.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pushButton_2_clicked(); // Gère l'ajout et la suppression
    void refreshTable();
    void pushButton_3_clicked();  // Make sure this matches your UI button
    void on_suppButton_clicked();
    void onPdfButtonClicked();  // Déclaration du slot
    void on_stat_clicked();
    void onQRVerified(int testId);
    void onQRInvalid();
    void onSearchButtonClicked();

    void on_ok_clicked();
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
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    void clearFields();


     void setupSearchUI();






};

#endif // MAINWINDOW_H
