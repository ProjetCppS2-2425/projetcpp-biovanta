#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Client.cpp"
#include <QMessageBox>
#include <iostream>
#include <QTextStream>
using namespace std;
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
    if (checked) {

        int id = ui->lineEdit_ID->text().toInt();
        QString nomA = ui->lineEdit_nomA->text();
        QString type = ui->typeCombo->currentText();
        QString rep = ui->lineEdit_Rep->text();
        QString adr = ui->lineEdit_adr->text();
        QString email = ui->lineEdit_email->text();
        int ctr = ui->lineEdit_ctr->text().toInt();


        if (id <= 0) {
            QMessageBox::warning(this, "Entrée invalide", "L'ID doit être un nombre positif !");
            return;
        }
        if (nomA.isEmpty() || !nomA.at(0).isLetter()) {
            QMessageBox::warning(this, "Entrée invalide", "Le nom de l'association doit commencer par une lettre et ne peut pas être vide !");
            return;
        }
        if (adr.isEmpty()) {
            QMessageBox::warning(this, "Entrée invalide", "L'adresse ne peut pas être vide !");
            return;
        }
        if (type.isEmpty()) {
            QMessageBox::warning(this, "Entrée invalide", "Le type d'association ne peut pas être vide !");
            return;
        }
        static const QRegularExpression repRegex("^[A-Za-z]+$");

        if (rep.isEmpty() || !repRegex.match(rep).hasMatch()) {
            QMessageBox::warning(this, "Entrée invalide", "Le nom du représentant doit contenir uniquement des lettres et ne peut pas être vide !");
            return;
        }
        static const QRegularExpression emailRegex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,6}$");

        if (!emailRegex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Entrée invalide", "Veuillez saisir une adresse e-mail valide !");
            return;
        }

        if (ctr <= 0) {
            QMessageBox::warning(this, "Entrée invalide", "L'ID du contrat doit être un nombre positif !");
            return;
        }


        Client C(id, nomA, adr, type, rep, email, ctr);


        bool test = C.ajouter();
        if (test) {
            QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");


            ui->lineEdit_ID->clear();
            ui->lineEdit_nomA->clear();
            ui->lineEdit_Rep->clear();
            ui->lineEdit_adr->clear();
            ui->lineEdit_email->clear();
            ui->lineEdit_ctr->clear();
            ui->typeCombo->setCurrentIndex(0);

            ui->radioButton_Ajouter->setAutoExclusive(false);
            ui->radioButton_Ajouter->setChecked(false);
            ui->radioButton_Ajouter->setAutoExclusive(true);
        }
        else {
            QMessageBox::critical(this, "Erreur", "Ajout non effectué. Veuillez vérifier la connexion à la base de données.");
        }
    }
}

void MainWindow::on_pushButton_supp_clicked(){
     int id=ui->LineEdit_supp->text().toInt();
    //bool q=C.exists(id);
    // QString result = QString("Value: %1").arg(q ? "true" : "false");
    // ui->label_debug->setText(result);
    if (C.exists(id)){
    bool test=C.supprimer(id);
         QString result = QString("Value: %1").arg(test ? "true" : "false");
         ui->label_debug->setText(result);
     if (test){
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Suppression effectuée\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
         ui->radioButton_Ajouter->setAutoExclusive(false);
         ui->radioButton_Ajouter->setChecked(false);
         ui->radioButton_Ajouter->setAutoExclusive(true);
              }
     else {
         QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Suppression non effectuée.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
          }
    }
     else {
        QMessageBox::warning(this, "ID Introuvable", "L'ID saisi n'existe pas dans la base de données.");
    }
     }

