#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include "chercheur.h"
#include <QTableWidget>  // Include QTableWidget to handle the table
#include <QSqlQueryModel>  // Include QSqlQueryModel for database results

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pushButton_2_clicked();  // Slot for adding a Chercheur
    void refreshTable();          // Slot to refresh and display data in the table
    void onRadioButtonDeleteClicked();
    void onRadioButtonModifyClicked();


    void clearFields();


private:
    bool isDataFetched; //

private:
    QString selectedId;  // Add this variable to track the selected ID for modification



    // Slot to handle delete radio button click

public:
    bool modify(int id, const QString &nom, const QString &prenom, const QString &email, int num_tlp, const QString &domaine_recherche, const QString &projet_en_cours);
    // To modify a chercheur's details



private:
    Ui::MainWindow *ui;

    QTableWidget *tableWidget;
        // Declare the table widget

    // Make sure the tableWidget is instantiated and populated in your constructor or initialization
};



#endif // MAINWINDOW_H
