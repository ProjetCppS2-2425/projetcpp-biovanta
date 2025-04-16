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
#include <QTableWidget>
#include <QMainWindow>

#include "ai_report_generator.h"// Include QSqlQueryModel for database results

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
    bool isDataFetched;

private:
    QString selectedId;  // Add this variable to track the selected ID for modification


    // Add this declaration

    // Slot to handle delete radio button click

public:
    bool modify(int id, const QString &nom, const QString &prenom, const QString &email, int num_tlp, const QString &domaine_recherche, const QString &projet_en_cours);
    bool validateInput(int id, const QString& nom, const QString& prenom, const QString& email, int num_tlp, const QString& projet_en_cours);




    // Update slot name to match signal

private slots:
    void on_searchButton_clicked();
    void onTriClicked();
    void on_stat_clicked();
    void onPdfButtonClicked();
    void onCellClicked(int row, int column);

private slots:
    void updateReportInTable(const QString &projectName, const QString &report);






private:
    Ui::MainWindow *ui;
     AIReportGenerator* m_aiGenerator;

    // Add connection tracking
    bool m_aiConnected = false; // Add this member
     ;  // Column index for report in tableWidget_5
    // Table column constants
    enum Table5Columns {
        T5_NOM_COL = 0,
        T5_ID_COL,
        T5_PROJET_COL,
        T5_RAPPORT_COL
    };

    void showResearcherHistory(int row);
    void addHistoryIcon(int row, int researcherId);

    // Add this constant (or make it a static const class member)
    static const int HISTORY_COLUMN = 7;
    QTableWidget *tableWidget;
        // Declare the table widget

    // Make sure the tableWidget is instantiated and populated in your constructor or initialization
};



#endif // MAINWINDOW_H
