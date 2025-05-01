#include "equipement1.h"
#include "ui_equipement1.h"
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
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QWidget>
#include <QtCharts>
#include <QSqlQuery>
#include <QLabel>
#include <QGroupBox>
#include <QFont>
#include "arduinoE.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initArduinoConnection();
    connect(ui->supp_3, &QPushButton::clicked, this, &MainWindow::supp_3_clicked);
    isModifying = false;
    connect(ui->ok_3, &QPushButton::clicked, this, &MainWindow::on_ok_3_clicked);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked);
    connect(ui->radioButton_9, &QRadioButton::clicked, this, &MainWindow::onTriDeclenche);
    connect(ui->radioButton_10, &QRadioButton::clicked, this, &MainWindow::onTriDeclenche);
    connect(ui->comboBox_12, QOverload<int>::of(&QComboBox::currentIndexChanged), [this]() {
        if (ui->radioButton_9->isChecked() || ui->radioButton_10->isChecked()) {
            onTriDeclenche();
        }
    });
    ui->logo->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\bg.jpg"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\empe.png"));
    ui->supp_3->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\effacer.png"));
    ui->chercheur->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\cher.png"));
    ui->pdf_3->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\client.png"));
    ui->stat_3->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\st.png"));
    ui->ok_3->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\search.png"));
    ui->pushButton_10->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\loading-arrow.png"));
    ui->noti->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\notif.png"));
    ui->calen->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\calend.png"));


    QList<Equipement> liste = Equipement::afficher();
    afficherEquipements(liste);
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

    notificationTimer = new QTimer(this);
    connect(notificationTimer, &QTimer::timeout, this, &MainWindow::checkEquipmentStatus);
    notificationTimer->start(6000);
    checkEquipmentStatus();
   connect(ui->noti, &QPushButton::clicked, this, &MainWindow::showAlertNotification);

    ui->tableWidget_3->setStyleSheet(
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

    ui->tableWidget_3->repaint();

    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données !");
    }
    QTimer::singleShot(0, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page_liste);
    });
    etatView = new QChartView(ui->page_stats);
    dispoView = new QChartView(ui->page_stats);
    typeView = new QChartView(ui->page_stats);

    QVBoxLayout *statsLayout = new QVBoxLayout(ui->page_stats);

    QLabel *statsTitle = new QLabel("Statistiques des Équipements");
    statsTitle->setAlignment(Qt::AlignCenter);
    QFont titleFont = statsTitle->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    statsTitle->setFont(titleFont);

    statsLayout->addWidget(statsTitle);

    QGridLayout *chartsLayout = new QGridLayout();
    chartsLayout->addWidget(etatView, 0, 0);
    chartsLayout->addWidget(dispoView, 0, 1);
    chartsLayout->addWidget(typeView, 1, 0, 1, 2);

    statsLayout->addLayout(chartsLayout);

    QPushButton *backButton = new QPushButton("Retour à la liste");
    backButton->setStyleSheet("QPushButton { background-color: #02767F; color: white; padding: 8px; border-radius: 4px; }");
    connect(backButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page_liste);
    });
    statsLayout->addWidget(backButton, 0, Qt::AlignLeft);
    connect(ui->calen, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->calender_page);
        afficherDisponibiliteSurCalendrier();
    });

    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::afficherDetailsEquipement);
     calendarWidget = ui->calendarWidget;

     connect(ui->calen, &QPushButton::clicked, this, [this]() {
         ui->stackedWidget->setCurrentWidget(ui->calender_page);
         afficherDisponibiliteSurCalendrier();
     });
     connect(calendarWidget, &QCalendarWidget::currentPageChanged,
             this, &MainWindow::afficherDisponibiliteSurCalendrier);

     backButtonCalendar = new QPushButton("Retour", ui->calender_page);
     backButtonCalendar->setGeometry(20, 10, 121, 41);
     backButtonCalendar->setStyleSheet(
         "QPushButton {"
         "    background-color: #02767F;"
         "    color: white;"
         "    border-radius: 5px;"
         "    padding: 10px;"
         "    font-weight: bold;"
         "    border: none;"
         "}"
         "QPushButton:hover {"
         "    background-color: #247361;"
         "}"
         );


     backButtonCalendar->setIcon(QPixmap("C:\\Users\\manel\\Desktop\\projet_c\\back.png"));
     backButtonCalendar->setIconSize(QSize(20, 20));


     connect(backButtonCalendar, &QPushButton::clicked, this, [this]() {
         ui->stackedWidget->setCurrentWidget(ui->page_liste);
     });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_12_clicked() {
    QString id = ui->lineEdit_8->text();
    QDate dateDebut = ui->dateEditDebut->date();
    QDate dateFin = ui->dateEditFin->date();

    if (id.isEmpty() || id.length() > 5 || !id.toInt()) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'équipement doit être un nombre entier de maximum 5 chiffres.");
        return;
    }
    // Vérification des dates
    if (dateDebut > dateFin) {
        QMessageBox::warning(this, "Erreur", "La date de début doit être antérieure à la date de fin.");
        return;
    }
    if (ui->radioButton_12->isChecked()) {
        if (!isModifying) {
            if (!equip.existe(id)) {
                QMessageBox::warning(this, "Erreur", "L'équipement avec cet ID n'existe pas.");
                return;
            }

            chargerEquipement();
            isModifying = true;
        } else {
            QString nom = ui->lineEdit_9->text();
            QString type = ui->comboBox_15->currentText();
            QString etat = ui->comboBox_13->currentText();
            QString dispo = ui->comboBox_14->currentText();
            int nbre = ui->spinBox_3->value();
            QString resis = ui->comboBox_16->currentText();
            QRegularExpression nomRegex("^[A-Za-z\\s]+$");
            if (nom.isEmpty() || !nomRegex.match(nom).hasMatch()) {
                QMessageBox::warning(this, "Erreur", "Le nom de l'équipement ne peut contenir que des lettres et des espaces.");
                return;
            }

            if (type.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type d'équipement.");
                return;
            }

            if (etat.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un état pour l'équipement.");
                return;
            }

            if (dispo.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une disponibilité pour l'équipement.");
                return;
            }
            if (nbre <= 0) {
                QMessageBox::warning(this, "Erreur", "Le nombre d'équipements doit être supérieur à zéro.");
                return;
            }
            Equipement equip(id, nom, etat, selectedImageData, type, dispo, nbre, dateDebut, dateFin, resis);
            if (equip.modifier()) {
                QMessageBox::information(this, "Succès", "Équipement modifié avec succès.");
                actualiserTableau();
                reinitialiserFormulaire();
                refreshAlertCount();
                isModifying = false;
                afficherDisponibiliteSurCalendrier();
            }

        }
    } else if (ui->radioButton_11->isChecked()) { // Mode ajout
        if (equip.existe(id)) {
            QMessageBox::warning(this, "Erreur", "Un équipement avec cet ID existe déjà.");
            return;
        }

        QString nom = ui->lineEdit_9->text();
        QString type = ui->comboBox_15->currentText();
        QString etat = ui->comboBox_13->currentText();
        QString dispo = ui->comboBox_14->currentText();
        int nbre = ui->spinBox_3->value();
        QString resis = ui->comboBox_16->currentText();
        QRegularExpression nomRegex("^[A-Za-z\\s]+$");
        if (nom.isEmpty() || !nomRegex.match(nom).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "Le nom de l'équipement ne peut contenir que des lettres et des espaces.");
            return;
        }
        if (type.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type d'équipement.");
            return;
        }
        if (etat.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un état pour l'équipement.");
            return;
        }
        if (dispo.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une disponibilité pour l'équipement.");
            return;
        }
        if (nbre <= 0) {
            QMessageBox::warning(this, "Erreur", "Le nombre d'équipements doit être supérieur à zéro.");
            return;
        }
        Equipement equip(id, nom, etat, selectedImageData, type, dispo, nbre, dateDebut, dateFin, resis);
        if (equip.ajouter()) {
            QMessageBox::information(this, "Succès", "Équipement ajouté avec succès.");
            actualiserTableau();
            reinitialiserFormulaire();
            afficherDisponibiliteSurCalendrier();
        } else {
            QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
        }
    } else {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner 'Ajouter' ou 'Modifier' avant de valider.");
    }
}
void MainWindow::on_pushButton_11_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir l'image sélectionnée.");
            return;
        }
        QByteArray imageData = file.readAll();
        file.close();
        selectedImageData = imageData;

        ui->pushButton_11->setText("Image sélectionnée");
    }
}

void MainWindow::afficherEquipements(const QList<Equipement>& liste) {
    ui->tableWidget_3->setRowCount(liste.size());
   QStringList headers = {"ID", "Nom", "Image", "Type", "État", "Disponibilité", "Nombre", "Résistance feu"};
    ui->tableWidget_3->setHorizontalHeaderLabels(headers);
    ui->tableWidget_3->setUpdatesEnabled(false);

    for (int i = 0; i < liste.size(); ++i) {
        const Equipement& e = liste[i];

        ui->tableWidget_3->setItem(i, 0, new QTableWidgetItem(e.getId()));
        ui->tableWidget_3->setItem(i, 1, new QTableWidgetItem(e.getNom()));


        QByteArray imageData = e.getImageData();
        if (!imageData.isEmpty()) {
            QPixmap pixmap;
            if (pixmap.loadFromData(imageData)) {
                QLabel *imageLabel = new QLabel();
                imageLabel->setPixmap(pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                imageLabel->setAlignment(Qt::AlignCenter);
                ui->tableWidget_3->setCellWidget(i, 2, imageLabel);
            } else {
                ui->tableWidget_3->setItem(i, 2, new QTableWidgetItem("Image invalide"));
            }
        } else {
            ui->tableWidget_3->setItem(i, 2, new QTableWidgetItem("Aucune image"));
        }
        ui->tableWidget_3->setItem(i, 3, new QTableWidgetItem(e.getType()));
        ui->tableWidget_3->setItem(i, 4, new QTableWidgetItem(e.getEtat()));
        ui->tableWidget_3->setItem(i, 5, new QTableWidgetItem(e.getDispo()));
        ui->tableWidget_3->setItem(i, 6, new QTableWidgetItem(QString::number(e.getNombre())));
        ui->tableWidget_3->setItem(i, 7, new QTableWidgetItem(e.getResisFlamme()));
    }
    ui->tableWidget_3->setUpdatesEnabled(true);
    ui->tableWidget_3->resizeColumnsToContents();
    ui->tableWidget_3->resizeRowsToContents();
}


void MainWindow::actualiserTableau() {
    ui->tableWidget_3->clear();
    ui->tableWidget_3->setColumnCount(8);
    QStringList headers = {"ID", "Nom", "Image", "Type", "État", "Disponibilité", "Nombre" , "Résistance feu"};
    ui->tableWidget_3->setHorizontalHeaderLabels(headers);
    QList<Equipement> liste = Equipement::afficher();
    ui->tableWidget_3->setRowCount(liste.size());
    for (int i = 0; i < liste.size(); ++i) {
        ui->tableWidget_3->setItem(i, 0, new QTableWidgetItem(liste[i].getId()));
        ui->tableWidget_3->setItem(i, 1, new QTableWidgetItem(liste[i].getNom()));

        QByteArray imageData = liste[i].getImageData();
        if (!imageData.isEmpty()) {
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            if (!pixmap.isNull()) {
                QLabel *imageLabel = new QLabel();
                imageLabel->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio));
                ui->tableWidget_3->setCellWidget(i, 2, imageLabel);
            }
        }
        ui->tableWidget_3->setItem(i, 3, new QTableWidgetItem(liste[i].getType()));
        ui->tableWidget_3->setItem(i, 4, new QTableWidgetItem(liste[i].getEtat()));
        ui->tableWidget_3->setItem(i, 5, new QTableWidgetItem(liste[i].getDispo()));
        ui->tableWidget_3->setItem(i, 6, new QTableWidgetItem(QString::number(liste[i].getNombre())));
        ui->tableWidget_3->setItem(i, 7, new QTableWidgetItem(liste[i].getResisFlamme()));
    }
}

void MainWindow::supp_3_clicked() {
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
            actualiserTableau();
            afficherDisponibiliteSurCalendrier();
            selectedId.clear();
        } else {
            QMessageBox::critical(this, "Erreur", "La suppression a échoué ou l'équipement n'existe pas.");
        }
    }
}
void MainWindow::on_tableWidget_3_itemClicked(QTableWidgetItem *item) {
    if (!item) return;

    int row = item->row();
    if (row < 0 || row >= ui->tableWidget_3->rowCount()) return;
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_3->setSelectionMode(QAbstractItemView::SingleSelection);
    QTableWidgetItem *idItem = ui->tableWidget_3->item(row, 0);
    if (idItem) {
        selectedId = idItem->text();
        ui->tableWidget_3->selectRow(row);
    }
}
void MainWindow::chargerEquipement() {
    QString id = ui->lineEdit_8->text();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID d'équipement.");
        return;
    }

    Equipement equip = Equipement::getEquipementById(id);

    if (equip.getId().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun équipement trouvé avec cet ID.");
        return;
    }
    ui->lineEdit_9->setText(equip.getNom());
    ui->comboBox_15->setCurrentText(equip.getType());
    ui->comboBox_13->setCurrentText(equip.getEtat());
    ui->comboBox_14->setCurrentText(equip.getDispo());
    ui->spinBox_3->setValue(equip.getNombre());
    ui->comboBox_16->setCurrentText(equip.getResisFlamme());

    QByteArray imageData = equip.getImageData();
    if (!imageData.isEmpty()) {
        selectedImageData = imageData;
        QPixmap pixmap;
        if (pixmap.loadFromData(imageData)) {
            // ui->labelImage_3->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            ui->pushButton_11->setText("Image chargée");
        } else {
            ui->labelImage_3->clear();
            ui->pushButton_11->setText("Image corrompue");
            selectedImageData.clear();
        }
    } else {
        ui->labelImage_3->clear();
        ui->pushButton_11->setText("Choisir image");
        selectedImageData.clear();
    }

    isModifying = true;
}
void MainWindow::reinitialiserFormulaire() {
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->comboBox_15->setCurrentIndex(0);
    ui->comboBox_13->setCurrentIndex(0);
    ui->comboBox_14->setCurrentIndex(0);
    ui->comboBox_16->setCurrentIndex(0); // ou une autre valeur par défaut
    ui->spinBox_3->setValue(1);
    selectedImageData.clear();
    if (ui->labelImage_3) {
        ui->labelImage_3->clear();
    }
    ui->pushButton_11->setText("Choisir image");
    ui->pushButton_11->setIcon(QIcon());
    ui->radioButton_11->setAutoExclusive(false);
    ui->radioButton_11->setChecked(false);
    ui->radioButton_12->setChecked(false);
    ui->radioButton_11->setAutoExclusive(true);
    isModifying = false;
    ui->tableWidget_3->clearSelection();
    selectedId.clear();
    ui->lineEdit_8->setFocus();
}

void MainWindow::on_pushButton_13_clicked() {
    reinitialiserFormulaire();
}
void MainWindow::on_pdf_3_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableWidget_3->rowCount();
    const int columnCount = ui->tableWidget_3->columnCount();

    QString logoPath = QDir::tempPath() + "/logo_app.png";
    QPixmap originalLogo("C:\\Users\\manel\\Desktop\\projet_c\\logo1.png");
    QPixmap largeLogo = originalLogo.scaled(1050, 1050, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    largeLogo.save(logoPath);

    out << "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=UTF-8\">\n"
        << QString("<title>%1</title>\n").arg("Liste des Equipements")
        << "<style>\n"
           "body { font-family: Arial, sans-serif; font-size: 200px; margin: 250px; }\n"
           ".header { display: flex; justify-content: space-between; align-items: center; margin-bottom: 500px; }\n"
           ".logo { height: 3000px !important; }\n"
           ".grand-titre {font-size: 300px !important;font-weight: bold; text-align: center;color: #2c3e50;background: linear-gradient(to right, #3498db, #9b59b6);-webkit-background-clip: text;-webkit-text-fill-color: transparent;margin: 200px 0; letter-spacing: 15px;text-transform: uppercase; }\n"
           "table { border-collapse: collapse; width: 100%; border: 20px solid #ddd; }\n"
           "th, td { text-align: left; padding: 100px; border: 20px solid #ddd; }\n"
           "th { background-color: #2980B9; color: white; font-size: 200px; }\n"
           "tr:nth-child(even) { background-color: #f9f9f9; }\n"
           "tr:hover { background-color: #f1f1f1; }\n"
           "img { max-width: 300px; max-height: 300px; }\n"
           "</style>\n"
           "</head>\n"
           "<body>\n"
           "<div class='header'>\n"

        <<QString("<img class='logo' src='%1' />\n").arg(logoPath)
        << "<div class='grand-titre'>Liste des Equipements</div>\n"
           "<div style='width: 150px;'></div>\n"
           "</div>\n"
           "<br>\n"
           "<table>\n";


    // headers
    out << "<thead><tr> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        QString header = ui->tableWidget_3->horizontalHeaderItem(column)->text();
        out << QString("<th>%1</th>").arg(header);
    }
    out << "</tr></thead>\n";


    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            QString data;

            if (column == 2) {

                QLabel* imageLabel = qobject_cast<QLabel*>(ui->tableWidget_3->cellWidget(row, column));
                if (imageLabel) {
                    QPixmap pixmap = imageLabel->pixmap(Qt::ReturnByValue);
                    if (!pixmap.isNull()) {

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
                QTableWidgetItem* item = ui->tableWidget_3->item(row, column);
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
void MainWindow::on_stat_3_clicked()
{
    QSqlQuery query;

    // Obtenir le nombre total d'équipements
    int totalEquipements = 0;
    if (query.exec("SELECT COUNT(*) FROM EQUIPEMENT") && query.next()) {
        totalEquipements = query.value(0).toInt();
    }

    if (totalEquipements == 0) {
        QMessageBox::information(this, "Information", "Aucun équipement trouvé dans la base de données.");
        return;
    }

    // --- Série pour état ---
    QPieSeries *etatSeries = new QPieSeries();
    query.exec("SELECT etat, COUNT(*) FROM EQUIPEMENT GROUP BY etat");
    while (query.next()) {
        QString etat = query.value(0).toString();
        int count = query.value(1).toInt();
        double percentage = (count * 100.0) / totalEquipements;
        QPieSlice *slice = etatSeries->append(QString("%1 (%2%)").arg(etat).arg(QString::number(percentage, 'f', 1)), count);
        slice->setLabelVisible(true);
    }

    // --- Série pour disponibilité ---
    QPieSeries *dispoSeries = new QPieSeries();
    query.exec("SELECT disponibilite, COUNT(*) FROM EQUIPEMENT GROUP BY disponibilite");
    while (query.next()) {
        QString dispo = query.value(0).toString();
        int count = query.value(1).toInt();
        double percentage = (count * 100.0) / totalEquipements;
        QPieSlice *slice = dispoSeries->append(QString("%1 (%2%)").arg(dispo).arg(QString::number(percentage, 'f', 1)), count);
        slice->setLabelVisible(true);
    }

    // --- Série pour type ---
    QPieSeries *typeSeries = new QPieSeries();
    query.exec("SELECT type, COUNT(*) FROM EQUIPEMENT GROUP BY type");
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        double percentage = (count * 100.0) / totalEquipements;
        QPieSlice *slice = typeSeries->append(QString("%1 (%2%)").arg(type).arg(QString::number(percentage, 'f', 1)), count);
        slice->setLabelVisible(true);
    }

    // Créer les graphiques
    QChart *etatChart = new QChart();
    etatChart->addSeries(etatSeries);
    etatChart->setTitle("Répartition par état");
    etatChart->legend()->setVisible(true);
    etatChart->legend()->setAlignment(Qt::AlignBottom);
    etatChart->setAnimationOptions(QChart::SeriesAnimations);
    etatView->setChart(etatChart);
    etatView->setRenderHint(QPainter::Antialiasing);

    QChart *dispoChart = new QChart();
    dispoChart->addSeries(dispoSeries);
    dispoChart->setTitle("Répartition par disponibilité");
    dispoChart->legend()->setVisible(true);
    dispoChart->legend()->setAlignment(Qt::AlignBottom);
    dispoChart->setAnimationOptions(QChart::SeriesAnimations);
    dispoView->setChart(dispoChart);
    dispoView->setRenderHint(QPainter::Antialiasing);

    QChart *typeChart = new QChart();
    typeChart->addSeries(typeSeries);
    typeChart->setTitle("Répartition par type");
    typeChart->legend()->setVisible(true);
    typeChart->legend()->setAlignment(Qt::AlignBottom);
    typeChart->setAnimationOptions(QChart::SeriesAnimations);
    typeView->setChart(typeChart);
    typeView->setRenderHint(QPainter::Antialiasing);

    // Passer à la page des statistiques
    ui->stackedWidget->setCurrentWidget(ui->page_stats);
}
void MainWindow::on_ok_3_clicked() {
    if (!ui) {
        qDebug() << "Erreur: ui n'est pas initialisé!";
        return;
    }

    QString critere = ui->comboBox_11->currentText().trimmed();
    QString valeur = ui->lineEdit_7->text().trimmed();

    if (valeur.isEmpty()) {
        if (!QApplication::activeModalWidget()) { // Empêche double affichage
            QMessageBox::warning(this, "Erreur", "Veuillez entrer une valeur de recherche.");
        }
        return;
    }

    QMap<QString, QString> critereToColumn = {
        {"type", "type"},
        {"id équipement", "TRIM(id_equipement)"},
        {"disponibilité", "disponibilite"}
    };

    if (!critereToColumn.contains(critere)) {
        QMessageBox::warning(this, "Erreur", "Critère de recherche invalide.");
        return;
    }

    QString column = critereToColumn.value(critere);
    QString queryStr = QString("SELECT * FROM EQUIPEMENT WHERE %1 LIKE :valeur").arg(column);

    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":valeur", "%" + valeur + "%"); // Recherche partielle pour tous

    qDebug() << "Requête exécutée : " << queryStr << " avec valeur = " << valeur;

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur de recherche: " + query.lastError().text());
        return;
    }

    ui->tableWidget_3->clearContents();
    ui->tableWidget_3->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget_3->insertRow(row);
        ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(query.value("id_equipement").toString()));
        ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(query.value("nom_eq").toString()));

        QByteArray imageData = query.value("image").toByteArray();
        QTableWidgetItem *imgItem = new QTableWidgetItem;
        if (!imageData.isEmpty()) {
            QPixmap pixmap;
            if (pixmap.loadFromData(imageData)) {
                QLabel *imageLabel = new QLabel(this);
                imageLabel->setPixmap(pixmap.scaled(80, 80, Qt::KeepAspectRatio));
                ui->tableWidget_3->setCellWidget(row, 2, imageLabel);
            } else {
                ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem("Image invalide"));
            }
        } else {
            ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem("Aucune image"));
        }

        ui->tableWidget_3->setItem(row, 3, new QTableWidgetItem(query.value("type").toString()));
        ui->tableWidget_3->setItem(row, 4, new QTableWidgetItem(query.value("etat").toString()));
        ui->tableWidget_3->setItem(row, 5, new QTableWidgetItem(query.value("disponibilite").toString()));
        ui->tableWidget_3->setItem(row, 6, new QTableWidgetItem(query.value("nbre_eq").toString()));
        ui->tableWidget_3->setItem(row, 7, new QTableWidgetItem(query.value("resis_flamme").toString()));
        row++;
    }

    // Vérification de la présence de résultats
    if (row == 0) {
        if (!QApplication::activeModalWidget()) { // Empêche l'affichage multiple du message
            QMessageBox::information(this, "Information", "Aucun résultat trouvé.");
        }
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    QList<Equipement> liste = Equipement::afficher();
    afficherEquipements(liste);
    ui->lineEdit_7->clear();
    ui->comboBox_11->setCurrentIndex(0);
}


void MainWindow::onTriDeclenche() {
    if (!ui->radioButton_9->isChecked() && !ui->radioButton_10->isChecked()) {
        return;
    }

    QString critere = ui->comboBox_12->currentText();
    bool ascendant = ui->radioButton_9->isChecked();

    QList<Equipement> liste = Equipement::afficher();
    if (liste.isEmpty()) return;
    auto getEtatPriority = [](const QString& etat) {
        QString etatLower = etat.toLower();
        if (etatLower.contains("fonctionnel") && !etatLower.contains("pas")) return 1;
        if (etatLower.contains("maintenance")) return 2;
        if (etatLower.contains("pas fonctionnel")) return 3;
        return 4;
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
    int nonFonctionnel = Equipement::countEquipementsParEtat("pas fonctionnel");
    int maintenance = Equipement::countEquipementsParEtat("maintenance");
    int total = nonFonctionnel + maintenance;

    qDebug() << "[DEBUG] Non fonctionnels:" << nonFonctionnel
             << "| En maintenance:" << maintenance
             << "| Total:" << total;

    updateNotificationBadge(total);
}

void MainWindow::updateNotificationBadge(int count)
{
    if (count > 0) {
        ui->noti->setProperty("alert", true);
        ui->noti->style()->unpolish(ui->noti);
        ui->noti->style()->polish(ui->noti);


        notificationBadge->setText(QString::number(count));
        notificationBadge->adjustSize();
        notificationBadge->show();

        if (QSystemTrayIcon::isSystemTrayAvailable()) {
            QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
            trayIcon->setIcon(QIcon(":/icons/app_icon.png"));
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

    QPushButton *closeButton = new QPushButton("Fermer");
    connect(closeButton, &QPushButton::clicked, alertDialog, &QDialog::accept);
    mainLayout->addWidget(closeButton, 0, Qt::AlignRight);

    alertDialog->exec();
    delete alertDialog;
}
void MainWindow::refreshAlertCount()
{
    checkEquipmentStatus();
}


void MainWindow::afficherDisponibiliteSurCalendrier() {

    calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

    QList<Equipement> equipements = Equipement::afficher();


    QTextCharFormat formatDisponible;
    formatDisponible.setBackground(QColor(100, 149, 237));
    formatDisponible.setForeground(Qt::white);
    formatDisponible.setFontWeight(QFont::Bold);
    formatDisponible.setProperty(QTextFormat::FullWidthSelection, true);
    formatDisponible.setToolTip("Disponible");


    QTextCharFormat formatNonDisponible;
    formatNonDisponible.setBackground(QColor(255, 182, 193)); // Rouge clair
    formatNonDisponible.setForeground(Qt::black);
    formatNonDisponible.setFontWeight(QFont::Bold);
    formatNonDisponible.setProperty(QTextFormat::FullWidthSelection, true);
    formatNonDisponible.setToolTip("Non disponible");

    foreach (const Equipement &equip, equipements) {
        QDate dateDebut = equip.getDateDebutDispo();
        QDate dateFin = equip.getDateFinDispo();

        if (!dateDebut.isValid() || !dateFin.isValid()) {
            qDebug() << "Dates invalides pour l'équipement ID:" << equip.getId();
            continue;
        }

        qDebug() << "Traitement équipement ID:" << equip.getId()
                 << "Du" << dateDebut.toString("dd/MM/yyyy")
                 << "au" << dateFin.toString("dd/MM/yyyy")
                 << "Dispo:" << equip.getDispo();

        // Appliquer le format selon la disponibilité
        QTextCharFormat format = (equip.getDispo().toLower() == "disponible")
                                     ? formatDisponible
                                     : formatNonDisponible;

        // Ajouter des informations à l'infobulle
        QString tooltip = QString("Équipement: %1\nID: %2\nType: %3\nÉtat: %4\nDisponibilité: %5\nPériode: %6 - %7")
                              .arg(equip.getNom())
                              .arg(equip.getId())
                              .arg(equip.getType())
                              .arg(equip.getEtat())
                              .arg(equip.getDispo())
                              .arg(dateDebut.toString("dd/MM/yyyy"))
                              .arg(dateFin.toString("dd/MM/yyyy"));
        format.setToolTip(tooltip);

        // Appliquer le format à toutes les dates de la plage
        for (QDate date = dateDebut; date <= dateFin; date = date.addDays(1)) {
            calendarWidget->setDateTextFormat(date, format);
        }
    }

    // Mettre en évidence la date actuelle (en jaune)
    QTextCharFormat todayFormat;
    todayFormat.setFontWeight(QFont::Bold);
    todayFormat.setBackground(QColor(255, 255, 150)); // Jaune clair
    todayFormat.setForeground(Qt::black);
    todayFormat.setProperty(QTextFormat::FullWidthSelection, true);
    calendarWidget->setDateTextFormat(QDate::currentDate(), todayFormat);
}


void MainWindow::afficherDetailsEquipement(const QDate &date) {
    QString details;
    QList<Equipement> equipements = Equipement::afficher();

    foreach (const Equipement &equip, equipements) {
        if (date >= equip.getDateDebutDispo() && date <= equip.getDateFinDispo()) {
            details += QString("🔧 *Équipement* : %1\n"
                               "🆔 *ID* : %2\n"
                               "🏷️ *Type* : %3\n"
                               "⚙️ *État* : %4\n"
                               "📅 *Disponible du* %5 *au* %6\n"
                               "🔄 *Statut* : %7\n\n")
                           .arg(equip.getNom())
                           .arg(equip.getId())
                           .arg(equip.getType())
                           .arg(equip.getEtat())
                           .arg(equip.getDateDebutDispo().toString("dd/MM/yyyy"))
                           .arg(equip.getDateFinDispo().toString("dd/MM/yyyy"))
                           .arg(equip.getDispo());
        }
    }

    if (details.isEmpty()) {
        details = "Aucun équipement réservé ou disponible pour cette date.";
    }

    QMessageBox::information(this, "📅 Détails des équipements", details);
}

void MainWindow::showAlertNotification()
{
    if (notificationPopup) {
        notificationPopup->close();
        delete notificationPopup;
        notificationPopup = nullptr;
        return;
    }

    QList<Equipement> alertes = Equipement::getEquipementsNonFonctionnels();

    QWidget* content = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(content);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(5, 5, 5, 5); // Réduire les marges
    mainLayout->setSpacing(5); // Réduire l'espace entre les éléments

    if (alertes.isEmpty()) {
        QLabel* label = new QLabel("Aucune alerte - Tous les équipements sont opérationnels", content);
        label->setStyleSheet("font-size: 11px;"); // Taille de police réduite
        mainLayout->addWidget(label);
    } else {
        QLabel* title = new QLabel(QString("Alertes (%1)").arg(alertes.count()), content);
        title->setStyleSheet("font-weight: bold; color: #d9534f; font-size: 12px;"); // Taille réduite
        mainLayout->addWidget(title);

        foreach (const Equipement &e, alertes) {
            QWidget* itemWidget = new QWidget(content);
            itemWidget->setStyleSheet(
                "margin-bottom: 5px;"
                "padding-bottom: 5px;"
                "border-bottom: 1px solid #eee;"
                );

            QHBoxLayout* itemLayout = new QHBoxLayout(itemWidget);
            itemLayout->setContentsMargins(2, 2, 2, 2); // Marges internes réduites
            itemLayout->setSpacing(5); // Espacement réduit

            // Image réduite à 50x50
            QLabel* imageLabel = new QLabel(itemWidget);
            QByteArray imageData = e.getImageData();
            if (!imageData.isEmpty()) {
                QPixmap pixmap;
                pixmap.loadFromData(imageData);
                if (!pixmap.isNull()) {
                    imageLabel->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    imageLabel->setFixedSize(50, 50);
                }
            }
            imageLabel->setAlignment(Qt::AlignCenter);
            itemLayout->addWidget(imageLabel);

            // Texte avec police réduite
            QString etatColor = e.getEtat().contains("maintenance", Qt::CaseInsensitive) ? "#f0ad4e" : "#d9534f";
            QLabel* infoLabel = new QLabel(
                QString("<b>%1</b> (ID: %2)<br>"
                        "Type: %3<br>"
                        "État: <span style='color: %4'>%5</span>")
                    .arg(e.getNom())
                    .arg(e.getId())
                    .arg(e.getType())
                    .arg(etatColor)
                    .arg(e.getEtat()),
                itemWidget
                );
            infoLabel->setStyleSheet("font-size: 11px;"); // Taille de police réduite
            itemLayout->addWidget(infoLabel);

            mainLayout->addWidget(itemWidget);
        }
    }

    notificationPopup = new NotificationPopup(this);
    notificationPopup->setStyleSheet(
        "QWidget {"
        "   background-color: white;"
        "   border: 1px solid #ddd;"
        "   border-radius: 4px;"
        "   padding: 5px;" // Padding réduit
        "}"
        );
    notificationPopup->setContent(content);
    notificationPopup->adjustSize();

    // Positionnement
    QPoint pos = ui->noti->mapToGlobal(QPoint(
        (ui->noti->width() - notificationPopup->width()) / 2,
        ui->noti->height() + 5
        ));
    notificationPopup->move(pos);
    notificationPopup->show();

}
bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (notificationPopup && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (!notificationPopup->geometry().contains(mouseEvent->globalPosition().toPoint())) {
            notificationPopup->close();
            delete notificationPopup;
            notificationPopup = nullptr;
            qApp->removeEventFilter(this);
        }
    }
    return QMainWindow::eventFilter(obj, event);
}


void MainWindow::initArduinoConnection() {
    int status = arduino.connect_arduino();

    if(status == 0) {
        connect(arduino.getserial(), &QSerialPort::readyRead,
                this, &MainWindow::readSerialData);
        ui->label_23->setText("Arduino connecté sur " + arduino.getarduino_port_name());
        ui->label_23->setStyleSheet("color: green;");
    } else {
        QString errorMsg = "Erreur de connexion: ";
        if(status == -1) {
            errorMsg += "Aucun port série disponible";
        } else if(status == 1) {
            errorMsg += "Impossible d'ouvrir le port " + arduino.getarduino_port_name();
        }
        ui->label_23->setText(errorMsg);
        ui->label_23->setStyleSheet("color: red;");
    }
}

void MainWindow::readSerialData() {
    while(arduino.getserial()->canReadLine()) {
        QString message = QString::fromUtf8(arduino.getserial()->readLine()).trimmed();

        if(message.contains("Flamme détectée")) {
            ui->label_23->setText("🔥 🚨 INCENDIE ! 🚨🔥\nFlamme détectée dans le laboratoire");
            ui->label_23->setStyleSheet(
                "QLabel {"
                "   color: red;"
                "   font-weight: bold;"
                "   font-size: 16px;"
                "   background-color: #FFEEEE;"
                "   border: 2px solid red;"
                "   border-radius: 8px;"
                "   padding: 8px;"
                "}"
                );
            handleFireDetection();
        }
        else if(message.contains("Aucune flamme détectée")) {
            ui->label_23->setText("🛡️Aucune flamme détectée 🛡️");
            ui->label_23->setStyleSheet(
                "QLabel {"
                "   color: green;"
                "   font-size: 15px;"
                "   background-color: #EEFFEE;"
                "   border: 2px solid green;"
                "   border-radius: 8px;"
                "   padding: 8px;"
                "}"
                );
        }
    }
}

void MainWindow::handleFireDetection() {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur : Base non connectée";
        return;
    }

    QSqlQuery query;
    query.prepare(
        "UPDATE EQUIPEMENT "
        "SET ETAT = 'Pas fonctionnel incendie' "
        "WHERE ETAT LIKE 'Fonctionnel%' "
        "AND ("
        "   UPPER(RESIS_FLAMME) IN ('NON', 'PAS RESISTIBLE') "
        "   OR RESIS_FLAMME IS NULL"
        ")"
        );

    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        return;
    }

    qDebug() << query.numRowsAffected() << "équipements fonctionnels mis à jour";
    actualiserTableau();
}
