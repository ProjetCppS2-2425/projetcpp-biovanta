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
    ui->logo->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\His-bg.jpg"));
    //connect(ui->btnRemove, &QPushButton::clicked, this, &Todo::on_btnRemove_clicked);
    ui->listWidget->setDragDropMode(QAbstractItemView::DragDrop);
    ui->listWidget_2->setDragDropMode(QAbstractItemView::DragDrop);
    path =  QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\toDoFile.txt";
    QFile file(path);
    if (!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file.errorString());
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(in.readLine(),ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags()|Qt::ItemIsEditable|Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
    }

    QFile file_2(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\toDoFile2.txt");
    if (!file_2.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file_2.errorString());
    }

    QTextStream kin(&file_2);
    while(!kin.atEnd()){
        QListWidgetItem* item = new QListWidgetItem(kin.readLine(),ui->listWidget_2);
        ui->listWidget_2->addItem(item);
        item->setFlags(item->flags()|Qt::ItemIsEditable|Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled);
    }

    file_2.close();

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

    QFile file_2(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\toDoFile2.txt");
    if (!file_2.open(QIODevice::ReadWrite)){
        QMessageBox::information(nullptr,"error",file_2.errorString());
    }
    QTextStream outt(&file_2);
    for (int i=0; i<ui->listWidget_2->count();i++){
        outt<<ui->listWidget_2->item(i)->text()<<"\n";
    }
    file_2.close();
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




void Todo::on_pushButton_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void Todo::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
}


void Todo::on_pushButton_3_clicked()
{
    QListWidgetItem* item = ui->listWidget_2->takeItem(ui->listWidget_2->currentRow());
    delete item;
}


void Todo::on_pushButton_4_clicked()
{
    ui->listWidget_2->clear();
}

