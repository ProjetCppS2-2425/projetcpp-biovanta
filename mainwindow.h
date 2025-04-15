#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStackedWidget>
#include "employe.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_valider_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_modification_clicked();

    void on_annuler_clicked();

    void afficherStatistiquesEmployes();

    void on_pdfEmployes_clicked();

    void onTriComboBoxChanged(int index);

    void onSearchTextChanged(const QString &text);

    void on_quitButton_clicked();
    void showEmployePage();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
private:
    void refreshEmployeeTable();// Declaration
    QString currentSortColumn;
    QString currentSortOrder;
    void updateSearchQuery();
    void populateTable(QSqlQuery &query);


};
#endif // MAINWINDOW_H
