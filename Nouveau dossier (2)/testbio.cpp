#include "testbio.h"
#include "qboxlayout.h"
#include "qtimer.h"
#include "ui_testbio.h"
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
#include <QApplication>  // For QToolTip static methods
#include <QWidget>
#include <QToolTip>  // For tooltip functionality// Base class for widgets
#include "qrcodegen.hpp"
#include <QPixmap>
#include <QPainter>
#include <QStandardPaths>


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
#include <QPixmap>
#include <QPainter>
  // QR code generation library
#include <QInputDialog>

#include <QPainter>
#include <QNetworkReply>  // Add this line
#include <QNetworkAccessManager>

  TestBio::TestBio(QWidget *parent)
      : QMainWindow(parent)
      , ui(new Ui::TestBio)  // Changed from Ui::MainWindow
  {
      ui->setupUi(this);

      // Basic table setup
      ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
      ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
      ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

      // Changed MainWindow to TestBio in the lambda
      connect(ui->stat, &QPushButton::clicked, [this]() {
          ui->stackedWidget->setCurrentIndex(1); // Switch to stats page first
          QTimer::singleShot(0, this, &TestBio::on_stat_clicked); // Changed here
      });
    // Visual styling (inspired by chercheur_1)
    ui->tableWidget->setStyleSheet(
        "QTableWidget {"
        "    background-color: white;"
        "    border: 1px solid #d0d0d0;"
        "    gridline-color: #eaeaea;"
        "    font: 10pt 'Segoe UI';"
        "    color: #333333;"
        "    border-radius: 4px;"
        "}"
        "QHeaderView::section {"
        "    background-color: #2C3E50;"
        "    color: white;"
        "    padding: 6px;"
        "    border: none;"
        "    font-weight: normal;"
        "}"
        "QTableWidget::item:hover {"
        "    background-color: #f5f5f5;"
        "}"
        "QTableWidget::item:selected {"
        "    background-color: #2C3E50;"
        "    color: white;"
        "}"
        );

    // Connect cell click signal
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &TestBio::onCellClicked);
    // Core table properties
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Ensure no initial selection
    ui->tableWidget->clearSelection();
    ui->tableWidget->setCurrentItem(nullptr);
    isDataFetched = false;





    // Connexion du bouton

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur: La connexion à la base de données a échoué ->" << db.lastError().text();
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée !");
    } else {
        qDebug() << "Connexion à la base de données réussie.";
    }
    connect(ui->pushButton_2, &QPushButton::clicked, this, &TestBio::pushButton_2_clicked);
    connect(ui->pdfButton, &QPushButton::clicked, this, &TestBio::onPdfButtonClicked);
    connect(ui->suppButton, &QPushButton::clicked, this, &TestBio::on_suppButton_clicked);
    connect(ui->ok, &QPushButton::clicked, this, &TestBio::onSearchClicked);
    // Set up combo box items


     ui->tri->setCurrentIndex(2);  // Select ID in combo box
    ui->ASC->setChecked(true);      // Check ASC radio button

    // Connect signals
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TestBio::onTriChanged);
    connect(ui->ASC, &QRadioButton::toggled, this, &TestBio::onSortOrderChanged);
    connect(ui->DSC, &QRadioButton::toggled, this, &TestBio::onSortOrderChanged);
    connect(ui->suppButton, &QPushButton::clicked,
            this, &TestBio::on_suppButton_clicked);
    // Load initial data sorted by ID ASC
    applySorting();
    // Enable full row selection when clicking anywhere on the row
    // In MainWindow constructor (after ui->setupUi(this)):

    // Ensure clicking a row selects it

    // In your constructor:
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // Optional: Force selection on click (if still not working)
    connect(ui->tableWidget, &QTableWidget::cellClicked, [this](int row, int) {
        ui->tableWidget->selectRow(row);  // Manually select the row
    });
    // Add this to your stylesheet (if you have one)
    ui->tableWidget->setStyleSheet(
        "QTableWidget { selection-background-color: #4CAF50; selection-color: white; }"
        );    // Allow only one row to be selected
    // Set up UI elements

    // optional helper: click anywhere in a row and it selects
    connect(ui->tableWidget, &QTableWidget::cellClicked,
            [this](int row, int){
                ui->tableWidget->selectRow(row);
            });

    ui->logo->setPixmap(QPixmap("C:\\Users\\Molka\\Music\\projet_c (3)\\projet_c\\projet_c\\logo1.png"));

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
    applySorting();
}

TestBio::~TestBio()
{
    delete ui;
}

void TestBio::refreshTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Set column count and headers
    ui->tableWidget->setColumnCount(6); // Adjust as needed
    QStringList headers = {"ID", "Nom", "Type", "Chercheur", "Date", "QR Code"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Get data
    QList<TestBiologique> tests = TestBiologique::afficher();

    // Populate table
    for (const TestBiologique &test : tests) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Helper function to create properly configured items
        auto createItem = [](const QString& text) {
            QTableWidgetItem* item = new QTableWidgetItem(text);
            item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            item->setTextAlignment(Qt::AlignCenter);
            return item;
        };

        // Add data
        ui->tableWidget->setItem(row, 0, createItem(QString::number(test.getIdTest())));
        ui->tableWidget->setItem(row, 1, createItem(test.getNom()));
        ui->tableWidget->setItem(row, 2, createItem(test.getType()));
        ui->tableWidget->setItem(row, 3, createItem(test.getChercheur_responsable()));
        ui->tableWidget->setItem(row, 4, createItem(test.getDatePre().toString("dd/MM/yyyy")));

        // Add QR button
        addQRButtonToRow(row, test.getIdTest());
    }

    // Adjust column widths
    ui->tableWidget->resizeColumnsToContents();
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
        int current = ui->tableWidget->columnWidth(i);
        if (current < 80) ui->tableWidget->setColumnWidth(i, 80);
    }
}

void TestBio::pushButton_3_clicked() {
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
void TestBio::pushButton_2_clicked() {
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
void TestBio::onPdfButtonClicked()
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
void TestBio::on_stat_clicked()
{
    TestBiologique test;
    test.afficherStatistiques(ui->stackedWidget); // Pass the stacked widget instead of 'this'
}

void TestBio::clearFields()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->comboBox_4->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
}
// Implémentation de on_suppButton_clicked()

void TestBio::on_suppButton_clicked()
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
            QMessageBox::information(this, "Succès", "Suppression reffectuée");
        } else {
            QMessageBox::critical(this, "Erreur", query.lastError().text());
        }
    }
}

void TestBio::onSearchClicked()
{
    QString searchTerm = ui->lineEdit_4->text().trimmed();
    QString filterField = ui->comboBox_5->currentText();

    if (searchTerm.isEmpty()) {
        refreshTable();
        return;
    }

    QList<TestBiologique> results = TestBiologique::searchByIdNameType(searchTerm, filterField);

    // Clear and setup table
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Ensure columns exist (should match your refreshTable() column count)
    if (ui->tableWidget->columnCount() != 6) {  // Changed from 5 to 6 to include QR code column
        ui->tableWidget->setColumnCount(6);
        QStringList headers = {"ID", "Nom", "Type", "Chercheur", "Date Prélèvement", "QR Code"};
        ui->tableWidget->setHorizontalHeaderLabels(headers);
    }

    // Populate table
    for (const TestBiologique& test : results) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Create items with proper flags
        auto createItem = [](const QString& text) {
            QTableWidgetItem* item = new QTableWidgetItem(text);
            item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            return item;
        };

        // Add regular data items
        ui->tableWidget->setItem(row, 0, createItem(QString::number(test.getIdTest())));
        ui->tableWidget->setItem(row, 1, createItem(test.getNom()));
        ui->tableWidget->setItem(row, 2, createItem(test.getType()));
        ui->tableWidget->setItem(row, 3, createItem(test.getChercheur_responsable()));
        ui->tableWidget->setItem(row, 4, createItem(test.getDatePre().toString("dd/MM/yyyy")));

        // Add QR button (ONCE per row) - removed the duplicate call
        addQRButtonToRow(row, test.getIdTest());
    }

    if (results.isEmpty()) {
        QMessageBox::information(this, "Information",
                                 QString("Aucun résultat trouvé pour:\nTerme: %1\nFiltre: %2")
                                     .arg(searchTerm)
                                     .arg(filterField));
    }
}
void TestBio::onTriChanged()
{
    applySorting();
}
void TestBio::onSortOrderChanged()
{
    applySorting();
}

void TestBio::applySorting()
{
    // 1. Get the selected column and sort order from UI
    QString column = ui->tri->currentText();  // Get sort column from combo box
    QString order = ui->ASC->isChecked() ? "ASC" : "DESC";  // Get sort direction

    // 2. Build the SQL query with sorting
    QSqlQuery query;
    QString queryStr = "SELECT * FROM TESTBIOLOGIQUE ORDER BY ";

    // Map UI column names to database columns
    if (column == "ID") queryStr += "ID_TEST ";
    else if (column == "Nom") queryStr += "NOM ";
    else if (column == "Type") queryStr += "TYPE ";
    else if (column == "Chercheur") queryStr += "CHERCHEUR_RESPONSABLE ";
    else if (column == "Date") queryStr += "DATE_PRE ";
    else queryStr += "ID_TEST "; // Default sort

    queryStr += order; // Add ASC or DESC

    // 3. Execute the query
    if (!query.exec(queryStr)) {
        qDebug() << "Sorting error:" << query.lastError().text();
        return;
    }

    // 4. Process results and display
    QList<TestBiologique> sortedTests;
    while (query.next()) {
        sortedTests.append(TestBiologique(
            query.value("ID_TEST").toInt(),
            query.value("NOM").toString(),
            query.value("TYPE").toString(),
            query.value("CHERCHEUR_RESPONSABLE").toString(),
            query.value("DATE_PRE").toDate()
            ));
    }

    // 5. Display the sorted results using your existing method
    displayTests(sortedTests);

}

void TestBio::displayTests(const QList<TestBiologique>& tests)
{
    ui->tableWidget->setRowCount(0);

    if (ui->tableWidget->columnCount() == 0) {
        ui->tableWidget->setColumnCount(5);
        QStringList headers;
        headers << "ID" << "Nom" << "Type" << "Chercheur" << "Date Prélèvement";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
    }

    for (const TestBiologique& test : tests) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        auto createItem = [](const QString& text) {
            QTableWidgetItem* item = new QTableWidgetItem(text);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            return item;
        };

        ui->tableWidget->setItem(row, 0, createItem(QString::number(test.getIdTest())));
        ui->tableWidget->setItem(row, 1, createItem(test.getNom()));
        ui->tableWidget->setItem(row, 2, createItem(test.getType()));
        ui->tableWidget->setItem(row, 3, createItem(test.getChercheur_responsable()));
        ui->tableWidget->setItem(row, 4, createItem(test.getDatePre().toString("dd/MM/yyyy")));
         addQRButtonToRow(row, test.getIdTest());
    }
}

QPixmap TestBio::generateQRCode(const QString& data, int size)
{
    std::string text = data.toStdString();
    const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text.c_str(), qrcodegen::QrCode::Ecc::MEDIUM);

    QImage img(qr.getSize(), qr.getSize(), QImage::Format_RGB32);
    img.fill(Qt::white);

    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            if (qr.getModule(x, y)) {
                img.setPixel(x, y, qRgb(0, 0, 0)); // Black pixels
            }
        }
    }

    return QPixmap::fromImage(img.scaled(size, size, Qt::KeepAspectRatio));
}
void TestBio::addQRButtonToRow(int row, int testId)
{
    QPushButton *btn = new QPushButton("🏁"); // QR emoji
    btn->setStyleSheet("border: none; background: transparent; font-size: 16px;");

    connect(btn, &QPushButton::clicked, [this, testId]() {
        // Create the dialog
        QDialog qrDialog(this);
        qrDialog.setWindowTitle("QR Code - Test " + QString::number(testId));

        // Generate QR content
        QString qrContent = QString("TestID:%1\nDate:%2")
                                .arg(testId)
                                .arg(QDate::currentDate().toString("dd/MM/yyyy"));

        // Create and add the QR image
        QLabel *qrLabel = new QLabel(&qrDialog);
        qrLabel->setPixmap(generateQRCode(qrContent, 250)); // 250x250 pixels

        // Add a close button
        QPushButton *closeBtn = new QPushButton("Close", &qrDialog);
        connect(closeBtn, &QPushButton::clicked, &qrDialog, &QDialog::accept);

        // Layout
        QVBoxLayout *layout = new QVBoxLayout(&qrDialog);
        layout->addWidget(qrLabel, 0, Qt::AlignCenter);
        layout->addWidget(closeBtn, 0, Qt::AlignRight);

        qrDialog.exec();
    });

    ui->tableWidget->setCellWidget(row, 5, btn);
}
void TestBio::onCellClicked(int row, int column)
{
    // Ensure the entire row is selected
    ui->tableWidget->selectRow(row);

    // Optional: Get the ID of the clicked item
    QTableWidgetItem* item = ui->tableWidget->item(row, 0);
    if (item) {
        int id = item->text().toInt();
        qDebug() << "Selected row ID:" << id;
    }
}
