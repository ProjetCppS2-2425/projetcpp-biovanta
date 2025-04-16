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
#include "mainwindow.h"  // Include MainWindow header to use MainWindow class

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
                       const QString &domaine_recherche, const QString &newProject) {

    if (!fetchDataById(id)) {
        qDebug() << "Failed to fetch researcher data";
        return false;
    }

    // This will store clean, non-nested data
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
    query.bindValue(":projet", projet_en_cours);  // Now contains clean JSON

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Chercheur> Chercheur::searchChercheur(const QString &searchTerm, const QString &filter) {
    QList<Chercheur> results;
    QSqlQuery query;

    QString sqlQuery = "SELECT * FROM CHERCHEUR WHERE ";
    if (filter == "Nom") {
        sqlQuery += "NOM LIKE :searchTerm";
    }
    else if (filter == "Email") {
        sqlQuery += "EMAIL LIKE :searchTerm";
    }
    else if (filter == "Projet En Cours") {
        // Use JSON_EXTRACT to search the "current" project in JSON
        sqlQuery += "json_extract(PROJET_EN_COURS, '$.current') LIKE :searchTerm";
    }
    else {
        // Default case if filter doesn't match
        sqlQuery += "(NOM LIKE :searchTerm OR EMAIL LIKE :searchTerm OR json_extract(PROJET_EN_COURS, '$.current') LIKE :searchTerm)";
    }

    query.prepare(sqlQuery);
    query.bindValue(":searchTerm", "%" + searchTerm + "%");

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
void Chercheur::afficherStatistiques(QStackedWidget *stackedWidget) // Change parameter to QStackedWidget
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

    // Get the second page of stacked widget
    QWidget *statsPage = stackedWidget->widget(1);

    // Clear existing widgets from the stats page
    QLayout *existingLayout = statsPage->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    // Create new layout for the stats page
    QVBoxLayout *mainLayout = new QVBoxLayout(statsPage);
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
    barSeries->setLabelsFormat("@value");

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

    // Add back button
    QPushButton *backButton = new QPushButton("Retour");
    backButton->setStyleSheet(R"(
        QPushButton {
            background-color: #2b7a78;
            color: white;
            font-weight: bold;
            padding: 10px 24px;
            border-radius: 8px;
            border: none;
        }
        QPushButton:hover {
            background-color: #3aafa9;
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

    // Setup printer with clean professional settings
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(finalFilePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(20, 20, 20, 15), QPageLayout::Millimeter);

    // Create document
    QTextDocument doc;
    doc.setDocumentMargin(10);
    QTextCursor cursor(&doc);

    // Add logo at the top, centered
    // Create a larger background area for the image
    QTextBlockFormat blockFormat;
    blockFormat.setAlignment(Qt::AlignCenter); // Center-align the image and its background

    // Create a larger block to represent the background width
    cursor.insertBlock(blockFormat);

    // Add a background color for the block (larger area)
    QTextCharFormat blockBgFormat;
    blockBgFormat.setBackground(QColor(44, 62, 80)); // Dark blue background from your style
    cursor.setCharFormat(blockBgFormat);

    // Insert the image (keeping it small)
    QTextImageFormat logoFormat;
    logoFormat.setName("C:/Users/nesri/Downloads/projet_c (3) (2)/projet_c/logo1.png");
    logoFormat.setWidth(80);  // Fixed width (small image size)
    logoFormat.setHeight(40);  // Fixed height (small image size)
    cursor.insertImage(logoFormat);
    cursor.insertBlock(); // Insert a block to finish the image line


    // Add BIOVANTA header
    QTextBlockFormat centerFormat;
    centerFormat.setAlignment(Qt::AlignCenter);
    QTextCharFormat headerFormat;
    headerFormat.setFont(QFont("Segoe UI", 20, QFont::Bold));
    headerFormat.setForeground(QColor(44, 62, 80)); // Dark blue from your style
    cursor.setBlockFormat(centerFormat);
    cursor.insertText("BIOVANTA", headerFormat);

    cursor.insertBlock();
    cursor.insertBlock();

    // Add title
    QTextCharFormat titleFormat;
    titleFormat.setFont(QFont("Segoe UI", 14, QFont::Bold));
    cursor.setBlockFormat(centerFormat);
    cursor.insertText("Liste des Chercheurs", titleFormat);

    cursor.insertBlock();
    cursor.insertBlock();

    // Create table matching your UI style
    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setBorderBrush(QBrush(QColor(208, 208, 208))); // #d0d0d0 from your style
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(6);
    tableFormat.setCellSpacing(0);
    tableFormat.setAlignment(Qt::AlignLeft);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

    QTextTable *table = cursor.insertTable(1, 7, tableFormat);

    // Add column headers with dark blue background
    QStringList headers = {"ID", "Nom", "Prénom", "Email", "Téléphone", "Domaine", "Projet"};
    QTextTableCellFormat headerCellFormat;
    headerCellFormat.setBackground(QColor(44, 62, 80)); // #2C3E50 from your style
    headerCellFormat.setFont(QFont("Segoe UI", 10));
    headerCellFormat.setForeground(Qt::white);
    headerCellFormat.setVerticalAlignment(QTextCharFormat::AlignMiddle);

    for (int i = 0; i < headers.size(); ++i) {
        QTextTableCell cell = table->cellAt(0, i);
        cell.setFormat(headerCellFormat);
        cell.firstCursorPosition().insertText(headers[i]);
    }

    // Add data rows with clean styling
    QTextCharFormat cellFormat;
    cellFormat.setFont(QFont("Segoe UI", 9));
    cellFormat.setForeground(QColor(51, 51, 51)); // #333 from your style

    QTableWidget *tableWidget = parent->findChild<QTableWidget*>();
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        table->appendRows(1);

        // Optional: Add special formatting for Histologie rows
        if (tableWidget->item(row, 5) && tableWidget->item(row, 5)->text().contains("Histologie")) {
            QTextTableCellFormat histoFormat;
            histoFormat.setBackground(QColor(240, 230, 255)); // #f0e6ff from your style
            histoFormat.setFont(QFont("Segoe UI", 9, QFont::Bold));
            for (int col = 0; col < 7; col++) {
                table->cellAt(row + 1, col).setFormat(histoFormat);
            }
        }

        for (int col = 0; col < 7; ++col) {
            QTableWidgetItem *item = tableWidget->item(row, col);
            QTextTableCell cell = table->cellAt(row + 1, col);
            cell.setFormat(cellFormat);

            QString text = item ? item->text() : "";
            if (col == 3) { // Fix email formatting
                text = text.replace(" @", "@").replace("@ ", "@");
            }
            cell.firstCursorPosition().insertText(text);
        }
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
    cursor.insertText("Généré le " + QDate::currentDate().toString("dd/MM/yyyy"), footerTextFormat);

    // Generate PDF
    doc.print(&printer);

    // Verify and open
    if (QFile::exists(finalFilePath)) {
        QMessageBox::information(parent, "Succès", QString("PDF généré avec succès!\n\nFichier: %1").arg(finalFilePath));
        QDesktopServices::openUrl(QUrl::fromLocalFile(finalFilePath));
    } else {
        QMessageBox::warning(parent, "Erreur", "Le fichier PDF n'a pas été créé.");
    }
}

void Chercheur::initProjectJson() {
    if (projet_en_cours.isEmpty() || !projet_en_cours.startsWith("{")) {
        // Create clean new structure
        QJsonObject json;
        json["current"] = "";
        json["history"] = QJsonArray();
        projet_en_cours = QJsonDocument(json).toJson(QJsonDocument::Compact);
        return;
    }

    // Clean existing structure
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(projet_en_cours.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError) return;

    QJsonObject json = doc.object();
    QString current = json["current"].toString();

    // Fix nested current project
    if (current.startsWith("{")) {
        QJsonDocument nested = QJsonDocument::fromJson(current.toUtf8());
        if (nested.isObject()) {
            json["current"] = nested.object()["current"].toString();
        } else {
            json["current"] = "";
        }
    }

    // Fix history entries
    QJsonArray history = json["history"].toArray();
    for (int i = 0; i < history.size(); i++) {
        QJsonObject item = history[i].toObject();
        QString project = item["project"].toString();
        if (project.startsWith("{")) {
            QJsonDocument nested = QJsonDocument::fromJson(project.toUtf8());
            if (nested.isObject()) {
                item["project"] = nested.object()["current"].toString();
                history[i] = item;
            }
        }
    }
    json["history"] = history;

    projet_en_cours = QJsonDocument(json).toJson(QJsonDocument::Compact);
}

void Chercheur::updateProjectHistory(const QString &newProject) {
    initProjectJson(); // Ensure clean structure

    QJsonDocument doc = QJsonDocument::fromJson(projet_en_cours.toUtf8());
    QJsonObject json = doc.object();
    QString current = cleanProjectName(json["current"].toString());

    if (current != newProject && !current.isEmpty()) {
        QJsonArray history = json["history"].toArray();

        history.prepend(QJsonObject{
            {"date", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")},
            {"project", current} // Store already cleaned name
        });

        // Keep last 10 entries
        while (history.size() > 10) history.removeLast();
        json["history"] = history;
    }

    json["current"] = newProject;
    projet_en_cours = QJsonDocument(json).toJson(QJsonDocument::Compact);
}
QString Chercheur::getCurrentProject() const {
    QJsonDocument doc = QJsonDocument::fromJson(projet_en_cours.toUtf8());
    return doc.object()["current"].toString();
}
QString Chercheur::getFormattedHistory() const {
    if (projet_en_cours.isEmpty()) {
        return "No history available";
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(projet_en_cours.toUtf8(), &error);

    if (error.error != QJsonParseError::NoError || !doc.isObject()) {
        return "Invalid project data";
    }

    QJsonObject json = doc.object();
    QString current = json["current"].toString();
    QJsonArray history = json["history"].toArray();

    QString result;
    result += "<b>Current Project:</b> " + cleanProjectName(current) + "<br><br>";
    result += "<b>History:</b>";

    for (const QJsonValue& item : history) {
        if (item.isObject()) {
            QJsonObject obj = item.toObject();
            result += QString("<br>• %1: %2")
                          .arg(obj["date"].toString())
                          .arg(cleanProjectName(obj["project"].toString()));
        }
    }

    return result;
}

QString Chercheur::cleanProjectName(const QString &project) const {
    if (project.isEmpty()) return "None";
    if (!project.startsWith("{")) return project;

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(project.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError && doc.isObject()) {
        QString clean = doc.object()["current"].toString();
        return clean.isEmpty() ? "Invalid" : clean;
    }
    return "Invalid";
}
