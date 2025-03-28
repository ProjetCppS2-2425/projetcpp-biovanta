#include "qtstat.h"
#include "ui_qtstat.h"
#include <QtCharts>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
Qtstat::Qtstat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Qtstat)
{
    ui->setupUi(this);

    //series is a container to bars
    QBarSeries *series = new QBarSeries();

    //setting the bars
    QBarSet *set_1 = new QBarSet("first"); //bar data name
    set_1->append(10);
    QBarSet *set_2 = new QBarSet("first");
    set_2->append(10);
    QBarSet *set_3 = new QBarSet("first");
    set_3->append(10);
    QBarSet *set_4 = new QBarSet("first");
    set_4->append(10);

    //putting bars inside series
    series->append(set_1);
    series->append(set_2);
    series->append(set_3);
    series->append(set_4);

    //the chart holding it all together
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Client stats");
    chart->setAnimationDuration(QChart::SeriesAnimations);

    //setting the names of bars horizontally
    QStringList Subjectname;
    Subjectname.append("stuff");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(Subjectname);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    //basic: the y axis stuff
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,50);
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
