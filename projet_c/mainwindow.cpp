#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Client.cpp"
#include <QMessageBox>
#include <iostream>
#include <QTextStream>
#include <QTableWidget>
#include <QAbstractProxyModel>
#include <QSortFilterProxyModel>
#include "Client.h"
#include <QFileDialog>
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QPrinter>
#include <QDebug>
#include <QPageLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "qtstat.h"
#include "connection.h"
#include "todo.h"
#include "history.h"
#include <QTextStream>
#include <QStandardPaths>
#include "arduino.h"
#include <QString>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    //qDebug()<<"***********************************************"<<ret;
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "***************************arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
    ui->logo->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\logo1.png"));
    ui->bg->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\bg.jpg"));
    ui->logout->setPixmap(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\logout.png"));
    ui->emp1->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\empe.png"));
    ui->chercheur->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\cher.png"));
    ui->pdf->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\pdf1.png"));
    ui->vac->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\vaccin.png"));
    ui->eq->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\equipement.png"));
    ui->test->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\teste.png"));
    ui->client->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\client.png"));
    ui->stat->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\st.png"));
    ui->ok->setIcon(QPixmap("C:\\Users\\Medie\\Desktop\\projet_c\\projet_c\\search.png"));
    connect(ui->radioButton_Ajouter, &QRadioButton::toggled, this, &MainWindow::on_radioButton_Ajouter_toggled);
    connect(ui->radioButton_Modifier, &QRadioButton::toggled, this, &MainWindow::on_radioButton_Modifier_toggled);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::onPdfButtonClicked);
    connect(ui->stat, &QPushButton::clicked, this, &MainWindow::on_stat_clicked);
    connect(ui->todo, &QPushButton::clicked, this, &MainWindow::on_todo_clicked);
    connect(ui->History, &QPushButton::clicked, this, &MainWindow::on_History_clicked);
    connect(ui->ASC, &QCheckBox::toggled, this, &MainWindow::on_CBtri_currentIndexChanged);
    connect(ui->DSC, &QCheckBox::toggled, this, &MainWindow::on_CBtri_currentIndexChanged);
    //ui->debug->setText(QString::number(C.countClients()));
    //ui->debug->setText( c.check_data_base() ? "true" : "false");
    //connect(A.getserial(), &QSerialPort::readyRead, this, &MainWindow::checkDatabaseForUID);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::checkDatabaseForUID()
{
    QSqlQuery query;
    QByteArray temp =A.read_from_arduino();
    QString uid = QString::fromUtf8(temp);
    query.prepare("SELECT NOM, PRENOM FROM EMPLOYEE WHERE U_ID = :uid");
    query.bindValue(":uid", uid);
    qDebug() << temp<<"temp = ";
    if (query.exec()) {
        if (query.next()) {
            QString nom = query.value(0).toString();
            QString prenom = query.value(1).toString();
            QString employee = nom + " " + prenom;
            qDebug() << "RFID UID" << uid << "********************found in the database. Granting access to:**************" << employee;
            A.write_to_arduino(("NAME:" + employee + "\n").toUtf8());
        } else {
            qDebug() << "RFID UID" << uid << "not found in the database. Denying access.";
            QString denied = "DENIED\n";
             A.write_to_arduino(denied.toUtf8());
        }
    }
}

void MainWindow::display(){
     proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(C.afficher());
     proxy->setSortCaseSensitivity(Qt::CaseInsensitive);
     proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(-1);
      ui->tableView->setModel(proxy);
}
void MainWindow::on_radioButton_Ajouter_toggled(bool checked)
{

    if (checked) {
        AjouterResult A;
        int id = ui->lineEdit_ID->text().toInt();
        QString nomA = ui->lineEdit_nomA->text();
        QString type = ui->typeCombo->currentText();
        QString rep = ui->lineEdit_Rep->text();
        QString adr = ui->lineEdit_adr->text();
        QString email = ui->lineEdit_email->text();
        int ctr = ui->lineEdit_ctr->text().toInt();


        if (id <= 0) {
            QMessageBox::warning(this, "Entrée invalide", "L'ID doit être un nombre positif !");
            return;
        }
        if (nomA.isEmpty() || !nomA.at(0).isLetter()) {
            QMessageBox::warning(this, "Entrée invalide", "Le nom de l'association doit commencer par une lettre et ne peut pas être vide !");
            return;
        }
        if (adr.isEmpty()) {
            QMessageBox::warning(this, "Entrée invalide", "L'adresse ne peut pas être vide !");
            return;
        }
        if (type.isEmpty()) {
            QMessageBox::warning(this, "Entrée invalide", "Le type d'association ne peut pas être vide !");
            return;
        }
        static const QRegularExpression repRegex("^[A-Za-z]+$");

        if (rep.isEmpty() || !repRegex.match(rep).hasMatch()) {
            QMessageBox::warning(this, "Entrée invalide", "Le nom du représentant doit contenir uniquement des lettres et ne peut pas être vide !");
            return;
        }
        static const QRegularExpression emailRegex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,6}$");

        if (!emailRegex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Entrée invalide", "Veuillez saisir une adresse e-mail valide !");
            return;
        }

        if (ctr <= 0) {
            QMessageBox::warning(this, "Entrée invalide", "L'ID du contrat doit être un nombre positif !");
            return;
        }


        Client C(id, nomA, adr, type, rep, email, ctr);


        bool test = C.ajouter();
        if (test) {
            ui->tableView->setModel(C.afficher());
            QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");


            ui->lineEdit_ID->clear();
            ui->lineEdit_nomA->clear();
            ui->lineEdit_Rep->clear();
            ui->lineEdit_adr->clear();
            ui->lineEdit_email->clear();
            ui->lineEdit_ctr->clear();
            ui->typeCombo->setCurrentIndex(0);

            ui->radioButton_Ajouter->setAutoExclusive(false);
            ui->radioButton_Ajouter->setChecked(false);
            ui->radioButton_Ajouter->setAutoExclusive(true);
            A.Cajt=C;
            A.success=true;

            QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\ajout.txt");
            if (!file.open(QIODevice::ReadWrite)){
                QMessageBox::information(nullptr,"error",file.errorString());
            }
            QString historyajt = QString("%1|%2|%3|%4|%5|%6|%7\n")
                                       .arg(id)
                                       .arg(nomA)
                                       .arg(type)
                                       .arg(rep)
                                       .arg(adr)
                                       .arg(email)
                                       .arg(ctr);
            QTextStream out(&file);
            QString content = file.readAll();
            out<<QDateTime::currentDateTime().toString()<<"Ajout:"<<historyajt<<"\n";
            file.close();
        }

        else {
            QMessageBox::critical(this, "Erreur", "Ajout non effectué.");
            A.success=false;
        }
        emit ajouterResultReady(A);
    }
}

void MainWindow::on_pushButton_supp_clicked(){
         int id=ui->LineEdit_supp->text().toInt();

        bool test=C.supprimer(id);

         if (test){
            // Client temp = C.fetch(id);
             QFile Suppfile(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\supp.txt");
             if (!Suppfile.open(QIODevice::ReadWrite)){
                 QMessageBox::information(nullptr,"error",Suppfile.errorString());
             }
             QString sup = QString("%1\n").arg(id);

             QTextStream outsup(&Suppfile);
             QString content = Suppfile.readAll();
             outsup<<QDateTime::currentDateTime().toString()<<"Suppression du Client sous ID:"<<sup<<"\n";
             Suppfile.close();

             QMessageBox::information(nullptr, QObject::tr("OK"),
                                      QObject::tr("Suppression effectuée\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(C.afficher());
              // ui->tableView->setModel(proxy);
             ui->radioButton_Ajouter->setAutoExclusive(false);
             ui->radioButton_Ajouter->setChecked(false);
             ui->radioButton_Ajouter->setAutoExclusive(true);
                  }
         else {
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("Suppression non effectuée.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
              }
        }


        void MainWindow::on_radioButton_Modifier_toggled(bool checked){
            {
                if (checked) {

                    int id = ui->lineEdit_ID->text().toInt();
                    QString nomA = ui->lineEdit_nomA->text();
                    QString type = ui->typeCombo->currentText();
                    QString rep = ui->lineEdit_Rep->text();
                    QString adr = ui->lineEdit_adr->text();
                    QString email = ui->lineEdit_email->text();
                    int ctr = ui->lineEdit_ctr->text().toInt();


                    if (id <= 0) {
                        QMessageBox::warning(this, "Entrée invalide", "L'ID doit être un nombre positif !");
                        return;
                    }
                    if (nomA.isEmpty() || !nomA.at(0).isLetter()) {
                        QMessageBox::warning(this, "Entrée invalide", "Le nom de l'association doit commencer par une lettre et ne peut pas être vide !");
                        return;
                    }
                    if (adr.isEmpty()) {
                        QMessageBox::warning(this, "Entrée invalide", "L'adresse ne peut pas être vide !");
                        return;
                    }
                    if (type.isEmpty()) {
                        QMessageBox::warning(this, "Entrée invalide", "Le type d'association ne peut pas être vide !");
                        return;
                    }
                    static const QRegularExpression repRegex("^[A-Za-z]+$");

                    if (rep.isEmpty() || !repRegex.match(rep).hasMatch()) {
                        QMessageBox::warning(this, "Entrée invalide", "Le nom du représentant doit contenir uniquement des lettres et ne peut pas être vide !");
                        return;
                    }
                    static const QRegularExpression emailRegex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,6}$");

                    if (!emailRegex.match(email).hasMatch()) {
                        QMessageBox::warning(this, "Entrée invalide", "Veuillez saisir une adresse e-mail valide !");
                        return;
                    }

                    if (ctr <= 0) {
                        QMessageBox::warning(this, "Entrée invalide", "L'ID du contrat doit être un nombre positif !");
                        return;
                    }


                    Client C(id, nomA, adr, type, rep, email, ctr);


                    bool test = C.modifier();
                    if (test) {
                        ui->tableView->setModel(C.afficher());

                        QMessageBox::information(this, "Succès", "Modification effectué avec succès !");


                        ui->lineEdit_ID->clear();
                        ui->lineEdit_nomA->clear();
                        ui->lineEdit_Rep->clear();
                        ui->lineEdit_adr->clear();
                        ui->lineEdit_email->clear();
                        ui->lineEdit_ctr->clear();
                        ui->typeCombo->setCurrentIndex(0);

                        QFile filemodif(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\modifier.txt");
                        if (!filemodif.open(QIODevice::ReadWrite)){
                            QMessageBox::information(nullptr,"error",filemodif.errorString());
                        }

                        QString historymodif = QString("%1|%2|%3|%4|%5|%6|%7\n")
                                                 .arg(id)
                                                 .arg(nomA)
                                                 .arg(type)
                                                 .arg(rep)
                                                 .arg(adr)
                                                 .arg(email)
                                                 .arg(ctr);
                        QTextStream outt(&filemodif);
                        QString content = filemodif.readAll();
                       // filemodif.seek(content.length() - 1);
                        outt<<QDateTime::currentDateTime().toString()<<"Modification:"<<historymodif<<"\n";
                        filemodif.close();
                    }
                    else {
                        QMessageBox::critical(this, "Erreur", "Modification non effectué.");
                    }
                }
            }
        }

         /* void MainWindow::onPdfButtonClicked() {
            QTextDocument doc;
            QSqlQueryModel *model = C.afficher();
                            QString head = R"(
                <table style="border-spacing: 5px; width: 630px; table-layout: fixed; text-align: left;">
                    <colgroup>
                        <col style="width: 90px;">
                        <col style="width: 90px;">
                        <col style="width: 90px;">
                        <col style="width: 90px;">
                        <col style="width: 90px;">
                        <col style="width: 90px;">
                        <col style="width: 90px;">
                    </colgroup>
                    <tr>
                        <th style="background-color: #2C3E50; color: white; padding: 5px; border: 1px solid black;">ID</th>
                        <th style="background-color: #2C3E50; color: white; padding: 5px; border: 1px solid black;">NOM ASSOCIATION</th>
                        <th style="background-color: #2C3E50; color: white; padding: 5px; border: 1px solid black;">ADRESSE</th>
                        <th style="background-color: #2C3E50; color: white; padding: 5px; border: 1px solid black;">TYPE ASSOCIATION</th>
                        <th style="background-color: #2C3E50; color: white; padding: 5px; border: 1px solid black;">NOM RESPONSABLE</th>
                        <th style="background-color: #2C3E50; color: white; padding: 5px; border: 1px solid black;">EMAIL</th>
                        <th style="background-color: #2C3E50; color: white; padding: 5px; border: 1px solid black;">ID CONTRAT</th>
                    </tr>)";
            int count;
            QString data="<tr>";
            for (count =1; count<=model->rowCount();count++){
                if (count==model->rowCount()){
                    int id_c = model->data(model->index(count, 0)).toInt();
                    QString nomA = model->data(model->index(count, 1)).toString();
                    QString adresse = model->data(model->index(count, 2)).toString();
                    QString typeA = model->data(model->index(count, 3)).toString();
                    QString nomR = model->data(model->index(count, 4)).toString();
                    QString email = model->data(model->index(count, 5)).toString();
                    int id_contrat = model->data(model->index(count, 6)).toInt();
                    data += R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ QString::number(id_c) +"</td>";
                    data = data +  R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ nomA +"</td>";
                    data = data + R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ adresse +"</td>";
                    data = data +  R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ typeA +"</td>";
                    data = data + R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ nomR +"</td>";
                    data = data +  R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ email +"</td>";
                    data = data +  R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ QString::number(id_contrat) +"</td>";
                    data = data + "</tr>";
                    break;
                }
                int id_c = model->data(model->index(count, 0)).toInt();
                QString nomA = model->data(model->index(count, 1)).toString();
                QString adresse = model->data(model->index(count, 2)).toString();
                QString typeA = model->data(model->index(count, 3)).toString();
                QString nomR = model->data(model->index(count, 4)).toString();
                QString email = model->data(model->index(count, 5)).toString();
                int id_contrat = model->data(model->index(count, 6)).toInt();
                data += R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ QString::number(id_c) +"</td>";
                data = data +  R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ nomA +"</td>";
                data = data + R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ adresse +"</td>";
                data = data +  R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ typeA +"</td>";
                data = data + R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ nomR +"</td>";
                data = data +  R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ email +"</td>";
                data = data +  R"(<td width="90px"  style="background-color: #136f5c;  color: white;">)"+ QString::number(id_contrat) +"</td>";
                data = data + "</tr>" +"<tr>";

            }
            doc.setHtml(head + "<tr>" + data + "</tr>" + "</table>");
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            QString saveas = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");
            printer.setOutputFileName(saveas);
            doc.print(&printer);
        }*/


        void MainWindow::onPdfButtonClicked() {
            //doc generated
            QTextDocument doc;
            //preparing the model
            QSqlQueryModel *model = C.afficher();
            //html
            //pdfline
            int id=ui->pdfline->text().toInt();
            int count;
            QString nomA ;
            QString adresse;
            QString typeA ;
            QString nomR ;
            QString email;
            int id_contrat;
            for (count =1; count<=model->rowCount();count++){
                //if (count==model->rowCount()){
                    int id_c = model->data(model->index(count, 0)).toInt();
                    if (id_c==id){
                         nomA = model->data(model->index(count, 1)).toString();
                         adresse = model->data(model->index(count, 2)).toString();
                         typeA = model->data(model->index(count, 3)).toString();
                         nomR = model->data(model->index(count, 4)).toString();
                         email = model->data(model->index(count, 5)).toString();
                         id_contrat = model->data(model->index(count, 6)).toInt();
                        break;
                    }
                //}
            }
            QString code = R"(<!DOCTYPE html>
          <body>

              <h1 class="title"> Contrat Commercial</h1>
              <p id="currentTime">2024/2025</p>

              <h5>Parties concernées:</h5>
               <p>Le présent contrat est conclu entre )" + nomA + R"(, une)" + typeA + R"( immatriculée à )" + adresse +R"(, représenté(e) par )" + nomR +R"(, et Sample Biotechnology Association. Le Client autorise expressément l'utilisation de ses données professionnelles uniquement pour l'exécution des services décrits dans ce
               contrat, conformément au RGPD et aux lois locales sur la protection des données.</p>

               <h5>Objet:</h5>
              <p>Le présent contrat a pour objet la fourniture de vaccins par
              le Prestataire au Client, selon les conditions décrites ci-après.</p>

              <h5>Services:</h5>
              <p>Fourniture de <strong>100 doses de vaccins</strong> conformes aux normes ISO.</p>

              <h5>Engagement des Parties :</h5>
          <p>
            Le contrat N°<strong>)"+ QString::number(id_contrat) +R"(</strong> lie les Parties pour la durée nécessaire à l'exécution des prestations.<br>
            Toute communication relative à ce contrat se fera à l'adresse email : <strong>)"+email+R"(</strong>.
          </p>

          <h5>Résiliation :</h5>
          <p>En cas de manquement grave, le contrat pourra
          être résilié avec un préavis de <strong>30 jours</strong> par lettre recommandée.</p>

          <h5>Signature :</h5>
          <p><strong>Pour _____________ :</strong> _________________________<br>
            <strong>Pour Sample Biotechnology Association :</strong> _________________________</p>

          </body>
        )";
         doc.setHtml(code);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        QString saveas = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");
        printer.setOutputFileName(saveas);
        doc.print(&printer);
        }


        void MainWindow::on_stat_clicked()
        {
            s = new Qtstat(this);
            s->show();

        }

        void MainWindow::on_todo_clicked()
        {
            auto todo = new Todo(this);
            todo->setAttribute(Qt::WA_DeleteOnClose);
            todo->show();
        }



        void MainWindow::on_History_clicked()
        {
            auto h = new History(this);
            h->setAttribute(Qt::WA_DeleteOnClose);
            h->show();
        }


        void MainWindow::on_Rbar_textChanged(const QString &arg1)
        {
            proxy->setFilterFixedString(arg1);
        }


        void MainWindow::on_CBbar_currentIndexChanged(int index)
        {
            if (index==1){
                index=-1;
            }
            proxy->setFilterKeyColumn(index);
        }


        void MainWindow::on_CBtri_currentIndexChanged(int index)
        {
            if (ui->ASC->checkState()==Qt::Checked){
                proxy->sort(index + 1,Qt::AscendingOrder);
            }
            else if (ui->DSC->checkState()==Qt::Checked){
                proxy->sort(index + 1,Qt::DescendingOrder);
            }
        }

