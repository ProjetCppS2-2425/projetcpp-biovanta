#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Client.cpp"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logo->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\bg.jpg"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\empe.png"));
    ui->chercheur->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\cher.png"));
    ui->pdf->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\client.png"));
    ui->stat->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\st.png"));
    ui->ok->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\search.png"));
    connect(ui->radioButton_Ajouter, &QRadioButton::toggled, this, &MainWindow::on_radioButton_Ajouter_toggled);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_radioButton_Ajouter_toggled(bool checked)
{
    if (checked){
    int id=ui->lineEdit_ID->text().toInt();
    QString nomA=ui->lineEdit_nomA->text();
    QString type = ui->typeCombo->currentText();
    QString rep=ui->lineEdit_Rep->text();
    QString adr=ui->lineEdit_adr->text();
    QString email=ui->lineEdit_email->text();
    int ctr=ui->lineEdit_ctr->text().toInt();
    Client C(id,nomA,adr,type,rep,email,ctr)  ;
    bool test=C.ajouter();
    if (test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (!test){
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}
    }
}
