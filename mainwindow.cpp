#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QPushButton>
#include <QRegularExpression>
#include <QTextDocument>
#include <QPrinter>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QTimer>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::supp_clicked);
    isModifying = false; // Initialiser à false (mode ajout par défaut)
    connect(ui->ok, &QPushButton::clicked, this, &MainWindow::on_ok_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);
    connect(ui->radioButton_3, &QRadioButton::clicked, this, &MainWindow::onTriDeclenche);
    connect(ui->radioButton_4, &QRadioButton::clicked, this, &MainWindow::onTriDeclenche);


    // (Optionnel) Si vous voulez aussi que le critère (combobox) déclenche le tri SEULEMENT si un radioButton est coché :
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [this]() {
        if (ui->radioButton_3->isChecked() || ui->radioButton_4->isChecked()) {
            onTriDeclenche();
        }
    });
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
    ui->pushButton_4->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\loading-arrow.png"));
    ui->noti->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\notif.png"));

    // Récupérer la liste des équipements et l'afficher
    QList<Equipement> liste = Equipement::afficher();
    afficherEquipements(liste); // Appeler avec l'argument liste
    // Création du badge de notification
    notificationBadge = new QLabel(ui->noti);
    notificationBadge->setObjectName("notificationBadge");
    notificationBadge->setStyleSheet(
        "background-color: red;"
        "color: white;"
        "border-radius: 9px;"
        "min-width: 18px;"
        "min-height: 18px;"
        "font-size: 10px;"
        "padding: 0px 3px;"
        );
    notificationBadge->setAlignment(Qt::AlignCenter);
    notificationBadge->move(ui->noti->width() - 27, 5);
    notificationBadge->hide();

    // Style du bouton de notification
    ui->noti->setStyleSheet(
        "QPushButton {"
        "    background-color: #02767F;"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "    border: none;"
        "}"
        "QPushButton:hover {"
        "    background-color: #247361;"
        "}"
        "QPushButton[alert='true'] {"
        "    background-color: #ff6b6b;"
        "}"
        );

    // Timer pour vérifier les équipements non fonctionnels
    notificationTimer = new QTimer(this);
    connect(notificationTimer, &QTimer::timeout, this, &MainWindow::checkEquipmentStatus);
    notificationTimer->start(6000); // Toutes les 5 minutes

    // Vérification initiale
    checkEquipmentStatus();

    // Connecter le clic sur le bouton de notification
    connect(ui->noti, &QPushButton::clicked, this, &MainWindow::showEquipmentAlerts);

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

    if (id.isEmpty() || id.length() > 5 || !id.toInt()) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'équipement doit être un nombre entier de maximum 5 chiffres.");
        return;
    }

    if (ui->radioButton_2->isChecked()) {
        if (!isModifying) {
            if (!equip.existe(id)) {
                QMessageBox::warning(this, "Erreur", "L'équipement avec cet ID n'existe pas.");
                return;
            }

            chargerEquipement();
            isModifying = true;
        } else {
            QString nom = ui->lineEdit_3->text();
            QString type = ui->comboBox_4->currentText();
            QString etat = ui->comboBox_2->currentText();
            QString dispo = ui->comboBox_3->currentText();
            int nbre = ui->spinBox->value();
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

            // Enregistrer les modifications (utilisation de selectedImageData au lieu de selectedImagePath)
            Equipement equip(id, nom, etat, selectedImageData, type, dispo, nbre);
            if (equip.modifier()) {
                QMessageBox::information(this, "Succès", "Équipement modifié avec succès.");
                actualiserTableau();
                reinitialiserFormulaire();
                refreshAlertCount();
                isModifying = false;
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

        // Ajout avec les données binaires de l'image (utilisation de selectedImageData)
        Equipement equip(id, nom, etat, selectedImageData, type, dispo, nbre);
        if (equip.ajouter()) {
            QMessageBox::information(this, "Succès", "Équipement ajouté avec succès.");
            actualiserTableau();
            reinitialiserFormulaire();
        } else {
            QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
        }
    } else {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner 'Ajouter' ou 'Modifier' avant de valider.");
    }
}
void MainWindow::on_pushButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir l'image sélectionnée.");
            return;
        }

        // Lire l'image en tant que données binaires
        QByteArray imageData = file.readAll();
        file.close();
        selectedImageData = imageData;

        ui->pushButton->setText("Image sélectionnée");
    }
}

// Dans mainwindow.cpp
void MainWindow::afficherEquipements(const QList<Equipement>& liste) {
    ui->tableWidget->setRowCount(liste.size());

    QStringList headers = {"ID", "Nom", "Image", "Type", "État", "Disponibilité", "Nombre"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget->setUpdatesEnabled(false);

    for (int i = 0; i < liste.size(); ++i) {
        const Equipement& e = liste[i];

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(e.getId()));

        // Colonne Nom
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(e.getNom()));

        // Colonne Image (affichage de l'image depuis les données BLOB)
        QByteArray imageData = e.getImageData();
        if (!imageData.isEmpty()) {
            QPixmap pixmap;
            if (pixmap.loadFromData(imageData)) {
                QLabel *imageLabel = new QLabel();
                imageLabel->setPixmap(pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                imageLabel->setAlignment(Qt::AlignCenter);
                ui->tableWidget->setCellWidget(i, 2, imageLabel);
            } else {
                ui->tableWidget->setItem(i, 2, new QTableWidgetItem("Image invalide"));
            }
        } else {
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("Aucune image"));
        }

        // Autres colonnes
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(e.getType()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(e.getEtat()));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(e.getDispo()));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(e.getNombre())));
    }

    // Réactiver les mises à jour et ajuster la taille des colonnes
    ui->tableWidget->setUpdatesEnabled(true);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
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

        QByteArray imageData = liste[i].getImageData(); // Supposons que vous avez cette méthode
        if (!imageData.isEmpty()) {
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            if (!pixmap.isNull()) {
                QLabel *imageLabel = new QLabel();
                imageLabel->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
                ui->tableWidget->setCellWidget(i, 2, imageLabel);
            }
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
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer cet équipement ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Equipement e;
        if (e.supprimer(selectedId)) {
            QMessageBox::information(this, "Succès", "Équipement supprimé avec succès.");
            actualiserTableau(); // Actualiser l'affichage après suppression
            selectedId.clear(); // Réinitialiser l'ID sélectionné
        } else {
            QMessageBox::critical(this, "Erreur", "La suppression a échoué ou l'équipement n'existe pas.");
        }
    }
}
void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item) {
    if (!item) return; // Protection contre les pointeurs nuls

    int row = item->row();

    // Vérifier que la ligne est valide
    if (row < 0 || row >= ui->tableWidget->rowCount()) return;

    // Configurer la sélection par ligne
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // Stocker l'ID de l'équipement sélectionné
    QTableWidgetItem *idItem = ui->tableWidget->item(row, 0);
    if (idItem) {
        selectedId = idItem->text();

        // Mettre en surbrillance toute la ligne
        ui->tableWidget->selectRow(row);
    }
}
void MainWindow::chargerEquipement() {
    QString id = ui->lineEdit->text();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID d'équipement.");
        return;
    }

    Equipement equip = Equipement::getEquipementById(id);

    if (equip.getId().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun équipement trouvé avec cet ID.");
        return;
    }

    // Remplir les champs du formulaire
    ui->lineEdit_3->setText(equip.getNom());
    ui->comboBox_4->setCurrentText(equip.getType());
    ui->comboBox_2->setCurrentText(equip.getEtat());
    ui->comboBox_3->setCurrentText(equip.getDispo());
    ui->spinBox->setValue(equip.getNombre());

    QByteArray imageData = equip.getImageData();
    if (!imageData.isEmpty()) {
        selectedImageData = imageData; // Stocker les données binaires

        // Afficher un aperçu de l'image
        QPixmap pixmap;
        if (pixmap.loadFromData(imageData)) {
            // Si vous avez un QLabel pour l'aperçu (remplacez 'ui->labelImage' par votre widget)
            ui->labelImage->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            ui->pushButton->setText("Image chargée");
        } else {
            ui->labelImage->clear();
            ui->pushButton->setText("Image corrompue");
            selectedImageData.clear();
        }
    } else {
        ui->labelImage->clear();
        ui->pushButton->setText("Choisir image");
        selectedImageData.clear();
    }

    isModifying = true;
}
void MainWindow::on_pushButton_3_clicked() {
    ui->lineEdit->clear();  // id
    ui->lineEdit_3->clear();  // nom
    ui->comboBox_4->setCurrentIndex(0);  // type
    ui->comboBox_2->setCurrentIndex(0);  // etat
    ui->comboBox_3->setCurrentIndex(0);  // dispo
    ui->spinBox->setValue(0);  // nbre
    selectedImageData.clear();  // image
    ui->radioButton->setChecked(false);  // "Ajouter"
    ui->radioButton_2->setChecked(false);  // "Modifier"
}

void MainWindow::reinitialiserFormulaire() {
    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->comboBox_4->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->spinBox->setValue(1);
    selectedImageData.clear();
    if (ui->labelImage) {
        ui->labelImage->clear();
    }
    ui->pushButton->setText("Choisir image");
    ui->pushButton->setIcon(QIcon());
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton->setAutoExclusive(true);
    isModifying = false;
    ui->tableWidget->clearSelection();
    selectedId.clear();
    ui->lineEdit->setFocus();
}

void MainWindow::on_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableWidget->rowCount();
    const int columnCount = ui->tableWidget->columnCount();

    out << "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=UTF-8\">\n"
        << QString("<title>%1</title>\n").arg("Liste des Equipements")
        << "<style>\n"
           "body { font-family: Arial, sans-serif; font-size: 200px; margin: 250px; }\n"
           ".grand-titre { font-size: 200px !important; font-weight: bold; text-align: center; text-decoration: underline; margin: 200px 0; }\n"
           "table { border-collapse: collapse; width: 100%; border: 20px solid #ddd; }\n"
           "th, td { text-align: left; padding: 100px; border: 20px solid #ddd; }\n"
           "th { background-color: #2980B9; color: white; font-size: 200px; }\n"
           "tr:nth-child(even) { background-color: #f9f9f9; }\n"
           "tr:hover { background-color: #f1f1f1; }\n"
           "img { max-width: 300px; max-height: 300px; }\n"
           "</style>\n"
           "</head>\n"
           "<body>\n"

           "<div class='grand-titre'>Liste des Equipements</div>\n"
           "<br><br>\n"
           "<table>\n";

    // headers
    out << "<thead><tr> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        QString header = ui->tableWidget->horizontalHeaderItem(column)->text();
        out << QString("<th>%1</th>").arg(header);
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            QString data;

            if (column == 2) { // Colonne image
                // Récupérer le widget de la cellule (qui devrait être un QLabel avec l'image)
                QLabel* imageLabel = qobject_cast<QLabel*>(ui->tableWidget->cellWidget(row, column));
                if (imageLabel) {
                    QPixmap pixmap = imageLabel->pixmap(Qt::ReturnByValue);
                    if (!pixmap.isNull()) {
                        // Sauvegarder temporairement l'image et utiliser son chemin
                        QString tempImagePath = QDir::tempPath() + QString("/temp_image_%1_%2.png").arg(row).arg(column);
                        if (pixmap.save(tempImagePath)) {
                            data = QString("<img src='%1' width='500' height='500' />").arg(tempImagePath);

                        }
                    }
                }
                if (data.isEmpty()) {
                    data = "Aucune image";
                }
            } else {
                QTableWidgetItem* item = ui->tableWidget->item(row, column);
                data = item ? item->text() : QString();
            }

            out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        out << "</tr>\n";
    }

    // Pied de page
    out << "</tbody></table>"
           "<div class=\"footer\">"
           "<br><br>\n  Généré le " << QDateTime::currentDateTime().toString("dd/MM/yyyy à HH:mm") <<
        "</div>"
        "</body></html>";

    QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageLayout().paintRectPixels(printer.resolution()).size());
    doc.print(&printer);

    QMessageBox::information(this, "PDF généré", QString("Le fichier PDF a été généré avec succès dans %1.").arg(fileName));
}


void MainWindow::on_stat_clicked()
{
    // Requêtes SQL pour compter les équipements par état et disponibilité
    QSqlQuery query;

    // Compter les équipements par état
    query.exec("SELECT etat, COUNT(*) FROM EQUIPEMENT GROUP BY etat");
    QPieSeries *etatSeries = new QPieSeries();

    while (query.next()) {
        QString etat = query.value(0).toString();
        int count = query.value(1).toInt();
        etatSeries->append(etat + " (" + QString::number(count) + ")", count);
    }

    // Compter les équipements par disponibilité
    query.exec("SELECT disponibilite, COUNT(*) FROM EQUIPEMENT GROUP BY disponibilite");
    QPieSeries *dispoSeries = new QPieSeries();

    while (query.next()) {
        QString dispo = query.value(0).toString();
        int count = query.value(1).toInt();
        dispoSeries->append(dispo + " (" + QString::number(count) + ")", count);
    }

    // Compter les équipements par type
    query.exec("SELECT type, COUNT(*) FROM EQUIPEMENT GROUP BY type");
    QPieSeries *typeSeries = new QPieSeries();

    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        typeSeries->append(type + " (" + QString::number(count) + ")", count);
    }

    // Création des graphiques
    QChart *etatChart = new QChart();
    etatChart->addSeries(etatSeries);
    etatChart->setTitle("Répartition par état");
    etatChart->legend()->setVisible(true);
    etatChart->legend()->setAlignment(Qt::AlignBottom);

    QChart *dispoChart = new QChart();
    dispoChart->addSeries(dispoSeries);
    dispoChart->setTitle("Répartition par disponibilité");
    dispoChart->legend()->setVisible(true);
    dispoChart->legend()->setAlignment(Qt::AlignBottom);

    QChart *typeChart = new QChart();
    typeChart->addSeries(typeSeries);
    typeChart->setTitle("Répartition par type");
    typeChart->legend()->setVisible(true);
    typeChart->legend()->setAlignment(Qt::AlignBottom);

    // Configuration des vues
    QChartView *etatView = new QChartView(etatChart);
    etatView->setRenderHint(QPainter::Antialiasing);

    QChartView *dispoView = new QChartView(dispoChart);
    dispoView->setRenderHint(QPainter::Antialiasing);

    QChartView *typeView = new QChartView(typeChart);
    typeView->setRenderHint(QPainter::Antialiasing);

    // Création d'une fenêtre pour afficher tous les graphiques
    QWidget *statsWindow = new QWidget();
    statsWindow->setWindowTitle("Statistiques des équipements");
    statsWindow->resize(1200, 600);

    QGridLayout *layout = new QGridLayout(statsWindow);
    layout->addWidget(etatView, 0, 0);
    layout->addWidget(dispoView, 0, 1);
    layout->addWidget(typeView, 1, 0, 1, 2);

    statsWindow->setLayout(layout);
    statsWindow->show();
}
void MainWindow::on_ok_clicked() {
    if (!ui) {
        qDebug() << "Erreur: ui n'est pas initialisé!";
        return;
    }

    QString critere = ui->comboBox_5->currentText().trimmed(); // Éviter les espaces invisibles
    QString valeur = ui->lineEdit_2->text().trimmed();

    if (valeur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une valeur de recherche.");
        return;
    }

    // Déclaration de la requête SQL
    QString queryStr;

    if (critere == "type") {
        queryStr = "SELECT * FROM EQUIPEMENT WHERE type LIKE :valeur";
    }
    else if (critere == "id équipement") {
        queryStr = "SELECT * FROM EQUIPEMENT WHERE TRIM(id_equipement) LIKE :valeur";
    }
    else if (critere == "disponibilité") {
        queryStr = "SELECT * FROM EQUIPEMENT WHERE disponibilite = :valeur";
    }
    else {
        QMessageBox::warning(this, "Erreur", "Critère de recherche invalide.");
        return;
    }

    QSqlQuery query;
    query.prepare(queryStr);

    if (critere == "type" || critere == "id équipement") {
        query.bindValue(":valeur", "%" + valeur + "%");
    } else {
        query.bindValue(":valeur", valeur);
    }

    // Affichage de la requête pour debug
    qDebug() << "Requête exécutée : " << queryStr << " avec valeur = " << valeur;

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur de recherche: " + query.lastError().text());
        return;
    }

    // Affichage des résultats
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("id_equipement").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("nom_eq").toString()));

        QByteArray imageData = query.value("image").toByteArray();
        if (!imageData.isEmpty()) {
            QPixmap pixmap;
            if (pixmap.loadFromData(imageData)) {
                QLabel *imageLabel = new QLabel(this);
                imageLabel->setPixmap(pixmap.scaled(80, 80, Qt::KeepAspectRatio));
                ui->tableWidget->setCellWidget(row, 2, imageLabel);
            } else {
                ui->tableWidget->setItem(row, 2, new QTableWidgetItem("Image invalide"));
            }
        } else {
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem("Aucune image"));
        }

        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("type").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("etat").toString()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("disponibilite").toString()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("nbre_eq").toString()));

        row++;
    }

    if (row == 0) {
        QMessageBox::information(this, "Information", "Aucun résultat trouvé.");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    // Récupère la liste des équipements
    QList<Equipement> liste = Equipement::afficher();

    // Réaffiche tous les équipements avec la liste obtenue
    afficherEquipements(liste);

    // Réinitialise les champs de recherche si nécessaire
    ui->lineEdit_2->clear();
    ui->comboBox_5->setCurrentIndex(0);
}


void MainWindow::onTriDeclenche() {
    if (!ui->radioButton_3->isChecked() && !ui->radioButton_4->isChecked()) {
        return;
    }

    QString critere = ui->comboBox->currentText();
    bool ascendant = ui->radioButton_3->isChecked();

    QList<Equipement> liste = Equipement::afficher();
    if (liste.isEmpty()) return;

    // Définition de l'ordre des états avec priorité
    auto getEtatPriority = [](const QString& etat) {
        QString etatLower = etat.toLower();
        if (etatLower.contains("fonctionnel") && !etatLower.contains("pas")) return 1;
        if (etatLower.contains("maintenance")) return 2;
        if (etatLower.contains("pas fonctionnel")) return 3;
        return 4; // Pour les autres états non prévus
    };

    auto comparer = [critere, ascendant, getEtatPriority](const Equipement& a, const Equipement& b) {
        if (critere == "état") {
            int prioriteA = getEtatPriority(a.getEtat());
            int prioriteB = getEtatPriority(b.getEtat());
            return ascendant ? (prioriteA < prioriteB) : (prioriteA > prioriteB);
        }
        else if (critere == "nbre d'équipement") {
            return ascendant ? (a.getNombre() < b.getNombre())
                            : (a.getNombre() > b.getNombre());
        }
        else { // "nom d'équipement"
            return ascendant ? (a.getNom().compare(b.getNom(), Qt::CaseInsensitive) < 0)
                            : (a.getNom().compare(b.getNom(), Qt::CaseInsensitive) > 0);
        }
    };

    std::sort(liste.begin(), liste.end(), comparer);
    afficherEquipements(liste);
}

void MainWindow::checkEquipmentStatus() {
    // Recherche flexible
    int nonFonctionnel = Equipement::countEquipementsParEtat("pas fonctionnel");
    int maintenance = Equipement::countEquipementsParEtat("maintenance");
    int total = nonFonctionnel + maintenance;

    qDebug() << "[DEBUG] Non fonctionnels:" << nonFonctionnel
             << "| En maintenance:" << maintenance
             << "| Total:" << total;

    updateNotificationBadge(total); // Met à jour le badge
}

void MainWindow::updateNotificationBadge(int count)
{
    if (count > 0) {
        // Activer le mode alerte
        ui->noti->setProperty("alert", true);
        ui->noti->style()->unpolish(ui->noti);
        ui->noti->style()->polish(ui->noti);

        // Mettre à jour le badge
        notificationBadge->setText(QString::number(count));
        notificationBadge->adjustSize();
        notificationBadge->show();

        // Afficher une notification système
        if (QSystemTrayIcon::isSystemTrayAvailable()) {
            QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
            trayIcon->setIcon(QIcon(":/icons/app_icon.png")); // Remplacez par votre icône

            // Calcul des différents états
            int nonFonctionnel = Equipement::countEquipementsParEtat("Pas fonctionnel");
            int maintenance = Equipement::countEquipementsParEtat("Maintenance");

            QString message;
            if (nonFonctionnel > 0 && maintenance > 0) {
                message = QString("%1 équipement(s) non fonctionnel(s) + %2 en maintenance")
                              .arg(nonFonctionnel).arg(maintenance);
            }
            else if (nonFonctionnel > 0) {
                message = QString("%1 équipement(s) non fonctionnel(s)").arg(nonFonctionnel);
            }
            else {
                message = QString("%1 équipement(s) en maintenance").arg(maintenance);
            }

            trayIcon->showMessage("Alertes Équipements",
                                  message,
                                  QSystemTrayIcon::Warning,
                                  10000); // 10 secondes

            // Nettoyage automatique
            QTimer::singleShot(11000, trayIcon, &QObject::deleteLater);
        }
    } else {
        // Désactiver le mode alerte
        ui->noti->setProperty("alert", false);
        ui->noti->style()->unpolish(ui->noti);
        ui->noti->style()->polish(ui->noti);

        // Cacher le badge
        notificationBadge->hide();

        // Notification de retour à la normale
        if (QSystemTrayIcon::isSystemTrayAvailable() && wasInAlertState) {
            QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
            trayIcon->setIcon(QIcon(":/icons/app_icon.png"));
            trayIcon->showMessage("Statut Équipement",
                                  "Tous les équipements sont opérationnels",
                                  QSystemTrayIcon::Information,
                                  5000);
            QTimer::singleShot(6000, trayIcon, &QObject::deleteLater);
        }
    }
    wasInAlertState = (count > 0);
}
void MainWindow::showEquipmentAlerts()
{
    QList<Equipement> alertes = Equipement::getEquipementsNonFonctionnels();

    if (alertes.isEmpty()) {
        QMessageBox::information(this, "Aucune alerte", "Tous les équipements sont opérationnels");
        return;
    }

    QDialog *alertDialog = new QDialog(this);
    alertDialog->setWindowTitle("Alertes Équipements");
    alertDialog->setMinimumSize(600, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(alertDialog);

    // Titre
    QLabel *titleLabel = new QLabel(QString("%1 Équipement(s) nécessitant attention").arg(alertes.count()));
    titleLabel->setStyleSheet("font-weight: bold; font-size: 16px; margin-bottom: 15px;");
    mainLayout->addWidget(titleLabel);

    // Zone scrollable
    QScrollArea *scrollArea = new QScrollArea();
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *alertsLayout = new QVBoxLayout(scrollContent);

    foreach (const Equipement &e, alertes) {
        QFrame *alertFrame = new QFrame();

        // Déterminez la couleur en fonction de l'état
        QString frameStyle = "padding: 10px; margin: 5px; border-left: 4px solid ";
        QString etat = e.getEtat().toLower();

        if (etat.contains("maintenance")) {
            frameStyle += "#ffc107; background-color: #fff8e6;"; // Jaune pour maintenance
        } else {
            frameStyle += "#dc3545; background-color: #fff5f5;"; // Rouge pour non fonctionnel
        }

        alertFrame->setStyleSheet(frameStyle);

        QHBoxLayout *frameLayout = new QHBoxLayout(alertFrame);

        // Icône
        QLabel *iconLabel = new QLabel();
        QPixmap pixmap;
        if (!e.getImageData().isEmpty() && pixmap.loadFromData(e.getImageData())) {
            iconLabel->setPixmap(pixmap.scaled(40, 40, Qt::KeepAspectRatio));
        } else {
            iconLabel->setPixmap(QPixmap(etat.contains("maintenance")
                                         ? ":/icons/warning.png"
                                         : ":/icons/error.png").scaled(40, 40));
        }
        frameLayout->addWidget(iconLabel);

        // Informations
        QLabel *infoLabel = new QLabel(
            QString("<b>%1</b><br>"
                    "ID: %2<br>"
                    "Type: %3<br>"
                    "État: <span style='color: %4'>%5</span>")
                .arg(e.getNom())
                .arg(e.getId())
                .arg(e.getType())
                .arg(etat.contains("maintenance") ? "#ff9900" : "#dc3545")
                .arg(e.getEtat()));

        infoLabel->setStyleSheet("font-size: 12px;");
        frameLayout->addWidget(infoLabel, 1);
        alertsLayout->addWidget(alertFrame);
    }

    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);

    // Bouton Fermer
    QPushButton *closeButton = new QPushButton("Fermer");
    connect(closeButton, &QPushButton::clicked, alertDialog, &QDialog::accept);
    mainLayout->addWidget(closeButton, 0, Qt::AlignRight);

    alertDialog->exec();
    delete alertDialog;
}
void MainWindow::refreshAlertCount()
{
    checkEquipmentStatus(); // Force la vérification immédiate
}
