#include "history.h"
#include "ui_history.h"
#include "client1.h"
#include <QTextStream>
#include <QStandardPaths>
History::History(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::History)
{
    ui->setupUi(this);
    ui->logo->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\bgbg.jpg"));
    path =  QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\ajout.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file.errorString());
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(in.readLine(),ui->ajout);
        ui->ajout->addItem(item);
        item->setFlags(item->flags()|Qt::ItemIsEditable|Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
    }

    QString modifpath =  QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\modifier.txt";
    QFile filemodif(modifpath);
    if (!filemodif.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",filemodif.errorString());
    }

    QTextStream inmod(&filemodif);
    while(!inmod.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(inmod.readLine(),ui->modifier);
        ui->modifier->addItem(item);
       // ui->modifier->setCurrentRow(ui->modifier->currentRow() + 1);
        item->setFlags(item->flags()|Qt::ItemIsEditable|Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
    }


    QFile Suppfile(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\supp.txt");
    if (!Suppfile.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",Suppfile.errorString());
    }

    QTextStream insup(&Suppfile);
    while(!insup.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(insup.readLine(),ui->supp);
        ui->supp->addItem(item);
        // ui->modifier->setCurrentRow(ui->modifier->currentRow() + 1);
        item->setFlags(item->flags()|Qt::ItemIsEditable|Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
    }

}

History::~History()
{
    delete ui;
}
void History::on_ajouter_performed(){

}
