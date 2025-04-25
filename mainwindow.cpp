#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QCryptographicHash>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QByteArray>
#include <QEventLoop>
#include <QSslConfiguration>
#include <QAuthenticator>
#include <QIODevice>
#include <QRandomGenerator>
#include <QDateTime>
#include <QIcon>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTableWidgetItem>
#include <QTextDocument>
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QRandomGenerator>
#include <QDateTime>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QSqlError>
#include <QtCharts>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QPushButton>
#include <QSqlQuery>
#include <QFont>
#include <QColor>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QAbstractItemModel>
#include <QMarginsF>
#include <QDate>
#include <QDateTime>
#include <QHeaderView>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QRandomGenerator>
#include <QDateTime>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
    QStringList headers;
    headers << "ID" << "Nom" << "Prénom" << "Email" << "Téléphone"
            << "Date Embauche" << "Poste" << "Salaire" << "Mot de passe";
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);  // Select full rows
    ui->table->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->logo->setPixmap(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\bg.jpg"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\logout.png"));
    ui->logo->setPixmap(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\logo1.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\empe.png"));
    ui->chercheur->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\cher.png"));
    ui->pdfEmployes->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\client.png"));
    ui->stat->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\st.png"));
    ui->logo1->setPixmap(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\logo2.png"));
    //ui->rechercheButton->setIcon(QPixmap("C:\\Users\\litai\\OneDrive\\Documents\\application\\assets\\search.png"));
    ui->table->setColumnCount(headers.size());
    ui->table->setHorizontalHeaderLabels(headers);
    connect(ui->stat, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesEmployes);
    connect(ui->pdfEmployes, &QPushButton::clicked, this, &MainWindow::on_pdfEmployes_clicked);
    currentSortColumn = "DATE_EMBAUCHE";
    currentSortOrder = "ASC";
    ui->tri->addItem("Date d'embauche ▲", "DATE_EMBAUCHE ASC");
    ui->tri->addItem("Date d'embauche ▼", "DATE_EMBAUCHE DESC");
    ui->tri->addItem("Salaire croissant", "SALAIRE ASC");
    ui->tri->addItem("Salaire décroissant", "SALAIRE DESC");
    ui->tri->addItem("Nom A-Z", "NOM ASC");
    ui->tri->addItem("Nom Z-A", "NOM DESC");
    ui->re->addItem("Nom");
    ui->re->addItem("Poste");
    ui->re->addItem("ID");
    connect(ui->quit, &QPushButton::clicked, this, &MainWindow::on_quitButton_clicked);
    connect(ui->rechercher, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    QPushButton *connectionButton = ui->stackedWidget->findChild<QPushButton*>("connectionButton");
    if (connectionButton) {
        connect(connectionButton, &QPushButton::clicked, this, &MainWindow::verifyLoginAndSwitchPage);
        qDebug() << "connectionButton signal connected to verifyLoginAndSwitchPage.";
    } else {
        qDebug() << "Error: connectionButton not found in the UI!";
    }

    ui->stackedWidget->setCurrentIndex(1);
setupForgotPasswordPage();    // Start on the login page
    mdpOubTentativesMap = QMap<QString, int>();
    mdpOubBlocageMap = QMap<QString, QDateTime>();
    // Connect signal
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onTriComboBoxChanged);
    refreshEmployeeTable();


    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données !");
    }
}

void MainWindow::verifyLoginAndSwitchPage()
{
    QString email = ui->emailline->text().trimmed(); // Assuming your email QLineEdit is named 'emailline'
    QString password = ui->mdpline->text();       // Assuming your password QLineEdit is named 'mdpline'

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre email et votre mot de passe.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT ID FROM EMPLOYE WHERE EMAIL = :email AND MDP = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (query.exec()) {
        if (query.next()) {
            // Login successful, switch to the next page (assuming index 1)
            ui->stackedWidget->setCurrentIndex(0);
            qDebug() << "Login successful. Switched to page index 1.";
            // Optionally, you can store the logged-in user's ID or other information here
        } else {
            // Login failed
            QMessageBox::critical(this, "Erreur de Connexion", "Email ou mot de passe incorrect.");
            qDebug() << "Login failed: Incorrect email or password.";
        }
    } else {
        QMessageBox::critical(this, "Erreur de base de données", "Erreur lors de l'exécution de la requête: " + query.lastError().text());
        qDebug() << "Database error:" << query.lastError().text();
    }
}

// You might still have a separate switchToPage2() slot if needed for other purposes
void MainWindow::switchToPage2()
{
    ui->stackedWidget->setCurrentIndex(1);
    qDebug() << "switchToPage2() called (for other reasons). Current index:" << ui->stackedWidget->currentIndex();
}
void MainWindow::refreshEmployeeTable()
{
    // Clear existing data
    ui->table->setRowCount(0);

    QSqlQuery query;

    // FIXED: Proper string declaration and formatting
    QString queryString =
        "SELECT ID, NOM, PRENOM, EMAIL, NUM_TLP, "
        "TO_CHAR(DATE_EMBAUCHE, 'DD-MM-YYYY') AS DATE_EMBAUCHE, "
        "POSTE, SALAIRE, MDP FROM EMPLOYE "
        "ORDER BY %1 %2";  // Sorting placeholders

    query.prepare(queryString.arg(currentSortColumn, currentSortOrder));

    if(!query.exec()) {
        qDebug() << "Refresh Error:" << query.lastError().text();
        return;
    }

    // ... rest of your existing population code ...
    int row = 0;
    while(query.next()) {
        ui->table->insertRow(row);

        for(int col = 0; col < 9; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());

            // Format numeric columns
            if(col == 0 || col == 4 || col == 7) {
                item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            }

            ui->table->setItem(row, col, item);
        }
        row++;
    }
}

void MainWindow::on_valider_clicked()
{
        qDebug() << "Bouton Valider cliqué !";

        // Récupération des données du formulaire pour Employé
        int id = ui->ID->text().toInt();
        QString email = ui->Email->text().trimmed();
        QString nom = ui->Nom->text().trimmed();
        int telephone = ui->Telephone->text().toInt();
        QDate dateEmbauche = ui->date->date();
        QString prenom = ui->prenom->text().trimmed();
        int salaire = ui->salaire->text().toInt();
        QString poste = ui->poste->currentText().trimmed();
        QString mdp = ui->mdp->text().trimmed();
        // Affecter des valeurs par défaut pour les champs non présents dans l'UI



        qDebug() << "ID récupéré:" << id;

        // Vérification des champs obligatoires (email, nom, telephone et prenom)
        if (email.isEmpty() || nom.isEmpty() ||  prenom.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
            return;
        }

        // Création de l'objet Employé avec les données récupérées
        Employe emp(id, nom, prenom, email, telephone, dateEmbauche, poste, salaire, mdp);

        // Mode modification si un ID > 0 est présent
        if (id > 0) {
            qDebug() << "Mode modification - ID:" << id;
            emp.setId(id);
           bool test = emp.modifier();
            if (test) {
                QMessageBox::information(this, "Succès", "Modification effectuée avec succès !");
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la modification !");
                qDebug() << "Erreur: Modification non effectuée.";
                return;
            }
        }
        // Mode ajout si l'ID est 0 (aucun ID fourni)
        else {
        bool test = emp.ajouter();
        if (test) {
            QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout !");
            qDebug() << "Erreur: Ajout non effectué.";
            return;
        }


       /* // Rafraîchissement du tableau des employés (tableView_Employe)
        QTableWidget *model = qobject_cast<QTableWidget*>(ui->table->model());
        if (model) {
            model->setTable("EMPLOYE");
            model->select();
            qDebug() << "Table EMPLOYE rafraîchie avec succès.";
        } else {
            qDebug() << "Erreur : Impossible de caster le modèle en QSqlTableModel.";
        }*/
            QSqlQuery query;
            query.prepare("SELECT * FROM EMPLOYE");
            if (!query.exec()) {
                qDebug() << "Erreur lors de l'exécution de la requête d'affichage:" << query.lastError();
            } else {
                ui->table->clearContents();
                ui->table->setRowCount(0);
                int row = 0;
                 connect(ui->annuler, &QPushButton::clicked, this, &MainWindow::on_annuler_clicked);
                while (query.next()) {
                    ui->table->insertRow(row);
                    // Assurez-vous que l'ordre des colonnes correspond à votre table EMPLOYE
                    ui->table->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
                    ui->table->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
                    ui->table->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
                    ui->table->setItem(row, 3, new QTableWidgetItem(query.value("EMAIL").toString()));
                    ui->table->setItem(row, 4, new QTableWidgetItem(query.value("NUM_TLP").toString()));
                    ui->table->setItem(row, 5, new QTableWidgetItem(query.value("DATE_EMBAUCHE").toDate().toString("yyyy-MM-dd")));
                    ui->table->setItem(row, 6, new QTableWidgetItem(query.value("POSTE").toString()));
                    ui->table->setItem(row, 7, new QTableWidgetItem(query.value("SALAIRE").toString()));
                    ui->table->setItem(row, 8, new QTableWidgetItem(query.value("MDP").toString()));
                    row++;
                }
                qDebug() << "Table EMPLOYE rafraîchie avec succès.";
                // Remove the old code that uses QSqlTableModel and replace it with:

                QSqlQueryModel *model = new QSqlQueryModel();
                model->setQuery("SELECT ID, NOM, PRENOM, EMAIL, NUM_TLP, DATE_EMBAUCHE, POSTE, SALAIRE, MDP FROM EMPLOYE");

                if (model->lastError().isValid()) {
                    qDebug() << "Query Error:" << model->lastError().text();
                    return;
                }

                // Clear existing content
                ui->table->clearContents();
                ui->table->setRowCount(0);

                // Set column headers
                QStringList headers;
                headers << "ID" << "Nom" << "Prénom" << "Email" << "Téléphone"
                        << "Date Embauche" << "Poste" << "Salaire" << "Mot de passe";
                ui->table->setColumnCount(headers.size());
                ui->table->setHorizontalHeaderLabels(headers);

                // Populate the table widget
                for (int row = 0; row < model->rowCount(); ++row) {
                    ui->table->insertRow(row);
                    for (int col = 0; col < model->columnCount(); ++col) {
                        QTableWidgetItem *item = new QTableWidgetItem(
                            model->data(model->index(row, col)).toString()
                            );

                        // Format date column
                        if (col == 5) { // DATE_EMBAUCHE is 6th column (index 5)
                            QDate date = model->data(model->index(row, col)).toDate();
                            item->setText(date.toString("dd-MM-yyyy"));
                        }

                        ui->table->setItem(row, col, item);
                    }
                }

                qDebug() << "Table EMPLOYE rafraîchie avec" << model->rowCount() << "lignes";
            }
            if (test) {
                QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
                refreshEmployeeTable(); // Refresh the table after insertion
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de l'ajout !");
            }

}
        }
void MainWindow::on_supprimer_clicked()
{
    Employe emp;
    QString idText = ui->ID->text();

    if (idText.isEmpty()) {
        QMessageBox::warning(this, tr("Champ vide"),
                             tr("Veuillez entrer un ID valide avant de supprimer."),
                             QMessageBox::Ok);
        return;
    }

    int id = idText.toInt();
    bool test = emp.supprimer(id);  // Use your Employe class's supprimer() method

    if (test) {
        QMessageBox::information(this, tr("Succès"),
                                 tr("Suppression effectuée.\nCliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
        ui->ID->clear();
        refreshEmployeeTable();  // Refresh your table widget showing employees
    } else {
        QMessageBox::critical(this, tr("Échec"),
                              tr("La suppression a échoué.\nVérifiez l'ID et réessayez."),
                              QMessageBox::Cancel);
        ui->ID->clear();
    }
}


void MainWindow::on_modifier_clicked()
{
    // Get selected row
    int currentRow = ui->table->currentRow();
    if(currentRow < 0) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un employé à modifier!");
        return;
    }

    // Get ID from selected row
    int id = ui->table->item(currentRow, 0)->text().toInt();

    // Create employee object with existing data
    Employe emp;
    emp.setId(id);
    emp.setNom(ui->table->item(currentRow, 1)->text());
    emp.setPrenom(ui->table->item(currentRow, 2)->text());
    emp.setEmail(ui->table->item(currentRow, 3)->text());
    emp.setNumTel(ui->table->item(currentRow, 4)->text().toLongLong());
    emp.setDateEmbauche(QDate::fromString(ui->table->item(currentRow, 5)->text(), "dd-MM-yyyy"));
    emp.setposte(ui->table->item(currentRow, 6)->text());
    emp.setSalaire(ui->table->item(currentRow, 7)->text().toDouble());
    emp.setMdp(ui->table->item(currentRow, 8)->text());

    // Open edit dialog or populate existing UI fields
    // Assuming you have input fields similar to your "ajouter" interface
    ui->ID->setText(QString::number(emp.getId()));
    ui->Nom->setText(emp.getNom());
    ui->prenom->setText(emp.getPrenom());
    ui->Email->setText(emp.getEmail());
    ui->Telephone->setText(QString::number(emp.getNumTel()));
    ui->date->setDate(emp.getDateEmbauche());
    ui->poste->setCurrentText(emp.getposte());
    ui->salaire->setText(QString::number(emp.getSalaire()));
    ui->mdp->setText(emp.getMdp());
}

void MainWindow::on_modification_clicked()
{
    // NEW: More reliable row detection
    int currentRow = ui->table->currentRow();
    if(currentRow < 0) {
        QMessageBox::warning(this, "Erreur", "Aucun employé sélectionné !");
        return;
    }

    // NEW: Verify ID exists
    if(!ui->table->item(currentRow, 0) || ui->table->item(currentRow, 0)->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }

    int originalId = ui->table->item(currentRow, 0)->text().toInt();

    // NEW: Validate all critical fields
    if(ui->Nom->text().isEmpty() ||
        ui->prenom->text().isEmpty() ||
        ui->Email->text().isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Remplissez tous les champs obligatoires !");
        return;
    }

    // NEW: Better data validation
    bool telOk;
    long telephone = ui->Telephone->text().toLong(&telOk);
    if(!telOk || telephone <= 0) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide !");
        return;
    }

    bool salaireOk;
    double salaire = ui->salaire->text().replace(",", ".").toDouble(&salaireOk);
    if(!salaireOk || salaire <= 0) {
        QMessageBox::warning(this, "Erreur", "Salaire invalide !");
        return;
    }

    // Create employee object
    Employe emp;
    emp.setId(originalId);
    emp.setNom(ui->Nom->text());
    emp.setPrenom(ui->prenom->text());
    emp.setEmail(ui->Email->text());
    emp.setNumTel(telephone);
    emp.setDateEmbauche(ui->date->date());
    emp.setposte(ui->poste->currentText());
    emp.setSalaire(salaire);
    emp.setMdp(ui->mdp->text());

    // NEW: Verify database connection
    if(!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "Connexion base de données perdue !");
        return;
    }

    if(emp.modifier()) {
        QMessageBox::information(this, "Succès", "Modification réussie !");
        refreshEmployeeTable();  // Force refresh

        // NEW: Clear fields after success
        ui->ID->clear();
        ui->Nom->clear();
        ui->prenom->clear();
        ui->Email->clear();
        ui->Telephone->clear();
        ui->date->setDate(QDate::currentDate());
        ui->poste->setCurrentIndex(0);
        ui->salaire->clear();
        ui->mdp->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification : " + emp.getLastError());
    }
}


void MainWindow::on_annuler_clicked()
{
    ui->ID->clear();
    ui->Nom->clear();
    ui->prenom->clear();
    ui->Email->clear();
    ui->Telephone->clear();
    ui->date->setDate(QDate::currentDate());
    ui->poste->setCurrentIndex(0);
    ui->salaire->clear();
    ui->mdp->clear();
}

void MainWindow::afficherStatistiquesEmployes()
{
    QSqlQuery query;
    query.prepare("SELECT POSTE, COUNT(*) FROM EMPLOYE GROUP BY POSTE");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur de base de données: " + query.lastError().text());
        return;
    }

    QMap<QString, int> posteData;
    int total = 0;
    QVector<QColor> employeePalette = {
        QColor(255, 105, 97),   // Coral
        QColor(255, 179, 71),   // Gold
        QColor(144, 202, 249),  // Light Blue
        QColor(102, 187, 106),  // Light Green
        QColor(179, 157, 219),  // Purple
        QColor(255, 204, 128)   // Light Orange
    };

    while (query.next()) {
        posteData.insert(query.value(0).toString(), query.value(1).toInt());
        total += query.value(1).toInt();
    }

    QDialog statsDialog(this);
    statsDialog.setWindowTitle(" Statistiques des Employés par Poste");
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

    // 1. Diagramme Circulaire (Répartition par Poste)
    QPieSeries *pieSeries = new QPieSeries();
    pieSeries->setPieSize(0.75);
    int colorIndex = 0;

    for (const QString &poste : posteData.keys()) {
        qreal percentage = (posteData[poste] * 100.0) / total;
        QPieSlice *slice = pieSeries->append(poste, posteData[poste]);
        slice->setColor(employeePalette[colorIndex % employeePalette.size()]);
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1\n%2 employés (%3%)")
                            .arg(poste)
                            .arg(posteData[poste])
                            .arg(percentage, 0, 'f', 1));
        slice->setBorderWidth(1);
        slice->setBorderColor(Qt::white);
        colorIndex++;
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition des Employés par Poste");
    pieChart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));
    pieChart->legend()->setAlignment(Qt::AlignRight);
    pieChart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);
    pieChartView->setStyleSheet("border-radius: 8px; border: 1px solid #d1d9e6; background: white;");
    tabs->addTab(pieChartView, " Répartition par Poste");

    // 2. Diagramme en Barres (Nombre d'Employés par Poste)
    QBarSeries *barSeries = new QBarSeries();
    QBarSet *barSet = new QBarSet("Employés");
    barSet->setColor(QColor(70, 130, 180)); // Steel Blue

    QStringList categories;
    for (const QString &poste : posteData.keys()) {
        *barSet << posteData[poste];
        categories << poste;
    }

    barSeries->append(barSet);
    barSeries->setLabelsVisible(true);
    barSeries->setLabelsFormat("@value");

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Nombre d'Employés par Poste");
    barChart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));

    QBarCategoryAxis *xAxis = new QBarCategoryAxis();
    xAxis->append(categories);
    barChart->addAxis(xAxis, Qt::AlignBottom);
    barSeries->attachAxis(xAxis);

    QValueAxis *yAxis = new QValueAxis();
    yAxis->setLabelFormat("%d");
    barChart->addAxis(yAxis, Qt::AlignLeft);
    barSeries->attachAxis(yAxis);
    barChart->setAnimationOptions(QChart::AllAnimations);
    QChartView *barChartView = new QChartView(barChart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    barChartView->setStyleSheet("border-radius: 8px; border: 1px solid #d1d9e6; background: white;");
    tabs->addTab(barChartView, " Analyse Comparative des Postes");

    mainLayout->addWidget(tabs);

    // Bouton de fermeture
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *closeButton = new QPushButton(" Fermer");
    closeButton->setStyleSheet(
        "QPushButton { background: #f5f8fa; color: #2d3748; padding: 12px 18px; border-radius: 6px; font-weight: bold; border: 1px solid #d1d9e6; }"
        "QPushButton:hover { background: #e2e8f0; }"
        );
    QObject::connect(closeButton, &QPushButton::clicked, &statsDialog, &QDialog::accept);
    buttonLayout->addWidget(closeButton);
    buttonLayout->setAlignment(Qt::AlignRight);
    mainLayout->addLayout(buttonLayout);

    statsDialog.exec();
}
void MainWindow::on_pdfEmployes_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter le Rapport des Employés en PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    QPdfWriter pdf(fileName);
    pdf.setResolution(300);
    pdf.setPageMargins(QMarginsF(30, 30, 30, 30));

    const int pageWidth = pdf.width();
    const int pageHeight = pdf.height();

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    const int leftMargin = 50;
    const int topMargin = 100;
    const int bottomMargin = 50;
    int currentY = topMargin;

    painter.setFont(QFont("Arial", 16, QFont::Bold));
    QRect titleRect(0, 50, pageWidth, 40);
    painter.drawText(titleRect, Qt::AlignCenter, "Rapport Détaillé des Employés");
    currentY += 60;

    QSqlQueryModel model;
    model.setQuery("SELECT ID, NOM, PRENOM, EMAIL, NUM_TLP, DATE_EMBAUCHE, POSTE, SALAIRE, MDP FROM EMPLOYE");

    if (model.lastError().isValid()) {
        QMessageBox::critical(this, "Erreur de base de données", "Erreur lors de la récupération des données des employés : " + model.lastError().text());
        painter.end();
        return;
    }

    if (model.rowCount() == 0) {
        painter.setFont(QFont("Arial", 12));
        painter.drawText(leftMargin, currentY, "Aucun employé à afficher.");
        painter.end();
        return;
    }

    const int columnCount = model.columnCount();
    const int rowCount = model.rowCount();
    const int headerHeight = 30;
    const int rowHeight = 25;
    const int cellPadding = 5;

    QVector<int> columnWidths(columnCount);
    int totalWidth = 0;

    painter.setFont(QFont("Arial", 8, QFont::Bold));
    for (int col = 0; col < columnCount; ++col) {
        QString header = model.headerData(col, Qt::Horizontal).toString();
        columnWidths[col] = painter.fontMetrics().horizontalAdvance(header) + cellPadding * 2;

        painter.setFont(QFont("Arial", 8));
        for (int row = 0; row < rowCount; ++row) {
            QString data = model.data(model.index(row, col)).toString();
            columnWidths[col] = qMax(columnWidths[col], painter.fontMetrics().horizontalAdvance(data) + cellPadding * 2);
        }
        columnWidths[col] = qMax(columnWidths[col], 80); // Minimum width
        totalWidth += columnWidths[col];
    }

    if (totalWidth > pageWidth - 2 * leftMargin) {
        double ratio = (pageWidth - 2 * leftMargin) / (double)totalWidth;
        for (int col = 0; col < columnCount; ++col) {
            columnWidths[col] *= ratio;
        }
    }

    int tableLeft = leftMargin; // Align left
    currentY += 20;

    // Draw Table Header
    painter.setFont(QFont("Arial", 8, QFont::Bold));
    painter.setPen(QPen(Qt::black, 1));
    painter.setBrush(QBrush(QColor(220, 220, 220))); // Light Gray

    int currentX = tableLeft;
    for (int col = 0; col < columnCount; ++col) {
        painter.drawRect(currentX, currentY, columnWidths[col], headerHeight);
        painter.drawText(QRect(currentX + cellPadding, currentY, columnWidths[col] - 2 * cellPadding, headerHeight),
                         Qt::AlignLeft | Qt::AlignVCenter, model.headerData(col, Qt::Horizontal).toString());
        currentX += columnWidths[col];
    }
    currentY += headerHeight;

    // Draw Table Data
    painter.setFont(QFont("Arial", 8));
    painter.setPen(QPen(Qt::black, 0.5));
    painter.setBrush(Qt::NoBrush);

    for (int row = 0; row < rowCount; ++row) {
        currentX = tableLeft;
        for (int col = 0; col < columnCount; ++col) {
            painter.drawRect(currentX, currentY, columnWidths[col], rowHeight);
            QString text = model.data(model.index(row, col)).toString();
            if (col == 5) { // Format Date
                QDate date = QDate::fromString(text, Qt::ISODate);
                if (date.isValid()) {
                    text = date.toString("dd-MM-yyyy");
                }
            }
            painter.drawText(QRect(currentX + cellPadding, currentY, columnWidths[col] - 2 * cellPadding, rowHeight),
                             Qt::AlignLeft | Qt::AlignVCenter, text);
            currentX += columnWidths[col];
        }
        currentY += rowHeight;

        if (currentY > pageHeight - bottomMargin - rowHeight) {
            painter.setFont(QFont("Arial", 8));
            painter.drawText(QRect(0, pageHeight - 30, pageWidth, 20),
                             Qt::AlignCenter,
                             "Date de génération : " + QDate::currentDate().toString("dd-MM-yyyy"));
            pdf.newPage();
            currentY = topMargin + 60 + headerHeight; // Reset Y after title and header on new page

            // Redraw Header on new page
            currentX = tableLeft;
            painter.setFont(QFont("Arial", 8, QFont::Bold));
            painter.setPen(QPen(Qt::black, 1));
            painter.setBrush(QBrush(QColor(220, 220, 220)));
            for (int col = 0; col < columnCount; ++col) {
                painter.drawRect(currentX, currentY - headerHeight, columnWidths[col], headerHeight);
                painter.drawText(QRect(currentX + cellPadding, currentY - headerHeight, columnWidths[col] - 2 * cellPadding, headerHeight),
                                 Qt::AlignLeft | Qt::AlignVCenter, model.headerData(col, Qt::Horizontal).toString());
                currentX += columnWidths[col];
            }
            painter.setFont(QFont("Arial", 8));
            painter.setPen(QPen(Qt::black, 0.5));
            painter.setBrush(Qt::NoBrush);
        }
    }

    painter.setFont(QFont("Arial", 8));
    painter.drawText(QRect(0, pageHeight - 30, pageWidth, 20),
                     Qt::AlignCenter,
                     "Date de génération : " + QDate::currentDate().toString("dd-MM-yyyy"));

    painter.end();
    QMessageBox::information(this, "Export PDF", "Le rapport des employés a été exporté avec succès !");
}
void MainWindow::onTriComboBoxChanged(int index)
{
    QString sortData = ui->tri->itemData(index).toString();
    QStringList parts = sortData.split(" ");

    if(parts.size() == 2) {
        currentSortColumn = parts[0];
        currentSortOrder = parts[1];
    }

    refreshEmployeeTable();
}
void MainWindow::onSearchTextChanged(const QString &text)
{
    QString criteria = ui->re->currentText();
    QSqlQuery query;
    QString queryStr = "SELECT * FROM EMPLOYE WHERE ";

    QSqlDatabase db = QSqlDatabase::database(); // Get the default database connection
    if (!db.isOpen()) {
        qDebug() << "Erreur : La base de données n'est pas ouverte.";
        return;
    }
    // Construction de la requête
    if (criteria == "Nom") {
        queryStr += "NOM LIKE :search";
        query.prepare(queryStr);
        query.bindValue(":search", "%" + text + "%");
    }
    else if (criteria == "Poste") {
        queryStr += "POSTE LIKE :search";
        query.prepare(queryStr);
        query.bindValue(":search", "%" + text + "%");
    }
    else if (criteria == "ID") {
        queryStr += "ID LIKE :search";
        query.prepare(queryStr);
        query.bindValue(":search", "%" + text + "%");

    } else {
        // Handle the case where the criteria is not one of the handled types
        ui->table->clearContents();
        ui->table->setRowCount(0);
        return;
    }

    // Exécuter la requête et remplir le tableau
    if (query.exec()) {
        ui->table->setRowCount(0); // Réinitialiser

        int row = 0;
        while (query.next()) {
            ui->table->insertRow(row);

            // Remplir chaque colonne (assuming 9 columns in EMPLOYE table)
            for (int col = 0; col < 9; col++) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());

                // Formatage des colonnes numériques (adjust indices if needed)
                if (col == 0 || col == 4 || col == 7) {
                    item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
                }

                ui->table->setItem(row, col, item);
            }
            row++;
        }
    } else {
        qDebug() << "Erreur SQL :" << query.lastError().text();
    }
}

// Fonction utilitaire pour remplir le tableau
// Dans mainwindow.cpp
void MainWindow::populateTable(QSqlQuery& query)
{
    ui->table->setRowCount(0);
    int row = 0;

    while(query.next()) {
        ui->table->insertRow(row);

        for(int col = 0; col < 9; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());

            if(col == 0 || col == 4 || col == 7) {
                item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            }

            ui->table->setItem(row, col, item);
        }
        row++;
    }
}
void MainWindow::on_quitButton_clicked()
{
    ui->rechercher->clear();
    refreshEmployeeTable(); // Réinitialise l'affichage
}
QString MainWindow::generateRandomCode(int length) {
    const QString possibleCharacters("0123456789");
    QString randomString;
    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        randomString.append(possibleCharacters.at(index));
    }
    return randomString;
}


void MainWindow::on_pb_mdp_oub_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Switch to the "Forgot Password" page (index 2)

    // 1. Read the email (already done in the previous step, assuming le_email_login exists)
    QString email = ui->emailline->text();
    ui->le_email_oub->setText(email);


    // 2. Line edit for entering the code sent to the email (le_verification_code_oub)
    ui->le_code_oub->setVisible(true); // Make the code input field visible
    ui->le_code_oub->clear();        // Clear any previous text

    // 3. Line edit for the change password (le_new_mdp_oub)
    ui->le_new_mdp_oub->setVisible(true);        // Make the new password field visible
    ui->le_new_mdp_oub->clear();                // Clear any previous text
    ui->le_new_mdp_oub->setPlaceholderText("Nouveau mot de passe"); // Optional placeholder

    // 4. Push button named "valider" (pb_valider_mdp_oub) to send the code
    ui->pb_valider_mdp_oub->setText("Valider le code"); // Change button text to reflect its new action
    ui->pb_valider_mdp_oub->setVisible(true);      // Make sure the button is visible

    // You might want to hide the initial "Confirm" button if you had one
    // ui->pb_confirm_email_oub->setVisible(false);
}
void MainWindow::on_pb_confirm_email_oub_clicked()
{
    QString email = ui->le_email_oub->text();

    // Vérifier si cet email est bloqué
    if (mdpOubBlocageMap.contains(email)) {
        QDateTime blocage = mdpOubBlocageMap.value(email);
        int secondsSinceBlocage = blocage.secsTo(QDateTime::currentDateTime());
        if (secondsSinceBlocage < BLOCK_DURATION_SECONDS) {
            QMessageBox::critical(this, "Blocage temporaire",
                                  QString("Trop de tentatives. Veuillez patienter %1 secondes.").arg(BLOCK_DURATION_SECONDS - secondsSinceBlocage));
            return;
        } else {
            mdpOubTentativesMap.remove(email);
            mdpOubBlocageMap.remove(email);
        }
    }

    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre email.");
        mdpOubTentativesMap[email] = mdpOubTentativesMap.value(email, 0) + 1;
        if (mdpOubTentativesMap[email] >= MAX_TENTATIVES)
            mdpOubBlocageMap[email] = QDateTime::currentDateTime();
        return;
    }

    if (verifyEmailAndSendOTP(email)) {
        ui->le_email_oub->setVisible(false);
        ui->le_code_oub->setVisible(true);
        ui->le_code_oub->setVisible(true); // Assuming this is where you want to enter the new password eventually
        ui->le_new_mdp_oub->setVisible(true);
    } else {
        // verifyEmailAndSendOTP handles its own error messages
        mdpOubTentativesMap[email] = mdpOubTentativesMap.value(email, 0) + 1;
        if (mdpOubTentativesMap[email] >= MAX_TENTATIVES)
            mdpOubBlocageMap[email] = QDateTime::currentDateTime();
    }
}
void MainWindow::on_pb_reset_password_oub_clicked()
{
    QString email = ui->le_email_oub->text();
    QString enteredCode = ui->le_code_oub->text();
    QString newPassword = ui->le_new_mdp_oub->text();

    if (enteredCode.isEmpty() || newPassword.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer le code de vérification et le nouveau mot de passe.");
        return;
    }

    if (otpStorage.contains(email) && otpStorage.value(email) == enteredCode) {
        // Code is correct - proceed with password reset
        QByteArray hashedNewPassword = QCryptographicHash::hash(newPassword.toUtf8(), QCryptographicHash::Sha256);
        QString hashedNewMdp = hashedNewPassword.toHex();

        QSqlDatabase db = QSqlDatabase::database();
        if (db.isOpen()) {
            QSqlQuery query(db);
            query.prepare("UPDATE EMPLOYES SET MDP = :newMdp WHERE EMAIL_EMP = :email");
            query.bindValue(":newMdp", hashedNewMdp);
            query.bindValue(":email", email);

            if (query.exec()) {
                QMessageBox::information(this, "Succès", "Mot de passe mis à jour avec succès ! Veuillez vous reconnecter.");
                ui->stackedWidget->setCurrentIndex(1); // Go back to login
                // Clear fields and stored data:
                ui->le_email_oub->clear();
                ui->le_code_oub->clear();
                ui->le_new_mdp_oub->clear();
                otpStorage.remove(email); // Remove the used OTP
                mdpOubTentativesMap.remove(email);
                mdpOubBlocageMap.remove(email);
            } else {
                QMessageBox::critical(this, "Erreur", "Erreur lors de la mise à jour du mot de passe.");
                qDebug() << "Database update error:" << query.lastError().text();
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Base de données non ouverte.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Code de vérification incorrect.");
        mdpOubTentativesMap[email] = mdpOubTentativesMap.value(email, 0) + 1;
        if (mdpOubTentativesMap[email] >= MAX_TENTATIVES) {
            mdpOubBlocageMap[email] = QDateTime::currentDateTime();
        }
    }
}
bool MainWindow::verifyEmailAndSendOTP(const QString& email)
{
    QSqlDatabase db = QSqlDatabase::database(); // Get the default database connection
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database is not open.");
        return false;
    }

    // 1. Verify if the email exists in the database
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT EMAIL_EMP FROM EMPLOYES WHERE EMAIL_EMP = :email");
    checkQuery.bindValue(":email", email);

    if (!checkQuery.exec()) {
        qDebug() << "Database query error:" << checkQuery.lastError().text();
        return false;
    }

    if (!checkQuery.next()) {
        QMessageBox::warning(this, "Error", "Email address not found.");
        return false;
    }

    // 2. Generate a new OTP
    QString otp = generateRandomCode(8); // Generate an 8-digit OTP

    // 3. Store the OTP temporarily
    otpStorage[email] = otp;
    qDebug() << "Generated OTP for" << email << ":" << otp;

    // 4. Send the OTP to the provided email address
    QString subject = "Your One-Time Password (OTP)";
    QString body = "Your OTP for password reset is: " + otp + ". This code will be valid for a short time.";

    if (sendEmail(email, subject, body)) {
        QMessageBox::information(this, "OTP Sent", "A one-time password has been sent to your email address.");
        return true;
    } else {
        QMessageBox::critical(this, "Error", "Failed to send OTP email.");
        // Optionally, remove the stored OTP if sending fails
        otpStorage.remove(email);
        return false;
    }
}
void MainWindow::on_pb_valider_mdp_oub_clicked()
{
    QString email = ui->le_email_oub->text();

    // Vérifier si cet email est bloqué
    if (mdpOubBlocageMap.contains(email)) {
        QDateTime blocage = mdpOubBlocageMap.value(email);
        int secondsSinceBlocage = blocage.secsTo(QDateTime::currentDateTime());
        if (secondsSinceBlocage < BLOCK_DURATION_SECONDS) {
            QMessageBox::critical(this, "Blocage temporaire",
                                  QString("Trop de tentatives. Veuillez patienter %1 secondes.").arg(BLOCK_DURATION_SECONDS - secondsSinceBlocage));
            return;
        } else {
            mdpOubTentativesMap.remove(email);
            mdpOubBlocageMap.remove(email);
        }
    }

    if (ui->pb_valider_mdp_oub->text() == "Confirm") {
        // Phase 1: User enters email, we send the code
        if (email.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez entrer votre email.");
            mdpOubTentativesMap[email] = mdpOubTentativesMap.value(email, 0) + 1;
            if (mdpOubTentativesMap[email] >= MAX_TENTATIVES)
                mdpOubBlocageMap[email] = QDateTime::currentDateTime();
            return;
        }

        storedVerificationCode_oub = generateRandomCode();
        currentEmailForReset_oub = email;
        QString subject = "Password Reset Code";
        QString body = "Your password reset code is: " + storedVerificationCode_oub;

        if (sendEmail(email, subject, body)) {
            QMessageBox::information(this, "Code Sent", "Verification code sent to your email.");
            ui->pb_valider_mdp_oub->setText("Reset Password"); // Change button text
            ui->le_code_oub->setVisible(true); // Show the (misused) new password field
        } else {
            QMessageBox::critical(this, "Error", "Failed to send verification code.");
            mdpOubTentativesMap[email] = mdpOubTentativesMap.value(email, 0) + 1;
            if (mdpOubTentativesMap[email] >= MAX_TENTATIVES)
                mdpOubBlocageMap[email] = QDateTime::currentDateTime();
        }
    } else if (ui->pb_valider_mdp_oub->text() == "Reset Password") {
        // Phase 2: User enters verification code (in the password field!)
        QString enteredCode = ui->le_code_oub->text(); // Misusing this field
        if (enteredCode.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez entrer le code de vérification.");
            return;
        }

        if (enteredCode == storedVerificationCode_oub && email == currentEmailForReset_oub) {
            // Code is correct - proceed with password reset
            // In this simplified version, we're not asking for a *new* password, just verifying the code to "log in" (reset)
            QMessageBox::information(this, "Success", "Verification successful! You are now logged in.");
            ui->stackedWidget->setCurrentIndex(1); // Go back to login
            // Clear fields:
            ui->le_email_oub->clear();
            ui->le_code_oub->clear();
            ui->pb_valider_mdp_oub->setText("Confirm"); // Reset button text
            // Clear stored code:
            storedVerificationCode_oub = "";
            currentEmailForReset_oub = "";

        } else {
            QMessageBox::critical(this, "Error", "Incorrect verification code.");
            mdpOubTentativesMap[email] = mdpOubTentativesMap.value(email, 0) + 1;
            if (mdpOubTentativesMap[email] >= MAX_TENTATIVES)
                mdpOubBlocageMap[email] = QDateTime::currentDateTime();
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupForgotPasswordPage()
{
    connect(ui->omdp, &QPushButton::clicked,
            this, &MainWindow::on_pb_mdp_oub_clicked);

    // Initially set stackedWidget_2 to index 1 (assuming your login page is at index 1)
    ui->stackedWidget->setCurrentIndex(1);
}



bool MainWindow::sendEmail(QString recipient, QString subject, QString body) {
    QString smtpServer = "gmail.com";   // Replace with your SMTP server address
    int smtpPort = 587;                             // Replace with your SMTP server port (e.g., 587 for TLS, 465 for SSL)
    QString senderEmail = "your_email@example.com"; // Replace with your email address
    QString senderPassword = "App password";      // Replace with your email password

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url;
    if (smtpPort == 465) {
        url.setUrl(QString("https://%1:%2").arg(smtpServer).arg(smtpPort)); // For SSL, though direct SMTP over SSL might be needed
    } else {
        url.setUrl(QString("smtp://%1:%2").arg(smtpServer).arg(smtpPort));   // For STARTTLS
    }
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray postData;
    postData.append(QString("EHLO %1\r\n").arg("localhost").toUtf8()); // Or your domain
    if (!senderEmail.isEmpty() && !senderPassword.isEmpty()) {
        postData.append(QString("AUTH LOGIN\r\n").toUtf8());
        postData.append(QByteArray(senderEmail.toUtf8().toBase64() + "\r\n"));
        postData.append(QByteArray(senderPassword.toUtf8().toBase64() + "\r\n"));
    }
    postData.append(QString("MAIL FROM:<%1>\r\n").arg(senderEmail).toUtf8());
    postData.append(QString("RCPT TO:<%1>\r\n").arg(recipient).toUtf8());
    postData.append(QString("DATA\r\n").toUtf8());
    postData.append(QString("Subject: %1\r\n\r\n%2\r\n.\r\n").arg(subject).arg(body).toUtf8());
    postData.append(QString("QUIT\r\n").toUtf8());

    QNetworkReply *reply = manager->post(request, postData);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    bool success = false;
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Email sent successfully to" << recipient;
        success = true;
    } else {
        qDebug() << "Error sending email to" << recipient << ":" << reply->errorString();
        // Optionally log the full reply for debugging:
        // qDebug() << "Reply content:" << reply->readAll();
    }

    reply->deleteLater();
    manager->deleteLater();
    return success;
}
