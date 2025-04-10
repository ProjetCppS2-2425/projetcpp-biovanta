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


}

void statistique::on_pushButton_11_clicked()
{
    close();
}

