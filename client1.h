#ifndef CLIENT1_H
#define CLIENT1_H
#include <QPixmap>
#include <QIcon>
#include <QWidget>
#include "ui_client1.h"
#include <QMainWindow>
#include "Client.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include "qtstat.h"
#include <QSortFilterProxyModel>
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class client1;
}
QT_END_NAMESPACE



class client1 : public QMainWindow
{
    Q_OBJECT

public:
    client1(QWidget *parent = nullptr);
    ~client1();
     QCollator collator;
    struct AjouterResult {
        Client Cajt;
        bool success;
    };
    struct ModifierResult {
         Client Cmod;
        bool success;
    };
    struct SupprimerResult {
         Client Csupp;
        bool success;
    };
    QSortFilterProxyModel * proxy;
    void checkDatabaseForUID();

public slots:
    void on_radioButton_Ajouter_toggled(bool checked);
    void on_pushButton_supp_clicked();
    void on_radioButton_Modifier_toggled(bool checked);
    void onPdfButtonClicked();
    void on_stat_clicked();

    void display();

private slots:


    void on_todo_clicked();

    void on_History_clicked();
    void on_Rbar_textChanged(const QString &arg1);

    void on_CBbar_currentIndexChanged(int index);

    void on_CBtri_currentIndexChanged(int index);

signals:
     void ajouterResultReady( AjouterResult &A);

private:
    Ui::client1 *ui;
    Client C;
    Qtstat *s;
    QByteArray data;
    //Arduino A;

};
#endif // CLIENT1_H
