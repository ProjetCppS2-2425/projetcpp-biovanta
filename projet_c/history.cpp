#include "history.h"
#include "ui_history.h"
#include "mainwindow.h"

History::History(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::History)
{
    ui->setupUi(this);
    ui->logo->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\bgbg.jpg"));
}

History::~History()
{
    delete ui;
}
void History::on_ajouter_performed(){
    QMessageBox::information(nullptr, QObject::tr("slot thingy works"),
                             QObject::tr("3malt 3amla.\n"
                                         "ken khdamt mramma khir."), QMessageBox::Cancel);
}
