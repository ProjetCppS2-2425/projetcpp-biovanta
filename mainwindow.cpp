#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QSqlError>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isDataFetched = false;





    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::pushButton_2_clicked);
    connect(ui->radioButton_3, &QRadioButton::clicked, this, &MainWindow::onRadioButtonDeleteClicked);  // For delete
    connect(ui->radioButton_2, &QRadioButton::clicked, this, &MainWindow::onRadioButtonModifyClicked);   // For modify

    ui->logo->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\logo1.png"));

    ui->logout->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\empe.png"));
    ui->chercheur->setIcon(QPixmap("C:\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\cher.png"));
    ui->pdf->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\client.png"));
    ui->stat->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\st.png"));
    ui->ok->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\search.png"));
    ui->supp->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\effacer.png"));

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::pushButton_2_clicked() {
    // Validate ID
    int id = ui->lineEdit->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide (nombre entier positif).");
        return;
    }

    // Validate Nom
    QString nom = ui->lineEdit_3->text().trimmed();
    if (nom.isEmpty() || !nom.contains(QRegularExpression("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$"))) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom valide (lettres uniquement).");
        return;
    }

    // Validate Prenom
    QString prenom = ui->lineEdit_4->text().trimmed();
    if (prenom.isEmpty() || !prenom.contains(QRegularExpression("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$"))) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un prénom valide (lettres uniquement).");
        return;
    }

    // Validate Email
    QString email = ui->lineEdit_5->text().trimmed();
    QRegularExpression emailRegex(R"((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$))");
    if (email.isEmpty() || !emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse email valide.");
        return;
    }

    // Validate Numéro de Téléphone
    QString numTlpStr = ui->lineEdit_7->text().trimmed();
    bool isNumTlpValid;
    int num_tlp = numTlpStr.toInt(&isNumTlpValid);
    if (!isNumTlpValid || numTlpStr.length() != 8) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un numéro de téléphone valide (8 chiffres).");
        return;
    }

    // Validate Domaine Recherche
    QString domaine_recherche = ui->comboBox_4->currentText().trimmed();
    if (domaine_recherche.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un domaine de recherche.");
        return;
    }

    // Validate Projet en Cours
    QString projet_en_cours = ui->lineEdit_8->text().trimmed();
    if (projet_en_cours.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un projet en cours.");
        return;
    }

    // If all validations pass, proceed with the operation
    if (ui->radioButton->isChecked()) {  // Add button (RadioButton 1)
        Chercheur c(id, nom, prenom, email, num_tlp, domaine_recherche, projet_en_cours);
        if (c.ajouter()) {
            QMessageBox::information(this, "Succès", "Chercheur ajouté avec succès");
            refreshTable();
            clearFields();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout du chercheur");
        }
    } else if (ui->radioButton_2->isChecked()) {  // Modify button (RadioButton 2)
        Chercheur c;
        if (c.modify(id, nom, prenom, email, num_tlp, domaine_recherche, projet_en_cours)) {
            QMessageBox::information(this, "Succès", "Chercheur modifié avec succès");
            refreshTable();
            clearFields();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la modification du chercheur");
        }
    } else if (ui->radioButton_3->isChecked()) {  // Delete button (RadioButton 3)
        Chercheur c;
        if (c.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Chercheur supprimé avec succès");
            refreshTable();
            clearFields();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression du chercheur");
        }
    }
}

void MainWindow::refreshTable() {
    // Clear the existing rows
    ui->tableWidget->setRowCount(0);

    // Fetch data from the database and populate the table
    QSqlQuery query("SELECT * FROM CHERCHEUR");  // Example SQL query to fetch data from the CHERCHEUR table
    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Set each column data
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
    }
}

void MainWindow::onRadioButtonDeleteClicked() {
    isDataFetched = false;  // Reset the state when switching modes

    if (ui->radioButton_2->isChecked()) {  // Modify
        // Enable fields for modification
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_3->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
    } else if (ui->radioButton_3->isChecked()) {  // Delete
        // Enable only the ID field for input and disable the rest
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_8->clear();
        ui->comboBox_4->setCurrentIndex(0);

        // Disable fields related to modifying or adding
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->lineEdit_7->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_8->setEnabled(false);
        ui->comboBox_4->setEnabled(false);
    }
}

void MainWindow::clearFields() {
    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_5->clear();
    ui->comboBox_4->setCurrentIndex(0);  // Reset Domaine Recherche to default
    ui->lineEdit_8->clear();
}
void MainWindow::onRadioButtonModifyClicked() {
    // Enable fields for modification
    ui->lineEdit->setEnabled(true);  // Enable ID field for input
    ui->lineEdit_3->setEnabled(true);  // Enable Name field
    ui->lineEdit_4->setEnabled(true);  // Enable Prenom field
    ui->lineEdit_7->setEnabled(true);  // Enable Email field
    ui->lineEdit_5->setEnabled(true);  // Enable TLP field
    ui->lineEdit_8->setEnabled(true);  // Enable Projet en cours field
    ui->comboBox_4->setEnabled(true);  // Enable ComboBox for Domaine Recherche
}
