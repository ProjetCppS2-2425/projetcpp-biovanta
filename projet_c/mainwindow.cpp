#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Client.cpp"
#include <QMessageBox>
#include <iostream>
#include <QTextStream>
#include <QTableWidget>
#include <QAbstractProxyModel>
#include <QSortFilterProxyModel>
#include "Client.h"
#include <QFileDialog>
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QPrinter>
#include <QDebug>
#include <QPageLayout>

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
    connect(ui->radioButton_Modifier, &QRadioButton::toggled, this, &MainWindow::on_radioButton_Modifier_toggled);
    Client C;
    ui->tableView->setModel(C.afficher());
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::onPdfButtonClicked);
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
            ui->tableView->setModel(C.afficher());
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
            QMessageBox::critical(this, "Erreur", "Ajout non effectué.");
        }
    }
}

void MainWindow::on_pushButton_supp_clicked(){
         int id=ui->LineEdit_supp->text().toInt();

        bool test=C.supprimer(id);

         if (test){
             QMessageBox::information(nullptr, QObject::tr("OK"),
                                      QObject::tr("Suppression effectuée\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(C.afficher());
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


        void MainWindow::on_radioButton_Modifier_toggled(bool checked){
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


                    bool test = C.modifier();
                    if (test) {
                        ui->tableView->setModel(C.afficher());
                        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");


                        ui->lineEdit_ID->clear();
                        ui->lineEdit_nomA->clear();
                        ui->lineEdit_Rep->clear();
                        ui->lineEdit_adr->clear();
                        ui->lineEdit_email->clear();
                        ui->lineEdit_ctr->clear();
                        ui->typeCombo->setCurrentIndex(0);

                       /* ui->radioButton_Modifier->setAutoExclusive(false);
                        ui->radioButton_Modifier->setChecked(false);
                        ui->radioButton_Modifier->setAutoExclusive(true);*/
                    }
                    else {
                        QMessageBox::critical(this, "Erreur", "Ajout non effectué.");
                    }
                }
            }
        }

        void MainWindow::onPdfButtonClicked() {
            // Open a file dialog to choose the save location
            QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");
            if (fileName.isEmpty()) {
                return; // User canceled the dialog
            }

            // Fetch the list of clients from the database
            Client C;
            QSqlQueryModel *model = C.afficher(); // Fetch data using your afficher() method

            // Create an HTML string for the PDF content
            QString html = "<div style='border: 5px solid green; padding: 20px; font-family: Arial;'>"
                           "<h1 style='text-align: center; color: green;'>Liste des Clients</h1>"
                           "<div style='margin: 0 auto; width: 100%;'>"
                           "<table border='1' cellpadding='10' cellspacing='0' style='width: 100%; border-collapse: collapse; font-size: 12px; margin: 0 auto;'>"
                           "<tr>"
                           "<th style='background-color: #f2f2f2; padding: 10px;'>ID</th>"
                           "<th style='background-color: #f2f2f2; padding: 10px;'>Nom</th>"
                           "<th style='background-color: #f2f2f2; padding: 10px;'>Adresse</th>"
                           "<th style='background-color: #f2f2f2; padding: 10px;'>Type</th>"
                           "<th style='background-color: #f2f2f2; padding: 10px;'>Nom Responsable</th>"
                           "<th style='background-color: #f2f2f2; padding: 10px;'>Email</th>"
                           "<th style='background-color: #f2f2f2; padding: 10px;'>ID Contrat</th>"
                           "</tr>";

            for (int row = 0; row < model->rowCount(); ++row) {
                int id_c = model->data(model->index(row, 0)).toInt();
                QString nomA = model->data(model->index(row, 1)).toString();
                QString adresse = model->data(model->index(row, 2)).toString();
                QString typeA = model->data(model->index(row, 3)).toString();
                QString nomR = model->data(model->index(row, 4)).toString();
                QString email = model->data(model->index(row, 5)).toString();
                int id_contrat = model->data(model->index(row, 6)).toInt();

                html += QString("<tr>"
                                "<td style='padding: 10px;'>%1</td>"
                                "<td style='padding: 10px;'>%2</td>"
                                "<td style='padding: 10px;'>%3</td>"
                                "<td style='padding: 10px;'>%4</td>"
                                "<td style='padding: 10px;'>%5</td>"
                                "<td style='padding: 10px;'>%6</td>"
                                "<td style='padding: 10px;'>%7</td>"
                                "</tr>")
                            .arg(id_c)
                            .arg(nomA)
                            .arg(adresse)
                            .arg(typeA)
                            .arg(nomR)
                            .arg(email)
                            .arg(id_contrat);
            }

            html += "</table></div>"; // Close the table

            // Footer with Contact Information
            html += "<div style='text-align: center; font-family: Arial; font-size: 12px; margin-top: 20px;'>"
                    "<p style='margin: 5px;'>Adresse: Ariana 2083</p>"
                    "<p style='margin: 5px;'>Email: smartvax@yahoo.com</p>"
                    "<p style='margin: 5px;'>Téléphone: +216 21 276 002</p>"
                    "<p style='margin-top: 15px; font-style: italic;'>Le Centre de Vaccination et de Recherche Biologique offre des services de vaccination de qualité et mène des recherches avancées pour la santé publique.</p>"
                    "</div>"
                    "</div>"; // Close outer div

            // Create a QTextDocument and set the HTML content
            QTextDocument document;
            document.setHtml(html);

            // Create a QPrinter to generate the PDF
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);

            // Set page margins (optional)
            printer.setPageMargins(QMarginsF(20, 20, 20, 20), QPageLayout::Millimeter); // 20mm margins on all sides

            // Print the document to the PDF file
            document.print(&printer);

            qDebug() << "PDF saved to:" << fileName;
        }

