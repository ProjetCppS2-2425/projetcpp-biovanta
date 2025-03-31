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

    //setting the bars
    QBarSet *set1 = new QBarSet("Ministère de santé"); //bar data name
    QBarSet *set2 = new QBarSet("Centre Pharmaceutique");
    QBarSet *set3 = new QBarSet("Laboratoire d'analyses");
    //set4->append(10);
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;

    //putting bars inside series
    series->append(set1);
    series->append(set2);
    series->append(set3);

    //the chart holding it all together
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Client stats");
    chart->setAnimationDuration(QChart::SeriesAnimations);

    //setting the names of bars horizontally
    QStringList Subjectname;
    Subjectname.append("stuff"); //one name set

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(Subjectname);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    //basic: the y axis stuff
    QValueAxis *axisY = new QValueAxis();
   // axisY->setRange(0,C.countClients());
    axisY->setRange(0,C.CalculLabo());
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

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
