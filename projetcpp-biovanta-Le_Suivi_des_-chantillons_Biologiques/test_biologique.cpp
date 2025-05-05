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
#include "mainwindow.h"
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
void TestBiologique::afficherStatistiques(QWidget *parent)
{
    QSqlQuery query;
    query.prepare("SELECT TYPE, COUNT(*) FROM TESTBIOLOGIQUE GROUP BY TYPE");

    if (!query.exec()) {
        QMessageBox::critical(parent, "Erreur", "Erreur de base de données: " + query.lastError().text());
        return;
    }

    QMap<QString, int> typeData;
    int total = 0;
    QVector<QColor> biologyPalette = {
        QColor(34, 193, 195),  // Bleu-vert
        QColor(253, 187, 45),   // Jaune
        QColor(40, 167, 69),    // Vert
        QColor(0, 123, 255),    // Bleu
        QColor(255, 123, 123),  // Rouge clair
        QColor(0, 204, 255)     // Cyan
    };

    while (query.next()) {
        typeData.insert(query.value(0).toString(), query.value(1).toInt());
        total += query.value(1).toInt();
    }

    QDialog statsDialog(parent);
    statsDialog.setWindowTitle("🔬 Statistiques des Tests Biologiques");
    statsDialog.setMinimumSize(980, 750);
    statsDialog.setStyleSheet(
        "QDialog { background: #f5f8fa; border-radius: 12px; padding: 15px; border: 2px solid #e2e8f0; }"
        "QLabel { color: #2d3748; font-size: 14px; font-weight: bold; }"
        );

    QVBoxLayout *mainLayout = new QVBoxLayout(&statsDialog);
    QTabWidget *tabs = new QTabWidget(&statsDialog);
    tabs->setStyleSheet(
        "QTabWidget::pane { border: none; }"
        "QTabBar::tab { background: #e2f7f2; color: #2d3748; padding: 12px 20px; border-radius: 8px; }"
        "QTabBar::tab:selected { background: #34c7c2; color: white; }"
        "QTabWidget { border-radius: 8px; }"
        );

    // 1. Diagramme Circulaire
    QPieSeries *pieSeries = new QPieSeries();
    pieSeries->setPieSize(0.75);
    int colorIndex = 0;

    for (const QString &type : typeData.keys()) { qreal percentage =
            (typeData[type] * 100.0) / total; QPieSlice *slice =
            pieSeries->append(type, typeData[type]);
        slice->setColor(biologyPalette[colorIndex % biologyPalette.size()]);
        slice->setLabelVisible(true); slice->setLabel(QString("%1\n%2 tests (%3%)")
                            .arg(type) .arg(typeData[type]) .arg(percentage, 0, 'f', 1));
        slice->setBorderWidth(1); slice->setBorderColor(Qt::white); colorIndex++;
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition des Types de Tests Biologiques");
    pieChart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));
    pieChart->legend()->setAlignment(Qt::AlignRight);
    pieChart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);
    pieChartView->setStyleSheet("border-radius: 8px; border: 1px solid #d1d9e6; background: white;");
    tabs->addTab(pieChartView, "🧪 Vue Globale");

    // 2. Diagramme en Barres
    QBarSeries *barSeries = new QBarSeries();
    QBarSet *barSet = new QBarSet("Tests");
    barSet->setColor(QColor(34, 193, 195));

    QStringList categories;
    for (const QString &type : typeData.keys()) {
        *barSet << typeData[type];
        categories << type;
    }

    barSeries->append(barSet);
    barSeries->setLabelsVisible(true);
    barSeries->setLabelsFormat("@value");

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Analyse Quantitative des Tests Biologiques");
    barChart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));

    QBarCategoryAxis *xAxis = new QBarCategoryAxis();
    xAxis->append(categories);
    barChart->addAxis(xAxis, Qt::AlignBottom);
    barSeries->attachAxis(xAxis);

    QValueAxis *yAxis = new QValueAxis();
    yAxis->setLabelFormat("%d");
    barChart->addAxis(yAxis, Qt::AlignLeft);
    barSeries->attachAxis(yAxis);

    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    barChartView->setStyleSheet("border-radius: 8px; border: 1px solid #d1d9e6; background: white;");
    tabs->addTab(barChartView, "📊 Analyse Comparée");

    mainLayout->addWidget(tabs);

    // Bouton de fermeture
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *closeButton = new QPushButton("❌ Fermer");

    QObject::connect(closeButton, &QPushButton::clicked, &statsDialog, &QDialog::accept);
    buttonLayout->addWidget(closeButton);
    buttonLayout->setAlignment(Qt::AlignRight);
    mainLayout->addLayout(buttonLayout);

    statsDialog.exec();
}
QList<TestBiologique> TestBiologique::searchByIdNameType(const QString &searchTerm, const QString &filterField)
{
    QList<TestBiologique> results;
    QSqlQuery query;
    QString queryStr;

    if (filterField == "ID") {
        bool ok;
        int id = searchTerm.toInt(&ok);
        if (!ok) return results;

        queryStr = "SELECT * FROM TESTBIOLOGIQUE WHERE ID_TEST = :id";
        query.prepare(queryStr);
        query.bindValue(":id", id);
    }
    else if (filterField == "NOM") {
        queryStr = "SELECT * FROM TESTBIOLOGIQUE WHERE NOM LIKE :term";
        query.prepare(queryStr);
        query.bindValue(":term", "%" + searchTerm + "%");
    }
    else if (filterField == "TYPE") {
        queryStr = "SELECT * FROM TESTBIOLOGIQUE WHERE TYPE LIKE :term";
        query.prepare(queryStr);
        query.bindValue(":term", "%" + searchTerm + "%");
    }
    else {
        return results;
    }

    if (!query.exec()) {
        qDebug() << "Erreur de recherche:" << query.lastError().text();
        return results;
    }

    while (query.next()) {
        results.append(TestBiologique(
            query.value("ID_TEST").toInt(),
            query.value("NOM").toString(),
            query.value("TYPE").toString(),
            query.value("CHERCHEUR_RESPONSABLE").toString(),
            query.value("DATE_PRE").toDate()
            ));
    }

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
