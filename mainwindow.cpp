#include "mainwindow.h"
#include "chercheur.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QFile>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const int HISTORY_COLUMN = 7; // Matches your "historique" column position

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

    // Initialize table
    ui->tableWidget->setColumnCount(8); // Removed history column
    QStringList headers = {"ID", "Nom", "Prénom", "Email", "Téléphone", "Domaine", "Projet" , "historique"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    // Add search components
    ui->S1->setPlaceholderText("Rechercher...");
    // When populating table rows:


connect(ui->tableWidget, &QTableWidget::cellClicked, this, &MainWindow::onCellClicked);
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


    // Connect search
    connect(ui->ok, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);

    QString searchTerm = ui->S1->text().trimmed();  // Trim any leading/trailing spaces


    // UI setup
    ui->lineEdit->setPlaceholderText("Entrez un ID numérique...");
    ui->lineEdit_5->setPlaceholderText("8 chiffres seulement");
    ui->lineEdit_7->setPlaceholderText("ex: chercheur@labo.com");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // Connect signals
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::onSuppButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::pushButton_2_clicked);
    connect(ui->stat, &QPushButton::clicked, this, &MainWindow::on_stat_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::onPdfButtonClicked);

    ui->tri->clear();
    ui->tri->addItems({"ID", "Nom", "Domaine"}); // Exact order matters!

    // Set default radio button (ASC/DSC)
    ui->tri->setCurrentIndex(0); // First item = "ID"
    ui->ASC->setChecked(true);

    // Connect sort button (assuming it's named 'triButton')
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTriClicked);
    // In MainWindow constructor
    connect(ui->ASC, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) ui->DSC->setChecked(false);
    });
    connect(ui->DSC, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) ui->ASC->setChecked(false);
    });

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
    if (ui->radioButton->isChecked()) {  // Add operation
        // Input validation
        bool ok;
        int id = ui->lineEdit->text().toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::warning(this, "Erreur", "ID doit être un nombre positif !");
            return;
        }

        QString nom = ui->lineEdit_3->text().trimmed();
        if (nom.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
            return;
        }

        QString phoneText = ui->lineEdit_5->text().trimmed();
        int num_tlp = phoneText.toInt(&ok);
        if (!ok || phoneText.length() != 8) {
            QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir 8 chiffres");
            return;
        }

        QString email = ui->lineEdit_7->text().trimmed();
        if (!email.contains("@") || !email.contains(".") || email.length() < 5) {
            QMessageBox::warning(this, "Erreur", "Format email invalide (ex: nom@domaine.com)");
            return;
        }

        QString domaine_recherche = ui->comboBox_4->currentText().trimmed();
        if (domaine_recherche.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Sélectionnez un domaine de recherche");
            return;
        }

        // Create and add researcher with initial empty history
        QJsonObject projectJson;
        projectJson["current"] = ui->lineEdit_8->text().trimmed();
        projectJson["history"] = QJsonArray();
        QString projetJsonString = QJsonDocument(projectJson).toJson();

        Chercheur c(id, nom,
                    ui->lineEdit_4->text().trimmed(),
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
    else if (ui->radioButton_2->isChecked()) {  // Modify operation
        bool ok;
        int id = ui->lineEdit->text().toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::warning(this, "Erreur", "ID invalide (doit être > 0)");
            return;
        }

        if (!ui->lineEdit_3->text().isEmpty()) {  // Modification mode
            // Validation
            QString nom = ui->lineEdit_3->text().trimmed();
            if (nom.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
                return;
            }

            QString phoneText = ui->lineEdit_5->text().trimmed();
            int num_tlp = phoneText.toInt(&ok);
            if (!ok || phoneText.length() != 8) {
                QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir 8 chiffres");
                return;
            }

            QString email = ui->lineEdit_7->text().trimmed();
            if (!email.contains("@") || !email.contains(".")) {
                QMessageBox::warning(this, "Erreur", "Format email invalide");
                return;
            }

            QString domaine = ui->comboBox_4->currentText().trimmed();
            if (domaine.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Sélectionnez un domaine de recherche");
                return;
            }

            QString newProject = ui->lineEdit_8->text().trimmed();

            // Fetch current data
            Chercheur c;
            if (c.fetchDataById(id)) {
                // Store old project before updating
                QString oldProject = c.getProjetEnCours();

                // Update project (this will handle history)
                c.setProjetEnCours(newProject);

                // Perform the database update with the complete JSON
                if (c.modify(id, nom,
                             ui->lineEdit_4->text().trimmed(),
                             email,
                             num_tlp,
                             domaine,
                             c.getProjetEnCours())) {
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
                ui->lineEdit_3->setText(c.getNom());
                ui->lineEdit_4->setText(c.getPrenom());
                ui->lineEdit_7->setText(c.getEmail());
                ui->lineEdit_5->setText(QString::number(c.getNumTlp()));
                ui->comboBox_4->setCurrentText(c.getDomaineRecherche());

                // Display current project (not the full JSON)
                ui->lineEdit_8->setText(c.getProjetEnCours());
            } else {
                QMessageBox::warning(this, "Erreur", "Chercheur non trouvé");
            }
        }
    }
}
void MainWindow::refreshTable()
{
    ui->tableWidget->setRowCount(0);
    QList<Chercheur> chercheurs = Chercheur::afficher();

    int row = 0;
    for (const Chercheur &c : chercheurs) {
        ui->tableWidget->insertRow(row);

        // Set regular data columns
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(c.getNom()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(c.getPrenom()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(c.getEmail()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(c.getNumTlp())));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(c.getDomaineRecherche()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(c.getProjetEnCours()));

        // Add history icon to the last column
        addHistoryIcon(row, c.getId());  // Fixed: use 'row' instead of 'i'

        row++;
    }
}

void MainWindow::addHistoryIcon(int row, int researcherId)
{
    QTableWidgetItem *historyIcon = new QTableWidgetItem("📜");
    historyIcon->setTextAlignment(Qt::AlignCenter);
    historyIcon->setToolTip("Cliquez pour voir l'historique des projets");
    historyIcon->setFlags(historyIcon->flags() ^ Qt::ItemIsEditable);
    historyIcon->setData(Qt::UserRole, researcherId);
    ui->tableWidget->setItem(row, HISTORY_COLUMN, historyIcon);
}

void MainWindow::onSuppButtonClicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow == -1) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    int id = ui->tableWidget->item(selectedRow, 0)->text().toInt();
    Chercheur c;
    if (c.supprimer(id)) {
        ui->tableWidget->removeRow(selectedRow);
        QMessageBox::information(this, "Succès", "Suppression réussie");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression");
    }
}

void MainWindow::clearFields()
{
    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->comboBox_4->setCurrentIndex(0);
    ui->radioButton->setChecked(true);
    ui->lineEdit->setFocus();
}
void MainWindow::on_searchButton_clicked() {
    QString searchTerm = ui->S1->text().trimmed();
    QString filter = ui->filtrage->currentText();

    QList<Chercheur> results = Chercheur::searchChercheur(searchTerm, filter);
    ui->tableWidget->setRowCount(0);

    for (int i = 0; i < results.size(); ++i) {
        const Chercheur &c = results[i];
        ui->tableWidget->insertRow(i);

        // Regular columns
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(c.getNom()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(c.getPrenom()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(c.getEmail()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(c.getNumTlp())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(c.getDomaineRecherche()));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(c.getProjetEnCours()));

        // Add history icon (assuming it's column 7)
        addHistoryIcon(i, c.getId());
    }

    if (results.isEmpty()) {
        QMessageBox::information(this, "Recherche", "Aucun résultat trouvé.");
    }
}
// In MainWindow.cpp
void MainWindow::onTriClicked() {
    if (!ui->ASC->isChecked() && !ui->DSC->isChecked()) {
        ui->ASC->setChecked(true);
    }
    QString sortBy = ui->tri->currentText();
    bool ascending = ui->ASC->isChecked();

    QList<Chercheur> chercheurs = Chercheur::getChercheursSorted(sortBy, ascending);
    ui->tableWidget->setRowCount(0);

    for (int i = 0; i < chercheurs.size(); ++i) {
        const Chercheur &c = chercheurs[i];
        ui->tableWidget->insertRow(i);

        // Regular columns
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(c.getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(c.getNom()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(c.getPrenom()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(c.getEmail()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(c.getNumTlp())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(c.getDomaineRecherche()));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(c.getProjetEnCours()));

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
    c.afficherStatistiques(this);

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
    if (row < 0 || row >= ui->tableWidget->rowCount()) return;

    int id = ui->tableWidget->item(row, 0)->text().toInt();
    Chercheur c;
    if (c.fetchDataById(id)) {
        QDialog historyDialog(this);
        historyDialog.setWindowTitle("Historique des Projets");

        QVBoxLayout layout(&historyDialog);
        QLabel title(QString("Historique pour %1 %2").arg(c.getPrenom()).arg(c.getNom()));

        QTextEdit historyDisplay;
        historyDisplay.setHtml(c.getFormattedHistory());
        historyDisplay.setReadOnly(true);

        QPushButton closeButton("Fermer");
        connect(&closeButton, &QPushButton::clicked, &historyDialog, &QDialog::accept);

        layout.addWidget(&title);
        layout.addWidget(&historyDisplay);
        layout.addWidget(&closeButton);

        historyDialog.exec();
    }
}

void MainWindow::onCellClicked(int row, int column)
{
    if (column == HISTORY_COLUMN) {
        showResearcherHistory(row);
    }
}
