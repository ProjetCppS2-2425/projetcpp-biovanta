
#ifndef CHERCHEUR_1_H
#define CHERCHEUR_1_H

#include <QtCharts>
#include <QPixmap>
#include <QIcon>
#include <QMainWindow>
#include "chercheur.h"
#include <QTableWidget>
#include <QSqlQueryModel>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include "ai_report_generator.h"
#include "arduino1.h"

QT_BEGIN_NAMESPACE
class QChartView;
class QChart;
namespace Ui {
class chercheur_1;  // Changed from MainWindow
}
QT_END_NAMESPACE

class chercheur_1 : public QMainWindow  // Changed from MainWindow
{
    Q_OBJECT

public:
   chercheur_1(QWidget *parent = nullptr);  // Changed
    ~chercheur_1();  // Changed

private slots:
    void pushButton_2_clicked();
    void refreshTable();
    void onSuppButtonClicked();
    void clearFields();

public:
    bool modify(int id, const QString &nom, const QString &prenom, const QString &email,
                int num_tlp, const QString &domaine_recherche, const QString &projet_en_cours);
    bool validateInput(int id, const QString& nom, const QString& prenom,
                       const QString& email, int num_tlp, const QString& projet_en_cours);

private slots:
    void on_searchButton_clicked();
    void onTriClicked();
    void on_stat_clicked();
    void onPdfButtonClicked();
    void onCellClicked(int row, int column);

    void generateHistoryPDF(int researcherId);
    void addReportIcon(int row, int researcherId, const QString& projectName);
    void displayReportForProject(const QString& projectName);

private:
    Ui::chercheur_1 *ui;  // Changed
    AIReportGenerator* m_aiGenerator;
    arduino arduino;
    bool isDataFetched;
    QString selectedId;
    bool m_aiConnected = false;
    QTableWidget *tableWidget;

    enum Table5Columns {
        T5_NOM_COL = 0,
        T5_ID_COL,
        T5_PROJET_COL,
        T5_RAPPORT_COL
    };

    static const int HISTORY_COLUMN = 7;
    static const int REPORT_COLUMN  = 8;




    void showResearcherHistory(int row);
    void addHistoryIcon(int row, int researcherId);
    void setupPDFExport();
    void generateResearcherPDF(int researcherId, const QString &reportText);
    void initArduinoConnection();
    void readSerialData();

signals:
    void on_btnGoToEquipement_clicked();
    // In chercheur_1.h
private:
    // ... existing private members ...
    void generateAIReportPDF(int researcherId, const QString& projectName, const QString& reportContent);
};
  // Add this in chercheur_1.h

#endif // CHERCHEUR_1_H
