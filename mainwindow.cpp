#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QPushButton>
#include <QRegularExpression>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::supp_clicked);
    isModifying = false; // Initialiser à false (mode ajout par défaut)


    ui->logo->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\bg.jpg"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\empe.png"));
    ui->supp->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\effacer.png"));
    ui->chercheur->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\cher.png"));
    ui->pdf->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\client.png"));
    ui->stat->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\st.png"));
    ui->ok->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\search.png"));
    afficherEquipements();
    // Appliquer le stylesheet à tableWidget
    ui->tableWidget->setStyleSheet(
        "QTableWidget {"
        "   background-color: #f8f9fa;"
        "   gridline-color: #dee2e6;"
        "   font-size: 14px;"
        "}"
        "QHeaderView::section {"
        "   background-color: #2C3E50;"
        "   color: white;"
        "   padding: 5px;"
        "   border: 1px solid #dee2e6;"
        "}"
        "QTableWidget::item {"
        "   padding: 5px;"
        "}"
        "QTableWidget::item:selected {"
        "   background-color: #cbddf5;"
        "   color: black;"
        "}"
        );

    ui->tableWidget->repaint();

    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données !");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() {
    QString id = ui->lineEdit->text();

    // Contrôle de saisie pour l'ID : Ne dépasse pas 5 entiers
    if (id.isEmpty() || id.length() > 5 || !id.toInt()) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'équipement doit être un nombre entier de maximum 5 chiffres.");
        return;
    }

    if (ui->radioButton_2->isChecked()) { // Mode modification
        if (!isModifying) {
            // Phase 1 : Charger les informations de l'équipement
            if (!equip.existe(id)) {
                QMessageBox::warning(this, "Erreur", "L'équipement avec cet ID n'existe pas.");
                return;
            }

            chargerEquipement(); // Charge les données de l'équipement dans les champs du formulaire
            isModifying = true; // Passer en mode modification
        } else {
            // Phase 2 : Appliquer le contrôle de saisie lors de la modification
            QString nom = ui->lineEdit_3->text();
            QString type = ui->comboBox_4->currentText();
            QString img = selectedImagePath;
            QString etat = ui->comboBox_2->currentText();
            QString dispo = ui->comboBox_3->currentText();
            int nbre = ui->spinBox->value();

            // Validation du nom : Accepte uniquement les lettres et les espaces
            QRegularExpression nomRegex("^[A-Za-z\\s]+$");
            if (nom.isEmpty() || !nomRegex.match(nom).hasMatch()) {
                QMessageBox::warning(this, "Erreur", "Le nom de l'équipement ne peut contenir que des lettres et des espaces.");
                return;
            }

            // Contrôle de saisie pour le type
            if (type.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type d'équipement.");
                return;
            }

            // Contrôle de saisie pour l'état
            if (etat.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un état pour l'équipement.");
                return;
            }

            // Contrôle de saisie pour la disponibilité
            if (dispo.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une disponibilité pour l'équipement.");
                return;
            }

            // Contrôle de saisie pour le nombre
            if (nbre <= 0) {
                QMessageBox::warning(this, "Erreur", "Le nombre d'équipements doit être supérieur à zéro.");
                return;
            }

            // Enregistrer les modifications
            Equipement equip(id, nom, etat, img, type, dispo, nbre);
            if (equip.modifier()) {
                QMessageBox::information(this, "Succès", "Équipement modifié avec succès.");
                actualiserTableau();
                reinitialiserFormulaire(); // Réinitialiser le formulaire
                isModifying = false; // Quitter le mode modification
            } else {
                QMessageBox::critical(this, "Erreur", "La modification a échoué.");
            }
        }
    } else if (ui->radioButton->isChecked()) { // Mode ajout
        // Vérifier si l'équipement existe déjà
        if (equip.existe(id)) {
            QMessageBox::warning(this, "Erreur", "Un équipement avec cet ID existe déjà.");
            return;
        }

        QString nom = ui->lineEdit_3->text();
        QString type = ui->comboBox_4->currentText();
        QString img = selectedImagePath;
        QString etat = ui->comboBox_2->currentText();
        QString dispo = ui->comboBox_3->currentText();
        int nbre = ui->spinBox->value();

        // Validation du nom : Accepte uniquement les lettres et les espaces
        QRegularExpression nomRegex("^[A-Za-z\\s]+$");
        if (nom.isEmpty() || !nomRegex.match(nom).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "Le nom de l'équipement ne peut contenir que des lettres et des espaces.");
            return;
        }

        // Contrôle de saisie pour le type
        if (type.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type d'équipement.");
            return;
        }

        // Contrôle de saisie pour l'état
        if (etat.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un état pour l'équipement.");
            return;
        }

        // Contrôle de saisie pour la disponibilité
        if (dispo.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une disponibilité pour l'équipement.");
            return;
        }

        // Contrôle de saisie pour le nombre
        if (nbre <= 0) {
            QMessageBox::warning(this, "Erreur", "Le nombre d'équipements doit être supérieur à zéro.");
            return;
        }

        Equipement equip(id, nom, etat, img, type, dispo, nbre);
        if (equip.ajouter()) {
            QMessageBox::information(this, "Succès", "Équipement ajouté avec succès.");
            actualiserTableau();
            reinitialiserFormulaire(); // Réinitialiser le formulaire
        } else {
            QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
        }
    } else {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner 'Ajouter' ou 'Modifier' avant de valider.");
    }
}
void MainWindow::on_pushButton_clicked() {
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

        // Extraire uniquement le nom du fichier (sans le chemin)
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();

        // Stocker le nom du fichier dans selectedImagePath
        selectedImagePath = fileName;

        // Afficher un message indiquant que l'image a été sélectionnée
        ui->pushButton->setText("Image sélectionnée");
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
    ui->tableWidget->setColumnCount(7);
    QStringList headers = {"ID", "Nom", "Image", "Type", "État", "Disponibilité", "Nombre"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Récupérer la liste des équipements
    QList<Equipement> liste = Equipement::afficher();
    ui->tableWidget->setRowCount(liste.size());

    // Remplir le tableau avec les données
    for (int i = 0; i < liste.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(liste[i].getId()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(liste[i].getNom()));

        // Afficher l'image dans la colonne "Image"
        QString imageName = liste[i].getImage();
        if (!imageName.isEmpty()) {
            QString imagePath = "C:/Users/manel/Desktop/projet_c/images/" + imageName;
            QPixmap pixmap(imagePath);
            if (!pixmap.isNull()) {
                QLabel *imageLabel = new QLabel();
                imageLabel->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio)); // Ajuster la taille de l'image
                ui->tableWidget->setCellWidget(i, 2, imageLabel);
            } else {
                // Si l'image ne peut pas être chargée, afficher un message d'erreur
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem("Image non trouvée"));
            }
        } else {
            // Si aucune image n'est associée, afficher un message
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("Aucune image"));
        }

        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(liste[i].getType()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(liste[i].getEtat()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(liste[i].getDispo()));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(liste[i].getNombre())));
    }
}
//supprimer

void MainWindow::supp_clicked() {
    if (selectedId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un équipement à supprimer.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cet équipement ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Equipement e;
        qDebug() << "ID sélectionné: " << selectedId;  // Vérification de l'ID sélectionné
        if (e.supprimer(selectedId)) {
            QMessageBox::information(this, "Succès", "Équipement supprimé avec succès.");
            actualiserTableau();  // Assurez-vous que cette méthode met à jour la table
            QApplication::processEvents();  // Force la mise à jour de l'interface
            selectedId.clear();
        } else {
            QMessageBox::critical(this, "Erreur", "La suppression a échoué.");
        }
    }
}

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item) {
    int row = item->row();
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    selectedId = ui->tableWidget->item(row, 0)->text();  // Stocke l'ID de l'équipement sélectionné
}


void MainWindow::on_pushButton_3_clicked() {
    // Vider tous les champs du formulaire
    ui->lineEdit->clear();  // id
    ui->lineEdit_3->clear();  // nom
    ui->comboBox_4->setCurrentIndex(0);  // type
    ui->comboBox_2->setCurrentIndex(0);  // etat
    ui->comboBox_3->setCurrentIndex(0);  // dispo
    ui->spinBox->setValue(0);  // nbre
    selectedImagePath.clear();  // image
    ui->radioButton->setChecked(false);  // "Ajouter"
    ui->radioButton_2->setChecked(false);  // "Modifier"
}
void MainWindow::chargerEquipement() {
    QString id = ui->lineEdit->text(); // Récupérer l'ID entré dans le formulaire

    // Contrôle de saisie pour l'ID
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID d'équipement.");
        return;
    }

    // Récupérer l'équipement par son ID
    Equipement equip = Equipement::getEquipementById(id);

    // Vérifier si l'équipement existe
    if (equip.getId().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun équipement trouvé avec cet ID.");
        return;
    }

    // Remplir le formulaire avec les informations de l'équipement
    ui->lineEdit_3->setText(equip.getNom());
    ui->comboBox_4->setCurrentText(equip.getType());
    ui->comboBox_2->setCurrentText(equip.getEtat());
    ui->comboBox_3->setCurrentText(equip.getDispo());
    ui->spinBox->setValue(equip.getNombre());

    // Récupérer le chemin de l'image
    QString imageName = equip.getImage();
    if (!imageName.isEmpty()) {
        // Reconstruire le chemin complet de l'image
        selectedImagePath = "C:/Users/manel/Desktop/projet_c/images/" + imageName; // Chemin absolu

        // Afficher un message indiquant que l'image a été chargée
        ui->pushButton->setText("Image chargée");

        // Afficher le chemin de l'image pour débogage
        qDebug() << "Chemin de l'image : " << selectedImagePath;
    } else {
        selectedImagePath.clear(); // Effacer le chemin de l'image si aucune image n'est associée
        ui->pushButton->setText("Choisir image"); // Réinitialiser le texte du bouton
    }

    isModifying = true; // Passer en mode modification
}
void MainWindow::reinitialiserFormulaire() {
    ui->lineEdit->clear();          // ID
    ui->lineEdit_3->clear();        // Nom
    ui->comboBox_4->setCurrentIndex(0); // Type
    ui->comboBox_2->setCurrentIndex(0); // État
    ui->comboBox_3->setCurrentIndex(0); // Disponibilité
    ui->spinBox->setValue(0);       // Nombre
    selectedImagePath.clear();      // Chemin de l'image
    ui->pushButton->setText("Choisir image"); // Réinitialiser le texte du bouton image
    ui->labelImage->clear();        // Effacer l'image affichée
    ui->radioButton->setChecked(false); // Désélectionner "Ajouter"
    ui->radioButton_2->setChecked(false); // Désélectionner "Modifier"
    isModifying = false;            // Réinitialiser le mode modification
}


