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

    QBarSet *set4 = new QBarSet("Ministère de santé");
    QBarSet *set5 = new QBarSet("Centres pharmaceutiques");
    QBarSet *set6 = new QBarSet("total laboratoires d'analyse");

    float tot = C.countClients();
    float m =(C.CalculMinister()/tot)*100;
    float c=(C.CalculCentre()/tot)*100;
    float l=(C.CalculLabo()/tot)*100;
    set4->append(m);
    set5->append(c);
    set6->append(l);


    //putting bars inside series

    series->append(set4);
    series->append(set5);
    series->append(set6);

    //the chart holding it all together
    QChart *chart = new QChart();
    chart->addSeries(series);
    //chart->addSeries(seriestot);
    chart->setTitle("Client stats and percentages");
    chart->setAnimationDuration(QChart::SeriesAnimations);

    //setting the names of bars horizontally
   /* QStringList Subjectname1;
    Subjectname1.append("Ministère de santé"); //one name set
    QStringList Subjectname2;
    Subjectname2.append("Centre Pharmaceutique"); //one name set
    QStringList Subjectname3;
    Subjectname3.append("Laboratoire d'analyses"); //one name set*/
    QStringList Subjectname4;
    Subjectname4.append("Total des clients par type");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(Subjectname4);
   /* axisX->append(Subjectname1);
    axisX->append(Subjectname2);
    axisX->append(Subjectname3);*/
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    series->setLabelsVisible(true);
    series->setLabelsFormat("@value%");
    //seriestot->attachAxis(axisX);

    //basic: the y axis stuff
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,100);
    axisY->setMinorTickCount(10);
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



