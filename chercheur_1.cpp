#include "chercheur_1.h"

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
#include <QPrinter>
#include <QPageLayout>
#include <QPageSize>
#include <QTextDocument>


#include "ui_chercheur_1.h"
#include "ai_report_generator.h"
#define REPORT_COLUMN 8
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



    // In your slot that connects to reportGenerated, add an error case
    // Replace the error connection with this complete connection setup:
    connect(m_aiGenerator, &AIReportGenerator::reportGenerated,
            this, [this](const QString& projectName, const QString& reportContent) {
                // Find which researcher this report is for
                for (int row = 0; row < ui->tableWidget_4->rowCount(); ++row) {
                    QTableWidgetItem* item = ui->tableWidget_4->item(row, REPORT_COLUMN);
                    if (item && item->data(Qt::UserRole + 1).toString() == projectName) {
                        int researcherId = item->data(Qt::UserRole).toInt();
                        generateAIReportPDF(researcherId, projectName, reportContent);
                        return;
                    }
                }
                QMessageBox::warning(this, "Erreur", "Chercheur non trouvé pour ce projet.");
            });

    connect(m_aiGenerator, &AIReportGenerator::reportError,
            this, [this](const QString& error) {
                QMessageBox::critical(this, "Erreur AI",
                                      "Échec de génération du rapport:\n" + error);
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



    connect(ui->tableWidget_4, &QTableWidget::cellClicked, this, &chercheur_1::onCellClicked);

    ui->logo1->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\logo1.png"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\logout.jpg"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\bg.jpg"));
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
    // Adjust based on your column count
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
        QJsonObject projectJson;
        projectJson["current"] = ui->lineEdit_24->text().trimmed();
        projectJson["history"] = QJsonArray();
        QString projetJsonString = QJsonDocument(projectJson).toJson();

        Chercheur c(id, nom,
                    ui->lineEdit_20->text().trimmed(),
                    email,
                    num_tlp,
                    domaine_recherche,
                    projetJsonString);

        if (c.ajouter()) {
            QMessageBox::information(this, "Succès", "Chercheur ajouté !");
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
    // Clear existing data but preserve columns
    ui->tableWidget_4->setRowCount(0);

    // Get data
    QList<Chercheur> chercheurs = Chercheur::afficher();

    for (int row = 0; row < chercheurs.size(); ++row) {
        const Chercheur &c = chercheurs[row];
        QString cleanProjectName = c.cleanProjectName(c.getProjetEnCours());

        // Insert new row
        ui->tableWidget_4->insertRow(row);

        // Standard columns (0-6)
        ui->tableWidget_4->setItem(row, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget_4->setItem(row, 1, new QTableWidgetItem(c.getNom()));
        ui->tableWidget_4->setItem(row, 2, new QTableWidgetItem(c.getPrenom()));
        ui->tableWidget_4->setItem(row, 3, new QTableWidgetItem(c.getEmail()));
        ui->tableWidget_4->setItem(row, 4, new QTableWidgetItem(QString::number(c.getNumTlp())));
        ui->tableWidget_4->setItem(row, 5, new QTableWidgetItem(c.getDomaineRecherche()));
        ui->tableWidget_4->setItem(row, 6, new QTableWidgetItem(cleanProjectName));

        // Your existing functions
        addHistoryIcon(row, c.getId());           // Column 7
        addReportIcon(row, c.getId(), cleanProjectName); // Column 8
    }

    // Force visibility and proper sizing
    ui->tableWidget_4->setColumnHidden(8, false);
    ui->tableWidget_4->resizeColumnsToContents();
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    qDebug() << "Table refreshed. Visible columns:" << ui->tableWidget_4->columnCount();
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
        QString cleanProjectName = c.cleanProjectName(c.getProjetEnCours());
        addReportIcon(i, c.getId(), cleanProjectName);
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
        QString cleanProjectName = c.cleanProjectName(c.getProjetEnCours());
        addReportIcon(i, c.getId(), cleanProjectName);


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
        historyDialog.setWindowTitle("🧬 Dossier Historique du Chercheur");
        historyDialog.setMinimumSize(600, 500);

        // Stylesheet: medical, clear, elegant
        historyDialog.setStyleSheet(R"(
            QDialog {
                background-color: #e8f2fb;
                border-radius: 12px;
            }
            QLabel#HeaderLabel {
                font-size: 20px;
                font-weight: bold;
                color: #1f3b57;
                padding: 10px;
                border-bottom: 2px solid #accbe1;
                margin-bottom: 10px;
            }
            QLabel.entryHeader {
                font-size: 14px;
                font-weight: bold;
                color: #2a628f;
                margin-top: 15px;
            }
            QLabel.entryText {
                font-size: 13px;
                color: #1f1f1f;
                padding-left: 10px;
            }
            QScrollArea {
                background-color: #ffffff;
                border: 1px solid #bdd8ee;
                border-radius: 8px;
            }
            QPushButton {
                background-color: #2a9df4;
                color: white;
                padding: 6px 16px;
                font-size: 14px;
                border-radius: 6px;
                font-weight: bold;
            }
            QPushButton:hover {
                background-color: #1d7ecb;
            }
        )");

        QVBoxLayout *mainLayout = new QVBoxLayout(&historyDialog);

        QLabel *header = new QLabel(QString("🧾 Historique de %1 %2").arg(c.getPrenom(), c.getNom()));
        header->setObjectName("HeaderLabel");
        mainLayout->addWidget(header);

        // Container for historical entries
        QWidget *historyContainer = new QWidget;
        QVBoxLayout *historyLayout = new QVBoxLayout(historyContainer);
        historyLayout->setSpacing(12);

        // Simulate formatted history entries (replace with real parsing if needed)
        QStringList entries = c.getFormattedHistory().split("<br>", Qt::SkipEmptyParts);
        for (const QString &entry : entries) {
            QLabel *entryLabel = new QLabel("📌 " + entry.trimmed());
            entryLabel->setWordWrap(true);
            entryLabel->setProperty("class", "entryText");
            historyLayout->addWidget(entryLabel);
        }

        QScrollArea *scrollArea = new QScrollArea;
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(historyContainer);
        mainLayout->addWidget(scrollArea);

        QPushButton *closeButton = new QPushButton("Fermer le Dossier");
        connect(closeButton, &QPushButton::clicked, &historyDialog, &QDialog::accept);
        mainLayout->addWidget(closeButton, 0, Qt::AlignRight);

        historyDialog.exec();
    }
}


void chercheur_1::onCellClicked(int row, int column)
{
    // 1) History column clicked?
    if (column == HISTORY_COLUMN) {
        // Simply open the history PDF/dialog
        generateHistoryPDF(ui->tableWidget_4->item(row, HISTORY_COLUMN)
                               ->data(Qt::UserRole)
                               .toInt());
        return;
    }

    // 2) Report column clicked?
    if (column == REPORT_COLUMN) {
        QTableWidgetItem *reportItem = ui->tableWidget_4->item(row, REPORT_COLUMN);
        if (!reportItem) return;

        const int researcherId = reportItem->data(Qt::UserRole).toInt();
        const QString projectName = reportItem->data(Qt::UserRole + 1).toString();

        if (projectName.isEmpty()) {
            QMessageBox::information(this,
                                     "Information",
                                     "Aucun projet associé à ce chercheur.");
            return;
        }

        // Show a modal progress dialog while waiting for the AI report
        auto *progress = new QProgressDialog(
            "Génération du rapport AI...", QString(), 0, 0, this);
        progress->setWindowModality(Qt::WindowModal);
        progress->show();

        // Connect only the success signal; capture 'this' and 'progress'
        connect(m_aiGenerator, &AIReportGenerator::reportGenerated,
                this,
                [this, researcherId, projectName, progress]
                (const QString&, const QString& reportContent) {
                    progress->close();
                    progress->deleteLater();
                    generateAIReportPDF(researcherId, projectName, reportContent);
                });

        // Trigger the async AI report generation
        m_aiGenerator->requestProjectReport(projectName);
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
// Add this new function:
void chercheur_1::addReportIcon(int row, int researcherId, const QString& projectName)
{
    if (row < 0 || row >= ui->tableWidget_4->rowCount()) return;
    if (ui->tableWidget_4->columnCount() <= REPORT_COLUMN) return;

    QTableWidgetItem *reportIcon = new QTableWidgetItem("📊");
    reportIcon->setTextAlignment(Qt::AlignCenter);
    reportIcon->setToolTip("Cliquez pour voir le rapport du projet");
    reportIcon->setFlags(reportIcon->flags() ^ Qt::ItemIsEditable);
    reportIcon->setData(Qt::UserRole, researcherId);
    reportIcon->setData(Qt::UserRole + 1, projectName);
    ui->tableWidget_4->setItem(row, REPORT_COLUMN, reportIcon);
}
void chercheur_1::displayReportForProject(const QString& projectName)
{
    // Find or create the text edit
    QTextEdit *textEdit = findChild<QTextEdit*>("textEditReport");
    if (!textEdit) {
        textEdit = new QTextEdit(ui->stackedWidget->widget(2)); // page 2
        textEdit->setObjectName("textEditReport");
        // Add to layout if needed
    }

    // Clear and show loading message
    textEdit->clear();
    textEdit->setText("Génération du rapport en cours...");

    // Request AI report
    m_aiGenerator->requestProjectReport(projectName);
}
void chercheur_1::generateAIReportPDF(int researcherId, const QString& projectName, const QString& reportContent)
{
    // Fetch researcher data
    Chercheur c;
    if (!c.fetchDataById(researcherId)) {
        QMessageBox::warning(this, "Erreur", "Chercheur non trouvé.");
        return;
    }

    // Ask for save location
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Enregistrer le rapport en PDF",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) +
            QString("/rapport_%1_%2.pdf").arg(c.getNom()).arg(projectName),
        "PDF Files (*.pdf)"
        );

    if (filePath.isEmpty()) return;
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath += ".pdf";
    }

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15), QPageLayout::Millimeter);

    QTextDocument doc;

    QString html = R"(
        <html>
        <head>
            <meta charset='utf-8'>
            <style>
                body { font-family: 'Arial', sans-serif; margin: 0; padding: 20px; color: #333; }
                .header {
                    background-color: #2c3e50;
                    color: white;
                    padding: 20px;
                    text-align: center;
                    border-radius: 5px;
                    margin-bottom: 30px;
                }
                .researcher-info {
                    background-color: #f8f9fa;
                    padding: 15px;
                    border-radius: 5px;
                    margin-bottom: 20px;
                }
                .report-content {
                    line-height: 1.6;
                    font-size: 12pt;
                    white-space: pre-wrap;
                }
                .footer {
                    text-align: right;
                    font-size: 10pt;
                    color: #777;
                    margin-top: 30px;
                    border-top: 1px solid #eee;
                    padding-top: 10px;
                }
                h1 { color: #2c3e50; margin-top: 0; }
                h2 { color: #3498db; border-bottom: 1px solid #eee; padding-bottom: 5px; }
            </style>
        </head>
        <body>
            <div class='header'>
                <h1>Rapport de Recherche Scientifique</h1>
                <h2>Projet: %1</h2>
            </div>

            <div class='researcher-info'>
                <strong>Chercheur:</strong> %2 %3<br>
                <strong>ID:</strong> %4<br>
                <strong>Domaine:</strong> %5<br>
                <strong>Email:</strong> %6<br>
                <strong>Téléphone:</strong> %7
            </div>

            <div class='report-content'>
                %8
            </div>

            <div class='footer'>
                Généré le %9 • Système de Gestion de Recherche
            </div>
        </body>
        </html>
    )";

    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");

    // Format the report content - preserve line breaks and basic formatting
    QString formattedContent = reportContent.toHtmlEscaped();
    formattedContent.replace("\n", "<br>");

    doc.setHtml(html.arg(
        projectName,
        c.getPrenom(),
        c.getNom(),
        QString::number(c.getId()),
        c.getDomaineRecherche(),
        c.getEmail(),
        QString::number(c.getNumTlp()),
        formattedContent,
        currentDate
        ));

    doc.print(&printer);

    // Show success message and open PDF
    QMessageBox::information(this, "Succès",
                             QString("Rapport AI généré avec succès!\n\nFichier: %1").arg(filePath));
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}
