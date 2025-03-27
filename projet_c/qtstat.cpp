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
    QBarSeries *series = new QBarSeries();
    QBarSet *set_1 = new QBarSet("first");
    set_1->append(10);
    set_1->append(20);
    set_1->append(30);
    set_1->append(40);
    set_1->append(50);
    series->append(set_1);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Client stats");
    chart->setAnimationDuration(QChart::SeriesAnimations);
    QStringList Subjectname;
    Subjectname.append("stuff");
    Subjectname.append("stuff");
    Subjectname.append("stuff");
    Subjectname.append("stuff");
    Subjectname.append("stuff");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(Subjectname);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setVisible(true);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setVisible(true);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartview);
    setLayout(layout);
}

Qtstat::~Qtstat()
{
    delete ui;
}
