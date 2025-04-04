#include "qtstat.h"
#include "ui_qtstat.h"
#include <QtCharts>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include "Client.h"
Qtstat::Qtstat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Qtstat)
{
    ui->setupUi(this);
    Client C;

    //series is a container to bars
    auto *series = new QBarSeries();
   // auto *seriestot = new QBarSeries();

    //setting the bars
    QBarSet *set1 = new QBarSet("TOP ADRESS"); //bar data name
    QBarSet *set2 = new QBarSet("SECOND ADRESS");
    QBarSet *set3 = new QBarSet("other");
    QBarSet *set4 = new QBarSet("TOTALM");
    QBarSet *set5 = new QBarSet("TOTALC");
    QBarSet *set6 = new QBarSet("TOTALL");
    set4->append(C.CalculMinister());
    set5->append(C.CalculCentre());
    set6->append(C.CalculLabo());
    *set1 << 0 << 3 << 6 << 4 << 8;
    *set2 << 0 << 3 << 8 << 13 << 8 << 5;
    *set3 << 0 << 3 << 7 << 3 << 4 << 5;

    //putting bars inside series
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);
    series->append(set6);

    //the chart holding it all together
    QChart *chart = new QChart();
    chart->addSeries(series);
    //chart->addSeries(seriestot);
    chart->setTitle("Client stats");
    chart->setAnimationDuration(QChart::SeriesAnimations);

    //setting the names of bars horizontally
    QStringList Subjectname1;
    Subjectname1.append("Ministère de santé"); //one name set
    QStringList Subjectname2;
    Subjectname2.append("Centre Pharmaceutique"); //one name set
    QStringList Subjectname3;
    Subjectname3.append("Laboratoire d'analyses"); //one name set
    QStringList Subjectname4;
    Subjectname4.append("Total");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(Subjectname4);
    axisX->append(Subjectname1);
    axisX->append(Subjectname2);
    axisX->append(Subjectname3);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    //seriestot->attachAxis(axisX);

    //basic: the y axis stuff
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,C.countClients());
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    //seriestot->attachAxis(axisY);

    //setting a legend: beautifying stats
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->setVisible(true);

    //working around the widget
    QChartView *chartview = new QChartView(chart);
    chartview->setVisible(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartview);
    setLayout(layout);
}

Qtstat::~Qtstat()
{
    delete ui;
}
