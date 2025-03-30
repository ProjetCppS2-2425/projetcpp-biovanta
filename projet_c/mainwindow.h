#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QIcon>

#include <QMainWindow>
#include "Client.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include "qtstat.h"

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
public slots:
    void on_radioButton_Ajouter_toggled(bool checked);
    void on_pushButton_supp_clicked();
    void on_radioButton_Modifier_toggled(bool checked);
    void onPdfButtonClicked();
    void on_stat_clicked();
    void display();
private slots:


private:
    Ui::MainWindow *ui;
    Client C;
    Qtstat *s;

};
#endif // MAINWINDOW_H
