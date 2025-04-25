#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "Client.h"
#include "history.h"
#include "arduino.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new  MainWindow();
    Connection c;
    Client E;
    History *h = new History();
    E.CalculCentre();
    E.CalculLabo();
    E.CalculMinister();
    bool test=c.createconnect();
    if(test)
    {
        w->show();
        w->display();
        QObject::connect(w,&MainWindow::ajouterResultReady,h,&History::on_ajouter_performed);
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
