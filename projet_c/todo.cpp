#include "todo.h"
#include "ui_todo.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QTextStream>

Todo::Todo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Todo)
{
    ui->setupUi(this);
    path =  QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\toDoFile.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file.errorString());
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(in.readLine(),ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags()|Qt::ItemIsEditable);
    }
    file.close();
}

Todo::~Todo()
{
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\toDoFile.txt");
    if (!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(nullptr,"error",file.errorString());
    }
    QTextStream out(&file);
    for (int i=0; i<ui->listWidget->count();i++){
        out<<ui->listWidget->item(i)->text()<<"\n";
    }
    file.close();
     delete ui;
}




void Todo::on_btnAdd_clicked()
{
    QListWidgetItem* item = new QListWidgetItem(ui->txtTask->text(),ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags()|Qt::ItemIsEditable);
    ui->txtTask->clear();
   // ui->txtTask->setFocus();
}


void Todo::on_btnRemove_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void Todo::on_btnRemoveAll_clicked()
{
     ui->listWidget->clear();
}

