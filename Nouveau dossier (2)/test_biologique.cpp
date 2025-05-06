#include "test_biologique.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QTableWidget>  // Add this line
#include <QHeaderView>
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
#include <QtCharts>
#include <QSqlQuery>
#include <QMessageBox>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QPrinter>
#include <QTextTableCell>
#include <QTextDocument>
#include <QTextCursor>
class QChartView;
class QChart;
#include "test_biologique.h"
#include <QFileDialog>
#include <QPushButton>
#include <QSqlError>
#include <QDebug>
#include <QDesktopServices>  // Add this include at the top
#include <QUrl>
class MainWindow;
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
#include <QInputDialog>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QList>
#include <QFile>
#include <QTextDocument>
#include <QPrinter>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include "testbio.h"
TestBiologique::TestBiologique() {}

TestBiologique::TestBiologique(int id_test, QString nom, QString type, QString Chercheur_responsable, QDate date_pre) {
    this->id_test = id_test;
    this->nom = nom;
    this->type = type;
    this->Chercheur_responsable = Chercheur_responsable;
    this->date_pre = date_pre;
}

bool TestBiologique::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO TESTBIOLOGIQUE (NOM, TYPE, CHERCHEUR_RESPONSABLE, DATE_PRE) "
                  "VALUES (:nom, :type, :chercheur, TO_DATE(:date_pre, 'YYYY-MM-DD'))");

    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":chercheur", Chercheur_responsable);
    query.bindValue(":date_pre", date_pre.toString("yyyy-MM-dd"));

    if(!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<TestBiologique> TestBiologique::afficher() {
    QList<TestBiologique> testList;
    QSqlQuery query;
    query.prepare("SELECT * FROM TESTBIOLOGIQUE");

    if (!query.exec()) {
        qDebug() << "SQL Error (Fetch Tests): " << query.lastError().text();
        return testList;
    }

    while (query.next()) {
        int id_test = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString type = query.value(2).toString();
        QString Chercheur_responsable = query.value(3).toString();
        QDate date_pre = QDate::fromString(query.value(4).toString(), "yyyy-MM-dd");

        TestBiologique test(id_test, nom, type, Chercheur_responsable, date_pre);

        testList.append(test);
    }

    return testList;
}



bool TestBiologique::modifier(int id, const QString &nom, const QString &type,
                              const QString &chercheur, QDate date) {
    QSqlQuery query;
    query.prepare("UPDATE TESTBIOLOGIQUE SET "
                  "NOM = :nom, TYPE = :type, "
                  "CHERCHEUR_RESPONSABLE = :chercheur, DATE_PRE = :date "
                  "WHERE ID_TEST = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":chercheur", chercheur);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));

    return query.exec();
}


bool TestBiologique::fetchDataById(int id) {
    QSqlQuery query;
    query.prepare(
        "SELECT NOM, TYPE, CHERCHEUR_RESPONSABLE, DATE_PRE "
        "FROM TESTBIOLOGIQUE "
        "WHERE ID_TEST = :id"
        );
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "SQL Error in fetchDataById:" << query.lastError().text();
        return false;
    }

    if (query.next()) {  // If a record is found
        nom = query.value("NOM").toString();
        type = query.value("TYPE").toString();
        Chercheur_responsable = query.value("CHERCHEUR_RESPONSABLE").toString();
        date_pre = query.value("DATE_PRE").toDate();
        return true;
    }

    qDebug() << "No test found with ID:" << id;
    return false;  // No matching record
}
void TestBiologique::generatePDF(const QString &filePath, QWidget *parent)
{
    if (filePath.isEmpty()) {
        return; // User cancelled
    }

    // Ensure .pdf extension
    QString finalFilePath = filePath;
    if (!finalFilePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        finalFilePath += ".pdf";
    }

    // 2. Setup printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(finalFilePath);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(30, 30, 30, 30), QPageLayout::Millimeter);

    // 3. Create document
    QTextDocument doc;
    QTextCursor cursor(&doc);

    // 4. Add logo at the top, centered
    QTextImageFormat logoFormat;
    logoFormat.setName(":/images/logo.png"); // Use resource path
    cursor.insertImage(logoFormat);
    cursor.insertBlock();
    cursor.insertBlock();

    // 5. Add header with alignment
    QTextBlockFormat blockFormat;
    blockFormat.setAlignment(Qt::AlignCenter);

    QTextCharFormat headerFormat;
    headerFormat.setFont(QFont("Arial", 24, QFont::Bold));
    cursor.setBlockFormat(blockFormat);
    cursor.insertText("BIOVANTA", headerFormat);

    cursor.insertBlock();
    cursor.insertBlock();

    // 6. Add title - Liste des Chercheurs
    QTextCharFormat titleFormat;
    titleFormat.setFont(QFont("Arial", 18, QFont::Bold));
    cursor.setBlockFormat(blockFormat);
    cursor.insertText("Liste des Chercheurs", titleFormat);

    cursor.insertBlock();
    cursor.insertBlock();

    // 7. Add subtitle
    QTextCharFormat centerFormat;
    centerFormat.setFont(QFont("Arial", 14));
    cursor.setBlockFormat(blockFormat);
    cursor.insertText("Centre de Biologie", centerFormat);

    cursor.insertBlock();

    // 8. Create table with your attributes
    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(5);
    tableFormat.setCellSpacing(2);
    tableFormat.setAlignment(Qt::AlignLeft);

    QTextTable *table = cursor.insertTable(1, 5, tableFormat); // 5 columns for your attributes

    // 9. Add column headers
    QStringList headers = {"ID", "Nom", "Type", "Chercheur", "Date"};
    QTextTableCellFormat headerCellFormat;
    headerCellFormat.setFont(QFont("Arial", 12, QFont::Bold));
    headerCellFormat.setBackground(QColor(240, 240, 240));

    for (int i = 0; i < headers.size(); ++i) {
        QTextTableCell cell = table->cellAt(0, i);
        cell.setFormat(headerCellFormat);
        cell.firstCursorPosition().insertText(headers[i]);
    }

    // 10. Add data rows with your attributes
    QTextCharFormat cellFormat;
    cellFormat.setFont(QFont("Arial", 10));

    QTableWidget *tableWidget = parent->findChild<QTableWidget *>(QString(), Qt::FindChildrenRecursively);
    if (tableWidget) {
        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            table->appendRows(1);

            // ID
            QTextTableCell idCell = table->cellAt(row + 1, 0);
            idCell.setFormat(cellFormat);
            idCell.firstCursorPosition().insertText(tableWidget->item(row, 0) ? tableWidget->item(row, 0)->text() : "");

            // Nom
            QTextTableCell nomCell = table->cellAt(row + 1, 1);
            nomCell.setFormat(cellFormat);
            nomCell.firstCursorPosition().insertText(tableWidget->item(row, 1) ? tableWidget->item(row, 1)->text() : "");

            // Type
            QTextTableCell typeCell = table->cellAt(row + 1, 2);
            typeCell.setFormat(cellFormat);
            typeCell.firstCursorPosition().insertText(tableWidget->item(row, 2) ? tableWidget->item(row, 2)->text() : "");

            // Chercheur
            QTextTableCell chercheurCell = table->cellAt(row + 1, 3);
            chercheurCell.setFormat(cellFormat);
            chercheurCell.firstCursorPosition().insertText(tableWidget->item(row, 3) ? tableWidget->item(row, 3)->text() : "");

            // Date
            QTextTableCell dateCell = table->cellAt(row + 1, 4);
            dateCell.setFormat(cellFormat);
            dateCell.firstCursorPosition().insertText(tableWidget->item(row, 4) ? tableWidget->item(row, 4)->text() : "");
        }
    }

    // 11. Add footer with generation date
    cursor.movePosition(QTextCursor::End);
    blockFormat.setAlignment(Qt::AlignCenter);
    QTextCharFormat footerFormat;
    footerFormat.setFont(QFont("Arial", 10));
    cursor.setBlockFormat(blockFormat);
    cursor.insertText("\n\nGénéré le " + QDate::currentDate().toString("dd/MM/yyyy"), footerFormat);

    // 12. Generate PDF
    doc.print(&printer);

    // 13. Verify and open the PDF
    if (QFile::exists(finalFilePath)) {
        QMessageBox::information(parent, "Succès", QString("PDF généré avec succès!\n\nFichier: %1").arg(finalFilePath));
        QDesktopServices::openUrl(QUrl::fromLocalFile(finalFilePath));
    } else {
        QMessageBox::warning(parent, "Erreur", "Le fichier PDF n'a pas été créé.");
    }
}
void TestBiologique::afficherStatistiques(QStackedWidget *stackedWidget)
{
    // Database query
    QSqlQuery query;
    query.prepare("SELECT TYPE, COUNT(*) FROM TESTBIOLOGIQUE GROUP BY TYPE");
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Database error: " + query.lastError().text());
        return;
    }

    // Process data
    QMap<QString, int> testData;
    int total = 0;
    int maxCount = 0;
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        testData.insert(type, count);
        total += count;
        maxCount = qMax(maxCount, count);
    }

    // Stats page container
    QWidget *statsPage = new QWidget();
    statsPage->setStyleSheet("background-color: #FFFFFF; border-radius: 15px; padding: 20px;");
    QVBoxLayout *mainLayout = new QVBoxLayout(statsPage);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Pie Chart
    QPieSeries *pieSeries = new QPieSeries();
    pieSeries->setPieSize(0.6);
    QStringList blueShades = {"#1E88E5", "#42A5F5", "#64B5F6", "#90CAF9", "#BBDEFB"};
    int idx = 0;
    for (auto it = testData.begin(); it != testData.end(); ++it, ++idx) {
        int count = it.value();
        double perc = (count * 100.0) / total;
        QPieSlice *slice = pieSeries->append(it.key(), count);
        slice->setLabel(QString("%1 (%2%)").arg(it.key()).arg(perc, 0, 'f', 1));
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setColor(QColor(blueShades[idx % blueShades.size()]));
        slice->setExploded(true);
        slice->setExplodeDistanceFactor(0.05);
    }
    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Test Distribution by Type");
    pieChart->legend()->setAlignment(Qt::AlignRight);
    pieChart->setAnimationOptions(QChart::SeriesAnimations);
    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);
    pieChartView->setMinimumSize(400, 300);

    // Bar Chart with explicit axes
    QBarSeries *barSeries = new QBarSeries();
    QBarSet *barSet = new QBarSet("Count");
    QStringList categories;
    for (auto it = testData.begin(); it != testData.end(); ++it) {
        *barSet << it.value();
        categories << it.key();
    }
    barSet->setColor(QColor("#1565C0"));
    barSeries->append(barSet);

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Counts by Type");
    barChart->setAnimationOptions(QChart::SeriesAnimations);
    barChart->legend()->setVisible(false);

    // Create and attach category axis for X
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    // Create and attach value axis for Y
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxCount + 1);
    axisY->setTitleText("Count");
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    barChartView->setMinimumSize(400, 300);

    // Layout both charts side by side
    QHBoxLayout *chartsLayout = new QHBoxLayout();
    chartsLayout->addWidget(pieChartView, 1);
    chartsLayout->addWidget(barChartView, 1);
    chartsLayout->setSpacing(30);
    mainLayout->addLayout(chartsLayout);

    // Summary Table
    QTableWidget *summaryTable = new QTableWidget();
    summaryTable->setColumnCount(3);
    summaryTable->setHorizontalHeaderLabels({"Test Type", "Count", "Percentage"});
    summaryTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    summaryTable->setRowCount(testData.size());
    summaryTable->setStyleSheet(
        "QTableWidget { background-color: #FAFAFA; border-radius: 10px; }"
        "QHeaderView::section { background-color: #1E88E5; color: white; padding:8px; }"
        );
    int row = 0;
    for (auto it = testData.begin(); it != testData.end(); ++it) {
        int count = it.value();
        double perc = (count * 100.0) / total;
        summaryTable->setItem(row, 0, new QTableWidgetItem(it.key()));
        summaryTable->setItem(row, 1, new QTableWidgetItem(QString::number(count)));
        summaryTable->setItem(row, 2, new QTableWidgetItem(QString::number(perc, 'f', 1) + "%"));
        for (int col = 0; col < 3; ++col)
            summaryTable->item(row, col)->setTextAlignment(Qt::AlignCenter);
        row++;
    }
    summaryTable->setFixedHeight(200);
    mainLayout->addWidget(summaryTable, 0, Qt::AlignTop);

    // Back Button
    QPushButton *backButton = new QPushButton("Back to List");
    backButton->setCursor(Qt::PointingHandCursor);
    backButton->setFixedHeight(36);
    backButton->setStyleSheet(
        "QPushButton { background-color: #1E88E5; color: white; border-radius:18px; font-size:11pt; padding:0 18px; }"
        "QPushButton:hover { background-color: #42A5F5; }"
        );

    // Fade-in animation
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(statsPage);
    statsPage->setGraphicsEffect(effect);
    QPropertyAnimation *anim = new QPropertyAnimation(effect, "opacity");
    anim->setDuration(600);
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->start(QAbstractAnimation::DeleteWhenStopped);

    mainLayout->addWidget(backButton, 0, Qt::AlignRight);

    // Insert into stacked widget
    if (stackedWidget->count() > 1) {
        delete stackedWidget->widget(1);
        stackedWidget->insertWidget(1, statsPage);
    } else {
        stackedWidget->addWidget(statsPage);
    }

    QAbstractAnimation::connect(backButton, &QPushButton::clicked, [stackedWidget]() {
        stackedWidget->setCurrentIndex(0);
    });

    stackedWidget->setCurrentIndex(1);
}

QList<TestBiologique> TestBiologique::searchByIdNameType(
    const QString &searchTerm,
    const QString &filterField)
{
    QList<TestBiologique> results;
    QString term = searchTerm.trimmed();
    if (term.isEmpty()) {
        qDebug() << "[search] terme vide";
        return results;
    }

    // Vérifie la connexion
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "[search] BDD fermée";
        return results;
    }

    QSqlQuery query;
    QString sql;
    QString upTerm = term.toUpper();
    QString wildcard = "%" + upTerm + "%";

    // 1) Selon le filtre, on construit la bonne requête
    if (filterField.compare("ID", Qt::CaseInsensitive) == 0) {
        bool ok; int id = term.toInt(&ok);
        if (!ok) {
            qDebug() << "[search] ID invalide :" << term;
            return results;
        }
        sql = R"(
            SELECT ID_TEST, NOM, TYPE, CHERCHEUR_RESPONSABLE, DATE_PRE
              FROM TESTBIOLOGIQUE
             WHERE ID_TEST = ?
        )";
        query.prepare(sql);
        query.addBindValue(id);
    }
    else if (filterField.compare("Nom", Qt::CaseInsensitive) == 0) {
        sql = R"(
            SELECT ID_TEST, NOM, TYPE, CHERCHEUR_RESPONSABLE, DATE_PRE
              FROM TESTBIOLOGIQUE
             WHERE UPPER(NOM) LIKE ?
        )";
        query.prepare(sql);
        query.addBindValue(wildcard);
    }
    else if (filterField.compare("Type", Qt::CaseInsensitive) == 0) {
        sql = R"(
            SELECT ID_TEST, NOM, TYPE, CHERCHEUR_RESPONSABLE, DATE_PRE
              FROM TESTBIOLOGIQUE
             WHERE UPPER(TYPE) LIKE ?
        )";
        query.prepare(sql);
        query.addBindValue(wildcard);
    }
    else {
        // Recherche globale sur ID, Nom et Type
        sql = R"(
            SELECT ID_TEST, NOM, TYPE, CHERCHEUR_RESPONSABLE, DATE_PRE
              FROM TESTBIOLOGIQUE
             WHERE ID_TEST = ?
               OR UPPER(NOM) LIKE ?
               OR UPPER(TYPE) LIKE ?
        )";
        query.prepare(sql);
        bool ok; int id = term.toInt(&ok);
        query.addBindValue(ok ? id : -1);
        query.addBindValue(wildcard);
        query.addBindValue(wildcard);
    }

    // Debug rapide
    qDebug() << "[search] SQL =" << query.lastQuery();
    qDebug() << "[search] binds =" << query.boundValues();

    // Exécution
    if (!query.exec()) {
        qDebug() << "[search] Erreur exec :" << query.lastError().text();
        return results;
    }

    // Lecture et conversion
    while (query.next()) {
        QString dateStr = query.value("DATE_PRE").toString();
        QDate   date   = QDate::fromString(dateStr, "yyyy-MM-dd");
        results.append(TestBiologique(
            query.value("ID_TEST").toInt(),
            query.value("NOM").toString(),
            query.value("TYPE").toString(),
            query.value("CHERCHEUR_RESPONSABLE").toString(),
            date.isValid() ? date : QDate::currentDate()
            ));
    }

    qDebug() << "[search] trouvés" << results.size() << "résultats";
    return results;
}

QList<TestBiologique> TestBiologique::rechercherTests(const QString& terme, const QString& filtre) {
    QList<TestBiologique> resultats;
    QSqlQuery requete;
    QString requeteStr;

    if (filtre == "ID") {
        bool ok;
        int id = terme.toInt(&ok);
        if (!ok) return resultats;

        requeteStr = "SELECT * FROM TESTBIOLOGIQUE WHERE ID_TEST = :id";
        requete.prepare(requeteStr);
        requete.bindValue(":id", id);
    }
    else if (filtre == "NOM") {
        requeteStr = "SELECT * FROM TESTBIOLOGIQUE WHERE NOM LIKE :terme";
        requete.prepare(requeteStr);
        requete.bindValue(":terme", "%" + terme + "%");
    }
    else if (filtre == "TYPE") {
        requeteStr = "SELECT * FROM TESTBIOLOGIQUE WHERE TYPE LIKE :terme";
        requete.prepare(requeteStr);
        requete.bindValue(":terme", "%" + terme + "%");
    }
    else {
        return resultats;
    }

    if (!requete.exec()) {
        qDebug() << "Erreur recherche:" << requete.lastError().text();
        return resultats;
    }

    while (requete.next()) {
        resultats.append(TestBiologique(
            requete.value("ID_TEST").toInt(),
            requete.value("NOM").toString(),
            requete.value("TYPE").toString(),
            requete.value("CHERCHEUR_RESPONSABLE").toString(),
            QDate::fromString(requete.value("DATE_PRE").toString(), "yyyy-MM-dd") // Convert string to QDate
            ));
    }
    return resultats;
}
void TestBiologique::afficherResultats(const QList<TestBiologique>& resultats, QTableWidget* table) {
    table->setRowCount(0);
    table->setColumnCount(5); // Match your 5 columns

    // Set column headers
    QStringList headers = {"ID Test", "Nom", "Type", "Chercheur", "Date"};
    table->setHorizontalHeaderLabels(headers);

    for (const TestBiologique& test : resultats) {
        int ligne = table->rowCount();
        table->insertRow(ligne);

        // Use all getter methods
        table->setItem(ligne, 0, new QTableWidgetItem(QString::number(test.getIdTest())));
        table->setItem(ligne, 1, new QTableWidgetItem(test.getNom()));
        table->setItem(ligne, 2, new QTableWidgetItem(test.getType()));
        table->setItem(ligne, 3, new QTableWidgetItem(test.getChercheur_responsable()));
        table->setItem(ligne, 4, new QTableWidgetItem(test.getDatePre().toString("dd/MM/yyyy")));
    }
}
bool TestBiologique::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM TESTBIOLOGIQUE WHERE ID_TEST = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text();
        return false;
    }
    return true;
}
