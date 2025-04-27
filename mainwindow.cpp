#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatbot.h"
#include "vaccin.h"

#include <QTimer>

#include<QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include "arduinomanager.h"
#include <QSerialPort>

ArduinoManager *arduino;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arduino = new ArduinoManager(this);
    arduino->start();

    connect(arduino, &ArduinoManager::fanStatusChanged, this, [=](const QString &status) {
        if (status == "FAN_ON")
            ui->labelFan->setText("Ventilateur en marche");
        else
            ui->labelFan->setText("Ventilateur arrêté");
    });
    statistique s;
    QChartView *chart = s.genererStatistiques();
    chart->setParent(ui->label);
    chart->show();
    ui->logo->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\logo1.png"));  // C:\\Users\\user\\Desktop\\projetarwa
    ui->bg->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\bg.jpg"));
    ui->logout_2->setPixmap(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\logout.png"));
    ui->emp->setIcon(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\empe.png"));
    ui->chercheur_->setIcon(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\cher.png"));
    ui->pdf_2->setIcon(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\pdf1.png"));
    ui->vac_2->setIcon(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\vaccin.png"));
    ui->eq_2->setIcon(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\equipement.png"));
    ui->client_2->setIcon(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\client.png"));
    ui->stat_2->setIcon(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\st.png"));
    ui->ok_2->setIcon(QPixmap("C:\\Users\\user\\Desktop\\projetarwa\\search.png"));

    ui->lineEdit_2->setPlaceholderText("ID Vaccin");
    ui->lineEdit_4->setPlaceholderText("Nom Vaccin");
    ui->lineEdit_5->setPlaceholderText("Température Conservation");

    ui->type_vaccin->setVisible(false);
    ui->nombre_doses->setVisible(false);

    ui->type_vaccin->setText("ARNm");
    ui->nombre_doses->setText("unidose");
    // dans ton constructeur
    Chatbot *chatbot = new Chatbot(
        ui->chatTextEdit_2,
        ui->inputLineEdit_2,
        ui->sendButton_2,
        this
    );


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTableView()
{
    vaccin vac;
    ui->tableView_vaccin->setModel(vac.afficher());
}

void MainWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    loadTableView();
}

QString MainWindow::checkType()
{
    if (ui->radioButton_3->isChecked()) return "add";
    if (ui->radioButton_4->isChecked()) return "edit";
    return "check edit or delete";
}

void MainWindow::clearInputs()
{
    ui->lineEdit_2->clear();
    ui->lineEdit_4->clear();
    ui->type_vaccin->clear();
    ui->nombre_doses->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

bool MainWindow::validateInputs()
{
    if (ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_4->text().isEmpty() ||
        ui->type_vaccin->text().isEmpty() ||
        ui->nombre_doses->text().isEmpty() ||
        ui->lineEdit_5->text().isEmpty()) {
        QMessageBox::warning(this, "Validation Error", "Tous les champs doivent être remplis !");
        return false;
    }

    return true;
}

void MainWindow::on_pushButton_7_clicked()
{
    QString type = checkType();

    if (type == "add") {
        if (!validateInputs()) return;

        QString id = ui->lineEdit_2->text();
        QString nom = ui->lineEdit_4->text();
        QString type_vaccin = ui->type_vaccin->text();
        QString nbr_doses = ui->nombre_doses->text();
        float temperature_conservation = ui->lineEdit_5->text().toFloat();
        QDate date_exp = ui->dateEdit->date();

        vaccin vac(id, nom, type_vaccin, temperature_conservation, nbr_doses, date_exp);

        if (vac.Ajouter()) {
            ui->tableView_vaccin->setModel(vac.afficher());
            QMessageBox::information(this, "Success!", "Vaccin ajouté avec succès.");

            //  Calcul des jours restants avant expiration
            QDate date_actuelle = QDate::currentDate();
            int jours_restants = date_actuelle.daysTo(date_exp);

            //  Création du message SMS
            QString message = "Un vaccin a été ajouté sous le nom : " + nom +
                              ". Il expirera dans " + QString::number(jours_restants) + " jour(s).";

             //Envoi du SMS
            //vac.sendSMS("+21650256940", message);

            clearInputs();
        } else {
            QMessageBox::critical(this, "Error!", "Problème d'ajout.");
        }
    }
    else if (type == "edit") {
        if (!validateInputs()) return;

        QString id = ui->lineEdit_2->text();
        QString nom = ui->lineEdit_4->text();
        QString type_vaccin = ui->type_vaccin->text();
        QString nbr_doses = ui->nombre_doses->text();
        float temperature_conservation = ui->lineEdit_5->text().toFloat();
        QDate date_exp = ui->dateEdit->date();

        vaccin vac(id, nom, type_vaccin, temperature_conservation, nbr_doses, date_exp);

        if (vac.modifier()) {
            ui->tableView_vaccin->setModel(vac.afficher());
            QMessageBox::information(this, "Success!", "Vaccin modifié avec succès.");
            clearInputs();
        } else {
            QMessageBox::critical(this, "Error!", "Problème de modification.");
        }
    }
    else {
        QMessageBox::warning(this, "Warning", "Veuillez choisir une option valide (ajout/modification).");
    }
}


void MainWindow::on_comboBox_10_currentTextChanged(const QString &arg1)
{
    ui->type_vaccin->setText(arg1);
}

void MainWindow::on_comboBox_11_currentTextChanged(const QString &arg1)
{
    ui->nombre_doses->setText(arg1);
}

void MainWindow::on_tableView_vaccin_doubleClicked(const QModelIndex &index)
{
    QString selectedId = ui->tableView_vaccin->model()->data(index.sibling(index.row(), 0)).toString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Êtes-vous sûr de vouloir supprimer ce vaccin?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        vaccin vac;
        if (vac.Supprime(selectedId)) {
            QMessageBox::information(this, "Success", "Le vaccin a été supprimé avec succès.");
            ui->tableView_vaccin->setModel(vac.afficher());
            clearInputs();
        } else {
            QMessageBox::critical(this, "Error", "Échec de la suppression du vaccin.");
        }
    }
}

void MainWindow::on_tableView_vaccin_clicked(const QModelIndex &index)
{
    int row = index.row();

    QString id = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 0)).toString();
    QString nom = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 1)).toString();
    QString type = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 2)).toString();
    QString nbr_doses = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 3)).toString();
    QString temperature_conservation = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 4)).toString();
    QString date_expiration = ui->tableView_vaccin->model()->data(ui->tableView_vaccin->model()->index(row, 5)).toString();

    ui->lineEdit_2->setText(id);
    ui->lineEdit_4->setText(nom);
    ui->type_vaccin->setText(type);
    ui->nombre_doses->setText(nbr_doses);
    ui->lineEdit_5->setText(temperature_conservation);
    ui->dateEdit->setDate(QDate::fromString(date_expiration, "yyyy-MM-dd"));
}

void MainWindow::on_pushButton_9_clicked()
{
    clearInputs();
}

void MainWindow::on_comboBox_7_activated(int index)
{
    if(ASC){
        QString choix=ui->comboBox_7->currentText();
        ui->tableView_vaccin->setModel(vac.afficher_choix_ASC(choix));
    }else if (DSC){
        QString choix=ui->comboBox_7->currentText();
        ui->tableView_vaccin->setModel(vac.afficher_choix_DSC(choix));
    }
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    ASC = (arg1 == Qt::Checked);
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
     DSC = (arg1 == Qt::Checked);
}


void MainWindow::on_ok_2_clicked()
{
    QString val=ui->le_rech->text();
    QString option=ui->cb_rech_emp->currentText();
    if((val!="")&&(option=="temperature_conservation"))
    {        ui->tableView_vaccin->setModel(vac.afficher_temperature_conservation(val));}
    else if((val!="")&&(option=="nom_vaccin"))
    {
        ui->tableView_vaccin->setModel(vac.afficher_nom_vaccin(val));
    }
    else if((val!="")&&(option=="type_vaccin"))
    {
        ui->tableView_vaccin->setModel(vac.afficher_type_vaccin(val));
    }else if(option=="choisir")
    {
        ui->tableView_vaccin->setModel(vac.afficher());
    }
    else if ((option=="id_vaccin")&&((val!="")) )
    {
        ui->tableView_vaccin->setModel(vac.afficher_id_vaccin(val));
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView_vaccin->setModel(vac.afficher());
}






void MainWindow::on_pdf_2_clicked()
{
    QString idpdf = ui->vaccin_id_input->text();
    vaccin temp;
    vaccin* v = temp.readvaccin(idpdf);

    if (!v) {
        QMessageBox::warning(this, "Erreur", "Vaccin introuvable !");
        return;
    }

    QString id = v->getIdVaccin();
    QString nom = v->getNomVaccin();
    QString type = v->getTypeVaccin();
    QString doses = v->getNombresDoses();
    QString temperature = QString::number(v->getTemperatureConservation(), 'f', 1) + " °C";
    QString date = v->getDateExpiration().toString("dd/MM/yyyy");

    // Choisir le chemin où enregistrer le fichier
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Enregistrer le PDF",
                                                    nom + "_" + id + ".pdf", // nom par défaut
                                                    "Fichiers PDF (*.pdf)");

    if (filePath.isEmpty()) {
        // L'utilisateur a annulé
        return;
    }

    QColor Color2(209, 148, 87);
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    QPainter painter;
    if (!painter.begin(&printer)) {
        qWarning("Échec lors de l'ouverture du fichier PDF");
        return;
    }

    painter.setFont(QFont("Bahnschrift Light", 25));
    painter.setPen(Color2);
    painter.drawText(130, 230, "Information relative au Vaccin");
    painter.setPen(Qt::black);
    QPen borderPen(Qt::black);
    borderPen.setWidth(1);
    painter.setPen(borderPen);
    painter.drawText(260, 150, "Gestion Vaccin");

    painter.setPen(Qt::black);
    painter.drawText(100, 300, "ID : " + id);
    painter.drawText(100, 350, "Nom : " + nom);
    painter.drawText(100, 400, "Type : " + type);
    painter.drawText(100, 450, "Nombre de doses : " + doses);
    painter.drawText(100, 500, "Température de conservation : " + temperature);
    painter.drawText(100, 550, "Date d'expiration : " + date);

    painter.end();

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Page 3 (index 2)
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Page 3 (index 2)
}
