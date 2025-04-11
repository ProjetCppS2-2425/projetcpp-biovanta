#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts>  // Keep this include

// Remove QT_CHARTS_USE_NAMESPACE and use this instead:
QT_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_END_NAMESPACE
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include "chercheur.h"
#include <QTableWidget>  // Include QTableWidget to handle the table
#include <QSqlQueryModel>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>// Include QSqlQueryModel for database results

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

    void onSuppButtonClicked();


    void clearFields();


private:
    bool isDataFetched; //

private:
    QString selectedId;  // Add this variable to track the selected ID for modification


 // Add this declaration

    // Slot to handle delete radio button click

public:
    bool modify(int id, const QString &nom, const QString &prenom, const QString &email, int num_tlp, const QString &domaine_recherche, const QString &projet_en_cours);
    bool validateInput(int id, const QString& nom, const QString& prenom, const QString& email, int num_tlp, const QString& projet_en_cours);


private slots:
    void on_stat_clicked();
    void onPdfButtonClicked();



    // Add this in the MainWindow class declaration:
  // Add this line

private:
    // ... existing members ...

    // Add helper function:
    int getResearcherIdFromRow(int row);  // Add this line



private slots:
    // Add this slot for search functionality
    void onSearchButtonClicked();
    void applySort();

private slots:
    void showHistory(int researcherId);  // Add this declaration

private:
    Ui::MainWindow *ui;
    QString getSearchField(int index) const;

    QTableWidget *tableWidget;
        // Declare the table widget

    // Make sure the tableWidget is instantiated and populated in your constructor or initialization
};



#endif // MAINWINDOW_H
