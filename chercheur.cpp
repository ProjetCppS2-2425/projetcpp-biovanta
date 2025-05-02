#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTextDocument>
#include <QPrinter>
#include <QFile>
#include <QDate>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
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
#include <QTextTable>
#include <QStandardPaths>
#include <QFont>
#include <QColor>
#include <QDate>
#include <QInputDialog>
#include <QTableWidget>  // Include the QTableWidget header
#include <QWidget>
#include <QLabel>
#include "chercheur.h"
#include <QtCharts>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QMessageBox>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QPrinter>
#include <QTextTableCell>
#include <QTextDocument>
#include <QTextCursor>
#include "chercheur_1.h"  // Include MainWindow header to use MainWindow class

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
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
class QLineEdit;
class QLabel;


Chercheur::Chercheur() {}

Chercheur::Chercheur(int id, QString nom, QString prenom, QString email,
                     int num_tlp, QString domaine_recherche, QString projet_en_cours)
    : id(id), nom(nom), prenom(prenom), email(email),
    num_tlp(num_tlp), domaine_recherche(domaine_recherche),
    projet_en_cours(projet_en_cours)
{
    initProjectJson();
}

bool Chercheur::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO CHERCHEUR (ID_CHERCHEUR, NOM, PRENOM, EMAIL, NUM_TLP, DOMAINE_RECHERCHE, PROJET_EN_COURS) "
                  "VALUES (:id, :nom, :prenom, :email, :num_tlp, :domaine_recherche, :projet_en_cours)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":num_tlp", num_tlp);
    query.bindValue(":domaine_recherche", domaine_recherche);
    query.bindValue(":projet_en_cours", projet_en_cours);

    if (query.exec()) {


        return true;
    }
    return false;
}
QList<Chercheur> Chercheur::afficher()
{
    QList<Chercheur> chercheurs;
    QSqlQuery query;

    if (query.exec("SELECT * FROM CHERCHEUR")) {
        while (query.next()) {
            Chercheur c(
                query.value("ID_CHERCHEUR").toInt(),
                query.value("NOM").toString(),
                query.value("PRENOM").toString(),
                query.value("EMAIL").toString(),
                query.value("NUM_TLP").toInt(),
                query.value("DOMAINE_RECHERCHE").toString(),
                query.value("PROJET_EN_COURS").toString()
                );
            chercheurs.append(c);
        }
    } else {
        qDebug() << "Database error:" << query.lastError().text();
    }

    return chercheurs;
}

bool Chercheur::supprimer(int id) {
    QSqlQuery query;

    // Prepare the SQL query to delete a record
    query.prepare("DELETE FROM CHERCHEUR WHERE ID_CHERCHEUR = :id");
    query.bindValue(":id", id);

    // Execute the query
    if (!query.exec()) {
        // If the query fails, log the error and return false
        qDebug() << "SQL Error: " << query.lastError().text();
        return false;

    }

    // If the query succeeds, return true
    return true;
}
bool Chercheur::fetchDataById(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM CHERCHEUR WHERE ID_CHERCHEUR = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        this->id = id;
        nom = query.value("NOM").toString();
        prenom = query.value("PRENOM").toString();
        email = query.value("EMAIL").toString();
        num_tlp = query.value("NUM_TLP").toInt();
        domaine_recherche = query.value("DOMAINE_RECHERCHE").toString();

        // Store the complete JSON string internally
        projet_en_cours = query.value("PROJET_EN_COURS").toString();

        // Initialize if empty or invalid
        initProjectJson();
        return true;
    }
    qDebug() << "Fetch error:" << query.lastError().text();
    return false;
}

bool Chercheur::modify(int id, const QString &nom, const QString &prenom,
                       const QString &email, int num_tlp,
                       const QString &domaine_recherche, const QString &newProject)
{
    if (!fetchDataById(id)) {
        return false;
    }

    // This updates both current project and history
    updateProjectHistory(newProject);

    QSqlQuery query;
    query.prepare("UPDATE CHERCHEUR SET "
                  "nom = :nom, prenom = :prenom, "
                  "email = :email, num_tlp = :num_tlp, "
                  "domaine_recherche = :domaine, "
                  "projet_en_cours = :projet "
                  "WHERE ID_CHERCHEUR = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":num_tlp", num_tlp);
    query.bindValue(":domaine", domaine_recherche);
    query.bindValue(":projet", getFullProjectJson()); // Store complete JSON

    return query.exec();
}

QList<Chercheur> Chercheur::searchChercheur(const QString &searchTerm, const QString &filter) {
    QList<Chercheur> results;
    QSqlQuery query;

    QString sqlQuery = "SELECT * FROM CHERCHEUR WHERE ";

    if (filter == "ID") {
        bool ok;
        int searchId = searchTerm.toInt(&ok);
        if (ok) {
            sqlQuery += "ID_CHERCHEUR = :id";
            query.prepare(sqlQuery);
            query.bindValue(":id", searchId);
        } else {
            return results;
        }
    }
    else if (filter == "Nom") {
        sqlQuery += "NOM LIKE :searchTerm";
        query.prepare(sqlQuery);
        query.bindValue(":searchTerm", "%" + searchTerm + "%");
    }
    else if (filter == "Email") {
        sqlQuery += "EMAIL LIKE :searchTerm";
        query.prepare(sqlQuery);
        query.bindValue(":searchTerm", "%" + searchTerm + "%");
    }
    else if (filter == "Projet En Cours") {
        // Search in cleaned project names
        sqlQuery += "LOWER(json_extract(PROJET_EN_COURS, '$.current')) LIKE LOWER(:searchTerm)";
        query.prepare(sqlQuery);
        query.bindValue(":searchTerm", "%" + searchTerm + "%");
    }
    else {
        // Default search
        sqlQuery += "(NOM LIKE :searchTerm OR EMAIL LIKE :searchTerm OR "
                    "LOWER(json_extract(PROJET_EN_COURS, '$.current')) LIKE LOWER(:searchTerm))";
        query.prepare(sqlQuery);
        query.bindValue(":searchTerm", "%" + searchTerm + "%");
    }

    if (!query.exec()) {
        qDebug() << "Search error:" << query.lastError().text();
        return results;
    }

    while (query.next()) {
        Chercheur c(
            query.value("ID_CHERCHEUR").toInt(),
            query.value("NOM").toString(),
            query.value("PRENOM").toString(),
            query.value("EMAIL").toString(),
            query.value("NUM_TLP").toInt(),
            query.value("DOMAINE_RECHERCHE").toString(),
            query.value("PROJET_EN_COURS").toString()
            );

        // Clean the project name before adding to results
        c.initProjectJson(); // Ensure clean JSON structure
        results.append(c);
    }

    return results;
}
QList<Chercheur> Chercheur::getChercheursSorted(const QString& sortBy, bool ascending) {
    QList<Chercheur> chercheurs;
    QSqlQuery query;

    QString orderBy;
    if (sortBy == "ID") {
        orderBy = "ID_CHERCHEUR";
    } else if (sortBy == "Nom") {
        orderBy = "NOM";
    } else if (sortBy == "Domaine de Recherche") {
        orderBy = "DOMAINE_RECHERCHE";
    } else {
        orderBy = "ID_CHERCHEUR"; // Default fallback
    }

    QString direction = ascending ? "ASC" : "DESC";
    QString sql = QString("SELECT * FROM CHERCHEUR ORDER BY %1 %2").arg(orderBy).arg(direction);

    if (query.exec(sql)) {
        while (query.next()) {
            Chercheur c(
                query.value("ID_CHERCHEUR").toInt(),
                query.value("NOM").toString(),
                query.value("PRENOM").toString(),
                query.value("EMAIL").toString(),
                query.value("NUM_TLP").toInt(),
                query.value("DOMAINE_RECHERCHE").toString(),
                query.value("PROJET_EN_COURS").toString()
                );
            chercheurs.append(c);
        }
    } else {
        qDebug() << "Sorting error:" << query.lastError().text();
    }

    return chercheurs;
}
void Chercheur::afficherStatistiques(QStackedWidget *stackedWidget)
{
    QSqlQuery query;
    query.prepare("SELECT DOMAINE_RECHERCHE, COUNT(*) FROM CHERCHEUR GROUP BY DOMAINE_RECHERCHE");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Erreur de base de données: " + query.lastError().text());
        return;
    }

    QMap<QString, int> domainData;
    int total = 0;
    QVector<QColor> bioResearchPalette = {
        QColor("#3AAFA9"), QColor("#2B7A78"), QColor("#DEF2F1"),
        QColor("#17252A"), QColor("#FEFFFF"), QColor("#88D498")
    };

    while (query.next()) {
        QString domain = query.value(0).toString();
        int count = query.value(1).toInt();
        domainData.insert(domain, count);
        total += count;
    }

    // Get the second page of the stacked widget
    QWidget *statsPage = stackedWidget->widget(1);

    // Clear existing layout if any
    QLayout *existingLayout = statsPage->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    QVBoxLayout *mainLayout = new QVBoxLayout(statsPage);

    // Create a tab widget for charts
    QTabWidget *tabs = new QTabWidget();
    tabs->setStyleSheet(R"(
        QTabWidget::pane {
            background-color: #ffffff;
            border-radius: 12px;
            margin: 8px;
            border: 1px solid #cbd5e0;
        }
        QTabBar::tab {
            background: #edf2f7;
            color: #2d3748;
            padding: 12px 20px;
            margin: 2px;
            border-top-left-radius: 10px;
            border-top-right-radius: 10px;
            font-weight: bold;
        }
        QTabBar::tab:selected {
            background-color: #38b2ac;
            color: #ffffff;
        }
    )");

    // PIE CHART
    QPieSeries *pieSeries = new QPieSeries();
    pieSeries->setPieSize(0.75);
    int colorIndex = 0;
    for (const QString &domain : domainData.keys()) {
        int count = domainData[domain];
        qreal percentage = (count * 100.0) / total;
        QPieSlice *slice = pieSeries->append(domain, count);
        slice->setColor(bioResearchPalette[colorIndex % bioResearchPalette.size()]);
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1\n%2 chercheurs (%3%)")
                            .arg(domain)
                            .arg(count)
                            .arg(percentage, 0, 'f', 1));
        slice->setBorderWidth(2);
        slice->setBorderColor(Qt::white);
        colorIndex++;
    }
    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition par Domaine de Recherche");
    pieChart->setTitleFont(QFont("Helvetica Neue", 15, QFont::Bold));
    pieChart->setAnimationOptions(QChart::SeriesAnimations);
    pieChart->legend()->setAlignment(Qt::AlignRight);
    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);
    pieChartView->setStyleSheet("border-radius: 12px; border: 1px solid #cbd5e0; background-color: #ffffff;");
    tabs->addTab(pieChartView, "🧬 Répartition Visuelle");

    // BAR CHART
    QBarSeries *barSeries = new QBarSeries();
    QBarSet *barSet = new QBarSet("Nombre de Chercheurs");
    barSet->setColor(QColor("#3AAFA9"));

    QStringList categories;
    for (const QString &domain : domainData.keys()) {
        *barSet << domainData[domain];
        categories << domain;
    }
    barSeries->append(barSet);
    barSeries->setLabelsVisible(true);
    barSeries->setLabelsFormat("@value"); // default numeric value

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Distribution Quantitative des Domaines");
    barChart->setTitleFont(QFont("Helvetica Neue", 15, QFont::Bold));
    barChart->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis *xAxis = new QBarCategoryAxis();
    xAxis->append(categories);
    xAxis->setTitleText("Domaines");
    barChart->addAxis(xAxis, Qt::AlignBottom);
    barSeries->attachAxis(xAxis);
    QValueAxis *yAxis = new QValueAxis();
    yAxis->setLabelFormat("%d");
    yAxis->setTitleText("Nombre de Chercheurs");
    barChart->addAxis(yAxis, Qt::AlignLeft);
    barSeries->attachAxis(yAxis);
    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    barChartView->setStyleSheet("border-radius: 12px; border: 1px solid #cbd5e0; background-color: #ffffff;");
    tabs->addTab(barChartView, "🔍 Vue Comparée");

    mainLayout->addWidget(tabs);

    // Create a smaller textual summary of the statistics including percentages
    QString summaryText;
    summaryText += "<h3 style='color:#2C3E50; font-family:Segoe UI; font-size:10pt;'>Résumé Statistique</h3>";
    summaryText += "<ul style='font-family:Segoe UI; font-size:9pt; margin-left:20px;'>";
    for (const QString &domain : domainData.keys()) {
        int count = domainData[domain];
        qreal percentage = (count * 100.0) / total;
        summaryText += QString("<li>%1 : %2 chercheurs (<b>%3%</b>)</li>")
                           .arg(domain)
                           .arg(count)
                           .arg(percentage, 0, 'f', 1);
    }
    summaryText += "</ul>";

    QLabel *summaryLabel = new QLabel;
    summaryLabel->setTextFormat(Qt::RichText);
    summaryLabel->setAlignment(Qt::AlignLeft);
    summaryLabel->setText(summaryText);
    summaryLabel->setStyleSheet("margin: 10px; padding: 5px; background-color: #f7f7f7; border: 1px solid #ddd; border-radius: 8px;");
    mainLayout->addWidget(summaryLabel);

    // Add a professionally styled back button
    QPushButton *backButton = new QPushButton("Retour");
    backButton->setStyleSheet(R"(
        QPushButton {
            background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                              stop:0 #2b7a78, stop:1 #3aafa9);
            color: white;
            font-weight: bold;
            padding: 10px 30px;
            border-radius: 12px;
            border: none;
            font-size: 11pt;
        }
        QPushButton:hover {
            background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                              stop:0 #3aafa9, stop:1 #2b7a78);
        }
        QPushButton:pressed {
            background-color: #2b7a78;
        }
    )");

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton);
    mainLayout->addLayout(buttonLayout);

    QObject::connect(backButton, &QPushButton::clicked, [stackedWidget]() {
        stackedWidget->setCurrentIndex(0); // Go back to first page
    });

    // Switch to the stats page
    stackedWidget->setCurrentIndex(1);
}

void Chercheur::generatePDF(const QString &filePath, QWidget *parent)
{
    if (filePath.isEmpty()) {
        return; // User cancelled
    }

    // Ensure .pdf extension
    QString finalFilePath = filePath;
    if (!finalFilePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        finalFilePath += ".pdf";
    }

    // Setup printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(finalFilePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(20, 20, 20, 15), QPageLayout::Millimeter);

    // Create document
    QTextDocument doc;
    doc.setDocumentMargin(10);
    QTextCursor cursor(&doc);

    // Add header
    QTextBlockFormat centerFormat;
    centerFormat.setAlignment(Qt::AlignCenter);
    QTextCharFormat headerFormat;
    headerFormat.setFont(QFont("Segoe UI", 20, QFont::Bold));
    headerFormat.setForeground(QColor(44, 62, 80));
    cursor.setBlockFormat(centerFormat);
    cursor.insertText("Chercheurs Report", headerFormat);
    cursor.insertBlock();
    cursor.insertBlock();

    // Create table
    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setBorderBrush(QBrush(QColor(208, 208, 208)));
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(6);
    tableFormat.setCellSpacing(0);
    tableFormat.setAlignment(Qt::AlignLeft);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

    // Get table data directly from database instead of table widget
    QList<Chercheur> chercheurs = afficher();

    // Create table with header
    QTextTable *table = cursor.insertTable(1, 7, tableFormat);

    // Header cells
    QStringList headers = {"ID", "Nom", "Prénom", "Email", "Téléphone", "Domaine", "Projet"};
    QTextTableCellFormat headerCellFormat;
    headerCellFormat.setBackground(QColor(44, 62, 80));
    headerCellFormat.setFont(QFont("Segoe UI", 10));
    headerCellFormat.setForeground(Qt::white);

    for (int i = 0; i < headers.size(); ++i) {
        QTextTableCell cell = table->cellAt(0, i);
        cell.setFormat(headerCellFormat);
        cell.firstCursorPosition().insertText(headers[i]);
    }

    // Add data rows
    QTextCharFormat cellFormat;
    cellFormat.setFont(QFont("Segoe UI", 9));
    cellFormat.setForeground(QColor(51, 51, 51));

    for (const Chercheur &c : chercheurs) {
        table->appendRows(1);
        int row = table->rows() - 1;

        // ID
        table->cellAt(row, 0).firstCursorPosition().insertText(QString::number(c.getId()));

        // Nom
        table->cellAt(row, 1).firstCursorPosition().insertText(c.getNom());

        // Prénom
        table->cellAt(row, 2).firstCursorPosition().insertText(c.getPrenom());

        // Email - ensure proper formatting
        QString email = c.getEmail();
        email = email.replace(" @", "@").replace("@ ", "@");
        table->cellAt(row, 3).firstCursorPosition().insertText(email);

        // Téléphone
        table->cellAt(row, 4).firstCursorPosition().insertText(QString::number(c.getNumTlp()));

        // Domaine
        table->cellAt(row, 5).firstCursorPosition().insertText(c.getDomaineRecherche());

        // Projet
        table->cellAt(row, 6).firstCursorPosition().insertText(c.getCurrentProject());
    }

    // Add footer
    cursor.movePosition(QTextCursor::End);
    cursor.insertBlock();
    QTextBlockFormat footerFormat;
    footerFormat.setAlignment(Qt::AlignRight);
    QTextCharFormat footerTextFormat;
    footerTextFormat.setFont(QFont("Segoe UI", 8));
    footerTextFormat.setForeground(QColor(150, 150, 150));
    cursor.setBlockFormat(footerFormat);
    cursor.insertText("Generated on " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"), footerTextFormat);

    // Generate PDF
    doc.print(&printer);

    // Open the generated file
    if (QFile::exists(finalFilePath)) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(finalFilePath));
    }
}

void Chercheur::initProjectJson()
{
    if (projet_en_cours.isEmpty() || !projet_en_cours.startsWith("{")) {
        // Initialize with proper JSON structure
        QJsonObject root;
        root["creation_date"] = QDateTime::currentDateTime().toString(Qt::ISODate);

        QJsonObject projects;
        projects["current"] = "";
        projects["history"] = QJsonArray();

        root["projects"] = projects;
        projet_en_cours = QJsonDocument(root).toJson(QJsonDocument::Compact);
    } else {
        // Clean existing JSON
        QJsonDocument doc = QJsonDocument::fromJson(projet_en_cours.toUtf8());
        QJsonObject root = doc.object();

        // Ensure creation date exists
        if (!root.contains("creation_date")) {
            root["creation_date"] = QDateTime::currentDateTime().toString(Qt::ISODate);
        }

        // Ensure projects structure exists
        if (!root.contains("projects")) {
            QJsonObject projects;
            projects["current"] = "";
            projects["history"] = QJsonArray();
            root["projects"] = projects;
        } else {
            QJsonObject projects = root["projects"].toObject();

            // Fix current project if it's nested JSON
            QString current = projects["current"].toString();
            if (current.startsWith("{")) {
                QJsonDocument nested = QJsonDocument::fromJson(current.toUtf8());
                if (nested.isObject()) {
                    projects["current"] = nested.object()["current"].toString();
                }
            }

            // Fix history entries
            QJsonArray history = projects["history"].toArray();
            for (int i = 0; i < history.size(); i++) {
                QJsonObject entry = history[i].toObject();
                if (entry["project"].toString().startsWith("{")) {
                    QJsonDocument nested = QJsonDocument::fromJson(entry["project"].toString().toUtf8());
                    if (nested.isObject()) {
                        entry["project"] = nested.object()["current"].toString();
                        history[i] = entry;
                    }
                }
            }
            projects["history"] = history;
            root["projects"] = projects;
        }

        projet_en_cours = QJsonDocument(root).toJson(QJsonDocument::Compact);
    }
}

void Chercheur::updateProjectHistory(const QString &newProject)
{
    initProjectJson(); // Ensure valid structure

    QJsonDocument doc = QJsonDocument::fromJson(projet_en_cours.toUtf8());
    QJsonObject root = doc.object();
    QJsonObject projects = root["projects"].toObject();

    QString currentProject = projects["current"].toString();
    QString cleanedNewProject = newProject.trimmed();

    // Only update if project actually changed
    if (currentProject != cleanedNewProject) {
        QJsonArray history = projects["history"].toArray();

        // Add current project to history before changing it
        if (!currentProject.isEmpty()) {
            QJsonObject historyEntry;
            historyEntry["date"] = QDateTime::currentDateTime().toString(Qt::ISODate);
            historyEntry["project"] = currentProject;
            history.prepend(historyEntry);

            // Keep only last 15 entries
            while (history.size() > 15) {
                history.removeLast();
            }
        }

        // Update current project
        projects["current"] = cleanedNewProject;
        projects["history"] = history;
        root["projects"] = projects;

        projet_en_cours = QJsonDocument(root).toJson(QJsonDocument::Compact);
    }
}

// Set the creation date in JSON data
void Chercheur::setCreationDate(const QString &date)
{
    QJsonDocument doc = QJsonDocument::fromJson(fullProjectJson.toUtf8());
    QJsonObject data = doc.object();
    data["creation_date"] = date;
    fullProjectJson = QJsonDocument(data).toJson();
}

// Get formatted history string for display


// Helper method to clean project names

QString Chercheur::getCurrentProject() const
{
    QJsonDocument doc = QJsonDocument::fromJson(projet_en_cours.toUtf8());
    if (doc.isNull()) return "Aucun projet";

    QJsonObject root = doc.object();
    if (!root.contains("projects")) return "Aucun projet";

    QJsonObject projects = root["projects"].toObject();
    QString project = projects["current"].toString();

    return cleanProjectName(project);
}
QString Chercheur::getFormattedHistory() const
{
    QJsonDocument doc = QJsonDocument::fromJson(projet_en_cours.toUtf8());
    if (doc.isNull()) return "Aucun historique disponible";

    QJsonObject root = doc.object();
    QString result;

    // Add creation date
    if (root.contains("creation_date")) {
        QDateTime created = QDateTime::fromString(root["creation_date"].toString(), Qt::ISODate);
        result += QString("🕒 Créé le: %1\n\n").arg(created.toString("dd/MM/yyyy HH:mm"));
    }

    // Add project history
    if (root.contains("projects")) {
        QJsonObject projects = root["projects"].toObject();
        QJsonArray history = projects["history"].toArray();

        if (!history.isEmpty()) {
            result += "📜 Historique des projets:\n";
            for (const QJsonValue &entry : history) {
                QJsonObject item = entry.toObject();
                QString date = QDateTime::fromString(item["date"].toString(), Qt::ISODate)
                                   .toString("dd/MM/yyyy");
                QString project = cleanProjectName(item["project"].toString());
                result += QString("• %1 - %2\n").arg(date, project);
            }
        }
    }

    return result.isEmpty() ? "Aucun historique disponible" : result;
}

QString Chercheur::cleanProjectName(const QString &project) const
{
    if (project.isEmpty() || project.compare("null", Qt::CaseInsensitive) == 0) {
        return "Aucun projet";
    }
    return project;
}

QString Chercheur::getCreationDate() const
{
    QJsonDocument doc = QJsonDocument::fromJson(fullProjectJson.toUtf8());
    if (doc.isNull() || !doc.object().contains("creation_date")) {
        return "Date inconnue";  // Return "Unknown date" if not found
    }
    return doc.object()["creation_date"].toString();
}
