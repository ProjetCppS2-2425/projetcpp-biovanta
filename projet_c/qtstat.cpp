#include "qtstat.h"
#include "ui_qtstat.h"

Qtstat::Qtstat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Qtstat)
{
    ui->setupUi(this);
}

Qtstat::~Qtstat()
{
    delete ui;
}
