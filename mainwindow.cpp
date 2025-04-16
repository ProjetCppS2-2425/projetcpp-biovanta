#include "mainwindow.h"
#include "chercheur.h"
#include "ui_mainwindow.h"
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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ai_report_generator.h"

// Global or class-level instance



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_aiGenerator(new AIReportGenerator(this))  // Create the generator instance
{
    ui->setupUi(this);

    // Connect the AI report signal to your update slot
    connect(m_aiGenerator, &AIReportGenerator::reportGenerated,
            this, &MainWindow::updateReportInTable);

    // Optional: connect a button





    QStringList headers;
    headers << "Nom" << "ID" << "Projet en cours" << "Rapport";
    ui->tableWidget_5->setColumnCount(headers.size());
    ui->tableWidget_5->setHorizontalHeaderLabels(headers);

    // Connect signals
    // Change from:


    // To:

    // Example: Add prefix to project name in tableWidget_5

    // In MainWindow constructor (mainwindow.cpp)
    ui->filtrage_4->clear();
    ui->filtrage_4->addItems({"ID", "Nom", "Email", "Projet En Cours"});  // Now includes "ID"
    connect(ui->btn_goToStats, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);  // Go to Page 1
    });
    // Example: "View Reports" button click

    connect(ui->btn_backHome, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);  // Go back to Page 0
    });
    // ---- Initialize recommendation widget FIRST ----
    // Add this column (typically in your table setup code)



    // Connect the cell click signal

    // Connections

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

    // Initialize table

    ui->S1_4->setPlaceholderText("Rechercher...");
    // When populating table rows:

    // Set up panel



    connect(ui->tableWidget_4, &QTableWidget::cellClicked, this, &MainWindow::onCellClicked);

    ui->logo->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\logo1.png"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\empe.png"));
    ui->chercheur->setIcon(QPixmap("C:\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\cher.png"));
    ui->pdf_4->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\client.png"));
    ui->stat_4->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\st.png"));
    ui->ok_4->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\search.png"));
    ui->supp_6->setIcon(QPixmap("C:\\Users\\nesri\\Downloads\\projet_c (3) (2)\\projet_c\\effacer.png"));
    // Replace whatever displays the current project with:

    // Connect search
    connect(ui->ok_4, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);


    // UI setup
    ui->lineEdit_1->setPlaceholderText("Entrez un ID numérique...");
    ui->lineEdit_21->setPlaceholderText("8 chiffres seulement");
    ui->lineEdit_23->setPlaceholderText("ex: chercheur@labo.com");
    ui->tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_4->setSelectionMode(QAbstractItemView::SingleSelection);

    // Connect signals
    connect(ui->supp_6, &QPushButton::clicked, this, &MainWindow::onSuppButtonClicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::pushButton_2_clicked);
    connect(ui->stat_4, &QPushButton::clicked, this, &MainWindow::on_stat_clicked);
    connect(ui->pdf_4, &QPushButton::clicked, this, &MainWindow::onPdfButtonClicked);

    ui->tri_4->clear();
    ui->tri_4->addItems({"ID", "Nom", "Domaine"}); // Exact order matters!

    // Set default radio button (ASC/DSC)
    ui->tri_4->setCurrentIndex(0); // First item = "ID"
    ui->ASC_4->setChecked(true);

    // Connect sort button (assuming it's named 'triButton')
    connect(ui->tri_4, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTriClicked);
    // In MainWindow constructor
    connect(ui->ASC_4, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) ui->DSC_4->setChecked(false);
    });
    connect(ui->DSC_4, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) ui->ASC_4->setChecked(false);
    });
    // After populating the table with data:
    ui->tableWidget_4->resizeColumnsToContents();

    // Set minimum widths after auto-resizing
    for (int i = 0; i < ui->tableWidget_4->columnCount(); ++i) {
        int current = ui->tableWidget_4->columnWidth(i);
        if (current < 80) ui->tableWidget_4->setColumnWidth(i, 80);
    }
    // Load initial data

    refreshTable();
    onTriClicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushButton_2_clicked()
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
                             ui->lineEdit_19->text().trimmed(),
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
void MainWindow::refreshTable()
{
    // Clear tables while preserving headers
    ui->tableWidget_4->setRowCount(0);
    ui->tableWidget_5->setRowCount(0);

    // Get researcher data
    QList<Chercheur> chercheurs = Chercheur::afficher();

    // Configure table properties
    ui->tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int row = 0; row < chercheurs.size(); ++row) {
        const Chercheur& c = chercheurs[row];
        QString cleanProjectName = c.cleanProjectName(c.getProjetEnCours());

        // ===== Main Researcher Table (tableWidget_4) =====
        ui->tableWidget_4->insertRow(row);

        // ID (Column 0)
        ui->tableWidget_4->setItem(row, 0,
                                   new QTableWidgetItem(QString::number(c.getId())));

        // Name (Column 1)
        ui->tableWidget_4->setItem(row, 1,
                                   new QTableWidgetItem(c.getNom()));

        // Email (Column 3)
        ui->tableWidget_4->setItem(row, 3,
                                   new QTableWidgetItem(c.getEmail()));

        // Project (Column 6)
        ui->tableWidget_4->setItem(row, 6,
                                   new QTableWidgetItem(cleanProjectName));

        // Add history icon (Column 7)
        addHistoryIcon(row, c.getId());

        // ===== Report Table (tableWidget_5) =====
        ui->tableWidget_5->insertRow(row);

        // ID (Column 0)
        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(c.getId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_5->setItem(row, 0, idItem);

        // Name (Column 1)
        ui->tableWidget_5->setItem(row, 1,
                                   new QTableWidgetItem(c.getNom()));

        // Project (Column 2)
        QTableWidgetItem* projectItem = new QTableWidgetItem(cleanProjectName);
        ui->tableWidget_5->setItem(row, 2, projectItem);

        // Report (Column 3)
        QTableWidgetItem* reportItem = new QTableWidgetItem("Generating report...");
        reportItem->setFlags(reportItem->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget_5->setItem(row, 3, reportItem);

        // Trigger AI report generation if we have a project name
        if (!cleanProjectName.isEmpty() && cleanProjectName != "None" && m_aiConnected) {
            m_aiGenerator->requestProjectReport(cleanProjectName);
        }
    }

    // Auto-resize columns with minimum widths
    ui->tableWidget_4->resizeColumnsToContents();
    ui->tableWidget_5->resizeColumnsToContents();

    // Ensure minimum column widths
    for (int col = 0; col < ui->tableWidget_4->columnCount(); ++col) {
        if (ui->tableWidget_4->columnWidth(col) < 80)
            ui->tableWidget_4->setColumnWidth(col, 80);
    }

    // Set specific width for report column
    ui->tableWidget_5->setColumnWidth(3, 300); // Wider for reports

    // Refresh the view
    ui->tableWidget_4->viewport()->update();
    ui->tableWidget_5->viewport()->update();
}
void MainWindow::addHistoryIcon(int row, int researcherId)
{
    QTableWidgetItem *historyIcon = new QTableWidgetItem("📜");
    historyIcon->setTextAlignment(Qt::AlignCenter);
    historyIcon->setToolTip("Cliquez pour voir l'historique des projets");
    historyIcon->setFlags(historyIcon->flags() ^ Qt::ItemIsEditable);
    historyIcon->setData(Qt::UserRole, researcherId);
    ui->tableWidget_4->setItem(row, HISTORY_COLUMN, historyIcon);
}

void MainWindow::onSuppButtonClicked()
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

void MainWindow::clearFields()
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
void MainWindow::on_searchButton_clicked() {
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
        ui->tableWidget_4->setItem(i, 6, new QTableWidgetItem(c.getProjetEnCours()));

        // Add history icon (assuming it's column 7)
        addHistoryIcon(i, c.getId());
    }

    if (results.isEmpty()) {
        QMessageBox::information(this, "Recherche", "Aucun résultat trouvé.");
    }
}
// In MainWindow.cpp
void MainWindow::onTriClicked() {
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
void MainWindow::on_stat_clicked()
{
    Chercheur c;
    c.afficherStatistiques(ui->stackedWidget); // Pass the stacked widget instead of 'this'
}
void MainWindow::onPdfButtonClicked() {
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
void MainWindow::showResearcherHistory(int row)
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


void MainWindow::onCellClicked(int row, int column)
{
    if (column == HISTORY_COLUMN) {
        showResearcherHistory(row);
    }
}

QString Chercheur::getReport() const
{
    // Implement your logic to generate/retrieve reports
    // This is just an example - modify according to your needs
    return QString("Rapport pour %1 - Projet: %2").arg(nom).arg(projet_en_cours);
}
void MainWindow::updateReportInTable(const QString &projectName, const QString &report)
{
    // Find all rows with matching project name
    for (int row = 0; row < ui->tableWidget_5->rowCount(); ++row) {
        QTableWidgetItem* projectItem = ui->tableWidget_5->item(row, 2); // Project is column 2
        if (projectItem && projectItem->text() == projectName) {
            QTableWidgetItem* reportItem = ui->tableWidget_5->item(row, 3); // Report is column 3
            if (reportItem) {
                reportItem->setText(report);
                reportItem->setForeground(Qt::black);

                // Auto-resize row height to fit content
                ui->tableWidget_5->resizeRowToContents(row);
            }
        }
    }
}

