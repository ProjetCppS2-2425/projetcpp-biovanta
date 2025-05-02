
#include "ui_chercheur_1.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QFile>
#include <QPixmap>
#include <QtConcurrent>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include "ai_report_generator.h"
#include "chercheur_1.h"
#include "ui_chercheur_1.h"
#include "ui_equipement1.h"


#include "ai_report_generator.h"
#include "arduino1.h"
#include "chercheur.h"



// Global or class-level instance



chercheur_1::chercheur_1(QWidget *parent)  // Fixed: QWidget not Widget
    : QMainWindow(parent),                 // Fixed: QMainWindow not QWainWindow
    ui(new Ui::chercheur_1),
    m_aiGenerator(new AIReportGenerator(this))  // Fixed: m_aiGenerator not m_aIGenerator
{
    ui->setupUi(this);

    // CORRECTED VERSION:
    ui->filtrage_4->clear();
    ui->filtrage_4->addItems(QStringList() << "ID" << "Nom" << "Email" << "Projet En Cours");// Now includes "ID"

    connect(ui->btn_goToStats, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(2);  // Go to Page 2 (index 2 typically means page 3)
    });



    ui->tableWidget_4->setStyleSheet(
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



    ui->S1_4->setPlaceholderText("Rechercher...");

    connect(ui->btn_goToStats, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);  // Go to Page 1

    });

    connect(ui->tableWidget_4, &QTableWidget::cellClicked, this, &chercheur_1::onCellClicked);

    ui->logo1->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\logo1.png"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\empe.png"));
    ui->ChercheurButton->setIcon(QPixmap("C:\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\cher.png"));
    ui->pdf_4->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\vaccin.png"));
    ui->EquipementButton->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\client.png"));
    ui->stat_4->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\st.png"));
    ui->ok_4->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\search.png"));
    ui->supp_6->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\effacer.png"));
    // Replace whatever displays the current project with:

    // Connect search
    connect(ui->ok_4, &QPushButton::clicked, this, &chercheur_1::on_searchButton_clicked);


    // UI setup
    ui->lineEdit_1->setPlaceholderText("Entrez un ID numérique...");
    ui->lineEdit_21->setPlaceholderText("8 chiffres seulement");
    ui->lineEdit_23->setPlaceholderText("ex: chercheur@labo.com");
    ui->tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_4->setSelectionMode(QAbstractItemView::SingleSelection);

    // Connect signals
    connect(ui->supp_6, &QPushButton::clicked, this, &chercheur_1::onSuppButtonClicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &chercheur_1::pushButton_2_clicked);
    connect(ui->stat_4, &QPushButton::clicked, this, &chercheur_1::on_stat_clicked);
    connect(ui->pdf_4, &QPushButton::clicked, this, &chercheur_1::onPdfButtonClicked);

    ui->tri_4->clear();
    ui->tri_4->addItems({"ID", "Nom", "Domaine"}); // Exact order matters!

    // Set default radio button (ASC/DSC)
    ui->tri_4->setCurrentIndex(0); // First item = "ID"
    ui->ASC_4->setChecked(true);

    // Connect sort button (assuming it's named 'triButton')
    connect(ui->tri_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &::chercheur_1::onTriClicked);
    // In MainWindow constructor
    connect(ui->ASC_4, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) ui->DSC_4->setChecked(false);
    });
    connect(ui->DSC_4, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) ui->ASC_4->setChecked(false);
    });
    // After populating the table with data:
    ui->tableWidget_4->resizeColumnsToContents();
    // Add this where you set up table columns (after HISTORY_COLUMN)
    const int REPORT_COLUMN = 8;  // Adjust based on your column count
    ui->tableWidget_4->setColumnCount(REPORT_COLUMN + 1);
    // Set minimum widths after auto-resizing
    for (int i = 0; i < ui->tableWidget_4->columnCount(); ++i) {
        int current = ui->tableWidget_4->columnWidth(i);
        if (current < 80) ui->tableWidget_4->setColumnWidth(i, 80);
    }
    // Load initial data

    refreshTable();
    onTriClicked();
}

chercheur_1::~chercheur_1()
{
    delete ui;
}
void chercheur_1::pushButton_2_clicked()
{
    if (ui->radioButton_5->isChecked()) {  // Add operation
        // Input validation
        bool ok;
        int id = ui->lineEdit_1->text().toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::warning(this, "Erreur", "ID doit être un nombre positif !");
            return;
        }

        QString nom = ui->lineEdit_19->text().trimmed();
        if (nom.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
            return;
        }

        QString phoneText = ui->lineEdit_21->text().trimmed();
        int num_tlp = phoneText.toInt(&ok);
        if (!ok || phoneText.length() != 8) {
            QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir 8 chiffres");
            return;
        }

        QString email = ui->lineEdit_23->text().trimmed();
        if (!email.contains("@") || !email.contains(".") || email.length() < 5) {
            QMessageBox::warning(this, "Erreur", "Format email invalide (ex: nom@domaine.com)");
            return;
        }

        QString domaine_recherche = ui->comboBox_7->currentText().trimmed();
        if (domaine_recherche.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Sélectionnez un domaine de recherche");
            return;
        }

        // Initialize project JSON structure
        QString currentProject = ui->lineEdit_24->text().trimmed();
        QString currentDateTime = QDateTime::currentDateTime().toString(Qt::ISODate);

        // Build the JSON object with an initial dated entry
        QJsonObject researcherData;
        researcherData["creation_date"] = currentDateTime;  // Add creation date

        QJsonObject projectJson;
        projectJson["current"] = currentProject;

        QJsonArray historyArray;
        QJsonObject initialEntry;
        initialEntry["project"] = currentProject;
        initialEntry["date"] = QDate::currentDate().toString(Qt::ISODate);
        historyArray.append(initialEntry);

        projectJson["history"] = historyArray;
        researcherData["projects"] = projectJson;  // Nest project data

        QString researcherJsonString = QJsonDocument(researcherData).toJson();

        QString projetJsonString = QJsonDocument(projectJson).toJson();

        Chercheur c(id, nom,
                    ui->lineEdit_20->text().trimmed(),
                    email,
                    num_tlp,
                    domaine_recherche,
                    projetJsonString);


        if (c.ajouter()) {
            QMessageBox::information(this, "Succès",
                                     QString("Chercheur ajouté le %1").arg(currentDateTime));
            refreshTable();
            clearFields();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout. Vérifiez les données.");
        }
    }
    else if (ui->radioButton_6->isChecked()) {  // Modify operation
        bool ok;
        int id = ui->lineEdit_1->text().toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::warning(this, "Erreur", "ID invalide (doit être > 0)");
            return;
        }

        if (!ui->lineEdit_19->text().isEmpty()) {  // Modification mode
            // Validation
            QString nom = ui->lineEdit_19->text().trimmed();
            if (nom.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
                return;
            }
            QString prenom = ui->lineEdit_20->text().trimmed();
            if (nom.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Le prenom ne peut pas être vide");
                return;
            }

            QString phoneText = ui->lineEdit_21->text().trimmed();
            int num_tlp = phoneText.toInt(&ok);
            if (!ok || phoneText.length() != 8) {
                QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir 8 chiffres");
                return;
            }

            QString email = ui->lineEdit_23->text().trimmed();
            if (!email.contains("@") || !email.contains(".")) {
                QMessageBox::warning(this, "Erreur", "Format email invalide");
                return;
            }

            QString domaine = ui->comboBox_7->currentText().trimmed();
            if (domaine.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Sélectionnez un domaine de recherche");
                return;
            }

            QString newProject = ui->lineEdit_24->text().trimmed();

            // Fetch current data
            Chercheur c;
            if (c.fetchDataById(id)) {
                // Update project history
                c.updateProjectHistory(newProject);

                // Perform database modification with complete JSON
                if (c.modify(id, nom,
                             ui->lineEdit_20->text().trimmed(),
                             email,
                             num_tlp,
                             domaine,
                             c.getFullProjectJson())) {
                    if (!newProject.isEmpty()) {

                    }

                    QMessageBox::information(this, "Succès", "Modification réussie");
                    refreshTable();

                    clearFields();
                } else {
                    QMessageBox::warning(this, "Erreur", "Échec de la modification");
                }
            } else {
                QMessageBox::warning(this, "Erreur", "Chercheur non trouvé");
            }
        }
        else {  // Fetch mode
            Chercheur c;
            if (c.fetchDataById(id)) {
                ui->lineEdit_19->setText(c.getNom());
                ui->lineEdit_20->setText(c.getPrenom());
                ui->lineEdit_23->setText(c.getEmail());
                ui->lineEdit_21->setText(QString::number(c.getNumTlp()));
                ui->comboBox_7->setCurrentText(c.getDomaineRecherche());

                // Display only current project name
                ui->lineEdit_24->setText(c.getCurrentProject());
            } else {
                QMessageBox::warning(this, "Erreur", "Chercheur non trouvé");
            }
        }
    }
}
void chercheur_1::refreshTable()
{
    qDebug() << "Starting table refresh...";

    // Clear existing data while preserving columns
    ui->tableWidget_4->setRowCount(0);
    ui->tableWidget_5->setRowCount(0);

    // Get all researchers from database
    QList<Chercheur> chercheurs;
    try {
        chercheurs = Chercheur::afficher();
        qDebug() << "Retrieved" << chercheurs.size() << "researchers from database";
    } catch (const std::exception &e) {
        qCritical() << "Database error:" << e.what();
        QMessageBox::critical(this, "Database Error",
                              QString("Failed to load researchers:\n%1").arg(e.what()));
        return;
    }

    // Configure table properties
    ui->tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Populate main table (tableWidget_4)
    for (int row = 0; row < chercheurs.size(); ++row) {
        const Chercheur &c = chercheurs[row];

        // Insert new row
        ui->tableWidget_4->insertRow(row);

        // Set data for each column
        auto setItem = [&](int col, const QVariant &data) {
            QTableWidgetItem *item = new QTableWidgetItem(data.toString());
            item->setFlags(item->flags() ^ Qt::ItemIsEditable); // Make read-only
            ui->tableWidget_4->setItem(row, col, item);
        };

        setItem(0, c.getId());
        setItem(1, c.getNom());
        setItem(2, c.getPrenom());
        setItem(3, c.getEmail());
        setItem(4, c.getNumTlp());
        setItem(5, c.getDomaineRecherche());

        // Clean and set project name
        QString cleanProject = c.cleanProjectName(c.getProjetEnCours());
        setItem(6, cleanProject);

        // Add history icon
        addHistoryIcon(row, c.getId());

        // Add PDF button
        QPushButton *pdfBtn = new QPushButton("📄");
        pdfBtn->setToolTip("Generate PDF Report");
        pdfBtn->setStyleSheet("border: none; background: none; padding: 5px;");
        connect(pdfBtn, &QPushButton::clicked, this, [this, c]() {
            generateResearcherPDF(c.getId(), "");
        });
        ui->tableWidget_4->setCellWidget(row, 8, pdfBtn);

        // Populate report table (tableWidget_5)
        ui->tableWidget_5->insertRow(row);
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(c.getId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_5->setItem(row, 0, idItem);
        ui->tableWidget_5->setItem(row, 1, new QTableWidgetItem(c.getNom()));
        ui->tableWidget_5->setItem(row, 2, new QTableWidgetItem(cleanProject));
    }

    // Auto-resize columns with minimum widths
    auto resizeColumns = [](QTableWidget *table) {
        table->resizeColumnsToContents();
        for (int col = 0; col < table->columnCount(); ++col) {
            int width = table->columnWidth(col);
            table->setColumnWidth(col, qMax(width, 80)); // Minimum width 80px
        }
    };

    resizeColumns(ui->tableWidget_4);
    resizeColumns(ui->tableWidget_5);

    qDebug() << "Table refresh completed successfully";
}
void chercheur_1::onSuppButtonClicked()
{
    int selectedRow = ui->tableWidget_4->currentRow();
    if (selectedRow == -1) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    int id = ui->tableWidget_4->item(selectedRow, 0)->text().toInt();
    Chercheur c;
    if (c.supprimer(id)) {
        ui->tableWidget_4->removeRow(selectedRow);
        QMessageBox::information(this, "Succès", "Suppression réussie");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression");
    }
}

void chercheur_1::clearFields()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_23->clear();
    ui->lineEdit_24->clear();
    ui->comboBox_7->setCurrentIndex(0);
    ui->radioButton_5->setChecked(true);
    ui->lineEdit_1->setFocus();
}
void chercheur_1::on_searchButton_clicked() {
    QString searchTerm = ui->S1_4->text().trimmed();
    QString filter = ui->filtrage_4->currentText();

    QList<Chercheur> results = Chercheur::searchChercheur(searchTerm, filter);
    ui->tableWidget_4->setRowCount(0);

    for (int i = 0; i < results.size(); ++i) {
        const Chercheur &c = results[i];
        ui->tableWidget_4->insertRow(i);

        // Regular columns
        ui->tableWidget_4->setItem(i, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget_4->setItem(i, 1, new QTableWidgetItem(c.getNom()));
        ui->tableWidget_4->setItem(i, 2, new QTableWidgetItem(c.getPrenom()));
        ui->tableWidget_4->setItem(i, 3, new QTableWidgetItem(c.getEmail()));
        ui->tableWidget_4->setItem(i, 4, new QTableWidgetItem(QString::number(c.getNumTlp())));
        ui->tableWidget_4->setItem(i, 5, new QTableWidgetItem(c.getDomaineRecherche()));

        // Use getCurrentProject() which returns cleaned name
        ui->tableWidget_4->setItem(i, 6, new QTableWidgetItem(c.getCurrentProject()));

        // Add history icon
        addHistoryIcon(i, c.getId());
    }

    if (results.isEmpty()) {
        QMessageBox::information(this, "Recherche", "Aucun résultat trouvé.");
    } else {
        statusBar()->showMessage(QString("%1 résultats trouvés").arg(results.size()), 3000);
    }
}
// In MainWindow.cpp
void chercheur_1::onTriClicked() {
    if (!ui->ASC_4->isChecked() && !ui->DSC_4->isChecked()) {
        ui->ASC_4->setChecked(true);
    }
    QString sortBy = ui->tri_4->currentText();
    bool ascending = ui->ASC_4->isChecked();

    QList<Chercheur> chercheurs = Chercheur::getChercheursSorted(sortBy, ascending);
    ui->tableWidget_4->setRowCount(0);

    for (int i = 0; i < chercheurs.size(); ++i) {
        const Chercheur &c = chercheurs[i];
        ui->tableWidget_4->insertRow(i);

        // Regular columns
        ui->tableWidget_4->setItem(i, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget_4->setItem(i, 1, new QTableWidgetItem(c.getNom()));
        ui->tableWidget_4->setItem(i, 2, new QTableWidgetItem(c.getPrenom()));
        ui->tableWidget_4->setItem(i, 3, new QTableWidgetItem(c.getEmail()));
        ui->tableWidget_4->setItem(i, 4, new QTableWidgetItem(QString::number(c.getNumTlp())));
        ui->tableWidget_4->setItem(i, 5, new QTableWidgetItem(c.getDomaineRecherche()));
        ui->tableWidget_4->setItem(i, 6, new QTableWidgetItem(c.getCurrentProject()));


        // Add history icon (assuming it's column 7)
        addHistoryIcon(i, c.getId());


    }

    statusBar()->showMessage(
        QString("Trié par %1 (%2)")
            .arg(sortBy)
            .arg(ascending ? "Croissant" : "Décroissant"),
        3000);
}
void chercheur_1::on_stat_clicked()
{
    Chercheur c;
    c.afficherStatistiques(ui->stackedWidget); // Pass the stacked widget instead of 'this'
}
void chercheur_1::onPdfButtonClicked() {
    // Ask user where to save the PDF
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Save PDF File",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/listchercheurs.pdf",
        "PDF Files (*.pdf)"
        );

    if (!filePath.isEmpty()) {

        Chercheur::generatePDF(filePath, this);

    }
}
void chercheur_1::showResearcherHistory(int row)
{
    if (row < 0 || row >= ui->tableWidget_4->rowCount()) return;

    int id = ui->tableWidget_4->item(row, 0)->text().toInt();
    Chercheur c;
    if (c.fetchDataById(id)) {
        QDialog historyDialog(this);
        historyDialog.setWindowTitle("🧬 Historique du Chercheur");
        historyDialog.setMinimumSize(500, 400);

        QVBoxLayout *mainLayout = new QVBoxLayout(&historyDialog);

        // Header with researcher info
        QLabel *header = new QLabel(QString("Historique de %1 %2 (ID: %3)")
                                        .arg(c.getPrenom())
                                        .arg(c.getNom())
                                        .arg(id));
        header->setStyleSheet("font-size: 16px; font-weight: bold; color: #2C3E50;");
        mainLayout->addWidget(header);

        // Creation date
        QString creationDate = c.getCreationDate();
        QLabel *createdLabel = new QLabel(QString("🕒 Ajouté le: %1").arg(creationDate));
        createdLabel->setStyleSheet("font-size: 12px; color: #555; margin-top: 5px;");
        mainLayout->addWidget(createdLabel);

        // Current project
        QString currentProject = c.getCurrentProject();
        QLabel *currentLabel = new QLabel(QString("📌 Projet actuel: %1").arg(currentProject));
        currentLabel->setStyleSheet("font-size: 12px; color: #27ae60; margin-top: 5px;");
        mainLayout->addWidget(currentLabel);

        // Project history section
        QLabel *projectsHeader = new QLabel("📜 Historique des projets:");
        projectsHeader->setStyleSheet("font-size: 14px; font-weight: bold; margin-top: 15px; color: #2C3E50;");
        mainLayout->addWidget(projectsHeader);

        QTextEdit *historyText = new QTextEdit();
        historyText->setReadOnly(true);
        historyText->setStyleSheet(R"(
            QTextEdit {
                border: 1px solid #ddd;
                border-radius: 4px;
                padding: 8px;
                background-color: #f9f9f9;
                font-size: 12px;
            }
        )");

        // Get formatted history
        QString formattedHistory = c.getFormattedHistory();
        if (formattedHistory.isEmpty()) {
            formattedHistory = "Aucun historique de projet disponible.";
        }
        historyText->setText(formattedHistory);
        mainLayout->addWidget(historyText);

        // Close button
        QPushButton *closeButton = new QPushButton("Fermer");
        closeButton->setStyleSheet(R"(
            QPushButton {
                background-color: #2C3E50;
                color: white;
                border: none;
                padding: 8px 16px;
                border-radius: 4px;
                min-width: 80px;
            }
            QPushButton:hover {
                background-color: #34495E;
            }
        )");
        connect(closeButton, &QPushButton::clicked, &historyDialog, &QDialog::accept);
        mainLayout->addWidget(closeButton, 0, Qt::AlignRight);

        historyDialog.exec();
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de charger les données du chercheur.");
    }
}


void chercheur_1::onCellClicked(int row, int column)
{
    if (column == HISTORY_COLUMN) {
        // Retrieve the researcher id stored in the history icon cell's UserRole
        QTableWidgetItem* historyItem = ui->tableWidget_4->item(row, HISTORY_COLUMN);
        if (historyItem) {
            int researcherId = historyItem->data(Qt::UserRole).toInt();
            generateHistoryPDF(researcherId);
        }
    }
}



void chercheur_1::updateReportInTable(const QString &projectName, const QString &report)
{
    // Iterate through the rows of tableWidget_5
    for (int row = 0; row < ui->tableWidget_5->rowCount(); ++row) {
        QTableWidgetItem *projectItem = ui->tableWidget_5->item(row, 2); // Project is in column 2
        if (projectItem && projectItem->text() == projectName) {
            QTableWidgetItem *reportItem = ui->tableWidget_5->item(row, 3); // Report is in column 3
            if (reportItem) {
                reportItem->setText(report);
                reportItem->setForeground(Qt::black);
                // Auto-resize the row to fit the new content
                ui->tableWidget_5->resizeRowToContents(row);
            }
        }
    }
}


void chercheur_1::generateHistoryPDF(int researcherId)
{
    // Fetch researcher data using the provided ID
    Chercheur c;
    if (!c.fetchDataById(researcherId)) {
        QMessageBox::warning(this, "Erreur", "Chercheur non trouvé.");
        return;
    }

    // Retrieve the formatted history (includes current project and history entries)
    QString historyText = c.getFormattedHistory();

    // Ask the user where to save the PDF file
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Enregistrer l'historique en PDF",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/history.pdf",
        "PDF Files (*.pdf)"
        );
    if (filePath.isEmpty()) {
        return;  // User cancelled the save dialog
    }
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath += ".pdf";
    }

    // Set up the printer for PDF generation
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(20, 20, 20, 20), QPageLayout::Millimeter);

    // Create a document to hold the history content with enhanced design.
    QTextDocument doc;
    QString html = R"(
        <html>
        <head>
            <meta charset='utf-8'>
            <style>
                body {
                    font-family: 'Segoe UI', sans-serif;
                    margin: 20px;
                    color: #333;
                }
                .header {
                    text-align: center;
                    padding: 10px;
                    background-color: #2C3E50;
                    color: white;
                    border-radius: 8px;
                    margin-bottom: 20px;
                }
                .content {
                    margin: 0 20px;
                    line-height: 1.6;
                }
                .footer {
                    text-align: right;
                    font-size: 10pt;
                    color: #777;
                    margin-top: 30px;
                }
                .section-title {
                    font-size: 14pt;
                    font-weight: bold;
                    margin-top: 20px;
                    color: #2C3E50;
                }
                .history-entry {
                    margin-bottom: 10px;
                    padding: 8px;
                    border-bottom: 1px solid #ddd;
                }
            </style>
        </head>
        <body>
            <div class='header'>
                <h2>Historique du Chercheur</h2>
            </div>
            <div class='content'>
                %1
            </div>
            <div class='footer'>
                Généré le %2
            </div>
        </body>
        </html>
    )";

    // Use the current date for the footer
    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");

    // Format the history content further if needed
    // For example, wrap each line or entry in a div with class 'history-entry'
    // (This is optional if your historyText already contains formatted HTML.)
    // Here we assume that historyText is plain text, so we wrap it in a preformatted block.
    QString formattedHistory = "<div class='section-title'>Détails de l'historique :</div>"
                               "<div class='history-entry'>" + historyText.replace("\n", "<br>") + "</div>";

    html = html.arg(formattedHistory, currentDate);

    doc.setHtml(html);

    // Print the document to PDF
    doc.print(&printer);

    // Inform the user and open the PDF
    QMessageBox::information(this, "Succès", QString("Historique PDF généré avec succès!\n\nFichier: %1").arg(filePath));
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}
void chercheur_1::addHistoryIcon(int row, int researcherId)
{
    QTableWidgetItem *historyIcon = new QTableWidgetItem("📜");
    historyIcon->setTextAlignment(Qt::AlignCenter);
    historyIcon->setToolTip("Cliquez pour voir l'historique des projets");
    historyIcon->setFlags(historyIcon->flags() ^ Qt::ItemIsEditable);
    historyIcon->setData(Qt::UserRole, researcherId);
    ui->tableWidget_4->setItem(row, HISTORY_COLUMN, historyIcon);
}
void chercheur_1::setupPDFExport()
{
    // Add PDF column as the last column
    const int PDF_COLUMN = 7; // Assuming history is column 7, make PDF column 8
    ui->tableWidget_4->setColumnCount(PDF_COLUMN + 1);

    // Set header
    QTableWidgetItem *pdfHeader = new QTableWidgetItem("Rapport");
    ui->tableWidget_4->setHorizontalHeaderItem(PDF_COLUMN, pdfHeader);
}

void chercheur_1::generateResearcherPDF(int researcherId, const QString &reportText)
{
    // Find researcher info from tableWidget_4
    QString researcherName, currentProject;
    for (int row = 0; row < ui->tableWidget_4->rowCount(); ++row) {
        if (ui->tableWidget_4->item(row, 0)->text().toInt() == researcherId) {
            researcherName = ui->tableWidget_4->item(row, 1)->text();
            currentProject = ui->tableWidget_4->item(row, 6)->text();
            break;
        }
    }

    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Enregistrer le rapport PDF",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) +
            "/Rapport_" + researcherName + ".pdf",
        "PDF Files (*.pdf)");

    if (!fileName.isEmpty()) {
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QString html = QString(R"(
            <html>
            <head>
                <style>
                    body { font-family: Arial; margin: 20px; }
                    h1 { color: #2c3e50; }
                    .header { background-color: #f2f2f2; padding: 10px; }
                    .content { margin-top: 20px; white-space: pre-wrap; }
                </style>
            </head>
            <body>
                <div class='header'>
                    <h1>Rapport de Recherche</h1>
                    <p><strong>Chercheur:</strong> %1</p>
                    <p><strong>Projet:</strong> %2</p>
                    <p><strong>Date:</strong> %3</p>
                </div>
                <div class='content'>
                    %4
                </div>
            </body>
            </html>
        )").arg(researcherName)
                           .arg(currentProject)
                           .arg(QDate::currentDate().toString("dd/MM/yyyy"))
                           .arg(reportText);

        doc.setHtml(html);
        doc.print(&printer);

        QMessageBox::information(this, "Succès", "Rapport PDF généré avec succès!");
    }
}
void chercheur_1::initArduinoConnection()
{
    qDebug();

    // Check available ports
    qDebug() << "Available ports:";
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port:" << info.portName()
        << "Description:" << info.description()
        << "Manufacturer:" << info.manufacturer();
    }

    int status = arduino.connect_arduino();
    qDebug() << "Connection status code:" << status;

    if(status == 0) {
        qDebug() << "Successfully connected to Arduino on" << arduino.getarduino_port_name();

        // Test if we can write to the port
        if(arduino.getserial()->write("PING\n") == -1) {
            qDebug() << "Write failed:" << arduino.getserial()->errorString();
        } else {
            qDebug() << "Test command sent to Arduino";
        }

        connect(arduino.getserial(), &QSerialPort::readyRead,
                this, &chercheur_1::readSerialData);
    }
}
void chercheur_1::readSerialData()
{
    // Check if data is actually available
    if(!arduino.getserial()->bytesAvailable()) {
        qDebug() << "No data available";
        return;
    }

    // Wait for data with timeout
    if(arduino.getserial()->waitForReadyRead(100)) {
        QByteArray data = arduino.getserial()->readAll();
        while(arduino.getserial()->waitForReadyRead(10))
            data += arduino.getserial()->readAll();

        QString message = QString::fromUtf8(data).trimmed();
        qDebug() << "Received raw data:" << data.toHex(); // Hex dump
        qDebug() << "As string:" << message;

        // Rest of your processing...
    } else {
        qDebug() << "Serial read timeout";
    }
}
// Add this in chercheur_1.cpp (outside any other functions)

