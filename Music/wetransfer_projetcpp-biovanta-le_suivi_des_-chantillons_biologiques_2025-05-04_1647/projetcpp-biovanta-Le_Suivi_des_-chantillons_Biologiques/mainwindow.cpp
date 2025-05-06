#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>
#include <QDate>
#include <QList>
#include <QtPrintSupport/QPrinter>
#include <QtPdf/QPdfDocument>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>

#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QPrinter>
#include <QTextTableCell>
#include <QTextDocument>
#include <QTextCursor>

#include <QFileDialog>
#include <QPushButton>
#include <QSqlError>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

#include <QPrinter>
#include <QTextDocument>
#include <QTextTable>
#include <QTextCursor>
#include <QTextTableCell>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QFont>
#include <QColor>
#include <QDate>
#include <QInputDialog>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isDataFetched = false;





    // Connexion du bouton

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur: La connexion à la base de données a échoué ->" << db.lastError().text();
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée !");
    } else {
        qDebug() << "Connexion à la base de données réussie.";
    }
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::pushButton_2_clicked);
    connect(ui->pdfButton, &QPushButton::clicked, this, &MainWindow::onPdfButtonClicked);
    connect(ui->suppButton, &QPushButton::clicked, this, &MainWindow::on_suppButton_clicked);
    connect(ui->ok, &QPushButton::clicked, this, &MainWindow::on_ok_clicked);
    // Set up UI elements
    ui->logo->setPixmap(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\bg.jpg"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\empe.png"));
    ui->chercheur->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\cher.png"));
    ui->pdfButton->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\client.png"));
    ui->stat->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\st.png"));
    ui->ok->setIcon(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\search.png"));
    ui->pdfButton->setCursor(Qt::PointingHandCursor);
    ui->pdfButton->setToolTip("Generate PDF report");
    // Initialize table
    refreshTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshTable() {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);

    // Set column headers
    QStringList headers;
    headers << "ID" << "Nom" << "Type" << "Chercheur" << "Date Prélèvement";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    QSqlQuery query;
    if (!query.exec("SELECT ID_TEST, NOM, TYPE, CHERCHEUR_RESPONSABLE, DATE_PRE FROM TESTBIOLOGIQUE")) {
        qDebug() << "Query error:" << query.lastError();
        return;
    }

    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Add items with proper data formatting
        for (int col = 0; col < 5; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem();
            if (col == 4) { // Date column
                item->setData(Qt::DisplayRole, query.value(col).toDate().toString("dd/MM/yyyy"));
            } else {
                item->setText(query.value(col).toString());
            }
            ui->tableWidget->setItem(row, col, item);
        }
    }
    ui->tableWidget->resizeColumnsToContents();
}
void MainWindow::pushButton_3_clicked()
{
    // Example implementation modifier
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Error", "Please select an item first");
        return;
    }

    int id = ui->tableWidget->item(currentRow, 0)->text().toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm",
                                  QString("Delete record ID %1?").arg(id),
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM TESTBIOLOGIQUE WHERE ID_TEST = ?");
        query.addBindValue(id);

        if (query.exec()) {
            refreshTable();
            QMessageBox::information(this, "Success", "Record deleted");
        } else {
            QMessageBox::critical(this, "Error", "Delete failed: " + query.lastError().text());
        }
    }
}



void MainWindow::pushButton_2_clicked() {
    if (ui->radioButton->isChecked()) {
        // Validate ID field first (amélioration)
        QString idText = ui->lineEdit->text();
        if (idText.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "L'ID ne peut pas être vide !");
            ui->lineEdit->setFocus();
            return;
        }

        bool ok;
        int id_test = idText.toInt(&ok);
        if (!ok || id_test <= 0) {
            QMessageBox::warning(this, "Erreur", "L'ID doit être un nombre positif seulement !");
            ui->lineEdit->setFocus();
            ui->lineEdit->selectAll();
            return;
        }

        // Contrôle de saisie pour le nom (amélioration)
        QString nom = ui->lineEdit_3->text();
        QRegularExpression nomRegex("^[a-zA-ZéèêëàâäôöûüçÉÈÊËÀÂÄÔÖÛÜÇ \\-]+$");
        if (nom.isEmpty() || !nomRegex.match(nom).hasMatch()) {
            QMessageBox::warning(this, "Erreur",
                                 "Le nom doit contenir uniquement des lettres, espaces ou tirets.\n"
                                 "Exemples valides: 'Marie Dupont' ou 'Jean-Claude'");
            ui->lineEdit_3->setFocus();
            ui->lineEdit_3->selectAll();
            return;
        }

        // Contrôle de saisie pour le chercheur (amélioration)
        QString Chercheur_responsable = ui->lineEdit_2->text();
        if (Chercheur_responsable.isEmpty() || !nomRegex.match(Chercheur_responsable).hasMatch()) {
            QMessageBox::warning(this, "Erreur",
                                 "Le nom du chercheur doit contenir uniquement des lettres, espaces ou tirets.\n"
                                 "Exemples valides: 'Pierre Martin' ou 'Anne-Sophie'");
            ui->lineEdit_2->setFocus();
            ui->lineEdit_2->selectAll();
            return;
        }

        // Le reste de votre code original inchangé
        QString type = ui->comboBox_4->currentText();
        QDate date_pre = ui->dateEdit->date();

        if (type.isEmpty()) {
            QMessageBox::warning(this, "Attention", "Veuillez sélectionner un type");
            return;
        }

        QSqlQuery query;
        query.prepare("INSERT INTO TESTBIOLOGIQUE (ID_TEST, NOM, TYPE, CHERCHEUR_RESPONSABLE, DATE_PRE) "
                      "VALUES (:id, :nom, :type, :Chercheur_responsable, :date_pre)");
        query.bindValue(":id", id_test);
        query.bindValue(":nom", nom);
        query.bindValue(":type", type);
        query.bindValue(":Chercheur_responsable", Chercheur_responsable);
        query.bindValue(":date_pre", date_pre.toString("yyyy-MM-dd"));

        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Test biologique ajouté avec succès");
            refreshTable();

            // Clear input fields
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->comboBox_4->setCurrentIndex(0);
            ui->dateEdit->setDate(QDate::currentDate());
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout du test biologique: " + query.lastError().text());
        }
    }
    else if (ui->radioButton_2->isChecked()) {  // Modifier operation
        // --- 1. Validate ID ---
        bool ok;
        int id_test = ui->lineEdit->text().toInt(&ok);
        if (!ok || id_test <= 0) {
            QMessageBox::warning(this, "Erreur", "ID invalide (doit être > 0)");
            ui->lineEdit->setFocus();
            return;
        }

        // --- 2. Check if in "Fetch Mode" (fields empty) ---
        if (ui->lineEdit_3->text().isEmpty()) {
            qDebug() << "Attempting to fetch data for ID:" << id_test;

            // Create a temporary TestBiologique object
            TestBiologique test;
            if (test.fetchDataById(id_test)) {
                qDebug() << "Data fetched successfully";
                // Populate fields with existing data
                ui->lineEdit_3->setText(test.getNom());
                ui->comboBox_4->setCurrentText(test.getType());
                ui->lineEdit_2->setText(test.getChercheur_responsable());
                ui->dateEdit->setDate(test.getDatePre());
                isDataFetched = true; // Set flag to indicate data was fetched
            } else {
                QMessageBox::warning(this, "Erreur",
                                     QString("Test non trouvé pour l'ID: %1\nVérifiez la console pour les détails d'erreur").arg(id_test));
                qDebug() << "Last SQL error:" << QSqlDatabase::database().lastError().text();
            }
            return; // Stop after fetching
        }

        // --- 3. If fields are filled, proceed with UPDATE ---
        if (isDataFetched) {
            QString nom = ui->lineEdit_3->text();
            QString type = ui->comboBox_4->currentText();
            QString chercheur = ui->lineEdit_2->text();
            QDate date_pre = ui->dateEdit->date();

            QSqlQuery query;
            query.prepare("UPDATE TESTBIOLOGIQUE SET NOM=:nom, TYPE=:type, "
                          "CHERCHEUR_RESPONSABLE=:chercheur, DATE_PRE=:date_pre "
                          "WHERE ID_TEST=:id");
            query.bindValue(":nom", nom);
            query.bindValue(":type", type);
            query.bindValue(":chercheur", chercheur);
            query.bindValue(":date_pre", date_pre.toString("yyyy-MM-dd"));
            query.bindValue(":id", id_test);

            if (query.exec()) {
                QMessageBox::information(this, "Succès", "Test biologique modifié avec succès");
                refreshTable();
                clearFields();
                isDataFetched = false; // Reset flag
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la modification: " + query.lastError().text());
            }
        }
    }
 }
void MainWindow::onPdfButtonClicked()
{
    // Ask user where to save the PDF with a default filename
    QString defaultFileName = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) +
                              "/TestBiologique_" + QDate::currentDate().toString("yyyyMMdd") + ".pdf";

    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("Enregistrer le fichier PDF"),
        defaultFileName,
        tr("Fichiers PDF (*.pdf);;Tous les fichiers (*)")
        );

    if (!filePath.isEmpty()) {
        // Verify the table widget exists and has data
        QTableWidget *table = ui->tableWidget; // Use the direct member variable
        if (table && table->rowCount() > 0) {
            try {
                // Call the PDF generation function
                TestBiologique::generatePDF(filePath, this);

                // Verify the PDF was created
                if (QFile::exists(filePath)) {
                    QMessageBox::information(this,
                                             tr("Succès"),
                                             tr("PDF généré avec succès!\nEmplacement: %1").arg(filePath));

                    // Try to open the PDF
                    if (!QDesktopServices::openUrl(QUrl::fromLocalFile(filePath))) {
                        QMessageBox::warning(this,
                                             tr("Attention"),
                                             tr("Le PDF a été créé mais n'a pas pu être ouvert automatiquement."));
                    }
                } else {
                    QMessageBox::critical(this,
                                          tr("Erreur"),
                                          tr("Le fichier PDF n'a pas été créé."));
                }
            } catch (const std::exception &e) {
                QMessageBox::critical(this,
                                      tr("Erreur"),
                                      tr("Erreur lors de la génération du PDF: %1").arg(e.what()));
            }
        } else {
            QMessageBox::warning(this,
                                 tr("Aucune donnée"),
                                 tr("Aucun test biologique à exporter. Le tableau est vide."));
        }
    }
}
void MainWindow::on_stat_clicked()
{
    TestBiologique test;
    test.afficherStatistiques(this);
}

void MainWindow::clearFields()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->comboBox_4->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
}
// Implémentation de on_suppButton_clicked()

void MainWindow::on_suppButton_clicked()
{
    if (!ui->tableWidget->currentItem()) {
        QMessageBox::warning(this, "Erreur", "Aucun élément sélectionné");
        return;
    }

    int row = ui->tableWidget->currentRow();
    int id = ui->tableWidget->item(row, 0)->text().toInt();

    if (QMessageBox::Yes == QMessageBox::question(this, "Confirmer",
                                                  QString("Supprimer le test #%1 ?").arg(id)))
    {
        QSqlQuery query;
        query.prepare("DELETE FROM TESTBIOLOGIQUE WHERE ID_TEST=?");
        query.addBindValue(id);

        if (query.exec()) {
            refreshTable();
            QMessageBox::information(this, "Succès", "Suppression effectuée");
        } else {
            QMessageBox::critical(this, "Erreur", query.lastError().text());
        }
    }
}
// Implémentations pour les autres fonctions si nécessaires
void MainWindow::onQRVerified(int result)
{
Q_UNUSED(result);}

void MainWindow::onQRInvalid()
{
}
void MainWindow::on_ok_clicked() {
    QString terme = ui->lineEdit_4->text().trimmed();
    QString filtre;

    switch(ui->comboBox->currentIndex()) {
    case 0: filtre = "NOM"; break;   // Recherche par nom
    case 1: filtre = "ID"; break;    // Recherche par ID
    case 2: filtre = "TYPE"; break;  // Recherche par type
    default: filtre = "NOM";
    }

    QList<TestBiologique> resultats = TestBiologique::rechercherTests(terme, filtre);
    TestBiologique::afficherResultats(resultats, ui->tableWidget);

    if (resultats.isEmpty() && !terme.isEmpty()) {
        QMessageBox::information(this, "Recherche", "Aucun test trouvé");
    }
}
void MainWindow::onSearchButtonClicked()
{
    // This is essentially the same as your on_ok_clicked() implementation
    QString terme = ui->lineEdit_4->text().trimmed();
    QString filtre;

    switch(ui->comboBox->currentIndex()) {
    case 0: filtre = "NOM"; break;
    case 1: filtre = "ID"; break;
    case 2: filtre = "TYPE"; break;
    default: filtre = "NOM";
    }

    QList<TestBiologique> resultats = TestBiologique::rechercherTests(terme, filtre);
    TestBiologique::afficherResultats(resultats, ui->tableWidget);

    if (resultats.isEmpty() && !terme.isEmpty()) {
        QMessageBox::information(this, "Recherche", "Aucun test trouvé");
    }
}
