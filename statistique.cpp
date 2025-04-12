#include "statistique.h"
#include "ui_statistique.h"

#include <QDialog>
#include <QtCharts/QPieSeries>



statistique::statistique(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}

void statistique::paintEvent(QPaintEvent *)
{

    int A=v.statistique1();//resultat count 1
    int B=v.statistique2();//resultat count 2

    float s1= A*100 ;
    float s2=B*100;
    float nb = A+B;
    float q1 ;
    q1 = s1/nb ;//pourcentage
    float q2;
    q2=s2/nb;
    float y  ;
    y= (q1*360)/100;//cercle
    float m;
    m= (q2*360)/100;

    float res1 = 16*y;
    float res2 = 16*m;


    QPieSeries *series = new QPieSeries();
    series->append("unidose", res1);
    series->append("multidose", res2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique par rapport au nombres doses");

    chartView = new QChartView(chart,ui->label);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(850,600);
    chartView->show();
}

void statistique::on_pushButton_11_clicked()
{
    close();
}

