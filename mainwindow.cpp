#include "mainwindow.h"

#include "chercheur.h"
#include "ui_mainwindow.h"
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
#include <QDesktopServices>  // Add this include at the top
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
#include <QComboBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
class QChartView;
class QChart;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);



    ui->tableWidget->setStyleSheet(
        // Base table style - simple and clean
        "QTableWidget {"
        "    background-color: white;"
        "    border: 1px solid #d0d0d0;"
        "    gridline-color: #eaeaea;"
        "    font: 10pt 'Segoe UI';"
        "    color: #333333;"
        "    border-radius: 4px;"
        "}"

        // Header style - dark blue
        "QHeaderView::section {"
        "    background-color: #2C3E50;"  // Your original dark blue
        "    color: white;"
        "    padding: 6px;"
        "    border: none;"
        "    font-weight: normal;"
        "}"

        // Special Histologie row - purple highlight
        "QTableWidget::item[histologie='true'] {"
        "    background-color: #f0e6ff;"  // Very light purple
        "    border-left: 3px solid #8e44ad;"  // Your original purple
        "    font-weight: bold;"
        "}"

        // Hover effect
        "QTableWidget::item:hover {"
        "    background-color: #f5f5f5;"
        "}"

        // Selection color - dark blue
        "QTableWidget::item:selected {"
        "    background-color: #2C3E50;"  // Your dark blue
        "    color: white;"
        "}"
        );
    // Add this where you set up table headers:
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("History"));
    // When populating your table
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        bool isHistologieRow = false;

        // Check cells in this row
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item && item->text().contains("Histologie", Qt::CaseInsensitive)) {
                isHistologieRow = true;
                break;
            }
        }

        // Apply highlight to entire row
        if (isHistologieRow) {
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                QTableWidgetItem *item = ui->tableWidget->item(row, col);
                if (item) {
                    item->setData(Qt::UserRole, "highlightRow");
                    item->setFont(QFont("Segoe UI Semibold", 11));
                }
            }
            ui->tableWidget->setRowHeight(row, 28);  // Slightly taller row
        }


    }




    isDataFetched = false;



    // Set placeholder text (gray hints)
    ui->lineEdit->setPlaceholderText("Entrez un ID numérique...");
    ui->lineEdit_5->setPlaceholderText("8 chiffres seulement");
    ui->lineEdit_7->setPlaceholderText("ex: chercheur@labo.com");


    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); // Allow only one row to be selected










    // Set default values:
    // 1. Set the combo box (tri) to the option corresponding to ID (assuming index 1 is ID)
    ui->tri->setCurrentIndex(1);   // Assuming index 1 corresponds to ID
    ui->ASC->setChecked(true);     // Default to ascending order
    ui->DSC->setChecked(false);    // Ensure descending is unchecked

    // Apply initial sort
    Chercheur::applySort(ui->tri, ui->ASC, ui->DSC, ui->tableWidget);

    // Connect signals for interactive sorting
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::applySort);
    connect(ui->ASC, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) ui->DSC->setChecked(false);
        applySort();
    });
    connect(ui->DSC, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) ui->ASC->setChecked(false);
        applySort();
    });
    // In your slot that handles changes (for example, in onSortChanged)



    connect(ui->ok, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    connect(ui->supp, &QPushButton::clicked, this, &MainWindow::onSuppButtonClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::pushButton_2_clicked);

    connect(ui->S1, SIGNAL(textChanged(QString)), this, SLOT(onSearchTextChanged(QString)));



    // In your MainWindow constructor (UI setup)
    connect(ui->stat, &QPushButton::clicked, this, &MainWindow::on_stat_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::onPdfButtonClicked);
    // In your MainWindow constructor or setup function:

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
    refreshTable();
    Chercheur::loadHistory();
    applySort();

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::pushButton_2_clicked() {
    if (ui->radioButton->isChecked()) {  // Add operation
        // --- Input Validation ---
        // 1. ID Validation (must be positive number)
        bool ok;
        int id = ui->lineEdit->text().toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::warning(this, "Erreur", "ID doit être un nombre positif !");
            return;
        }

        // 2. Name Validation (non-empty)
        QString nom = ui->lineEdit_3->text().trimmed();
        if (nom.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
            return;
        }

        // 3. Phone Validation (exactly 8 digits)
        QString phoneText = ui->lineEdit_5->text().trimmed();
        int num_tlp = phoneText.toInt(&ok);
        if (!ok || phoneText.length() != 8) {
            QMessageBox::warning(this, "Erreur", "Le téléphone doit contenir 8 chiffres");
            return;
        }

        // 4. Email Validation (basic format check)
        QString email = ui->lineEdit_7->text().trimmed();
        if (!email.contains("@") || !email.contains(".") || email.length() < 5) {
            QMessageBox::warning(this, "Erreur", "Format email invalide (ex: nom@domaine.com)");
            return;
        }

        // 5. Domain Validation
        QString domaine_recherche = ui->comboBox_4->currentText().trimmed();
        if (domaine_recherche.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Sélectionnez un domaine de recherche");
            return;
        }

        // --- Create and Add Researcher ---
        Chercheur c(id, nom,
                    ui->lineEdit_4->text().trimmed(), // Prenom
                    email,
                    num_tlp,
                    domaine_recherche,
                    ui->lineEdit_8->text().trimmed()); // Projet

        if (c.ajouter()) {
            QMessageBox::information(this, "Succès", "Chercheur ajouté !");
            refreshTable();

            // Clear fields
            ui->lineEdit->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_7->clear();
            ui->comboBox_4->setCurrentIndex(-1); // Better than 0
            ui->lineEdit_8->clear();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout. Vérifiez les données.");
        }

    }
    else if (ui->radioButton_2->isChecked()) {  // Modify operation
        // --- ID Validation ---
        bool ok;
        int id = ui->lineEdit->text().toInt(&ok);
        if (!ok || id <= 0) {
            QMessageBox::warning(this, "Erreur", "ID invalide (doit être > 0)");
            return;
        }

        // Check if fields are populated (save mode)
        if (!ui->lineEdit_3->text().isEmpty()) {
            // --- Validation (same as add) ---
            QString nom = ui->lineEdit_3->text().trimmed();
            if (nom.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Nom vide");
                return;
            }

            // Phone check
            QString phoneText = ui->lineEdit_5->text().trimmed();
            int num_tlp = phoneText.toInt(&ok);
            if (!ok || phoneText.length() != 8) {
                QMessageBox::warning(this, "Erreur", "Téléphone: 8 chiffres requis");
                return;
            }

            // Email check
            QString email = ui->lineEdit_7->text().trimmed();
            if (!email.contains("@") || !email.contains(".")) {
                QMessageBox::warning(this, "Erreur", "Email invalide");
                return;
            }

            // Domain check
            QString domaine = ui->comboBox_4->currentText().trimmed();
            if (domaine.isEmpty()) {
                QMessageBox::warning(this, "Erreur", "Domaine non sélectionné");
                return;
            }

            // --- Perform Modification ---
            Chercheur c;
            if (c.modify(id, nom,
                         ui->lineEdit_4->text().trimmed(),
                         email,
                         num_tlp,
                         domaine,
                         ui->lineEdit_8->text().trimmed())) {
                QMessageBox::information(this, "Succès", "Modification réussie");
                refreshTable();
                clearFields();
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la modification");
            }
        }
        else { // Fetch mode
            Chercheur c;
            if (c.fetchDataById(id)) {
                ui->lineEdit_3->setText(c.getNom());
                ui->lineEdit_4->setText(c.getPrenom());
                ui->lineEdit_7->setText(c.getEmail());
                ui->lineEdit_5->setText(QString::number(c.getNumTlp()));
                ui->comboBox_4->setCurrentText(c.getDomaineRecherche());
                ui->lineEdit_8->setText(c.getProjetEnCours());
            } else {
                QMessageBox::warning(this, "Erreur", "Chercheur non trouvé");
            }
        }
    }
}


void MainWindow::refreshTable() {
    // Clear the existing rows and set columns
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(8); // 7 data columns + history button column

    // Set headers (if not already done in constructor)
    QStringList headers = {"ID", "Nom", "Prénom", "Email", "Téléphone", "Domaine", "Projet", "Historique"};
    for (int col = 0; col < headers.size(); ++col) {
        ui->tableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem(headers[col]));
    }

    // Simple query without sorting
    QSqlQuery query("SELECT * FROM CHERCHEUR");

    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Set data columns (0-6)
        for (int col = 0; col < 7; col++) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }

        // Add history button (column 7)
        QPushButton *historyBtn = new QPushButton();

        // Use absolute path (replace with your actual path)
        QString iconPath = "C:/Users/nesri/Downloads/projet_c (3) (2)/projet_c/his.png";
        if (QFile::exists(iconPath)) {
            historyBtn->setIcon(QIcon(iconPath));
        } else {
            // Fallback to system icon if file not found
            historyBtn->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
            qDebug() << "Icon not found at:" << iconPath;
        }

        // Get the researcher ID from column 0
        int currentId = query.value(0).toInt();

        // Store ID as button property (optional, but useful for debugging)
        historyBtn->setProperty("id", currentId);

        historyBtn->setToolTip("Voir l'historique");
        historyBtn->setStyleSheet(
            "QPushButton { border: none; background: transparent; padding: 5px; }"
            "QPushButton:hover { background: #f0f0f0; }"
            );

        // Connect using the currentId we just obtained
        connect(historyBtn, &QPushButton::clicked, [this, currentId]() {
            showHistory(currentId); // Use the captured ID
        });

        ui->tableWidget->setCellWidget(row, 7, historyBtn);
    }

    // Adjust column widths if needed
    ui->tableWidget->setColumnWidth(7, 40); // Compact history column


    // Adjust column widths if needed
    ui->tableWidget->setColumnWidth(7, 40); // Compact history column
}
void MainWindow::onSuppButtonClicked() {
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow == -1) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    // Get ID from the selected row
    int id = ui->tableWidget->item(selectedRow, 0)->text().toInt();

    // Delete from database
    Chercheur c;
    if (c.supprimer(id)) {
        ui->tableWidget->removeRow(selectedRow);
        QMessageBox::information(this, "Succès", "Suppression réussie");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression");
    }
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
void MainWindow::on_stat_clicked()
{
    Chercheur c;
    c.afficherStatistiques(this);

}


void MainWindow::onSearchButtonClicked()
{
    QString searchTerm = ui->S1->text().trimmed();
    QString filterField;


    // Map combobox index to field names
    switch(ui->filtrage->currentIndex()) {
    case 0: filterField = "NOM"; break;    // Name
    case 1: filterField = "ID"; break;     // ID
    case 2: filterField = "EMAIL"; break;  // Email
    default: filterField = "NOM";
    }

    QList<Chercheur> results = Chercheur::searchByIdNameEmail(searchTerm, filterField);
    Chercheur::displayResults(results, ui->tableWidget);


    if (results.isEmpty() && !searchTerm.isEmpty()) {
        QMessageBox::information(this, "Search", "No matching records found");
    }
}
void MainWindow::showHistory(int researcherId) {
    // Get researcher data
    QString researcherName, currentProject;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        if (ui->tableWidget->item(i, 0)->text().toInt() == researcherId) {
            researcherName = ui->tableWidget->item(i, 1)->text();
            currentProject = ui->tableWidget->item(i, 6)->text();
            break;
        }
    }

    QDialog historyDialog(this);
    historyDialog.setWindowTitle("History - " + researcherName);
    historyDialog.setFixedSize(400, 300);

    QVBoxLayout *layout = new QVBoxLayout(&historyDialog);

    QLabel *currentLabel = new QLabel("Current Project: " + currentProject);
    layout->addWidget(currentLabel);

    QListWidget *historyList = new QListWidget();
    layout->addWidget(historyList);

    QList<QPair<QString, QDateTime>> history = Chercheur::getHistory(researcherId);
    if (history.isEmpty()) {
        historyList->addItem("No history available");
    } else {
        for (const auto& entry : history) {
            QString itemText = QString("%1 - %2")
            .arg(entry.second.toString("dd.MM.yyyy hh:mm"))
                .arg(entry.first);
            historyList->addItem(itemText);
        }
    }

    QPushButton *closeButton = new QPushButton("Close");
    connect(closeButton, &QPushButton::clicked, &historyDialog, &QDialog::accept);
    layout->addWidget(closeButton);

    historyDialog.exec();
}
void MainWindow::clearFields() {
    // Clear all input fields
    ui->lineEdit->clear();      // ID
    ui->lineEdit_3->clear();    // Nom
    ui->lineEdit_4->clear();    // Prénom
    ui->lineEdit_7->clear();    // Email
    ui->lineEdit_5->clear();    // Téléphone
    ui->lineEdit_8->clear();    // Projet en cours

    // Reset combo box
    ui->comboBox_4->setCurrentIndex(0); // Domaine recherche

    // Reset radio buttons if needed
    ui->radioButton->setChecked(true); // "Ajouter" mode

    // Clear any validation errors
    ui->lineEdit->setStyleSheet("");
    ui->lineEdit_3->setStyleSheet("");
    // ... clear other field styles if needed ...

    // Set focus back to ID field
    ui->lineEdit->setFocus();
}
void MainWindow::applySort() {
    // Ensure only one checkbox is active
    if (ui->ASC->isChecked() && ui->DSC->isChecked()) {
        ui->DSC->setChecked(false);
    }

    Chercheur::applySort(ui->tri, ui->ASC, ui->DSC, ui->tableWidget);

}
