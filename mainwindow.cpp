#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logo->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\bg.jpg"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\empe.png"));
    ui->chercheur->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\cher.png"));
    ui->pdf->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\client.png"));
    ui->stat->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\st.png"));
    ui->ok->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\search.png"));
    afficherEquipements();

    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données !");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Ajouter un équipement
void MainWindow::on_pushButton_2_clicked() {
    // Vérifier si le bouton radio "Ajouter" est coché
    if (ui->radioButton->isChecked()) {
        QString id = ui->lineEdit->text();
        QString nom = ui->lineEdit_3->text();
        QString etat = ui->comboBox->currentText();
        QString image = selectedImagePath;
        QString type = ui->comboBox_2->currentText();
        QString dispo = ui->comboBox_3->currentText();
        int nombre = ui->spinBox->text().toInt();

        // Vérification que l'utilisateur a bien choisi une image
        if (image.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une image !");
            return;
        }

        Equipement e(id, nom, etat, image, type, dispo, nombre);
        if (e.ajouter()) {
            QMessageBox::information(this, "Succès", "Équipement ajouté avec succés !");
            actualiserTableau();

        } else {
            QMessageBox::critical(this, "Erreur", "Ajout échoué !");
        }
    } else {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner 'Ajouter' avant d'ajouter un équipement.");
    }
}

void MainWindow::on_pushButton_clicked()
{
    // Ouvre une boîte de dialogue pour sélectionner une image
    QString filePath = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    // Vérifie si un fichier a été sélectionné
    if (!filePath.isEmpty()) {
        QFile file(filePath);

        // Vérifie si le fichier existe et est lisible
        if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir l'image sélectionnée.");
            return;
        }

        file.close();

        // Mise à jour de l'interface
        ui->pushButton->setText("Image sélectionnée"); // Ne pas afficher le chemin
        selectedImagePath = filePath; // Stocker le chemin dans la variable


    }
}
void MainWindow::afficherEquipements() {
    QList<Equipement> liste = Equipement::afficher();
    ui->tableWidget->setRowCount(liste.size()); // Définir le nombre de lignes

    for (int i = 0; i < liste.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(liste[i].getId()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(liste[i].getNom()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(liste[i].getImage()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(liste[i].getType()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(liste[i].getEtat()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(liste[i].getDispo()));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(liste[i].getNombre())));
    }
}


void MainWindow::actualiserTableau() {
    ui->tableWidget->clear();  // Efface le tableau avant mise à jour

    // Redéfinir les en-têtes (si nécessaire)
    ui->tableWidget->setColumnCount(7);  // Nombre de colonnes
    QStringList headers = {"ID", "Nom", "État", "Image", "Type", "Disponibilité", "Nombre"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Récupérer la liste des équipements
    Equipement e;
    QList<Equipement> liste = e.afficher();
    ui->tableWidget->setRowCount(liste.size());

    // Remplir le tableau avec les données
    for (int i = 0; i < liste.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(liste[i].getId()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(liste[i].getNom()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(liste[i].getEtat()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(liste[i].getImage()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(liste[i].getType()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(liste[i].getDispo()));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(liste[i].getNombre())));
    }
}


/*
// Supprimer un équipement
void MainWindow::on_pushButton_supprimer_clicked() {
    QString id = ui->lineEdit->text();
    if (equip.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Équipement supprimé !");
        ui->tableView->setModel(equip.afficher());  // Rafraîchir la table
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression échouée !");
    }
}*/




